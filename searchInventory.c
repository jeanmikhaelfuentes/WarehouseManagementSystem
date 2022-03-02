#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INPUT_LENGTH 8

int userInput();
int concatenation();
unsigned char choice[2];
FILE *fp;

int concatenation(char input[], int n)
{
	char qmark[255] = "\"";
	strcat(input, qmark);
	strcat(qmark, input);
	strncpy(input, qmark, n);
	return 0;
}

int userInput()
{
	char input[INPUT_LENGTH]; //"11111\0"
	//printf("%d", sizeof(input));
	int found = 0;
	char p1[255];
	char p2[255];
	char *data;
	char *in;
	fp = fopen("Inventory_ST_NoBOM.csv", "r+");
	printf("\n\nPlease input item ID number: ");
	scanf("%s", &input);
	printf("\nYou are searching for an item with ID number %s...\n", input);
	//printf("%d", sizeof(input));
	if (strlen(input) != 5 || input[0] == '-' || isdigit(input[0]) == 0 || isdigit(input[1]) == 0 || isdigit(input[2]) == 0 ||
		isdigit(input[3]) == 0 || isdigit(input[4]) == 0)
	{
		//for invalid input
		printf("Please input exactly positive 5 digit numbers.\n");
		printf("Please try again another input.\n");
		userInput();
	}
	else {
		//valid input
	concatenation(input, sizeof(input));
		while (fgets (p1, sizeof(p1), fp))
		//fgets(char p1, sizeofp1 is the number of characters to be copied, file pointer)
		{
		strncpy(p2, p1, sizeof(p2));
		//printf("%d", sizeof(p2));
		data = strtok(p2, ",");
			while (data)
			{
				if (strcmp(input, data) == 0)
				{
					found = 1;
					char *id1;
					char *id2;
					int column, row;
					printf("ID\tDescription\t\t\t\t\tQuantity\tExp. Date\tPrice(PHP)\n\n");
					column = 0;
					row++;
					if (row == 1)
					{
						continue;
					}
					id1 = strtok(p1, ",\"\"");
					while (id1)
					{
					    if (column == 1) 
						{
                    	printf("\t");
                		}
		                if (column == 2) 
						{
		                   printf("\t\t\t");
		                }
		                if (column == 3) 
						{
		                    printf("\t\t");
		                }
		                if (column == 4) 
						{
		                    printf("\t\t");
		                }
		                printf("%s", id1);
		                id1 = strtok(NULL, ",\"\"");
		                column++;
					}
					printf("\nWould you like to try searching another item?\n");
					printf("Press: Y - YES, B - BACK TO MAIN MENU\nPlease input your choice: ");
					choice[1] = 1;
					while(choice[1] == 1)
					{
						scanf(" %c", &choice[0]);
						
						switch(choice[0])
						{
						case 'y':
						case 'Y': 
							userInput();
							choice[1] = 0;
							break;
						//case 'b':
						//case 'B':
							//searchMenu();
							//choice[1] = 0;
							//break;
						default: 
							printf("Please choose from what is shown.\nPlease input again: ");
							break;
						}
					}
				}
				data = strtok(NULL, ",");
			}


		}
	fclose(fp);
	if (found == 0)
	{
		printf("ID\tDescription\t\t\t\t\tQuantity\tExp. Date\tPrice(PHP))\n\n");
		printf("The item does not exists.\n");
		printf("\nWould you like to try searching another item?\n");
		printf("Press: Y - YES, B - BACK TO MAIN MENU\nPlease input your choice: ");
		choice[1] = 1;
		while(choice[1] == 1)
		{
			scanf(" %c", &choice[0]);
				
			switch(choice[0])
			{
				case 'y':
				case 'Y': 
						userInput();
						choice[1] = 0;
						break;
				//case 'b':
				//case 'B':
						//searchMenu();
						//choice[1] = 0;
						//break;
				default: 
						printf("Please choose from what is shown.\nPlease input again: ");
						break;
			}
		
		}
	}
	return 0;
}
}
	
int main()
{
	printf("SEARCH FOR AN ITEM\n");
	userInput();
	return 0;
}