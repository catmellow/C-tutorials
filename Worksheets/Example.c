#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
Structure to define a student which has the following data:
id -- It is the student id
name -- It will store the student name
surname -- It will store the surname of the student
section -- It will store the section information of a student
**/
struct Student
{
    int id;
    char name[30];
    char surname[30];
    int  section;
};

/**
This function reads a file and populates the data from that file to an array of students.
Input: The name of the file and the list of students
Output: If it fails to read the file returns -1, otherwise it returns the number of students read from the file
**/
int scan_students(char *fileName, struct Student *list)
{
    //Open the file
    FILE *inFile = fopen(fileName,"r");
    if(inFile==NULL)
    {
        //If the file cannot be read, give relevant error message and return -1
        printf("%s Cannot be opened!",fileName);
        return -1;
    }
    //Set the record size to zero
    int i=0;
    char line[100];
    //We will read the file line by line
    while (fgets(line, 100, inFile))
    {
        char *token;
        //Get the first token
        token = strtok(line, " ");
        //Set a flag to take the data in order:
        int flag=1;
        //process the tokens - id name surname
        while( token != NULL )
        {
            //First token is the id
            if(flag==1)
                list[i].id=atoi(token);
            //Second token is the name
            else if(flag==2)
                strcpy(list[i].name,token);
            //Third token is the surname
            else{
                //Remove the new line at the end of the string
                if(token[strlen(token)-1]=='\n')
                    token[strlen(token)-1]='\0';
                strcpy(list[i].surname,token);
            }
            token = strtok(NULL, " ");
            flag++;
        }
        //If we read all three parts ok, id name surname then set the section number to zero
        if(flag>3){
            //Initialize the section number to zero
            list[i].section=0;
            i++;
        }
    }
    fclose(inFile);
    return i; //returns the number of students read
}

/**
This function displays the student list on the screen and writes them to the file as well
Input: student array, file name and the number of students in the array
Output: none
**/
void display_students(struct Student *list, char *fileName, int size){
    int i;
    FILE *outFile = fopen("students.txt","w");
    if(outFile==NULL){
        printf("\nCannot open file to write data");
        exit(1);
    }
    for(i=0;i<size;i++){
        printf("\nStudent ID:%d Name: %s, Surname: %s, section: %d\n",list[i].id, list[i].name, list[i].surname, list[i].section);
        fprintf(outFile,"%d %s %s %d\n",list[i].id, list[i].name, list[i].surname, list[i].section);
    }
    fclose(outFile);
}

/**
This function assigns students to their sections
a-k to section 1
l-z to section 2
Input: student list and the number of students
output: none
**/
void split_sections(struct Student *list, int size){
    int i;
    for(i=0;i<size;i++){
        //Convert to uppercase to ensure that we are always checking the ASCII code correctly
        //ASCII code of A=65
        //ASCII code of K=75
        if(toupper(list[i].surname[0])>=65 && toupper(list[i].surname[0])<=75)
            list[i].section=1;
        else
            list[i].section=2;
    }
}


int main()
{
    //Assume that we have at most 200 students in the file
    struct Student list[200];
    //Scan the file and retrieve students
    int size = scan_students("students.txt",list);
    if(size==-1){
        printf("\nFile cannot be processed");
        exit(1);
    }
    else if (size==0){
        printf("\nNo students data could be retrieved");
        exit(1);
    }
    else{
        split_sections(list,size);
        display_students(list,"student.txt",size);
    }
    return 0;
}
