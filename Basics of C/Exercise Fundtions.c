#include<stdio.h>
#include<math.h>

int fun (int);
void message(int);

int main()
{
    int result, count;
    for(count=0;count<5;count++){
        result = fun(count);
        message(result);
    }
    return 0;
}

int fun(int x){
    return x*x;
}

void message(int n){
    printf("Result=%d\n",n);
}

/*Bad example 1 --
Cannot nest a body of a function inside another function
int fun (int x){
    printf("Inside fun!");

    int g(void){
        printf("Inside g!");
    }
}*/

/*Bad Example 2:
A function is defined to have return so needs to return a value
int fun(int x){
    int y;
    y=x*x;
}*/

/*Bad Example 3:
Remember that your function needs to return a result
int fun(int x)
{
    if(x<0)
        return 0;
    else
    {
        int y;
        y=x*x;
    }
}*/

/*Bad Example 4:
No need to redeclare parameters!
int fun(int x)
{
    int x;
    int y=x*x;
    return y;
}*/




