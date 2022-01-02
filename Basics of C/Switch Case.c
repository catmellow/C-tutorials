#include <stdio.h>
int main()
{

    //Example 1

    int age=45;
    if(age>=65);
        printf("age>65");
    else
        printf("age <65");

    //Example 2
    /*
    int x=5;
    int y=5;
    if(x<10)
    if(y>10)
    printf("****\n");
    else
    printf("####\n");
    printf("$$$$\n");
    */

    //example 3
    /*int n=5, b=3, a=4, z;
    if(n>0)
        if(a>b)
            z=a;
        else
            z=b;
    printf("\nz=%d\n",z);*/

    //Example 4
    /*int a=2;
    int b=0;

    if(a<b)
        printf("factor=0.02");
    else if (a==b)
        printf("factor=0.04");
    else if(!a)
        printf("factor=0.06");
    else if (!a || !b)
        printf("factor=1.02");
    else if (!b)
        printf("factor=1.04");
    else
        printf("factor=1.06");*/

    //Example 5
    /*
    char c=9;
    switch(c)
    {
    case '0':    case '1':    case '2':    case '3':    case '4':    case '5':
    case '6':    case '7':    case '8':    case '9':
        printf("digit");
        break;
    case ' ':    case '\n':    case '\t':
        printf("Not white");
        break;
    default:
        printf("other char");
    } */

    //Example 6
    /*int commission, value;
    printf("Enter value of trade: ");
    scanf("%d", &value);

    if (value < 2500)
        commission = 30 + 17 * value;
    else if (value < 6250)
        commission = 56 + 66 * value;
    else if (value < 20000)
        commission = 76 + 34 * value;
    else if (value < 50000)
        commission = 100+ 22 * value;
    else if (value < 500000)
        commission = 155 + 11 * value;
    else
        commission = 255 + 9 * value;

    if (commission < 49)
        commission = 49;

    printf("Output here�\nCommission: $%5d\n", commission);*/

    printf("\n\n");
    return 0;

}

