#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "globalDeclerations.h"
//#include "addInventory.h"
#include "updateInventory.h"
#include "viewInventoryList.h"
#include "searchInventory.h"


int main(){
    if(fp = fopen(INV_FILE, "r")){
        fclose(fp);
        mainMenu();
    }
    else{
        fp = fopen(INV_FILE, "w");
        fclose(fp);
        mainMenu();
    }
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
            //addInventory();
            userChoice[1] = 0;
            break;
        case 'b':
        case 'B':
            printf("Update Inventory Item\n");
            updateInventory();
            userChoice[1] = 0;
            break;
        case 'c':
        case 'C':
            printf("View Inventory List\n"); 
            viewInventoryList();
            userChoice[1] = 0;
            break;
        case 'd':
        case 'D':
            printf("Search Inventory Item\n");
            searchInventory();
            userChoice[1] = 0;
            break;
        case 'x':
        case 'X':
            printf("\nThank you. Have a great day!\n");
            userChoice[1] = 0;
            break;
        default: 
            printf("Please choose a valid input.\n\nPlease try to input again: ");
            break;
        } 
    }
}