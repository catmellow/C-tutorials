#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void fun(int *,int);

int main() {

    //*******************
    //Example 1 -- Array type int[10] is not assignable
    //*******************
    /*
    int *ptr1;
    int ptr2[10];

    ptr1=(int *) malloc (10*sizeof(int));
    if(ptr1==NULL){
        printf("Failed to do memory allocation!");
        exit(1);
    }

    ptr1=ptr2;
    ptr2=ptr1;*/

     //*******************
    //Example 2 -- Pointer to pointer initialisation -- Existing memory
     //*******************
    /*char ch, *p, **pp;
    ch='a';
    p=&ch;
    pp=&p;
    printf("\nch=%c, *p=%c, **p=%c\n",ch,*p, **pp);*/

     //*******************
    //Example 3 -- Pointer to pointer initialisation -- Dynamic
     //*******************

    /*char ch, **pp;
    ch='a';
    pp=(char **) malloc(sizeof(char *));
    if(pp==NULL){
        printf("Failed to do memory allocation!");
        exit(1);
    }
    *pp = (char *) malloc (sizeof(char));
    if(*pp==NULL){
        printf("Failed to do memory allocation!");
        exit(1);
    }
    **pp='a';
    printf("\nch=%c **p=%c\n",ch, **pp);*/

     //*******************
    //Example 4 -- Different ways of representing two-dimensional arrays
     //*******************
    /*int arr[2][3];
    int i, j;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            arr[i][j]=i+j;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++)
            printf("%d",arr[i][j]);
        printf("\n");
    }

    int *arr2[2];
    arr2[0] = (int*)malloc(3*sizeof(int));
    if(arr2[0]==NULL){
        printf("Failed to do memory allocation!");
        exit(1);
    }
    arr2[1] = (int*)malloc(3*sizeof(int));
    if(arr2[1]==NULL){
        printf("Failed to do memory allocation!");
        exit(1);
    }
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            arr2[i][j]=i+j;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++)
            printf("%d",arr2[i][j]);
        printf("\n");
    }

    int **arr3;
    arr3 = malloc(2*sizeof(int *));
     if(arr3==NULL){
        printf("Failed to do memory allocation!");
        exit(1);
    }
    arr3[0] = (int*)malloc(3*sizeof(int));
    if(arr3[0]==NULL){
        printf("Failed to do memory allocation!");
        exit(1);
    }
    arr3[1] = (int*)malloc(3*sizeof(int));
    if(arr3[1]==NULL){
        printf("Failed to do memory allocation!");
        exit(1);
    }
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            arr3[i][j]=i+j;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++)
            printf("%d",arr3[i][j]);
        printf("\n");
    }*/

    //*******************
    //Example 4 -- Dynamic arrays and functions and free function!
    //*******************
    /*int *pt;
    int n,i;
    printf("How many elements you could like to store:");
    scanf("%d",&n);
    pt = (int *) malloc(n*sizeof(int));
    if(pt==NULL){
        printf("Failed to do memory allocation!");
        exit(1);
    }
    for(i=0;i<n;i++)
        pt[i]=10;
    fun(pt,n);
    for(i=0;i<n;i++)
        printf("%d\t",pt[i]);
    free(pt);*/

    return 0;
}

void fun(int *arr, int n){
    int i;
    for(i=0;i<n;i++)
        arr[i]+=10;
}
