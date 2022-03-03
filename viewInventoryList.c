#include <stdio.h>
#include <string.h>
char userChoice[2];
void nullChecker();
FILE *inventoryFile;
int size;

int main(){
        nullChecker();
        char buffer[1024];

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
            inventoryFile = fopen("inventory.csv", "r");
            int row = 0;
            int column = 0;
            printf("ID\tDescription\t\t\t\tQuantity\tExp. Date\tPrices (PHP)\n\n");
            while (fgets(buffer, 1024, inventoryFile)) {
                column = 0;
                row++;

                // Splitting the data
                char* value = strtok(buffer, ",\"\"");
    
                while (value) {
                
                    // Description
                    if (column == 1) {
                        printf("\t");
                    }
    
                    // Quantity
                    if (column == 2) {
                    printf("\t\t\t");
                    }
                    // Exp. Date
                    if (column == 3) {
                        printf("\t\t");
                    }
                    // Prices
                    if (column == 4) {
                        printf("\t\t");
                    }
    
                    printf("%s", value);
                    value = strtok(NULL, ",\"\"");
                    column++;
                }
            }
        }

    fclose(inventoryFile);
    return 0;
}

void nullChecker(){
    inventoryFile = fopen("inventory.csv", "r");
    fseek(inventoryFile, 0, SEEK_END);
    size = ftell(inventoryFile);
    fclose(inventoryFile);
}