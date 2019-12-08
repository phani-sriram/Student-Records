#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sub.h"
#include "menu.h"
#include "login.h"
int networks(void)
{
  char str[100] = "MT20200";
  char buff1[200];
  char buff2[200];
  char txt[60] = ".txt";
  char per[200] = "Personal info/";
  char gra[200] = "grades/";
  char operation[25];
  char ch;
  printf("|\t\t\t\t\t\t------  COMPUTER NETWORKS FACULTY  LOGIN  ------\n\n");
  fac_display();
  scanf("%s", operation);
  if (strlen(operation) == 1)
  {
    if (operation[0] == '1')
    {
      gen_marks(6, per, str, txt, buff1, buff2, gra);
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        networks();
      }
    }
    else if (operation[0] == '2')
    {
      calc_avg(6, per, str, txt, buff1, buff2, gra);
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        networks();
      }
    }

    else if (operation[0] == '3')
    {
      ABCgrade(6, 'A', per, str, txt, buff1, buff2, gra);
      printf("\n\n");
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        networks();
      }
    }
    else if (operation[0] == '4')
    {
      ABCgrade(6, 'B', per, str, txt, buff1, buff2, gra);
      printf("\n\n");
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        networks();
      }
    }
    else if (operation[0] == '5')
    {
      ABCgrade(6, 'C', per, str, txt, buff1, buff2, gra);
      printf("\n\n");
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        networks();
      }
    }
    else if (operation[0] == '6')
    {
      ABCgrade(6, 'D', per, str, txt, buff1, buff2, gra);
      printf("\n\n");
      getc(stdin);
      printf("Press Enter to go back:");
      ch = getchar();
      if (ch == '\n')
      {
        system("clear");
        networks();
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
      networks();
    }
  }
  else
  {
    system("clear");
    printf("INVALID INPUT\n");
    crypto();
  }
  return 0;
}
