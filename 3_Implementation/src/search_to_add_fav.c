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

char query[20],name[20];
FILE *fp, *fr;
int i,n,ch,l,found;

void search_to_add_fav()
{
    fflush(stdin);
    printf("\n\n\t..::ADD AN EXISTING CONTACT TO FAVOURITES\n\t==========================\n\t..::Enter the name of contact to add to favourite:");
    scanf("%[^\n]",&name);
    fp=fopen("contact.dll","r");
    fr=fopen("fav_contacts.dll","a");
    while(fread(&list,sizeof(list),1,fp)!=0)
          if (stricmp(name,list.name)==0)
                fwrite(&list,sizeof(list),1,fr);
                
        
    fclose(fr);
    fclose(fp);
       
}
