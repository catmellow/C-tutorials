#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main() {
     int n;
     printf("Enter number of courses:");
     scanf("%d",&n);

     /*Since we do not know the number of courses taken, we create dynamic arrays*/
     float *grades = (float *)malloc(n*sizeof(float));
     float *credits = (float *)malloc(n*sizeof(float));
     float *coefficients = (float *)malloc(n*sizeof(float));

     int i;
     for(i=0;i<n;i++){
         printf("Enter grade for course %d:",i+1);
         scanf("%f",&grades[i]);

         /*Depending on the grade entered a cofficient is decided*/
         if(grades[i]>=90 && grades[i]<=100)
            coefficients[i]=4.0;
         else if (grades[i]>=85)
            coefficients[i]=3.5;
         else if (grades[i]>=80)
            coefficients[i]=3.0;
        else if (grades[i]>=75)
            coefficients[i]=2.5;
        else if (grades[i]>=70)
            coefficients[i]=2.0;
        else if (grades[i]>=65)
            coefficients[i]=1.5;
        else if (grades[i]>=60)
            coefficients[i]=1.0;
        else if (grades[i]>=50)
            coefficients[i]=0.5;
        else
            coefficients[i]=0;
     }

    printf("\n");
    /*Course credit is entered by the users*/
    for(i=0;i<n;i++){
         printf("Enter credit for course %d:",i+1);
         scanf("%f",&credits[i]);
     }

     /*We calculate the total credits and also the total of credits multiplied with coefficients*/
    float total_credits=0;
    float total_credits_coefficient=0;
    for(i=0;i<n;i++){
         total_credits+=credits[i];
         total_credits_coefficient+=credits[i]*coefficients[i];
     }

    /*Her is the GPA calculation*/
    float gpa=total_credits_coefficient/total_credits;

    printf("Your GPA is %.2f",gpa);

    return 0;
}
