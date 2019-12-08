#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "login.h"
#include <string.h>
int li_display() /*Screen to be displayed once the student has logged in*/
{
   printf("\t\t----------------------------\n");
   printf("\t\t|\t1.Login\t\t|\n");
   printf("\t\t|\t2.Back\t\t|\n");
   printf("\t\t|\t3.Exit\t\t|\n");
   printf("\t\t----------------------------\n");
   printf("\t\tEnter your choice: ");
   char ch1[50];
   scanf("%s", ch1);
   if (strlen(ch1) > 1)
   {
      system("clear");
      printf("\n\nINVALID OPTION!!!!!!\n\n");
      li_display();
   }
   else
   {
      char op = ch1[0];
      switch (op)
      {
      case '1':
         facultylogin();
         break;
      case '2':
         system("clear");
         menu();
         break;
      case '3':
         exit(0);
         break;
      }
   }
   return 0;
}
int a_display()
{
   printf("\t\t---------------------------------\n");
   printf("\t\t|\t1.Faculty\t\t|\n");
   printf("\t\t|\t2.Office\t\t|\n");
   printf("\t\t|\t3.Co-ordinator\t\t|\n");
   printf("\t\t|\t4.Back\t\t\t|\n");
   printf("\t\t|\t5.Exit\t\t\t|\n");
   printf("\t\t---------------------------------\n");
   printf("\t\tEnter your choice: ");
}
int co_menu()
{
   printf("\t\t-----------------------------------------\n");
   printf("\t\t|\t1.Add Grades\t\t\t|\t\n");
   printf("\t\t|\t2.Display Grades\t\t|\n");
   printf("\t\t|\t3.Modify Grades\t\t\t|\n");
   printf("\t\t|\t4.Display Grades Subjectwise\t|\n");
   printf("\t\t|\t5.Logout\t\t\t|\n");
   printf("\t\t|\t6.Exit\t\t\t\t|\n");
   printf("\t\t-----------------------------------------\n");
   printf("\t\tEnter your choice: ");
}
int display_terms()
{
   system("clear");
   printf("1.Term 1\n2.Term 2\n3.Back\n4.Exit\n\nEnter your choice");
}
int fac_display(void)
{
   printf("\t\t1. Generate Subject Marksheet\n\n");
   printf("\t\t2. Average Grade\n\n");
   printf("\t\t3. Display A Graders\n\n");
   printf("\t\t4. Display B Graders\n\n");
   printf("\t\t5. Display C Graders\n\n");
   printf("\t\t6. Display D Graders\n\n");
   printf("\t\t7. Back\n\n");
   printf("\t\t Please Select The Operation To Be Performed : \n\n");
}