#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include"menu.h"
#include"index.h"
#include"sub.h"
#define BUFFER_SIZE 10   // size of string
int facultylogin()
{
   char roll[BUFFER_SIZE],c[BUFFER_SIZE];  //roll is a string to input roll no.
   char *pass = (char*)malloc(BUFFER_SIZE*sizeof(char));
   /*count is a counter variable to the line atb which the correspondingpassword of 
   student is stored*/ 
   int count = 0;
   int ch; /*variable to take the users choice*/

   // Id is a pointer to roll.txt ,passw a pointer to passwords.txt
   FILE *Id,*passw;
   Id = fopen("facultyid.txt","r");
   passw =fopen("fac_pass.txt","r");
   printf("ID: ");
   scanf("%s",roll);
   int line ,col;

   //index of finds the line of first occurence of the string
   indexOf(Id,roll,&line,&col);

   //traverse to the corresponding line in passwords.txt
   while ((fgets(c, BUFFER_SIZE, passw)) != NULL)
   {
      count++;
      if(count == line)
         break;
   }   
   //accept password and check if its right   
   pass = getpass("Password: ");
   if((strcmp(roll,pass) == 0) && line != 0)
   {//login if the password is right
         if(strcmp(roll,"Mlearning")==0)
         {
            system("clear");
            ml();
         }  
         else if(strcmp(roll,"ComilerDsgn")==0)
         {
            system("clear");
            compiler();
         }  
         else if(strcmp(roll,"Crypto")==0)
         {
            system("clear");
            crypto();
         }  
         else if(strcmp(roll,"Signal")==0)
         {
            system("clear");
            signal();
         }
         else if(strcmp(roll,"Networks")==0)
         {
            system("clear");
            networks();
         } 
         else if(strcmp(roll,"QuantumComp")==0)
         {
            system("clear");
            quantum();
         } 
      }
      //else diplay the options the user has left
   else 
   {
      printf("\nPassword or Username wrong");
      printf("\n1.Try Again\n2.Back\n3.Exit\nEnter your choice :");
      scanf("%d",&ch);
      switch (ch)
      {
      case 1:
         facultylogin();
         break;
      case 2:         
         adminpage();
         break;
      case 3:
         exit(0);
         break;      
      default:
         break;
      }
   }
   fclose(Id);
   fclose(passw);        
   return 0;
}