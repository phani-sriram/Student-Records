#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "menu.h"
#include "login.h"
#include "office.h"
#include "grades_coordinator.h"
int adminpage(void)
{
   char ch[50];
   char *password = (char *)malloc(15 * sizeof(char)); //pointer to accept password
   a_display();                                        //displays administation menu
   scanf("%s", ch);
   if (strlen(ch) > 1)
   {
      printf("\n\nINVALID OPTION!!!!!!\n\n");
      adminpage();
   }
   else
   {
      char op = ch[0];
      switch (op)
      {
      case '1':
         li_display(); //faculty login menu
         break;
      case '2':
      off:
         password = getpass("Password: ");
         if (strcmp(password, "Office") == 0)
         {
            system("clear");
            office();
         }
         else
         {
            printf("\nPassword wrong");
            printf("\n1.Try Again\n2.Back\n3.Exit\nEnter your choice :");
            scanf("%s", ch);
            op = ch[0];
            switch (op)
            {
            case '1':
               goto off;
               break;
            case '2':
               system("clear");
               menu();
               break;
            case '3':
               exit(0);
               break;
            default:
               printf("INVALID OPTION!!!!\n");
               goto off;
               break;
            }
         }
         break;

      case '3':
      pass:
         password = getpass("Password: ");
         if (strcmp(password, "admin") == 0)
         {
            co_ordinator();
         }
         else
         {
            printf("\nPassword wrong");
            printf("\n1.Try Again\n2.Back\n3.Exit\nEnter your choice :");
            scanf("%s", ch);
            op = ch[0];
            switch (op)
            {
            case '1':
               goto pass;
               break;
            case '2':
               system("clear");
               menu();
               break;
            case '3':
               exit(0);
               break;
            default:
               printf("INVALID OPTION!!!!!\n\n\n");
               break;
            }
         }
         break;
      case '4':
         system("clear");
         menu();
         break;
      case '5':
         exit(0);
         break;
      default:
         printf("INVALID OPTION!!!!!\n\n\n");
         adminpage();
         break;
      }
   }
   return 0;
}