#include <stdio.h>
#include <string.h>


int viewInvtoryList;
unsigned char userChoice[2];
int mainMenu();
FILE *inventoryFile;



int main(){

    if(inventoryFile = fopen("inventory.csv", "r")){
        fclose(inventoryFile);
        mainMenu();
    }else{
        inventoryFile = fopen("inventory.csv", "w");
        fclose(inventoryFile);
        mainMenu();
    }
    
    mainMenu();
 
    return 0;
}

int mainMenu(){
    printf("Group-2 Inventory Management System\n\n");
    printf("Main Menu\n");
    printf("[A] Add Inventory Item\n");
    printf("[B] Update Inventory Item\n");
    printf("[C] View Inventory List\n");
    printf("[D] Search Inventory Item\n");
    printf("[X] Exit\n\n");
    printf("Please input choice: ");
    userChoice[1] = 1;
    
    while(userChoice[1] == 1){
        scanf(" %c", &userChoice[0]);
        
        switch(userChoice[0]){
        case 'a':
        case 'A': 
            printf("Add Inventory Item\n");
            userChoice[1] = 0;
            break;
        case 'b':
        case 'B':
            printf("Update Inventory Item\n");
            userChoice[1] = 0;
            break;
        case 'c':
        case 'C':
            printf("View Inventory List\n"); 
            userChoice[1] = 0;
            break;
        case 'd':
        case 'D':
            printf("Search Inventory Item\n");
            userChoice[1] = 0;
            break;
        case 'x':
        case 'X':
            printf("\nThank you. Have a great day!\n");
            userChoice[1] = 0;
            break;
        default: 
            printf("\nPlease choose a valid input.\n\nPlease try to input again: ");
            break;
        } 
    }
}