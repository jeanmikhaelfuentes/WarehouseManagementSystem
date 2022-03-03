#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ID_LEN 7
unsigned char userChoice;
int search(char *temp);
int main();
FILE *fp;

int input(char str[], int n)
{
    char ch;
    int i;
    for (i = 0; (ch = getchar()) != '\n'; i++)
    {
        if (i < n)
        {
            str[i] = ch;
        }       
    }
    str[i] = '\0';
    return i;
}

int id_input_check(char str[], int input_len, int n)
{
    int i;
    char ch;
    int j;
    for (i = 0; i < n; i++)
    {
        j = 1;
        ch = str[i];
        if ((isdigit(ch) == 0) || (input_len != 5) || (ch == '\0'))
        {
            j = 0;
            printf("Please input exactly positive 5 digit numbers.\n");
            printf("Please try again another input.\n");
            break;
        }
    }
    return j;
}

void conc(char *temp, int n)
{
    char a[255] = "\"";
    strcat(temp, a);
    strcat(a, temp);
    strncpy(temp, a, n);
}

int search(char *temp)
{
	int found = 0;
	int match = 0;
	char s1[255];
    char s2[255];
    char *data;
    FILE *fp;
    
    fp = fopen("Inventory_ST_NoBOM.csv", "r");
    conc(temp, sizeof(temp));
    
    while (fgets(s1,sizeof(s1),fp))
    {
    	//found = 0;
        strncpy(s2, s1, sizeof(s2));
        data = strtok(s2, ",");

		for (int i = 0; data; i++)
		{
			if(strcmp(temp, data) == 0)
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
				id1 = strtok(s1, ",\"\"");
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
			}
			data = strtok(NULL, ",");
		}	
	}
	fclose(fp);
	if (found == 0)
	{
		printf("ID\tDescription\t\t\t\t\tQuantity\tExp. Date\tPrice(PHP))\n\n");
		printf("The item does not exists.\n");
		
	}
	return 0;
}



int main()
{
    char temp[255]; 
    char choice[255];
    int input_len = 0;
    printf("***SEARCH INVENTORY ITEM***\n\n");
    while (1)
    {
        printf("\nEnter product ID to search: ");
        input_len = input(temp, 5);
        if (id_input_check(temp, input_len, 5))
        {
            if (search(temp))
            {
 				break;
            }
        }
    }
}
