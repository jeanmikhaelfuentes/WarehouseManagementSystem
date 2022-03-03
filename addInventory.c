#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ID_LEN 7
#define EXP_DATE_LEN 12
#define DESCRIPTION_LEN 52
#define QUANTITY_LEN 6
#define PRICE_LEN 22

struct Products
{
    char ID[ID_LEN];
    char Description[DESCRIPTION_LEN];
    char Quantity[QUANTITY_LEN];
    char ExpiryDate[EXP_DATE_LEN];
    char Price[PRICE_LEN];
}P1;

// input function
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

// ID - returns a 1 if input is valid & 0 otherwise. 
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
            printf("Input ID is Invalid! Please try again.\nNOTE: ID must be a 5-digit number only.\n");
            break;
        }
    }
    return j;
}

// DESCRIPTION - returns a 1 if input is valid & 0 otherwise. 
int desc_input_check(char str[], int input_len, int n)
{
    int i;
    char ch;
    int j;
    for (i = 0; i < n; i++)
    {
        j = 1;
        ch = str[i];
        if (input_len > 50) 
        {
            j = 0;
            printf("Input Descripiton is Invalid! Please try again.\nNOTE: Description must not exceed 50 characters.\n");
            break;
        }
    }
    return j;
}

// QUANTITY - returns a 1 if input is valid & 0 otherwise. 
int qty_input_check(char *str, int input_len, int n)
{
    int i;
    char ch;
    int j;
    for (i = 0; i < n; i++)
    {
        j = 1;
        ch = str[i];
        if ((isdigit(ch) == 0) || (input_len >= 5)) 
        {
            j = 0;
            printf("Input Quantity is Invalid! Please try again.\nNOTE: Quantity must be a number.\n");
            break;
        }
    }
    return j;
}

// EXPIRY DATE - returns a 1 if input is valid & 0 otherwise.
int expd_input_check(char *str, int input_len, int n)
{
    int i;
    int j = 1;
    char ch[EXP_DATE_LEN];
    for (i = 0; i < n; i++)
    {
        ch[i] = str[i];
    }
    while (1)
    {
        if ((ch[0] == '-') && (input_len == 1))
        {
            break;
        }
        if ((input_len != 10) || (ch[4] != '-') || (ch[7] != '-'))
        {
            j = 0;
            printf("Input Expiry Date is Invalid! Please try again.\nNOTE: Follow this format (YYYY-MM-DD).\n");
            break;
        }
        for (i = 0; i < n; i++)
        {
            if  ((i != 4) && (i != 7))
            {
                if (isdigit(ch[i]) == 0)
                {    
                    j = 0;
                    printf("Input Expiry Date is Invalid! Please try again.\nNOTE: Follow this format (YYYY-MM-DD).\n");
                    break;
                }
            }
        }
        if ((ch[5] > '1') || (ch[8] > '3'))
        {
            printf("%c %c", ch[5], ch[8]);
            j = 0;
            printf("Input Expiry Date is Invalid! Please try again.\nNOTE: Follow this format (YYYY-MM-DD).\n");
            break;
        }
        if ((ch[5] == '1') && (ch[6] > '2'))
        {
            j = 0;
            printf("Input Expiry Date is Invalid! Please try again.\nNOTE: Follow this format (YYYY-MM-DD).\n");
            break;
        }
        if ((ch[8] == '3') && (ch[9] > '1'))
        {
                j = 0;
                printf("Input Expiry Date is Invalid! Please try again.\nNOTE: Follow this format (YYYY-MM-DD).\n");
                break;
        }
        if ((ch[5] == '0') && (ch[6] == '2') && (ch[8] > '2'))
        {
            j = 0;
                printf("Input Expiry Date is Invalid! Please try again.\nNOTE: Follow this format (YYYY-MM-DD).\n");
                break;
        }

        break;
    }

    return j;
}
// PRICE - returns a 1 if input is valid & 0 otherwise.
int price_input_check(char *str, int input_len, int n)
{
    int i, j, k;
    char ch;
    for (i = 0; i < n; i++)
    {
        j = 1;
        ch = str[i];
        if ( ((isdigit(ch) == 0) && (ch != '.')) || (input_len > PRICE_LEN))
        {
            j = 0;
            printf("Input Price is Invalid! Please try again.\nNOTE: Price must be a number.\n");
            break;
        }
    }
    return j;
}

// function to add  "" from strings
void conc(char *temp, int n)
{
    char a[255] = "\"";
    strcat(temp, a);
    strcat(a, temp);
    strncpy(temp, a, n);
}

// search if id exists
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
				printf("The item already exists.");
			}
			data = strtok(NULL, ",");
		}	
	}
	fclose(fp);
	return found;
}

// main
int main()
{
    FILE *fp1;
    fp1 = fopen("Inventory.csv", "a");
    char *data;
    int len;
    float p;
    int found = 0;

    do
    {
        printf("\nEnter ID: ");
        len = input(P1.ID, ID_LEN);
        if (id_input_check(P1.ID, len, 5))
        {
            if (search(P1.ID) == 1)
            {
                len = 0;
            }else{
                fprintf(fp1, "\n%s,", P1.ID);
            }
        }else{
            len = 0;
        }
    } while (len == 0);

    do
    {
        printf("Enter Description: ");
        len = input(P1.Description, DESCRIPTION_LEN);
        if (desc_input_check(P1.Description, len, 50))
        {
            conc(P1.Description,sizeof(P1.Description));
            fprintf(fp1, "%s,", P1.Description);
        }else{
            len = 0;
        }
    } while (len == 0);

    do
    {
        printf("Enter Quantity: ");
        len = input(P1.Quantity, QUANTITY_LEN);
        if (qty_input_check(P1.Quantity, len, len))
        {
            conc(P1.Quantity,sizeof(P1.Quantity));
            fprintf(fp1, "%s,", P1.Quantity);
        }else{
            len = 0;
        }
    } while (len == 0);

    do
    {
        printf("Enter Expiry Date(YYYY-MM-DD): ");
        len = input(P1.ExpiryDate, EXP_DATE_LEN);
        if (expd_input_check(P1.ExpiryDate, len, len))
        {
            conc(P1.ExpiryDate,sizeof(P1.ExpiryDate));
            fprintf(fp1, "%s,", P1.ExpiryDate);
        }else{
            len = 0;
        }
    } while (len == 0);

    do
    {
        printf("Enter Price(Php): ");
        len = input(P1.Price, PRICE_LEN);
        if (price_input_check(P1.Price, len, len))
        {
            p = atof(P1.Price);
            fprintf(fp1, "\"%.2f\"", p);
        }else{
            len = 0;
        }
    } while (len == 0);

    return 0;
}