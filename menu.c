#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
int menu(void)
{
   char ch[50];
   printf("\t\t---------------------------------\n");
   printf("\t\t|\tSTUDENT RECORDS\t\t|\n");
   printf("\t\t|\t1.Student\t\t|\n");
   printf("\t\t|\t2.Administration\t|\n");
   printf("\t\t|\t3.Exit\t\t\t|\n");
   printf("\t\t---------------------------------\n");
   printf("\t\tEnter your choice: ");
   scanf("%s", ch);
   if (strlen(ch) > 1)
   {
      printf("\n\nINVALID OPTION!!!!!!\n\n");
      menu();
   }
   else
   {
      char op = ch[0];
      switch (op)
      {
      case '1':
         system("clear");
         loginpage();
         break;
      case '2':
         system("clear");
         adminpage();
         break;
      case '3':
         exit(0);
      default:
         printf("\n\nINVALID OPTION!!!!!\n");
         menu();
         break;
      }
   }
   return 0;
}