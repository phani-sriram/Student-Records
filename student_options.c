#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_options.h"
#include "menu.h"

//_______________________________________________________________________________________________

void student_options()
{
    printf("Choose the action\n");
    printf("\n1.Display Personal Information\n\n");
    printf("2.Display term 1 Grades\n\n");
    printf("3.Display Term 2 Grades\n\n");
    printf("4.Display Term 3 Grades\n\n");
    printf("5.Seperate the courses based on the grade and Display them\n\n");
    printf("6.Display the Courses\n\n");
    printf("7.Logout\n\n");
    printf("Your choice ");
}

//________________________________________________________________________________________________

void student(char RollNumber[])
{
    student_options();
    char ch[50];
    scanf("%s", ch);
    if (strlen(ch) > 1)
    {
        printf("\n\nINVALID OPTION!!!!!!\n\n");
        student(RollNumber);
    }
    else
    {
        system("clear");
        char op = ch[0];
        switch (op)
        {
        case '1':
            personal(RollNumber);
            break;
        case '2':
            term1(RollNumber);
            break;
        case '3':
            term2(RollNumber);
            break;
        case '4':
            term3(RollNumber);
            break;
        case '5':
            seperate_courses(RollNumber);
            break;
        case '6':
            term_courses(RollNumber);
            break;
        case '7':
            logout(RollNumber);
            break;
        default:
            printf("INVALID INPUT\n");
            student(RollNumber);
            break;
        }
    }
}

//________________________________________________________________________________________________

void logout(char RollNumber[])
{
    loginpage();
}

//________________________________________________________________________________________________

void term1(char RollNumber[])
{
    char path[50] = "./grades/", c;

    strcat(path, RollNumber);
    strcat(path, ".txt");

    FILE *term1 = fopen(path, "r");
    fseek(term1, 0, SEEK_SET);
    printf("\n");

    for (int i = 1; i <= 24 * 4; i++)
    {
        c = fgetc(term1);
        printf("%c", c);
    }
    fclose(term1);
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    student(RollNumber);
    system("clear");
}
//_____________________________________________________________________________________________

void term2(char RollNumber[])
{
    char path[50] = "./grades/", c;

    strcat(path, RollNumber);
    strcat(path, ".txt");

    FILE *term2 = fopen(path, "r");
    printf("\n");

    fseek(term2, 5 * 24, SEEK_SET);
    for (int i = 1; i <= 24 * 4 - 1; i++)
    {
        c = fgetc(term2);
        printf("%c", c);
    }
    fclose(term2);

    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    student(RollNumber);
    system("clear");
}
//___________________________________________________

void personal(char RollNumber[])
{
    char path[50] = "./Personal info/", c;
    strcat(path, RollNumber);
    strcat(path, ".txt");

    FILE *pinfo = fopen(path, "r+");
    printf("\n");

    while ((c = fgetc(pinfo)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    fclose(pinfo);
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    student(RollNumber);
}

//____________________________________________________________________________________________

void seperate_courses(char RollNumber[])
{
    int flag = 0;
    char path[50] = "./grades/", grades[5] = " ABCD", *option, c;
    printf("\n1.A\n2.B\n3.C\n4.D\n5.Back\nEnter the grade you want from above ");
    option = (char *)malloc(25 * sizeof(char));
    scanf("%s", option);
    printf("\n");

    strcat(path, RollNumber);
    strcat(path, ".txt");

    FILE *f = fopen(path, "r");
    if (strlen(option) == 1)
    {
        if (option[0] == '5')
        {
            system("clear");
            student(RollNumber);
        }

        else
        {
            int opt = atoi(option);
            for (int i = 0; i < 9; i++)
            {
                fseek(f, 22 + i * 24, SEEK_SET);
                c = fgetc(f);
                if (c == grades[opt])
                {
                    flag = 1;
                    fseek(f, i * 24, SEEK_SET);
                    for (int j = 0; j < 22; j++)
                    {
                        c = fgetc(f);
                        printf("%c", c);
                    }
                    printf("\n");
                }
            }
        }
    }
    else
    {
        printf("INVALID OPTION");
        seperate_courses(RollNumber);
    }

    if (flag == 0)
    {
        printf("NO SUCH COURSE");
    }
    printf("\n Press any KEY and then ENTER to go back");
    char proceed[50];
    scanf("%s", proceed);
    system("clear");
    seperate_courses(RollNumber);
}

//__________________________________________________________________________

void term_courses(char RollNumber[])
{
    char path[35] = "./grades/", c, *options;
    options = (char *)malloc(25 * sizeof(char));

    strcat(path, RollNumber);
    strcat(path, ".txt");

    printf("\n1.Term 1\n2.Term 2\n3.Term 3\n4.Back\nChoose the action ");
    scanf("%s", options);
    printf("\n");

    FILE *f = fopen(path, "r");
    if (strlen(options) == 1)
    {
        if (options[0] == '1')
        {
            for (int i = 1; i < 4; i++)
            {
                fseek(f, 24 * i, SEEK_SET);
                for (int j = 1; j < 23; j++)
                {
                    c = fgetc(f);
                    printf("%c", c);
                }
                printf("\n");
            }
            printf("\n Press any KEY and then ENTER to go back");
            char proceed[50];
            scanf("%s", proceed);
            system("clear");
            term_courses(RollNumber);
        }
        if (options[0] == '2')
        {
            for (int i = 1; i < 4; i++)
            {
                fseek(f, 24 * i + 24 * 5, SEEK_SET);
                for (int j = 1; j < 23; j++)
                {
                    c = fgetc(f);
                    printf("%c", c);
                }
                printf("\n");
            }
            printf("\n Press any KEY and then ENTER to go back");
            char proceed[50];
            scanf("%s", proceed);
            system("clear");
            term_courses(RollNumber);
        }
        if (options[0] == '3')
        {
            fseek(f, 10 * 24, SEEK_SET);
            printf("BlockChain\nVLSI\nIOT");
            printf("\n Press any KEY and then ENTER to go back");
            char proceed[50];
            scanf("%s", proceed);
            system("clear");
            term_courses(RollNumber);
        }
        if (options[0] == '4')
        {
            system("clear");
            student(RollNumber);
        }
    }
    else
    {
        printf("INVALID OPTION\n");
        term_courses(RollNumber);
    }
}
//__________________________________________________________________________________

void term3(char RollNumber[])
{
    char proceed[50], path[30] = "./grades/", c;
    strcat(path, RollNumber);
    strcat(path, ".txt");

    FILE *term3 = fopen(path, "r");
    fseek(term3, 0, SEEK_END);

    if (ftell(term3) <= 216)
    {
        printf("Not Yet Graded\n");
    }

    else
    {
        fseek(term3, 10 * 24, SEEK_SET);
        while ((c = fgetc(term3)) != EOF)
        {
            printf("%c", c);
        }
    }
    printf("\n Press any KEY and then ENTER to go back");
    scanf("%s", proceed);
    system("clear");
    student(RollNumber);
}