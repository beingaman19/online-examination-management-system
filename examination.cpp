#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct question
{
	int qid;
	char cat[30],ques[100],opta[100],optb[100],optc[100],optd[100],cans[100];
}q;
struct student
{
      int roll;
      char nm[100],clg[100],pwd[100];
}s;
struct grade
{
    int roll;
    float marks;
}g;
void startexam(int roll1)
{
     FILE *fp1,*fp2;
     int i=1;
     char uans[100];
     fp1=fopen("satexam.dat","r");
     fp2=fopen("satresult.dat","a");
     g.marks=0;
     g.roll=roll1;
     while(fread(&q,sizeof(q),1,fp1))
     {
	 clrscr();
	 printf("%d)%s\n%s\n%s\n%s\n%s",i,q.ques,q.opta,q.optb,q.optc,q.optd);
	 printf("\nType Correct ans:");
	 fflush(stdin);
	 gets(uans);
	 if(strcmp(uans,q.cans)==0)
	 {
	   printf("\n Answer is correct");
	 g.marks++;
	 }
	 else
	   {
	       printf("\nWrong answer:");
	       g.marks=g.marks-.5;
	   }
	 printf("\n\nYour Score is: %f",g.marks);
	 printf("\n press enter for new qurestion:");
	 getch();
	 i++;
     }
     fwrite(&g,sizeof(g),1,fp2);
     fclose(fp1);
     fclose(fp2);
}





void stulogin()
{
     int roll1,f=0;
     char pwd1[100];
     FILE *fp;
     printf("\n Enter roll:");
     scanf("%d",&roll1);
     printf("\nEnter password:");
     fflush(stdin);
     gets(pwd1);
     fp=fopen("satstu.dat","r");
     while(fread(&s,sizeof(s),1,fp))
     {
	    if(s.roll==roll1 && strcmp(pwd1,s.pwd)==0)
	     {
		 f=1;
		 break;
	     }
     }
     if(f==1)
     {
	  printf("\nWelcome %s",s.nm);
	  printf("\n Press enter to start exam");
	  getch();
	  startexam(roll1);
     }
     else
     {
	  printf("\nInvalid User");

      }
}
void stureg()
{
	FILE *fp;
	fp=fopen("satstu.dat","a");
	printf("\nEnter roll:");
	fflush(stdin);
	scanf("%d",&s.roll);
	printf("\nEnter Name:");
	fflush(stdin);
	gets(s.nm);
	printf("\nEnter College:");
	fflush(stdin);
	gets(s.clg);
	printf("\nEnter password:");
	gets(s.pwd);
	fwrite(&s,sizeof(s),1,fp);
	printf("Registration successfully");
	fclose(fp);

}
void stumenu()
{
      int ch;
      while(1)
      {
	  printf("\n1 for registration\n 2 for login\n 3 for exit");
	  printf("\nEnter your choice");
	  fflush(stdin);
	  scanf("%d",&ch);
	  switch(ch)
	  {
	      case 1:
			stureg();
			break;
	      case 2:
			stulogin();
			break;
	      case 3:
		      exit(0);
	  }
      }
}

void modifyques()
{
    int qid1;
    FILE *fp1,*fp2;
    fp1=fopen("satexam.dat","r");
    fp2=fopen("satexam1.dat","w");
    printf("Enter qid to modify:");
    fflush(stdin);
    scanf("%d",&qid1);
    while(fread(&q,sizeof(q),1,fp1))
    {
       if(q.qid==qid1)
       {
	  printf("\nEnter new cat:");
	  fflush(stdin);
	  gets(q.cat);
	  printf("\nEnter new ques:");
	  fflush(stdin);
	  gets(q.ques);
	  printf("\nEnter new opta:");
	  fflush(stdin);
	  gets(q.opta);
	  printf("\nEnter new optb:");
	  fflush(stdin);
	  gets(q.optb);
	  printf("\nEnter new opt c:");
	  fflush(stdin);
	  gets(q.optc);
	  printf("\nEnter new optd:");
	  fflush(stdin);
	  gets(q.optd);
	  printf("\nEnter cans:");
	  fflush(stdin);
	  gets(q.cans);
       }
       fwrite(&q,sizeof(q),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    remove("satexam.dat");
    rename("satexam1.dat","satexam.dat");
    printf("\nModified successfully");
}


void delques()
{
    int qid1;
    FILE *fp1,*fp2;
    fp1=fopen("satexam.dat","r");
    fp2=fopen("satexam1.dat","w");
    printf("Enter question id to delete:");
    fflush(stdin);
    scanf("%d",&qid1);
    while(fread(&q,sizeof(q),1,fp1))
    {
	if(q.qid!=qid1)
	fwrite(&q,sizeof(q),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    remove("satexam.dat");
    rename("satexam1.dat","satexam.dat");
    printf("\nDeleteed successfully");
}
void displayques()
{
    FILE *fp;
    fp=fopen("satexam.dat","r");
    while(fread(&q,sizeof(q),1,fp))
    {
      printf("\n%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s",q.qid,q.cat,q.ques,q.opta,q.optb,q.optc,q.optd,q.cans);
    }
}
void insertques()
{
      FILE *fp;
      fp=fopen("satexam.dat","a");
      printf("\nEnter qid:");
      fflush(stdin);
      scanf("%d",&q.qid);
      printf("\nEnter category:");
      fflush(stdin);
      gets(q.cat);
      printf("\nEnter question:");
      fflush(stdin);
      gets(q.ques);
      printf("\nEnter option A:");
      fflush(stdin);
      gets(q.opta);
      printf("\nEnter optb:");
      fflush(stdin);
      gets(q.optb);
      printf("\nEnter optc:");
      fflush(stdin);
      gets(q.optc);
      printf("\nEnter optd:");
      fflush(stdin);
      gets(q.optd);
      printf("\nEnter cans:");
      fflush(stdin);
      gets(q.cans);
      fwrite(&q,sizeof(q),1,fp);
      printf("\nQuestion inserted successfully");
      fclose(fp);
}

void adminmenu()
{
	int ch;
	while(1)
	{
	   printf("\n1 for insert new question\n 2 for display all question");
	   printf("\n3 for delete question\n 4 for modify question");
	   printf("\n 5 for view student marks\n 6 for exit");
	   printf("\n Enter your choice:");
	   fflush(stdin);
	   scanf("%d",&ch);
	   switch(ch)
	   {
		case 1:
			insertques();
			break;
		case 2:
			displayques();
			break;
		case 3:
			 delques();
			 break;
		case 4:
			modifyques();
			break;
		case 5:
		case 6:exit(0);
	   }
      }
}
void admin()
{
    char uname[30],pwd[30];
    int i=0;
    printf("Enter Userid:");
    fflush(stdin);
    gets(uname);
    printf("Enter password:");
    do{
       pwd[i]=getch();
       if(pwd[i]==13)
       break;
       printf("*");
       i++;
    }while(pwd[i]!=13);
   pwd[i]=NULL;
   if(strcmp(uname,"sweety")==0 && strcmp(pwd,"rohit")==0)
   {
	printf("\nWelcome sweety:");
	adminmenu();
   }
   else
   {
      printf("\nInvalid userid or paassword:");
   }
}


void main()
{
    int ch;
    clrscr();
    while(1)
    {
       printf("\n.............EXAMINATION SYSTEM ............");
       printf("\n1 for admin \n 2 for user\n 3 for exit");
       printf("\nEnter your choice");
       scanf("%d",&ch);
       switch(ch)
       {
	case 1:
		admin();
		break;
	case 2:
		 stumenu();
		 break;
	case 3:exit(0);
       }
    }
}
