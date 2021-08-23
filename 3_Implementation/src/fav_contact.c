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
char query[20],name[20];
FILE *fp, *fc;
int i,n,ch1,l,found;
void fav_contact(){
printf("Do you want to add a new contact to fav or do you want to add existing contact to fav ?");
printf("[0]for new\t\t[1]existing");
printf("Enter the choice:");
scanf("%d",&ch1);

if (ch1 == 0){
        printf("For new contact: ");
        fc=fopen("fav_contacts.dll","a");
        for (;;)
        {
            fflush(stdin);
            printf("To exit enter blank space in the name input\nName (Use identical):");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("Phone:");
            scanf("%lld",&list.phone_number);
            fflush(stdin);
            printf("address:");
            scanf("%[^\n]",&list.add);
            fflush(stdin);
            printf("email address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fc);
        }
        fclose(fc);
        
        
}
else{
    search_to_add_fav();
}
        
        /* *********************Add new contacts************  */


    }

