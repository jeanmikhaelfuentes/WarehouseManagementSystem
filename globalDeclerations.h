#define ID_LEN 7
#define EXP_DATE_LEN 20
#define DESCRIPTION_LEN 52
#define QUANTITY_LEN 6
#define PRICE_LEN 13
#define INV_FILE "Inventory_ST_NoBOM.csv"

FILE *fp;
int mainMenu();
unsigned char userChoice[2];

struct Products
{
    char ID[ID_LEN];
    char Description[DESCRIPTION_LEN];
    char Quantity[QUANTITY_LEN];
    char ExpiryDate[EXP_DATE_LEN];
    char Price[PRICE_LEN];
}P1;

void endChoice(){
    printf("\n\n\nExit or go back to main menu? (X -- Exit or M -- Main Menu)\n");
    printf("Please input choice: ");
    userChoice[1]=1;
    while(userChoice[1]==1){
        scanf(" %1c",&userChoice[0]);
            switch(userChoice[0]){
                case 'm':
                case 'M':
                    userChoice[1]=0;
                    //printf("Main Menu");
                    memset(P1.ID,NULL,ID_LEN);
                    memset(P1.Description,NULL,DESCRIPTION_LEN);
                    memset(P1.Quantity,NULL,QUANTITY_LEN);
                    memset(P1.ExpiryDate,NULL,EXP_DATE_LEN);
                    memset(P1.Price,NULL,PRICE_LEN);
                    mainMenu();
                    break;
                case 'X':
                case 'x':
                    userChoice[1]=0;
                    printf("Thank you for using our inventory management system");
                    break;
                default:
                    printf("Invalid Input, please try again: ");
                    userChoice[1]=1;
            }
        }
    }