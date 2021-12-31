#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 1
#define FALSE 0
#define HEAD 1
#define TAIL 0

int main()
{
    //Prime Number
    /*
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int isPrime = TRUE, primeFactor;
    for(primeFactor=2;primeFactor<=sqrt(n);primeFactor++){
            if(n%primeFactor==0)
               isPrime = FALSE;
    }
    if(isPrime==TRUE)
        printf("\n%d is Prime\n",n);
    else
        printf("\n%d is NOT a Prime\n",n);
	*/


    
    /*
    int toss;
    srand(time(NULL));
    toss = (int) rand() % 2;
    if(toss==HEAD)
       printf("HEAD\n");
    else
		printf("TAIL\n");
	*/

   
    /*
    int toss,i;
    srand(time(NULL));
	int i;
	int noHead=0,noTail=0;
	for(i=0;i<1000;i++)		
	{
	    toss = (int) rand() % 2;
        if(toss==HEAD)
			noHead++;
        else
			noTail++;
	}
	printf("\nHead=%d, Tail=%d\n",noHead,noTail);
	*/
}
