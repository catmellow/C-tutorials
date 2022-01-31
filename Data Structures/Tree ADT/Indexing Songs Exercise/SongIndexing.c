#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "avltree.h"
#include "queue.h"

int Min(int x, int y);
AVLTree readData(char *filename, int *size);
AVLTree insertSong(char name[30], char genre[30], char album[30], char artist[30], char date[30], char time[30], int year, AVLTree);
void displaySongs(AVLTree mTree);
void popularArtist(AVLTree t, int size);
void oldestSong(AVLTree t, int size);

int main(int argc, char *argv[])
{
	int size;
	int condition = 0;//menu loop condition
	AVLTree myTree;
	myTree = CreateTree();
	myTree = readData(argv[1],&size);
	printf("Welcome to Song Indexing\n");
	while(!condition)
	{
		fflush(stdin);
		char menu;
		printf("\n-----------------------------------------------------------------------------\n");
		printf("1. Display the full index of songs\n");
		printf("2. Display the songs of popular artist\n");
		printf("3. Display the oldest song\n");
		printf("4. Exit\n\n");
		printf("Option: ");
		scanf("%c",&menu);
		fflush(stdin);

		switch(menu)
		{
			case '1'://displays alphabetically sorted tree
				printf("\n");
				displaySongs(myTree);
				break;
			case '2'://displays the most songs artist
				printf("\n");
				popularArtist(myTree,size);
				break;
			case '3'://displays the oldest song based on release year
				printf("\n");
				oldestSong(myTree,size);
				break;
			case '4'://breaking the loop to exit
				condition = 1;
				break;
			default:
				printf("invalid input!\n");
				break;
		}
	}

	return 0;
}

int Min(int x, int y)
{
	if(x <= y)
		return x;
	else
		return y;
}

AVLTree readData(char* filename ,int *size)
{
    FILE* sfile;
    sfile = fopen(filename,"r"); //Open file to read with given txt name.
    if (sfile == NULL)
    {
        printf("File could not open!!!\n");
        exit(1);
    }
    else
    {
        int line = 0;
        AVLTree t;
        t = CreateTree();
        while (!feof(sfile)) //reading from file and inserting to avltree.
        {
        	fflush(stdin);
           	char name[30], genre[30], album[30], artist[30], date[30], time[30];//I added extra variable time to get the date's input properly
    		int year;
            fscanf(sfile, "%[^;];%[^;];%[^;];%[^;];%d;%[^ ] %s\n",name,genre,album,artist,&year,date,time);
            line++;
            t = insertSong(name,genre,album,artist,date,time,year,t);
        }

        *size = line;
        printf(">>songIndexing %s\n\n",filename);
		return t;
    }
    fclose(sfile);
}

AVLTree insertSong(char name[30], char genre[30], char album[30], char artist[30], char date[30], char time[30], int year, AVLTree t)
{
	if (t == NULL)
	{
		t = (AVLTree)malloc(sizeof(struct Tree));//once dynamic memory for if t is NULL

		strcpy(t->Song_Name,name);
		strcpy(t->Song_Genre,genre);
		strcpy(t->Album_Name,album);
		strcpy(t->Artist_Name,artist);
		strcpy(t->Date,date);
		strcpy(t->time,time);
		t->Year = year;
        t->height = 0;
		t->left = NULL;
		t->right = NULL;
		t->next = NULL;
	}
	else
    {
        int c;
        c = strcmp(artist,t->Artist_Name);//comparing the Artist Names to sort alphabetically

		if (c < 0)
        {
            t->left = insertSong(name,genre,album,artist,date,time,year,t->left);
            if (AVLTreeHeight(t->left) - AVLTreeHeight(t->right) == 2)
            {
                int c2;
                c2 = strcmp(artist,t->left->Artist_Name);
                if (c2 < 0)
                {
                    t = SingleRotateWithLeft(t);
                }
                else
                {
                    t = DoubleRotateWithLeft(t);
                }
            }
        }
        else if (c > 0)
        {
            t->right = insertSong(name,genre,album,artist,date,time,year,t->right);
            if (AVLTreeHeight(t->right) - AVLTreeHeight(t->left) == 2)
            {
                int c3;
                c3 = strcmp(artist,t->right->Artist_Name);
                if (c3 > 0)
                {
                    t = SingleRotateWithRight(t);
                }
                else
                {
                    t = DoubleRotateWithRight(t);
                }
            }
        }
        else
        {
            t->next = insertSong(name,genre,album,artist,date,time,year,t->next);
            return t;
        }
    }

	return t;
}

void displaySongs(AVLTree mTree)
{
	AVLTree t;
    t = malloc(sizeof(struct Tree));
    t = mTree;

	if (t != NULL)
	{
		displaySongs(t->left);
        printf("%s;",t->Song_Name);
		printf("%s;",t->Song_Genre);
		printf("%s;",t->Album_Name);
		printf("%s;",t->Artist_Name);
		printf("%d;",t->Year);
		printf("%s %s\n",t->Date,t->time);
		displaySongs(t->next);
		displaySongs(t->right);
	}
}

void popularArtist(AVLTree t, int size)
{
	char arr[size][30];
	int i=0,k;
	int l=1, max = 0;
	char most_repeated[30];

	/*
	in order to tracking tree elements one by one, I used ADT (Queue)
	*/
	Queue q;
	q = CreateQueue();
	enqueue(q,t);
	AVLTree tmp;

	while(q->front != NULL)
    {
        strcpy(arr[i],q->front->data->Artist_Name);
        tmp = dequeue(q);// dequeue the q in order to put the elements into temporary tree
        i++;
        if(tmp->next != NULL)
        {
            enqueue(q,tmp->next);
        }
        if(tmp->right !=NULL)
        {
            enqueue(q,tmp->right);
        }
        if(tmp->left != NULL)
        {
            enqueue(q,tmp->left);
        }
    }

	for(i=0 ; i<size ; i++)//to decide which artist has the most songs, by comparing all tree elemnts
	{
		for(k=i+1 ; k<size ; k++)
		{
			int compare = strcmp(arr[i],arr[k]);

			if(compare == 0)
			{
				l++;
			}
		}
		if(l>max)
		{
			max = l;
			strcpy(most_repeated,arr[i]);
		}
		l = 1;
	}

	/*
	second ADT (Queue) used for the tracking to print
	*/
	Queue q2;
	q2 = CreateQueue();
	enqueue(q2,t);
	AVLTree tmp2;

	while(q2->front != NULL)
	{
		int compare = strcmp(q2->front->data->Artist_Name,most_repeated);

		if(compare == 0)
		{
			printf("%s;",q2->front->data->Song_Name);
			printf("%s;",q2->front->data->Song_Genre);
			printf("%s;",q2->front->data->Album_Name);
			printf("%s;",q2->front->data->Artist_Name);
			printf("%d;",q2->front->data->Year);
			printf("%s %s\n",q2->front->data->Date,q2->front->data->time);
		}
		tmp2 = dequeue(q2);

		if(tmp2->left != NULL)
        {
            enqueue(q2,tmp2->left);
        }
        if(tmp2->next != NULL)
        {
            enqueue(q2,tmp2->next);
        }
        if(tmp2->right != NULL)
        {
            enqueue(q2,tmp2->right);
        }
	}

}

void oldestSong(AVLTree t, int size)
{
	int arr[size];
	int i=0,k,l=0,min;
	int min_val = 0;

	/*
	in order to tracking tree elements one by one, I used ADT (Queue).
	Same algorithim as in the popularArtist()
	*/
	Queue q;
	q = CreateQueue();
	enqueue(q,t);
	AVLTree tmp;

	while(q->front != NULL)
    {
        arr[i] = q->front->data->Year;
        tmp = dequeue(q);
		i++;
        if(tmp->next != NULL)
        {
            enqueue(q,tmp->next);
        }
        if(tmp->right !=NULL)
        {
            enqueue(q,tmp->right);
        }
        if(tmp->left != NULL)
        {
            enqueue(q,tmp->left);
        }
    }

    for(i=0 ; i<size ; i++)//finding minimum year to find oldest song
    {
    	for(k=i+1 ; k<size ; k++)
    	{
			min_val = Min(arr[i],arr[k]);
		}
	}

	Queue q2;
	q2 = CreateQueue();
	enqueue(q2,t);
	AVLTree tmp2;

	/*
	second ADT (Queue) used for the tracking to print.
	Same algorithim as in the populerArtist()
	*/
	while(q2->front != NULL)
	{
		if(min_val == q2->front->data->Year)
		{
			printf("%s;",q2->front->data->Song_Name);
			printf("%s;",q2->front->data->Song_Genre);
			printf("%s;",q2->front->data->Album_Name);
			printf("%s;",q2->front->data->Artist_Name);
			printf("%d;",q2->front->data->Year);
			printf("%s %s\n",q2->front->data->Date,q2->front->data->time);
		}
		tmp2 = dequeue(q2);

		if(tmp2->left != NULL)
        {
            enqueue(q2,tmp2->left);
        }
        if(tmp2->next != NULL)
        {
            enqueue(q2,tmp2->next);
        }
        if(tmp2->right != NULL)
        {
            enqueue(q2,tmp2->right);
        }
	}
}
