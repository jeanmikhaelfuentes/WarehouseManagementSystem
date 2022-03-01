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

int conc(char temp[], int n)
{
    char a[255] = "\"";
    strcat(temp, a);
    strcat(a, temp);
    strncpy(temp, a, n);
    return 0;
}

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
    int j = 0;
    for (i = 0; i < n; i++)
    {
        ch = str[i];
        if ((isdigit(ch) == 0) || (input_len != 5) || (ch == '-') || (ch == '\0'))
        {
            printf("\nInput ID Invalid! Please try again.\nNOTE: ID must be a 5-digit number only.\n");
            break;
        }
        else 
        {
            j = 1;
        }
    }
    return j;
}

int desc_input_check(char str[], int input_len, int n)
{
    int i;
    int j = 0;
    char ch;
    for (i = 0; i < n; i++)
    {
        ch = str[i];
        if (input_len > 48) 
        {
            printf("Input Description Invalid! Please try again.\nNOTE: Description must not exceed 50 characters.\n");
            break;
        }
        else 
        {
            j = 1;
        }
    }
    return j;
}

void newValues(char *fp1)
{
    
}


int updateInventory() 
{
    char temp[255]; 
    int input_len;
    int found;
    int match = 0; 
    char s1[255];
    char s2[255];
    char *data;
    FILE *fp, *fp1; 
    
    while (1)
    {
        printf("Enter product ID to update: ");
        input_len = input(temp,ID_LEN);
        if (input_check(temp,input_len,ID_LEN))
        {
            break;
        }
    }
    fp = fopen("test.csv", "r");
    fp1 = fopen("temp.csv", "w");
    conc(temp, sizeof(temp));
    printf("Searching for Product %s...\n", temp);
    while (fgets(s1,sizeof(s1),fp))
    {
        found = 0;
        strncpy(s2, s1, sizeof(s2));
        printf("%s", s1); 
        data = strtok(s1, ",");

        for (int i = 0; data; i++)
        {
            if (strcmp(temp, data) == 0)
            {
                found = 1;
                match++;
                fflush(stdin);
                newValues(fp1);
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
    if (match == 0)
    {
        printf("\nProduct ID does not exist.\n");
    }
    return 0;
}   


int main() 
{
    updateInventory();
    return 0;
}
