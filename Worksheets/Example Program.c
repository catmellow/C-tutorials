#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void strCopy(char *s, char *t){
    int i=0;
    while(s[i]!='\0'){
      t[i]=s[i];
      i++;
    }
    t[i]='\0';
}

int main(int argc, char *argv[])
{
    //*******************
    //Example 1 -- Copy one string to another!
    //*******************
    char msg[80],copymsg[80];
    printf("Enter a string:");
    scanf("%s",msg);
    strCopy(msg,copymsg);
    printf("%s",copymsg);

    //*******************
    //Example 2 -- Array of strings
    //*******************
    /*char list[3][80]= {"Apple","Orange","Pear"};
    int i;
    for(i=0; i<3; i++)
        printf("%s\n",list[i]);
    printf("\n");*/


    //*******************
    //Example 3 -- Array of string pointers
    //*******************
    /*char *list2[10]= {"Apple","Orange","Pear"};
    for(i=0; i<3; i++)
        printf("%s\n",list2[i]);
    printf("\n");*/


    //*******************
    //Example 4 -- Dynamic array of strings
    //*******************
    /*char **list3;
    list3=(char **) malloc(3*sizeof(char*));
    if(list3==NULL){
        printf("Memory allocation error");
        exit(1);
    }
    for(i=0; i<3; i++)
    {
        list3[i]=malloc(10*sizeof(char));
        strcpy(list3[i],"hello");
    }
    for(i=0; i<3; i++)
        printf("%s\n",list3[i]);

    for(int i=0;i<3;i++)
        free(list3[i]);
    free(list3);*/


    //*******************
    //Example 5 -- Command line arguments: argc and argv
    //*******************
    /*printf("\nNumber of args=%d\n",argc);
    int i;
    for(i=0;i<argc;i++)
        printf("\nargv[%d]=%s\n",i,argv[i]);*/

    return 0;
}
