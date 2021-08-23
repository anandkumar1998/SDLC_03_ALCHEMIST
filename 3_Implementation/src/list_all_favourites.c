#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<direct.h>
#include<conio.h>
#include "fun.h"
struct contact
{
    long long int phone_number;
    char name[20],add[20],email[30];
} list;
FILE *fr;
void list_all_favourites(){
int found;
printf("\n\t\t================================\n\t\t\tLIST OF FAVOURITE CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");
        int i= 97;
        while(i<=122)
        {
            fr=fopen("fav_contacts.dll","r");
            fflush(stdin);
            found=0;
            while(fread(&list,sizeof(list),1,fr)==1)
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
            fclose(fr);
            i++;
        }
}
