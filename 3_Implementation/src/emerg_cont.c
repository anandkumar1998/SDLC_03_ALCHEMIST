/**
 * @file emerg_cont.c
 * @author Shiva S
 * @brief To list all default emergency contacts using File I/O and and also add
		add any additional eemrgency contacts using .dll and .txt files
 * @version 0.1
 * @date 2021-08-22
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include "fun.h"

struct emergency_add_contact
{
	
    int id;
	char name[20],address[20];
	long long int phone_number;

} list;

struct emer_contact 
{
    int id;
    char name[20];
    int num;
};


FILE *fp, *ft, *fw, *fr;

int i,n,ch,l,found;

void emerg_cont()

{
        system("cls");

        fp=fopen("emer_contact.dll","a");

        for (;;)

        {
            printf("Enter blank space to exit\n");
			fflush(stdin);
            
			system("cls");
			
			//BLOCK CODE
			fw = fopen ("emer_contact.txt", "w");
			if (fw == NULL)
			{
				fprintf(stderr, "\nError opend file\n");
				exit (1);
			}
		  
			struct emer_contact input1 = {1, "Police", 100};
			struct emer_contact input2 = {2, "Ambulance", 102};
			struct emer_contact input3 = {3, "Fire", 101};
			struct emer_contact input4 = {4, "Disaster Response", 108};
			struct emer_contact input5 = {5, "Accident", 103};
			
			  
			// write struct to file
			fwrite (&input1, sizeof(struct emer_contact), 1, fw);
			fwrite (&input2, sizeof(struct emer_contact), 1, fw);
			fwrite (&input3, sizeof(struct emer_contact), 1, fw);
			fwrite (&input4, sizeof(struct emer_contact), 1, fw);  
			fwrite (&input5, sizeof(struct emer_contact), 1, fw);  
			
			if(fwrite != 0) 
				printf("Here are your default emergency contacts !\n");
			else 
				printf("error writing file !\n");
		  
			// close file
			fclose (fw);
			
			
			struct emer_contact input;
			
			// Open emer_contact.dat for reading
			fr = fopen ("emer_contact.txt", "r");
			if (fr == NULL)
			{
				fprintf(stderr, "\nError opening file\n");
				exit (1);
			}
			
			// read file contents till end of file
			while(fread(&input, sizeof(struct emer_contact), 1, fr))
				printf ("ID.%d || Name = %s || Contact No. = %d\n", input.id,
				input.name, input.num);

			// close file

			fclose (fr);
			//END OF BLOCK CODE
			printf("You can add any additional emergency contacts here\nTo exit press spacebar and enter");
			printf("Enter you name\n");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;

            fflush(stdin);

            printf("Emergency contact no:");

            scanf("%ld",&list.phone_number);

            fflush(stdin);

            printf("address:");

            scanf("%[^\n]",&list.address);

            fflush(stdin);
            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        

        fclose(fp);

      
        system("cls");

        printf("\n\t\t=====================================\n\t\tLIST OF Additional Emergency Contacts\n\t\t=====================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("emer_contact.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\n",list.name,

                           list.phone_number,list.address);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
}
