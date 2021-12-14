# Data Structures – Programming Exercise
## InstuctorBook
This exercise aims to help you practice linked list data structure and basic linked list operations. The main task in this assignment is to write a C program to create a simple application that will allow you to manage information about instructors. The InstructorBook will include the list of instructors with their details (first name, last name, title, email, phone number, and room number). It will help you manage the list of instructors, where you can add an instructor, find the details of an instructor, and delete an instructor from your instructor list.

When the C program is run, the InstructorBook will first create a linked list of the instructors, which is initialized by reading the details of your instructors from an external text file. Then the program will provide some operations for you to manage the InstructorBook. Therefore, the program needs to support the following procedures. 

* **Reading the instructors from an external file and initialising the instructor list:**

The program needs to be invoked with a command-line argument: the file's name includes the instructor's details. If this command-line argument is not provided, the program needs to ask the user to enter the name of the text file. The file should include the first name, last name, title, email, phone number, and room number of the instructors, separated by a semicolon (;). We assume that there are no duplicates in the first names and surnames. An example file is shown below that contains three instructors: 

```
Melih;Star;Prof. Dr.;Star.melih@metu.edu.tr;2953;SZ99
Ata;Fisherman;Prof. Dr.;A.Fisherman@metu.edu.tr;2960;S132
Adam;Smith;Assoc. Prof. Dr.;smith.adam@metu.edu.tr;2961;R139
```
The program will read the instructors from the file and use a linked list to store the instructors’ details. Please note that any assumptions cannot be made about the number of instructors, and there is no upper limit for the number of instructors. In internal representation, you will need to decide about the structure of the linked list based on the txt file given. 

* **Inserting a new instructor:**

After initializing your InstructorBook with an external file, you may want to insert a new instructor to your instructor list. Therefore, the program should ask you the required details (first name, last name, title, email, phone number, and room number) for your new instructor and add them to the instructor list. 

* **Printing your instructor list:**

The program should traverse the list of the instructors and print the instructors on the screen with their details.

* **Searching for an instructor in your instructor list:**

The program should allow you to search for an instructor with their first name. Please note the search algorithm should have the O(log N) complexity
* **Current semester Instructors**

The program should create a separate instructor list for the current semester instructors. First of all, you need to enter the first name of your instructor to move them. Then the program will find the instructor, delete it from the list of the instructors, and add the current semester instructor to the list of the current instructors. Therefore, you need to have another linked list to keep the list of the current instructors. 

* **Printing your Current semester Instructors:**

The program should traverse the list of the current semester instructors and print them on the screen with their details.

When you write this program, you need to consider the data structure that will be necessary. Two linked lists will be required: one for the list of your instructors and another for your instructors. Therefore, it is recommended that you first implement your basic linked list operations (add/delete/search, etc.). Using these basic operations on linked lists can implement other required procedures. To achieve the steps, you can use the following functions. In addition to these functions below, you can write some helper/auxiliary functions. 



| Function  | Explanation | Input | Output |
| -------- | -------- | -------- | -------- |
| initialiseInstructorBook     | To create and initialise alist of instructors by reading the instructors from an external file     | File name     | A list of instructors     |
| InsertInstructor     | To insert a new instructor in the list of instructors by asking the required details     | A list of instructors     |      |
| PrintInstructors     | To display the list of the instructors with their details     | A list of instructors     |      |
| SearchInstructor     | To search for a specific instructor with given first name, and then print their details – O(log N)     | A list of instructors and the first name of the instructor     |      |
| CurrentSemesterInstructors     | Add the instructor to the current semester instructors list     | A list of instructors and A list of current semester instructors     | A list of current semester instructors     |
| printCurrentSemsterInstructors     | To display the list of current semester instructors with their details     | A list of current semester instructors     |      |

***Sample Run***
```
The instructors.txt file has been loaded successfully
----- MENU-----
1. Add Instructor
2. Print Instructor
3. Search Instructor
4. Create Current Semester Instructors List
5. Print Current Semester Instructors List
6. Exit

Enter your option: 1
    
Enter instructor name: Sherlock
Enter instructor surname: Walter
Enter instructor title: Assoc. Prof. Dr
Enter instructor email: sherlock@metu.edu.tr
Enter instructor phone number: 1234
Enter instructor room number: S999

The instructor has been added!! 
    
----- MENU-----
1. Add Instructor
2. Print Instructor
3. Search Instructor
4. Create Current Semester Instructors List
5. Print Current Semester Instructors List
6. Exit

Enter your option: 2
    
    
Instructor in your database:
-----------------------

Instructor name: Melih
Instructor surname: Star
Instructor title:Prof. Dr.
Instructor email: Star.melih@metu.edu.tr
Instructor phone number: 2960
Instructor room number: SZ99

Instructor name: Ata
Instructor surname: Fisherman
Instructor title: Prof. Dr.
Instructor email: Fisherman@metu.edu.tr
Instructor phone number: 2961
Instructor room number: SZ132

Instructor name: Adam
Instructor surname: Smith
Instructor title: Assoc. Prof. Dr.
Instructor email: smith.adam@metu.edu.tr
Instructor phone number: 2961
Instructor room number: R139

Instructor name: Sherlock
Instructor surname: Walter
Instructor title: Assoc. Prof. Dr
Instructor email: sherlock@metu.edu.tr
Instructor phone number: 1234
Instructor room number: S999

----- MENU-----
1. Add Instructor
2. Print Instructor
3. Search Instructor
4. Create Current Semester Instructors List
5. Print Current Semester Instructors List
6. Exit

Enter your option: 3

Enter the name of the instructor you want to search: Melih

Results
---------------------
Instructor name: Melih
Instructor surname: Star
Instructor title:Prof. Dr.
Instructor email: Star.melih@metu.edu.tr
Instructor phone number: 2960
Instructor room number: SZ99

----- MENU-----
1. Add Instructor
2. Print Instructor
3. Search Instructor
4. Create Current Semester Instructors List
5. Print Current Semester Instructors List
6. Exit

Enter your option: 3
    
Enter the name of the instructor you want to search: Sarah

Instructor not found!!!
    
----- MENU-----
1. Add Instructor
2. Print Instructor
3. Search Instructor
4. Create Current Semester Instructors List
5. Print Current Semester Instructors List
6. Exit

Enter your option: 4
    
Enter instructor name you want to add to your current
semester list: Sherlock

Sherlock has been moved to current semester list.

----- MENU-----
1. Add Instructor
2. Print Instructor
3. Search Instructor
4. Create Current Semester Instructors List
5. Print Current Semester Instructors List
6. Exit


Enter your option: 4
    
Enter instructor name you want to add to your current semester list: Sara

Instructor not found!!!

    
----- MENU-----
1. Add Instructor
2. Print Instructor
3. Search Instructor
4. Create Current Semester Instructors List
5. Print Current Semester Instructors List
6. Exit

Enter your option: 5

Results
---------------------
Instructor name: Sherlock
Instructor surname: Walter
Instructor title: Assoc. Prof. Dr
Instructor email: sherlock@metu.edu.tr
Instructor phone number: 1234
Instructor room number: S999
    
    ----- MENU-----
1. Add Instructor
2. Print Instructor
3. Search Instructor
4. Create Current Semester Instructors List
5. Print Current Semester Instructors List
6. Exit

Enter your option: 6
    
```



# Sample Code
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char firstname[30];
    char lastname[30];
    char title[30];
    char mail[30];
    char phone[10];
    char room[10];
    struct node *next;
};

struct ListRecord
{
    struct Node *head;
    struct Node *tail;
    int size;
};

typedef struct ListRecord *List;

struct ListRecord *initialiseInstructorBook(char filename[30])
{
    List L;
    L = (struct ListRecord*) malloc(sizeof(struct ListRecord));
    if(L==NULL) // checking whether or not the List is null.
        printf("[Error]: Out of memory\n");

    // making list empty
    L->head = (struct Node*) malloc(sizeof(struct Node));
    if(L->head==NULL) //checking whether or not the making empty list is null.
        printf("[Error]: Out of memory\n");

    L->head->next=NULL;
    L->tail = L->head;
    L->size=0;


	while(1)
	{

	    FILE *filep;
	    filep=fopen(filename,"r");

	    if(filep==NULL) // If this command line argument is not provided then the program asks the user to enter the name of the text file.
	    {
	    	char myfile[30]; // in case of the file does not exist or could not be opened.
	        printf("\n[Error]: File %s could not been loaded.\nPlease enter the file name again : ",filename);
	        scanf(" %s",&myfile);
			strcpy(filename,myfile);
	    }
	    else
	    {
	            printf("\nThe %s file has been loaded successfully!\n\n",filename); // if the file exist and opening without any errors

	            char ch;
	            int i;
	            int count=0; // represents how many lines the file has


	                while((ch= fgetc(filep)) !=EOF)
	                {
	                    if(ch=='\n')
	                    {
	                        count++;
	                    }
	                }
	                // Taking the cursor to the beginning of file so that we can read file again
	                fseek(filep,0L,SEEK_SET);
	                // Creating newnode
	                struct Node *newnode;
	                newnode = (struct Node*) malloc(sizeof(struct Node));

	                for(i = 0; i < count ; i++)
	                {
	                    newnode = (struct Node*) malloc(sizeof(struct Node));
	                    fscanf(filep,"%[^;];%[^;];%[^;];%[^;];%[^;];%s\n",newnode->firstname,newnode->lastname,newnode->title,newnode->mail,newnode->phone,newnode->room);
	                    newnode->next = NULL;
	                    L->tail->next=newnode;
	                    L->tail=newnode;
	                    L->size++;
	                }
	                L->tail->next = NULL;

	        break;
	    }
	}


	return L;


}

void insert(List L)
{
    // Creating newnode*
    struct Node *newnode;
    newnode = (struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter instructor name:");
    scanf("%s",newnode->firstname);
    printf("\nEnter instructor surname:");
    scanf("%s",newnode->lastname);
    printf("\nEnter instructor title:");
   	scanf(" %[^\n]s",newnode->title);
    printf("\nEnter instructor email:");
    scanf("%s",newnode->mail);
    printf("\nEnter instructor phone number:");
    scanf("%s",newnode->phone);
    printf("\nEnter instructor room number:");
    scanf("%s",newnode->room);
    newnode->next=NULL;

    // adding part
    L->tail->next=newnode;
    L->tail=newnode;
    L->size++;

}



void SearchInstructor(List liste)
{
	char searchdummy[30];
	struct Node *p;
    p=liste->head->next;

    printf("\nEnter the name of the instructor you want to search:");
    scanf("%s",&searchdummy);

    while(p!=NULL)
    {
    	if(strcmp(searchdummy,p->firstname)==0)
    	{
    		printf("\n\n\tResults");
    		printf("\n-------------------------");
			printf("\nInstructor name: %s",p->firstname);
			printf("\nInstructor surname: %s",p->lastname);
			printf("\nInstructor title: %s",p->title);
			printf("\nInstructor mail: %s",p->mail);
			printf("\nInstructor phone number: %s",p->phone);
			printf("\nInstructor room number: %s\n\n",p->room);
			return;

		}
		p=p->next;
	}
	printf("\nInstructor not found!!!\n");
}



struct ListRecord *CurrentSemsterInstructors(List L, List newliste)
{
	char checks[20]; 
	struct Node *curr;
    curr=L->head;
    printf("\nEnter instructor name you want to add to your current semester list:");
    scanf("%s",&checks);

    while(curr->next != NULL)
    {
       
        if(strcmp(curr->next,checks)==0)
        {
        	struct Node *to_remove;
        	to_remove = (struct Node*) malloc(sizeof(struct Node));
        	to_remove = curr->next;
        	curr->next = to_remove->next;
        	to_remove->next=NULL;
            printf("\n%s has been moved to current semester list.\n",to_remove->firstname);
            
            newliste->tail->next=to_remove;
   			newliste->tail=to_remove;
    		newliste->size++;
    		
            break;
			
        }

        curr=curr->next;
    }

	return newliste;
}


void PrintInstructors(List l)
{
    struct Node *p;
    p=l->head->next;
    while(p != NULL)
    {
    	printf("\n\nInstructor name: %s",p->firstname);
    	printf("\nInstructor surname: %s",p->lastname);
    	printf("\nInstructor title: %s",p->title);
    	printf("\nInstructor email: %s",p->mail);
    	printf("\nInstructor phone: %s",p->phone);
    	printf("\nInstructor room: %s",p->room);
    	printf("\n\n");
    	p=p->next;
    }
    printf("\n");
}


int main()
{
    int choice = 0; // declearing the choice 0
    char filename[20] = "instructors.txt";


    List newlist;
    // initializing new list
    newlist = (struct ListRecord*) malloc(sizeof(struct ListRecord));
	if(newlist==NULL) // checking the list if it's null or not
	    printf("[Error]: Out of memory\n");
	// making list empty
	newlist->head = (struct Node*) malloc(sizeof(struct Node));
	if(newlist->head==NULL) //checking whether the empty list is null or not.
		printf("[Error]: Out of memory\n");

	newlist->head->next=NULL;
	newlist->tail = newlist->head;
	newlist->size=0;

    List l;
    l = initialiseInstructorBook(filename);
        while(choice != 6)
        {

            printf("\n----- MENU-----\n\n");
            printf("1. Add Instructor\n");
            printf("2. Print Instructor\n");
            printf("3. Search Instructor\n");
            printf("4. Create Current Semester Instructors List\n");
            printf("5. Print Current Semester Instructors List\n");
            printf("6. Exit\n\n");
            printf("Enter your option:  ");
            scanf("%d",&choice);

            if(choice == 1) /* Adding Instructor  */
            {
                insert(l);
            }
            else if( choice == 2) /* Printing Instructors */
            {
                PrintInstructors(l);
            }
            else if( choice == 3) /*  Search Instructors */
            {
				SearchInstructor(l);
            }
            else if( choice == 4) /* Create Current Semester Instructors */
            {

				newlist = CurrentSemsterInstructors(l,newlist);
				
            }
            else if( choice == 5) /* Printing Current Semester Instructors*/
            {

                PrintInstructors(newlist);

            }

        }

}

```

