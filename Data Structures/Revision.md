# Revision

## (Pointers, Pointers and Arrays, and Structures)

Purpose:
This exercise aims to revise the following topics: 
1. how to use pointers, and how to do pointer based C programming;
2. the relation between pointers and arrays;
3. how to do dynamic memory allocation;
4. how to use structures. 

Write a program that aims to represent an RGB images and does some computations based on these. For this program you need to provide the following:

* **a.** Write a structure called RGB_Image that represents an RGB image – composed of three arrays (R, G and B) each with size of 5 by 5 pixels.

* b. Write a function called formRGBImage that takes the number of images that will be created and then it dynamically creates an array of RGB images, randomly assigns integer values between 0 and 255 for each image (R, G and B) and then returns the array back to the main function.

* **c.** Write a function called AverageOfChannels that takes an array structure, calculates and displays the average of R, G and B channels of each image.

*Sample run can be as follows for the created 2 RGB images;*

![](https://i.imgur.com/zOl05Hj.png)



```
Enter the number of images you want: 2
Average of each channel of images are as follows:
Image 1: R=114, G=122, B=119
Image 2: R=126, G=134, B=131
```



**Sample Code**

```c

#include<stdio.h>
#include<mem.h>
#include<string.h>
#include<time.h>

struct RGB_Image
{
    int R[5][5];
    int G[5][5];
    int B[5][5];
};

struct RGB_Image *formRGBImage(int numb)
{
    int i,j,k;
    struct RGB_Image *dynamicarr;
    dynamicarr = (int*)malloc( numb * sizeof(struct RGB_Image));

    srand(time(0));
    for(k=0 ; k<numb; k++)
    {
          for ( i = 0; i < 5; i++)
          {
              for (j = 0; j < 5; j++)
              {
                  int randomR = (rand() %(256));
                  int randomG = (rand() %(256));
                  int randomB = (rand() %(256));
                  dynamicarr[k].R[i][j]=randomR;
                  dynamicarr[k].G[i][j]=randomG;
                  dynamicarr[k].B[i][j]=randomB;
              }
          }
    }

    return dynamicarr;
}

void AverageOfChannels(struct RGB_Image *thing,int numb)
{
    int i,j,k;
    int countR=0;
    int countG=0;
    int countB=0;
    printf("\nAverage of each channel of images are as follows:\n");
    for(k=0 ; k<numb; k++)
    {
          for ( i = 0; i < 5; i++)
          {
              for (j = 0; j < 5; j++)
              {
                countR = countR + thing[k].R[i][j];
                countG = countG + thing[k].G[i][j];
                countB = countB + thing[k].B[i][j];
              }
          }
                printf("Image %d R: %d  G: %d B: %d\n",k+1,countR/(25),countG/(25),countB/(25));
    }

}

int main()
{
    int number,i,j,k;
    struct RGB_Image *array;
    printf("Enter the number of images you want: ");
    scanf("%d",&number);
    array = formRGBImage(number);
   AverageOfChannels(array,number);
}


```
