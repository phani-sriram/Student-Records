// This programme will allow coordinator to add grades of a term
#include <stdio.h>
#include <string.h>
#include "grades_coordinator.h"
#include <stdlib.h>
#include "index.h"
void Term3(FILE *fp) //This function is to give spaces and print term 3
{
    int i;
    for (i = 0; i < 23; i++)
    {
        fprintf(fp, " ");
    }
    fprintf(fp, "\n");
    for (i = 0; i < 7; i++)
    {
        fprintf(fp, "_");
    }
    fprintf(fp, "Term 3");
    for (i = 0; i < 10; i++)
    {
        fprintf(fp, "_");
    }
    fprintf(fp, "\n");
}

void Blockchain(FILE *fp) //Adding Blockchain
{
    char grades;
    int i;
    fprintf(fp, "Blockchain");
    for (i = 0; i < 12; i++)
    {
        fprintf(fp, " ");
    }
    getc(stdin);
    scanf("%c", &grades);
    fprintf(fp, "%c", grades);
    fprintf(fp, "\n");
}

void IOT(FILE *fp) // Adding IOT
{
    char grades;
    int i;
    fprintf(fp, "IOT");
    for (i = 0; i < 19; i++)
    {
        fprintf(fp, " ");
    }
    getc(stdin);
    scanf("%c", &grades);
    fprintf(fp, "%c", grades);
    fprintf(fp, "\n");
}

void VLSI(FILE *fp) //Adding VLSI
{
    char grades;
    int i;
    fprintf(fp, "VLSI");
    for (i = 0; i < 18; i++)
    {
        fprintf(fp, " ");
    }
    getc(stdin);
    scanf("%c", &grades);
    fprintf(fp, "%c", grades);
    fprintf(fp, "\n");
}

void add_grades()
{
    char path[100] = "./grades/";
    char rollno[20];
    printf("Enter Roll Number: ");
    scanf("%s", rollno);
    strcat(path, rollno);
    strcat(path, ".txt"); //This is the final path
    FILE *fp;
    fp = fopen(path, "a");
    int line, col;
    FILE *Roll = fopen("roll.txt", "r");
    indexOf(Roll, rollno, &line, &col);
    if (line == 0)
    {
        printf("\nNO SUCH RECORD EXISTS\n\n");
    error:
        printf("Enter 'b' to go back or 'c' to try again\n");
        char ch[25];
        scanf("%s", ch);
        if (strlen(ch) > 1)
        {
            printf("INVALID INPUT!!!!\n\n");
            goto error;
        }
        else
        {
            if (ch[0] == 'c')
                add_grades();
            else if (ch[0] == 'b')
                co_ordinator();
            else
            {
                printf("INVALID INPUT!!!!\n\n");
                goto error;
            }
        }
    }
    else if (ftell(fp) == 216 || 215 || 214 || 217) // If Term 3 is not added, then only we can add it
    {
        Term3(fp);
        printf("Enter Blockchain grade: ");
        Blockchain(fp);
        printf("Enter VLSI grade: ");
        VLSI(fp);
        printf("Enter IOT grade: ");
        IOT(fp);
        printf("\n Press any KEY and then ENTER to go back");
        char proceed[50];
        scanf("%s", proceed);
        system("clear");
        co_ordinator();
        fclose(fp);
    }
    else
    {
        printf("\nTerm 3 is already entered\n");
        printf("\n Press any KEY and then ENTER to go back");
        char proceed[50];
        scanf("%s", proceed);
        system("clear");
        co_ordinator();
    }
}
