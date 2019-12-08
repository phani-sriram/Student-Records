#include<stdio.h>
#include<string.h>
#include"sub.h"
#include<stdlib.h>
void ABCgrade(int he,char o,char per[],char str[],char txt[],char buff1[],char buff2[],char gra[])
{
  FILE *fp;
  FILE *fp1;
  int x;
  char ch;

  printf("\n    STUDENTS :\n");

  for (x = 1; x < 20; x++)
    {
      char s[20] = " ";


      snprintf (buff2, 200, "%s%s%02d%s", gra, str, x, txt);

      fp1 = fopen (buff2, "r");
      fseek (fp1, 46+23*he, SEEK_SET);

      while (1)
	{
	  ch = fgetc (fp1);

	  if (ch == EOF)
	    {
	      break;
	    }
	  if (ch == '\n')
	    {
	      break;
	    }
	  if (ch == o)
	    {
	      printf ("\n");
	      snprintf (buff1, 200, "%s%s%02d%s", per, str, x, txt);

	      fp = fopen (buff1, "r");
	      fseek (fp, 63, SEEK_SET);

	      while (1)
		{
		  ch = fgetc (fp);

		  if (ch == EOF)
		    {
		      break;
		    }
		  if (ch == '\n')
		    {
		      break;
		    }
		  strncat (s, &ch, 1);
		}
	      printf ("%20s", s);

	      fclose (fp);

	      printf ("\t");
	    }
	}
      fclose (fp1);
    }
  printf ("\n");
}

//________________________________________________________________________________________________________________________________________________________________
void calc_avg(int he,char per[],char str[],char txt[],char buff1[],char buff2[],char gra[])
{
	FILE * fp;
        FILE * fp1;
        int x;
	char ch;
        int count=0;

        for(x=1;x<20;x++){

        snprintf(buff2,200,"%s%s%02d%s",gra,str,x,txt);

        fp1=fopen(buff2,"r");
	fseek(fp1,46+23*he,SEEK_SET);
	
	while(1){
            ch=fgetc(fp1);

            if(ch==EOF){
                break;
            }
            if(ch=='\n'){
                break;
            }
            
	    if(ch=='A'){
                count+=100;
            }
            if(ch=='B'){
                count+=80;
            }
            if(ch=='C'){
                count+=60;
            }
            if(ch=='D'){
                count+=40;
            }
            if(ch=='E'){
                count+=20;
            }
            if(ch=='F'){
                count+=0;
            }
	}
	fclose(fp1);
        }
        if((count/20)==100||(count/20)>=90){
        printf("Average Grade Is A");
        }
        if((count/20)>=80&&(count/20)<90){
        printf("Average Grade Is B");
        }
        if((count/20)>=70&&(count/20)<80){
        printf("Average Grade Is B");
        }
        if((count/20)>=60&&(count/20)<70){
        printf("Average Grade Is C");
        }
        if((count/20)>=50&&(count/20)<60){
        printf("Average Grade Is C");
        }
        
        if((count/20)>=40&&(count/20)<50){
        printf("Average Grade Is D");
        }
        if((count/20)>=20&&(count/20)<30){
        printf("Average Grade Is E");
        }
        printf("\n");
}
//________________________________________________________________________________________________________________________________________________________________
void gen_marks(int he,char per[],char str[],char txt[],char buff1[],char buff2[],char gra[])
{
	FILE * fp;
    FILE * fp1;
    int x;
	char ch;
    for(x=1;x<20;x++)
    {
        char s[20]=" ";
        printf("\n");
        snprintf(buff1,200,"%s%s%02d%s",per,str,x,txt);
	fp=fopen(buff1,"r");
	fseek(fp,63,SEEK_SET);	
	while(1)
    {
        ch=fgetc(fp);
        if(ch==EOF)
        {
            break;
        }
        if(ch=='\n')
        {
            break;
        }
        strncat(s,&ch,1);
	}
    printf("%20s",s);   
	fclose(fp);       
    printf("\t\t");
    snprintf(buff2,200,"%s%s%02d%s",gra,str,x,txt);

    fp1=fopen(buff2,"r");
	fseek(fp1,46+23*he,SEEK_SET);
	
	while(1)
    {
        ch=fgetc(fp1);
        if(ch==EOF)
        {
            break;
        }
        if(ch=='\n')
        {
            break;
        }            
	    printf("%c",ch);        
	}
	fclose(fp1);
}
    printf("\n");
}