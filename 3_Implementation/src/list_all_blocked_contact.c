#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include "fun.h"

struct contact
{
    long long int phone_number;
    char name[20],add[20],email[30];
} list;

char query[20],name[20];
FILE *fp, *ft,*bp;
int i,n,ch,l,found;

// Function#2 used within block_contact()
void list_allblocked_contact(){                   
int found;
printf("\n\t\t================================\n\t\t\tLIST OF  BLOCKED CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");
        int i= 97;
        while(i<=122)
        {
            fp=fopen("blocked.dll","r");
            fflush(stdin);
            found=0;
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.name[0]==i || list.name[0]==i-32)
                {
                    printf("\nName\t: %s\nPhone\t: %lld\nAddress\t: %s\nEmail\t: %s\n",list.name,
                          list.phone_number,list.add,list.email);
                    found++;
                }
            }
            if(found!=0)
            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
                getch();
            }
            fclose(fp);
            i++;
        }
}