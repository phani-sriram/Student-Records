#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"
#include "index.h"
#include "student_options.h"
#define BUFFER_SIZE 10 // size of string
int login()
{
   char roll[BUFFER_SIZE], c[BUFFER_SIZE]; //roll is a string to input roll no.
   char *pass = (char *)malloc(BUFFER_SIZE * sizeof(char));
   /*count is a counter variable to the line atb which the correspondingpassword of 
   student is stored*/
   int count = 0;
   char ch[50]; /*variable to take the users choice*/

   // add is a pointer to roll.txt ,passw a pointer to passwords.txt
   FILE *add, *passw;
   add = fopen("roll.txt", "r");
   passw = fopen("passwords.txt", "r");
   printf("Roll Number: ");
   scanf("%s", roll);
   int line, col;

   //index of finds the line of first occurence of the string
   indexOf(add, roll, &line, &col);

   //traverse to the corresponding line in passwords.txt
   while ((fgets(c, BUFFER_SIZE, passw)) != NULL)
   {
      count++;
      if (count == line)
         break;
   }
   //accept password and check if its right
   pass = getpass("Password: ");
   if ((strcmp(c, pass) == 0) && line != 0 && strlen(roll) == 9)
      student(roll); //login if the password is right

   //else diplay the options the user has left
   else
   {
      printf("\nPassword or Username wrong");
      printf("\n1.Try Again\n2.Back\n3.Exit\nEnter your choice :");
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
            loginpage();
            break;
         case '3':
            exit(0);
            break;
         default:
            break;
         }
      }
   }
   fclose(add);
   fclose(passw);
   return 0;
}
