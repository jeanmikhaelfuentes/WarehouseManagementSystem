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
// returns a 1 if input is valid & 0 otherwise. 
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
// returns a 1 if input is valid & 0 otherwise. 
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
// returns a 1 if input is valid & 0 otherwise. 
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
// returns a 1 if input is valid & 0 otherwise.
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
// returns a 1 if input is valid & 0 otherwise.
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
// function for updating values
void newValues(FILE *fp1, char *data, int j)
{
    int len;
    float p;
    switch (j)
    {
        case 0: //Enter new ID
            while (1)
            {
                printf("\nEnter new ID: ");
                len = input(P1.ID, ID_LEN);
                if (strcmp(P1.ID, "\0") == 0) 
                {
                    printf("ID has no changes.\n");
                    fprintf(fp1, "%s,", data);
                    break;       
                }
                if (id_input_check(P1.ID, len, 5))
                {
                    conc(P1.ID,sizeof(P1.ID));
                    fprintf(fp1, "%s,", P1.ID);
                    break;
                }
            }
            break;
        case 1: //Enter new desc.
            while (1)
            {
                printf("Enter new Description: ");
                len = input(P1.Description, DESCRIPTION_LEN);
                if (strcmp(P1.Description, "\0") == 0) 
                {
                    printf("Description has no changes.\n");
                    fprintf(fp1, "%s,", data);
                    break;
                }
                if (desc_input_check(P1.Description, len, 50))
                {
                    conc(P1.Description,sizeof(P1.Description));
                    fprintf(fp1, "%s,", P1.Description);
                    break;
                }
            }
            break;
        case 2: //Enter new Quantity
            while (1)
            {
                printf("Enter new Quantity: ");
                len = input(P1.Quantity, QUANTITY_LEN);
                if (strcmp(P1.Quantity, "\0") == 0)
                {
                    printf("Quantity has no changes.\n");
                    fprintf(fp1, "%s,", data);
                    break;
                }
                if (qty_input_check(P1.Quantity, len, len))
                {
                    conc(P1.Quantity,sizeof(P1.Quantity));
                    fprintf(fp1, "%s,", P1.Quantity);
                    break;
                }
            }
            break;
        case 3: //Enter new Exp. Date
            while (1)
            {
                printf("Enter new Expiry Date(YYYY-MM-DD): ");
                len = input(P1.ExpiryDate, EXP_DATE_LEN);
                if (strcmp(P1.ExpiryDate, "\0") == 0)
                {
                    printf("Expiry Date has no changes.\n");
                    fprintf(fp1, "%s,", data);
                    break;
                }
                if (expd_input_check(P1.ExpiryDate, len, len))
                {
                    conc(P1.ExpiryDate,sizeof(P1.ExpiryDate));
                    fprintf(fp1, "%s,", P1.ExpiryDate);
                    break;
                }
            }
            break;
         case 4: //Enter new Price
            while (1)
            {
                printf("Enter new Price(Php): ");
                len = input(P1.Price, PRICE_LEN);
                if (strcmp(P1.Price, "\0") == 0)
                {
                    printf("Price has no changes.\n");
                    fprintf(fp1, "%s", data);
                    break;
                }
                if (price_input_check(P1.Price, len, len))
                {
                    p = atof(P1.Price);
                    fprintf(fp1, "\"%.2f\"\n", p);
                    break;
                }
            }
            break;
        default:
            break;
    }
}
// main function for searching and overwriting updates
int update(char *temp)
{
    int found;
    int match = 0; 
    char s1[255];
    char s2[255];
    char *data;
    FILE *fp, *fp1;

    fp = fopen("Inventory.csv", "r");
    fp1 = fopen("temp.csv", "w");
    conc(temp, sizeof(temp));
    printf("Searching for Product %s...\n", temp);
    
    while (fgets(s1,sizeof(s1),fp))
    {
        found = 0;
        strncpy(s2, s1, sizeof(s2));
        data = strtok(s1, ",");
 
        for (int i = 0; data; i++)
        {
            if (strcmp(temp, data) == 0)
            {
                found = 1;
                match++;
                fflush(stdin);
                printf("\nPlease enter new values, leave blank for no changes.");
                for (int j = 0; j < 5 ; j++)
                {
                    newValues(fp1, data, j);
                    data = strtok(NULL, ",");
                }
                break;
            }
            if ((found == 0) && (i == 4))
            {
                fprintf(fp1, "%s", s2);
            }
            data = strtok(NULL, ",");
        }
    }

    fclose(fp);
    fclose(fp1);
    if (match)
    {
        fp1 = fopen("temp.csv", "r");
        fp = fopen("Inventory.csv", "w");
        fflush(stdin);
        while (fgets(s1,sizeof(s1),fp1))
        {
            fprintf(fp,"%s", s1);
        }
        fclose(fp1);
        fclose(fp);

        printf("\nUpdate successful.\n\n");
    }
    else 
    {
        printf("\nProduct ID does not exist. Please try again.\n");
    }

    return match;
}
// calling update function in a loop
void main()
{
    char temp[255]; 
    int input_len = 0;
    printf("***UPDATE INVETORY ITEM***\n\n");
    while (1)
    {
        printf("Enter product ID to update: ");
        input_len = input(temp, 5);
        if (id_input_check(temp, input_len, 5))
        {
            if (update(temp))
            {
                break;
            }
        }
    }
}