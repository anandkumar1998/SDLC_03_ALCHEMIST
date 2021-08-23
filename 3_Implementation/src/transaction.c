#include "fun.h"

// Driver Code
void transaction()
{
    // Substitute the file_path string
    // with full path of CSV file
    FILE* fp = fopen("account.csv", "a+");

    struct transaction{
    char particulars[100];
    int  amount;
    char date[10];
    } account;
char cut='a';
int choice;
static int tempday=0, tempmonth=0;
    while (cut!='x'){
       if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
       
    }
   
    int day, month;
    char year[4];
    // Asking user input for the
    // new record to be added
    printf("\n enter Day of transaction\n");
    scanf("%d", &day);
    if(!(day>=1 && day<=31)){

        printf("Invalid input");
        break;
    }
    
    char daychar[10];
    itoa(day,daychar,10);
    strcat(daychar,"-");
   // printf("%s",daychar);
     printf("\n enter month of transaction\n");
    scanf("%d", &month);
    if ((!(month>=tempmonth))||(!(day>=1 && day<=12))){
        printf("invalid input");
        break;

    } 
    tempmonth = month;
    char monthchar[2];
    itoa(month,monthchar,10);
     strcat(daychar,monthchar);
    // printf("%s",daychar);
     strcat(daychar,"-");
    // printf("%s",daychar);
     printf("\n enter year of transaction\n");
    scanf("%s", &year);
    strcat(daychar,year);
    
    
    printf("%s",daychar);
    strcpy(account.date, daychar);   

    printf("\nEnter Particulars of transaction\n");
    scanf(" %s", &account.particulars);
    printf("\nEnter Amount\n");
    scanf("%d", &account.amount);
   printf("\n press 1 if amount is debited \n");
   printf("\n press 2 if amount is credidted \n");
  scanf("%d",&choice);
    // Saving data in file
    if(choice==1){
        int debit=account.amount;
        int credit = 0;
        fprintf(fp, "%d,%s, %s, %d, %d\n",month, account.date,
            account.particulars, debit, credit);

    }
    else if(choice == 2){
       int debit= 0;
        int credit = account.amount;
        fprintf(fp, "%d,%s, %s, %d, %d\n", month,account.date,
            account.particulars, debit, credit);

    }
    else {
        printf("invalid choice try again");
        break;
    }
    printf("\nNew Account added to record");
    printf("\npress x to exit\npress any key to continue\n");
    scanf(" %c",&cut);
    }
   
  
    fclose(fp);
    
}

