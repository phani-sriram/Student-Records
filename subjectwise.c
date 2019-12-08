#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grades_coordinator.h"
int maxthree(int a, int b, int c) //returns the maximum of three integers
{
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else if (c > a && c > b)
        return c;
    else if (a == b && b == c)
        return a;
    else if (a == b && b > c)
        return b;
    else if (b == c && c > a)
        return b;
    else if (a == c && c > b)
        return c;
}
void subjectwise() //lists grades student wise when coordinator enters the subject
{
    char array1[100] = "./grades/"; //relative path
    char array2[5] = "MT20";
    char roll[9] = "20001"; //stores rollno.
    strcat(array1, array2); //MT20 is added to the path
    int rolln = atoi(roll); //20001 is converted to an int
    printf("Enter for which term the grades you wish to see(1/2) or (0) to go back:");

    int counta = 0; //number of students with grade A
    int countb = 0;
    int countc = 0;
    int countd = 0;
    char arraydup[100]; //used in resetting the roll number array
    strcpy(arraydup, array1);
    int n = 20; //number of students
    int i;
    char array3[50];  //stores the digits of the rollno after MT20
    char subject[20]; //stores the subject
    char ch[25];
    scanf("%s", ch); //the term in which the subject is there
    if (ch[0] == '1')
    {
        printf("Enter the subject whose marks you wish to see:");
        scanf("%s", subject); //inputs the subject
        rolln = 20001;
        printf("\n");
        for (i = 20001; i < rolln + 20; i++) //for all 20 students
        {
            sprintf(array3, "%d", i); //stores the roll number in a string array3
            strcat(array1, array3);   //array1 is used to store the relative path now it contains the roll no as well
            strcat(array1, ".txt");   //the array1 now stores the path of the current rollnumber which is running in the loop
            FILE *fp = fopen(array1, "r");
            char strdef[10] = "MT20";                                                           //used to print the roll number before printing the grades
            if ((strncmp(subject, "Machine", 8) == 0) || (strncmp(subject, "machine", 8) == 0)) //if subject inputted is Machine
            {
                printf("%s   ", strcat(strdef, array3));
                fseek(fp, 46, SEEK_SET); //moves file pointer to where the grade is there
                char ch = fgetc(fp);
                printf("%c\n", ch); //prints the grades
                if (ch == 'A')      //these conditions are counting the number of As,Bs etc.
                    counta++;
                if (ch == 'B')
                    countb++;
                if (ch == 'C')
                    countc++;
                if (ch == 'D')
                    countd++;
            }
            else if (strncmp(subject, "Quantum", 8) == 0 || strncmp(subject, "quantum", 8) == 0)
            {
                printf("%s   ", strcat(strdef, array3));
                fseek(fp, 70, SEEK_SET);
                char ch = fgetc(fp);
                printf("%c\n", ch);
                if (ch == 'A')
                    counta++;
                if (ch == 'B')
                    countb++;
                if (ch == 'C')
                    countc++;
                if (ch == 'D')
                    countd++;
            }

            else if (strncmp(subject, "Signal", 7) == 0 || strncmp(subject, "signal", 7) == 0)
            {
                printf("%s   ", strcat(strdef, array3));
                fseek(fp, 94, SEEK_SET);
                char ch = fgetc(fp);
                printf("%c\n", ch);
                if (ch == 'A')
                    counta++;
                if (ch == 'B')
                    countb++;
                if (ch == 'C')
                    countc++;
                if (ch == 'D')
                    countd++;
            }
            else
            {
                printf("\n Press any KEY and then ENTER to go back");
                char proceed[50];
                scanf("%s", proceed);
                system("clear");
                subjectwise();
            }

            strcpy(array1, arraydup); //resets array1 so that in the next iteration it can store the path of the second rollnumber
        }
        printf("Number of students with A grade:%d\n", counta); //prints the number of students with each grade
        printf("Number of students with B grade:%d\n", countb);
        printf("Number of students with C grade:%d\n", countc);
        printf("Number of students with D grade:%d\n", countd);
        int j;
        j = maxthree(counta, countb, countc);
        if (j == counta)
            printf("The median grade in this course is A");
        else if (j == countb)
            printf("The median grade in this course is B");
        else if (j == countc)
            printf("The median grade is this course is C");
        printf("\n Press any KEY and then ENTER to go back");
        char proceed[50];
        scanf("%s", proceed);
        system("clear");
        co_ordinator();
    }
    else if (ch[0] == '2')
    {
        printf("Enter the subject whose marks you wish to see:");
        rolln = 20001;
        scanf("%s", subject);
        printf("\n");
        for (i = 20001; i < rolln + 20; i++)
        {
            sprintf(array3, "%d", i);
            strcat(array1, array3);
            strcat(array1, ".txt");
            FILE *fp = fopen(array1, "r");
            char strdef[10] = "MT20";
            if (strncmp(subject, "Compiler", 9) == 0 || strncmp(subject, "compiler", 9) == 0)
            {
                printf("%s   ", strcat(strdef, array3));
                fseek(fp, 166, SEEK_SET);
                char ch = fgetc(fp);
                printf("%c\n", ch);
                if (ch == 'A')
                    counta++;
                if (ch == 'B')
                    countb++;
                if (ch == 'C')
                    countc++;
                if (ch == 'D')
                    countd++;
            }
            else if (strncmp(subject, "Computer", 9) == 0 || strncmp(subject, "computer", 9) == 0)
            {
                printf("%s   ", strcat(strdef, array3));
                fseek(fp, 190, SEEK_SET);
                char ch = fgetc(fp);
                printf("%c\n", ch);
                if (ch == 'A')
                    counta++;
                if (ch == 'B')
                    countb++;
                if (ch == 'C')
                    countc++;
                if (ch == 'D')
                    countd++;
            }
            else if (strncmp(subject, "Cryptography", 13) == 0 || strncmp(subject, "cryptography", 13) == 0)
            {
                printf("%s   ", strcat(strdef, array3));
                fseek(fp, 214, SEEK_SET);
                char ch = fgetc(fp);
                printf("%c\n", ch);
                if (ch == 'A')
                    counta++;
                if (ch == 'B')
                    countb++;
                if (ch == 'C')
                    countc++;
                if (ch == 'D')
                    countd++;
            }
            else
            {
                system("clear");
                printf("INVALID SUBJECT!!!!!\n\n");
                printf("\n Press any KEY and then ENTER to go back");
                char proceed[50];
                scanf("%s", proceed);
                system("clear");
                subjectwise();
            }
            strcpy(array1, arraydup);
        }
        printf("Number of students with A grade:%d\n", counta);
        printf("Number of students with B grade:%d\n", countb);
        printf("Number of students with C grade:%d\n", countc);
        printf("Number of students with D grade:%d\n", countd);
        int j;
        j = maxthree(counta, countb, countc);
        if (j == counta)
            printf("The median grade in this course is A");
        else if (j == countb)
            printf("The median grade in this course is B");
        else if (j == countc)
            printf("The median grade is this course is C");
        printf("\n Press any KEY and then ENTER to go back");
        char proceed[50];
        scanf("%s", proceed);
        system("clear");
        co_ordinator();
    }
    else if (ch[0] == '0')
    {
        system("clear");
        co_ordinator();
    }
    else
    {
        printf("\n\nINVALID OPTION\n\n");
        printf("\n Press any KEY and then ENTER to go back");
        char proceed[50];
        scanf("%s", proceed);
        system("clear");
        subjectwise();
    }
}