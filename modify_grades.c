// This program will allow the coordinator to modify grades of a student
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grades_coordinator.h"
void Machine(FILE *fp) // For modifying machine learning subject
{
    char grades;
    getc(stdin);
    fseek(fp, 46, SEEK_SET);
    scanf("%c", &grades);
    fprintf(fp, "%c", grades);
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    co_ordinator();
}

void Quantum(FILE *fp) // For modifying quantum computing subject
{
    char grades;
    getc(stdin);
    fseek(fp, 70, SEEK_SET);
    scanf("%c", &grades);
    fprintf(fp, "%c", grades);
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    co_ordinator();
}

void Signal(FILE *fp) // For modifying signal processing subject
{
    char grades;
    getc(stdin);
    fseek(fp, 94, SEEK_SET);
    scanf("%c", &grades);
    fprintf(fp, "%c", grades);
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    co_ordinator();
}

void Compiler(FILE *fp) // For modifying compiler design subject
{
    char grades;
    getc(stdin);
    fseek(fp, 166, SEEK_SET);
    scanf("%c", &grades);
    fprintf(fp, "%c", grades);
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    co_ordinator();
}

void Computer(FILE *fp) //For modifying Computer networks grade
{
    char grades;
    getc(stdin);
    fseek(fp, 190, SEEK_SET);
    scanf("%c", &grades);
    fprintf(fp, "%c", grades);
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    co_ordinator();
}

void Cryptography(FILE *fp) //For modifying cryptography subject
{
    char grades;
    getc(stdin);
    fseek(fp, 214, SEEK_SET);
    scanf("%c", &grades);
    fprintf(fp, "%c", grades);
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    co_ordinator();
}

void sub_menu() // This will display the subjects
{
    printf("Select the subject to modify\n");
    printf("1.Machine Learning\n");
    printf("2.Quantum Computing\n");
    printf("3.Signal Processing\n");
    printf("4.Compiler Design\n");
    printf("5.Computer Networks\n");
    printf("6.Cryptography\n");
    printf("Enter the number: ");
}

void modify_grades()
{
    char path[100] = "./grades/"; //This will give the path
    char rollno[20];              //This will store the roll no
    printf("Enter Roll Number: ");
    scanf("%s", rollno);
    strcat(path, rollno);
    strcat(path, ".txt");
    FILE *fp;
    fp = fopen(path, "r+"); // To modify the file
    if (fp == NULL)
    {
        printf("\nNO SUCH RECORD EXISTS\n\n");
    error:
        printf("Enter 'b' to go back or 'c' to try again\n");
        char ch[25];
        scanf("%s", ch);
        if (strlen(ch) > 1)
        {
            printf("\n\nINVALID INPUT!!!!\n\n");
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
                printf("\n\nINVALID INPUT!!!!\n\n");
                goto error;
            }
        }
    }
    rewind(fp); // sets the cursor to start
    sub_menu();
    char ch[50];
    scanf("%s", ch);
    if (strlen(ch) > 1)
    {
        printf("\n\nINVALID OPTION!!!!!!\n\n");
        modify_grades();
    }
    else
    {
        char op = ch[0];
        switch (op)
        {
        case '1':
            Machine(fp);
            break;
        case '2':
            Quantum(fp);
            break;
        case '3':
            Signal(fp);
            break;
        case '4':
            Compiler(fp);
            break;
        case '5':
            Computer(fp);
            break;
        case '6':
            Cryptography(fp);
            break;
        default:
            printf("INVALID OPTION !!!!");
            modify_grades();
            break;
        }
    }
}