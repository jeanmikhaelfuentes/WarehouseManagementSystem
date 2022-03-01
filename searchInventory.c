#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
}

int userInput()
{
	char input[255];
	int found = 0;
	char p1[255];
	char p2[255];
	char *data;
	char *in;
	fp = fopen("Inventory_ST_NoBOM.csv", "r+");
	printf("\n\nPlease input item ID number: ");
	scanf("%s", &input);
	printf("\n");
	if (strlen(input) != 5 || input[0] == '-' || input[0] == '\n') {
		//for invalid input
		printf("Please input only positive 5 digit numbers.\n");
		printf("Please try again another input.\n");
		userInput();
	}
	else {
		//valid input
	concatenation(input, sizeof(input));
		while (fgets (p1, 255, fp))
		//fgets(char p1, 255(number of characters to copy), file pointer)
		{
		strncpy(p2, p1, sizeof(p2));
		data = strtok(p2, ",");
			while (data)
			{
				if (strcmp(input, data) == 0)
				{
					found = 1;
					char id[255];
					char desc[255];
					char price[255];
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
}