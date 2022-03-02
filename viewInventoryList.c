#include <stdio.h>
#include <string.h>
char userChoice[2];
FILE *inventoryFile;
int size;
void nullChecker();
void viewList();

typedef struct items{
    char ID[10];
    char description[50];
    char quantity[10];
    char expDate[20];
    char prices[10];
}items;

char main(){
    nullChecker();

    if(size == 0){
        printf("Inventory is empty...\n\n");
        printf("Exit or go back to main menu? (X -- Exit or M -- Main Menu)\n");
        printf("Please input choice: ");
        userChoice[1]=1;

        while(userChoice[1]==1){
            scanf(" %1c",&userChoice[0]);
            switch(userChoice[0]){
                case 'm':
                case 'M':
                    userChoice[1]=0;
                    printf("main menu");
                    break;
                case 'X':
                case 'x':
                    userChoice[1]=0;
                    printf("Thank you for using our inventory management system");
                    break;
                default:
                    printf("Invalid Input, please try again: ");
                    userChoice[1]=1;
            }
        }
    }else{
        inventoryFile = fopen("./Data/inventory.csv", "r");
        char row = 0;
        char column = 0;
        char i = 0;
        char buffer[256];
        items num[999];
        while (fgets(buffer, 1024, inventoryFile)) {
            column = 0;
            row++;
          
            char* value = strtok(buffer, ",\"\"");
            while (value) {
                // ID
                if (column == 0){
                    strcpy(num[i].ID, value);
                }
                // Description
                if (column == 1) {
                   // printf("\t");
                    strcpy(num[i].description, value);
                }
                // Quantity
                if (column == 2) {
                  // printf("\t\t\t");
                   strcpy(num[i].quantity, value);
                }
                // Exp. Date
                if (column == 3) {
                   // printf("\t\t");
                    strcpy(num[i].expDate, value);
                }
                // Prices
                if (column == 4) {
                    //printf("\t\t");
                    strcpy(num[i].prices, value);
                }
                //printf("%s", value);
                value = strtok(NULL, ",\"\"");
                column++;
               
            }
            i++;
        }
        fclose(inventoryFile);
        viewList(num);
   // printf("ID\tDescription\t\t\t\tQuantity\tExp. Date\tPrices(PHP)\n\n");
        return 0;
    }
}
    
void viewList(items num[]){
    printf("ID\tDescription\t\t\t\tQuantity\tExp. Date\tPrices(PHP)\n\n");

    for (int i= 0; i<5; i++){
        printf("%s\t%s\t\t\t\t%s\t%s\t%s\n", num[i].ID, num[i].description, num[i].quantity, num[i].expDate, num[i].prices);
    }
}

void nullChecker(){
    inventoryFile = fopen("./Data/inventory.csv", "r");

    fseek(inventoryFile, 0, SEEK_END);
    size = ftell(inventoryFile);
    fclose(inventoryFile);
}
    
        
