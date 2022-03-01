#include <stdio.h>
#include <string.h>
char userChoice[2];

int main(){
    
    FILE *inventoryFile = fopen("./Data/inventory.csv", "r");
 
        char buffer[1024];
 
        int row = 0;
        int column = 0;
        printf("ID\tDescription\t\t\t\tQuantity\tExp. Date\tPrices(PHP)\n\n");
        while (fgets(buffer,
                     1024, inventoryFile)) {
            column = 0;
            row++;
            if (row == 1)
                continue;
 
            // Splitting the data
            char* value = strtok(buffer, ",\"\"");
 
            while (value) {
                // ID
                if (column == 0) {
                    printf("");
                }
 
                // Description
                if (column == 1) {
                    printf("\t");
                }
 
                // Quantity
                if (column == 2) {
                   printf("\t\t");
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
 
            printf("\n");
        }
    fclose(inventoryFile);
    return 0;
}
    
   
    


    
