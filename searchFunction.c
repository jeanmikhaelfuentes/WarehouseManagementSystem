#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define id_item 5
#define description_item 50
#define price_item 20

struct items
{
	char itemID[id_item];
	char itemDescription[description_item];
	char price[price_item];
} item;

int conc(char input[], int n)
{
	char qmark[255] = "\"";
	strcat(input, qmark);
	strcat(qmark, input);
	strncpy(input, qmark, n);
}

int userInput()
{
	char input[255];
	int found = 0;
	char p1[255];
	char p2[255];
	char *data;
	FILE *fp;
	fp = fopen("inv2.csv", "r+");
	printf("--------------------------------------------------\n");
	printf("SEARCH FOR AN ITEM\n");
	printf("Please input item ID number: ");
	scanf("%s", &input);
	printf("--------------------------------------------------\n");
	if (strlen(input) != 5 || input[0] == '-' || input[0] == '\n') { //invalid input
		printf("Please input exactly positive 5 digit numbers. \n");
		printf("Please try again another input.\n");
		userInput();
	}
	else { //valid input
	conc(input, sizeof(input));
	printf("You are searching for an item with item ID:%s\n", input);
		while (fgets (p1, 255, fp)) //fgets(char p1, 255(number of characters to copy), file pointer)
		{
		strncpy(p2, p1, sizeof(p2));
		//printf("%s", p1);
		data = strtok(p2, ",");
		
			while (data)
			{
				if (strcmp(input, data) == 0)
				{
					found = 1;
					int choice;
					printf("--------------------------------------------------\n");
					printf("ITEM ID\t\tITEM DESCRIPTION\tITEM PRICE\n");
					printf("--------------------------------------------------\n");
					printf("TBA\t\tTBA\t\t\tTBA\n");
					printf("\nWould you like to try searching another item?\n");
					printf("Press: 1 - YES, 2 - BACK TO MAIN MENU\nPlease input your choice: ");
					scanf("%d", &choice);
					//printf("You have entered: %d", choice);
					switch(choice)
						{
						case 1: userInput();
					//	case 2: searchMenu();
					//	break;
						default: printf("Please Choose what is shown!");
						break;
					}
				}
				data = strtok(NULL, ",");
			}


		}
	fclose(fp);
	if (found == 0)
	{
		int choice;
		printf("--------------------------------------------------\n");
		printf("ITEM ID\t\tITEM DESCRIPTION\tITEM PRICE\n");
		printf("--------------------------------------------------\n");
		printf("The item does not exists.\n");
		printf("\nWould you like to try searching another item?\n");
		printf("Press: 1 - YES, 2 - BACK TO MAIN MENU\nPlease input your choice: ");
		scanf("%d", &choice);
		//printf("You have entered: %d", choice);
		switch(choice)
			{
			case 1: userInput();
		//	case 2: searchMenu();
		//	break;
			default: printf("Please Choose what is shown!");
			break;
		}
		
	}
	}
	return 0;
}
	

int main()
{
	userInput();
}
	
	
