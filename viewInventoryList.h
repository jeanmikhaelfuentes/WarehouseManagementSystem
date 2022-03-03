int size;

void nullChecker();
void endChoice();

int viewInventoryList(){
        nullChecker();
        char buffer[1024];

        if(size == 0){
        printf("Inventory is empty...\n\n");
        endChoice();
    }else{
            fp = fopen("Inventory_ST_NoBOM.csv", "r");
            int row = 0;
            int column = 0;
            int i = 0;
            printf("ID\tDescription\t\t\t\tQuantity\tExp. Date\tPrices (PHP)\n\n");
            while (fgets(buffer, 1024, fp)) {
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
            }
        }
    fclose(fp);
    endChoice();
    return 0;
}

void nullChecker(){
    fp = fopen("Inventory_ST_NoBOM", "r");
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);
}