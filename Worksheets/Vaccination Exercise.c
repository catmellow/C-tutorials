#include<stdio.h>
#include<time.h>

int number_vaccinated(int days, int new_vac)
{
    if(days==1)
        return new_vac;
    else
        return number_vaccinated(days-1,new_vac)+new_vac;

}

void display_message(int pop,int inf)
{
    if(inf>=(pop*70)/100)
    {
            printf("\n\n Herd Immunity Achieved");
    }
    else if(inf>(pop*50)/100)
    {
        printf("\n\n  More vaccines needed to achieve herd immunity ");
    }
    else
    {
        printf("\n\n  Herd Immunity NOT Achieved! ");
    }
}


int main()
{
    srand(time(NULL));
    int i,j,pop,check=0,count=0;
    int N=5;
    int array[N];
    printf("\nEnter the population for country[%d]:",check+1);
    while(1)
    {


            scanf("%d",&pop);

                if(pop<=90000 && pop>=10000) // checks whether the population satisfies or not
                {
                    array[check]=pop;

                    check++;

                }
                else
                {
                    printf("\n Error! Enter a value between 10000-90000! Please Enter Again.");

                }
            if(check==5)
                break;
            printf("\nEnter the population for country[%d]:",check+1);
    }

    int up1=(array[0]*30)/100;
    int up2=(array[1]*30)/100; // 30% of the population
    int up3=(array[2]*30)/100;
    int up4=(array[3]*30)/100;
    int up5=(array[4]*30)/100;

     int lower=1;
     int vac1= (rand() % (up1 - lower + 1)) + lower;
     int vac2= (rand() % (up2 - lower + 1)) + lower;
     int vac3= (rand() % (up3 - lower + 1)) + lower;
     int vac4= (rand() % (up4 - lower + 1)) + lower;//randomly generated number of vaccinated per day;
     int vac5= (rand() % (up5 - lower + 1)) + lower;

     printf("\n Counry 1, Number of newly vaccinated: %d", vac1); // for country 1
     int total=number_vaccinated(6,vac1);
     printf("\n In 5 days, number of vaccinated people in country 1 will be %d",total);
     display_message(array[0],total);

     printf("\n Counry 2, Number of newly vaccinated: %d", vac2);// for country 2
     int total2=number_vaccinated(6,vac2);
     printf("\n In 5 days, number of vaccinated people in country 2 will be %d",total);
     display_message(array[1],total2);

     printf("\n Counry 3, Number of newly vaccinated: %d", vac3);// for country 3
     int total3=number_vaccinated(6,vac3);
     printf("\n In 5 days, number of vaccinated people in country 3 will be %d",total);
     display_message(array[2],total3);

     printf("\n Counry 4, Number of newly vaccinated: %d", vac4);// for country 4
     int total4=number_vaccinated(6,vac4);
     printf("\n In 5 days, number of vaccinated people in country 4 will be %d",total);
     display_message(array[3],total4);

     printf("\n Counry 5, Number of newly vaccinated: %d", vac5);
     int total5 =number_vaccinated(6,vac5);
     printf("\n In 5 days, number of vaccinated people in country 5 will be %d",total);// for country 5

     display_message(array[4],total5);



}
