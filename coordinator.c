#include<stdio.h>
#include"grades_coordinator.h"
#include<stdlib.h>
#include<string.h>
#include"menu.h"
int co_ordinator()
{
   co_menu();
   char ch1[50];
   scanf("%s",ch1);
   if (strlen(ch1) > 1)
   {
      system("clear");
      printf("\n\nINVALID OPTION!!!!!!\n\n");   
      co_ordinator();
   }
   else
   {
      char op = ch1[0];
      switch (op)
      {
      case '1':
         system("clear");
         add_grades();
         break;
      case '2':
         display();
         break;
      case '3':
         system("clear");
         modify_grades();
         break;
      case '4':
         system("clear");
         subjectwise();
         break;
      case '5':
         system("clear");
         adminpage();
         break;
      case '6':
         exit(0);
         break;
      default:
         printf("INVALID OPTION!!!!!\n\n\n");
         co_ordinator();
         break;
      }
   }
}               