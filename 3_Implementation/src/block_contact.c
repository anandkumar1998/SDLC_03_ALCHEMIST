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

// Main function, which is executed, when the user wants to block
void block_contact(){
	contact_to_block();
    bp=fopen("blocked.dll","a");                        
	fwrite(&list,sizeof(list),1,bp);
	fclose(bp);
	list_allblocked_contact();

    }
