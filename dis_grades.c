#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"grades_coordinator.h"
void display()
{
    char path[100] = "./grades/";  
    /*basicaly stores the path and name of the file in a char array concatenates path and roll number, rollnumber and .txt*/
    char rollno[20];
    printf("Enter the Roll number : ");
    scanf("%s",rollno);
    strcat(path,rollno);
    strcat(path,".txt");
    /*standard code to print the file using the path string*/
    char c;             
    FILE *fptr;
    fptr = fopen(path,"r");
    if (fptr == NULL)
    {
        printf("NO SUCH STUDENT RECORD EXISTS\n\n");
        printf("Enter 'b' to go back or 'c' to continue");
        getc(stdin);
        char c = getchar();
        if (c == 'c')
            display();
        else if(c == 'b')
            co_ordinator();
        else 
        {
            printf;("OOPS!!! SOMETHING WENT WRONG");
            exit(0);
        }
    }
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
    fclose(fptr);
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s",proceed);
    system("clear");
	co_ordinator();
}