# File Exercises
## Example Code
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

	int lineNum=0 ,i, year;
	char  ch,day[20],month[20];

	// Open a file for reading
	FILE *inFile;
    inFile=fopen("data.txt","r");
    if(inFile==NULL)
		{printf("Failed to open the file!\n");exit(1);}
	else
		printf("Successfully open the file!\n");

	// Find number of lines in the file
	while((ch= fgetc(inFile)) !=EOF)
        if(ch=='\n')
            lineNum++;
    printf("The number lines is %d\n",lineNum);
    
    // Taking the cursor to the beginning of file
    fseek(inFile,0L,SEEK_SET);
    
    // Reading lines in a file with a delimeter
	while(fscanf(inFile,"%[^;]; %[^;]; %d\n",day,month,&year)!=EOF)				
		printf("%s  %s  %d\n", day, month, year);
		
    fclose(inFile);
    
    return 0;
}
```

**Data.txt**
```
Saturday;July;1989
Monday;June;1995

```
