#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "index.h"
#include "menu.h"
void office()
{
    int proceed;
    char roll[30], d1[30], d2[30], ch[25];
    printf("1.Display Student profiles");
    printf("\n2.Logout");
    printf("\nEnter your choice : ");
    scanf("%s", ch);
    if (strlen(ch) > 1)
    {
        printf("\n\nINVALID OPTION!!!!!\n\n");
        office();
    }
    else
    {
        switch (ch[0])
        {
        case '1':
            printf("Enter Rollnumber : ");
            scanf("%s", roll); //Taking a input of rollnumber from user.
            FILE *Roll;
            Roll = fopen("roll.txt", "r");
            int line, col;
            char ch;
            indexOf(Roll, roll, &line, &col);
            if (line == 0)
            {
                printf("\nNO SUCH RECORD EXISTS\n\nPress any Enter to go back");
                getc(stdin);
                proceed = getchar();
                if (proceed == '\n')
                {
                    system("clear");
                    office();
                }
            }
            else
            {
                strcpy(d1, "./Personal info/"); //Copying the path of file tod1
                strcat(d1, roll);
                strcat(d1, ".txt"); //Final path of the file.
                char ch1;
                FILE *f2;
                f2 = fopen(d1, "r");
                while ((ch1 = fgetc(f2)) != EOF) //Copying the each character of file f2 to ch till EOF comes
                {
                    printf("%c", ch1); //Printing one by one by character to terminal
                }
                fclose(f2); //Closing f2
                printf("\n");
                FILE *f1;
                char ch;
                strcpy(d2, "./grades/");
                strcat(d2, roll);
                strcat(d2, ".txt"); //Defining the whole path to d2 of file f1
                f1 = fopen(d2, "r");
                while ((ch = fgetc(f1)) != EOF) //Copying the each character of file f2 to ch till EOF comes
                {
                    printf("%c", ch); //Printing one by one by character to terminal
                }
                fclose(f1); //Closing the file f1
                printf("\n\nPress Enter to go back: ");
                getc(stdin);
                proceed = getchar();
                if (proceed == '\n')
                {
                    system("clear");
                    office();
                }
            }
            break;
        case '2':
            adminpage();
            break;

        default:
            printf("\n\nINVALID OPTION!!!\n\n");
            office();
            break;
        }
    }
}