#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "login.h"
#include <string.h>
int loginpage(void)
{
   char ch[50];
   printf("\t\t      STUDENT LOGIN\n");
   printf("\t\t-------------------------\n");
   printf("\t\t|\t1.Login\t\t|\n");
   printf("\t\t|\t2.Back\t\t|\n");
   printf("\t\t|\t3.Exit\t\t|\n");
   printf("\t\t-------------------------\n");
   printf("\t\tEnter your choice: ");
   scanf("%s", ch);
   if (strlen(ch) > 1)
   {
      printf("\n\nINVALID OPTION!!!!!!\n\n");
      loginpage();
   }
   else
   {
      char op = ch[0];
      switch (op)
      {
      case '1':
         login();
         break;
      case '2':
         system("clear");
         menu();
         break;
      case '3':
         exit(0);
         break;
      default:
         printf("\n\nINVALID OPTION!!!!!!\n\n");
         loginpage();
         break;
      }
   }
   return 0;
}