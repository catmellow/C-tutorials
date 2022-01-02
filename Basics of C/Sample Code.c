#include<stdio.h>
#include<math.h>

void pb(int);
int power(int,int);
int catalan(int);

int main(){
    int n;
    printf("Enter an integer:");
    scanf("%d",&n);
    printf("\n");
    pb(n);
    return 0;
}

void pb(int n){
    if(n!=0){
        pb(n/2);
        printf("%c",'0'+n%2);
    }
}

//Example 2
/*int power(int x, int n){
    if(n==0)
        return 1;
    else
        return x*power(x,n-1);

    //OR can be written as follows
    //return (n==0)?1:x*power(x,n-1);
}*/

//Example 3
/*int catalan(int n){
    if(n<=0)
        return 1;
    else{
        int sum=0, i;
        for(i=1;i<=n;i++)
            sum+=catalan(i-1)*catalan(n-i);
        return sum;
    }
}*/




