#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sub.h"
#include "menu.h"
#include "login.h"
int quantum(void)
{
  char str[100] = "MT20200";
  char buff1[200];
  char buff2[200];
  char txt[60] = ".txt";
  char per[200] = "Personal info/";
  char gra[200] = "grades/";
  char ch, operation[25];
  printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
  printf("|\t\t\t\t\t\t------  QUANTUM COMPUTING FACULTY  LOGIN  ------\n\n");
  fac_display();
  scanf("%s", operation);
  if (strlen(operation) == 1)
  {
    if (operation[0] == '1')
    {
      gen_marks(1, per, str, txt, buff1, buff2, gra);
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        quantum();
      }
    }
    else if (operation[0] == '2')
    {
      calc_avg(1, per, str, txt, buff1, buff2, gra);
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        quantum();
      }
    }

    else if (operation[0] == '3')
    {
      ABCgrade(1, 'A', per, str, txt, buff1, buff2, gra);
      printf("\n\n");
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        quantum();
      }
    }
    else if (operation[0] == '4')
    {
      ABCgrade(1, 'B', per, str, txt, buff1, buff2, gra);
      printf("\n\n");
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        quantum();
      }
    }
    else if (operation[0] == '5')
    {
      ABCgrade(1, 'C', per, str, txt, buff1, buff2, gra);
      printf("\n\n");
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        quantum();
      }
    }
    else if (operation[0] == '6')
    {
      ABCgrade(1, 'D', per, str, txt, buff1, buff2, gra);
      printf("\n\n");
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        quantum();
      }
    }
    else if (operation[0] == '7')
    {
      li_display();
      printf("\n");
    }
    else
    {
      system("clear");
      printf("INVALID INPUT\n");
      quantum();
    }
  }
  else
  {
    system("clear");
    printf("INVALID INPUT\n");
    quantum();
  }
  return 0;
}
