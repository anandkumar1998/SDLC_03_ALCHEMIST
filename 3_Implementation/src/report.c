#include "fun.h"
  
// Driver Code
void report()
{
    int flag=0;
    // Substitute the full file path
    // for the string file_path
    FILE* fp = fopen("account.csv", "r");
  
    if (!fp)
        printf("Can't open file\n");
  
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
        int month = 0, credit=0, debit =0;
        printf("enter month:\t");
        scanf("%d",&month);
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ", ");
  
            while (value) {
                // Column 1
                if (column == 0) {

                   
                    if(atoi(value)==month){
                         printf("month:");
                        flag = 1;
                        printf("%s", value);
                    }
         
                }
  
                // Column 2
                if (column == 2) {
                    if(flag==1){
                    printf("\tparticular :");
                    printf("%s", value);
                    }
                }
  
                // Column 3
                if (column == 3) {
                   
                    if(flag==1){
                         printf("\tdebit :");
                    printf("%s", value);
                         debit = debit + atoi(value);
                         
                        
                    }
                }

                 if (column == 4) {
                    
                     if(flag==1){
                         printf("\tcredit :");
                    printf("%s", value);
                        credit = credit + atoi(value);
                        flag=0;
                    }
                }
  
                
                value = strtok(NULL, ", ");
                
                column++;
            }
            
  
            //printf("\n");
        }
        printf("total debit of the month = %d and total credit of the month = %d",debit,credit);
  
        // Close the file
        fclose(fp);
    }
    
}