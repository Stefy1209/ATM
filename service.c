#include <stdio.h>
#include <string.h>
#include "validate.h"
#include "date.h"
#include "infrastructure.h"
#include "tranzaction.h"

void read_command();
void addMenu();
void calculateBalance();
void betweenMenu();
void loadFile();
void saveFile();

void run_menu(){
    tranzaction v[1000];
    int l = 0, finished = 0, valid, loaded = 0;
    char command[1001];
    FILE *fptr;

    while(!finished){
        //validare comand
        do{
            read_command(command);

            valid = valid_command(command);
            if(valid == 0)
                printf("\nInvalid comand!\n\n");

        }while(!valid);

        printf("\n");

        //executare comanda
        switch(action(command)){
            case 0://add tranzaction
                addMenu(v, &l);
                break;

            case 1://show tranzactions loaded or added
                for(int i = 0; i < l; i++)
                    printf_tranzaction(v[i]);
                break;

            case 2://show balance
                calculateBalance(v, l);
                break;

            case 3://load tranzactions from file
                if(!loaded){
                    loadFile(v, &l, fptr);
                    loaded = 1;
                }
                break;

            case 4://save tranzactions in file
                if(!loaded){
                    loadFile(v, &l, fptr);
                    loaded = 1;
                }
                saveFile(v, l, fptr);
                break;

            case 5://show the tranzactions between e dates
                betweenMenu(v, l);
                break;

            case 6://exit program
                finished = 1;
                break;
        }
    }
}

void read_command(char command[1001]){
    //reads command as a string
    printf(">>> ");
    get_command(command);
}

void addMenu(tranzaction ListTranzactions[], int *l){
    //reads the information of a tranzaction like date, description, amount and type and adds it to a list
    //reads and validate the information
    char Date[12], description[301], amount[301], type[101];
    int valid;

    do{
        Date[0] = '\0';
        printf("Date: ");
        fgets(Date, 12, stdin);
        Date[strlen(Date) - 1] = '\0';

        valid = validate_date(Date);

        if(!valid){
            printf("\nInvalid date!\n\n");
        }
    }while(!valid);

    do{
        printf("Description: ");
        fgets(description, 300, stdin);
        description[strlen(description) - 1] = '\0';

        valid = 1;
    }while(!valid);

    do{
        printf("Amount: ");
        fgets(amount, 300, stdin);
        amount[strlen(amount) - 1] = '\0';

        valid = validate_amount(amount);

        if(!valid){
            printf("\nInvalid number!\n\n");
        }
    }while(!valid);

    do{
        printf("Type: ");
        fgets(type, 100, stdin);
        type[strlen(type) - 1] = '\0';

        valid = validate_type(type);

        if(!valid){
            printf("\nInvalid type!\n\n");
        }
    }while(!valid);

    printf("\n");

    //creates a date
    int day, month, year;
    char number[10] = "";

    strncpy(number, Date, 2);
    day = transform_char_to_int(number);

    strncpy(number, Date + 3, 2);
    month = transform_char_to_int(number);

    strncpy(number, Date + 6, 4);
    year = transform_char_to_int(number);

    date data = create_date(day, month, year);

    //creates an amount
    float x;
    x = transform_char_to_float(amount); 

    //creates a type
    int v;
    for(int i = 0; i < strlen(type); i++)
        if('A' <= type[i] && type[i] <= 'Z')
            type[i] = type[i] + ('a' - 'A');

    if(strcmp(type, "income") == 0)
        v = 0;
    else v = 1;

    //creates a tranzaction
    tranzaction t = create_tranzaction(data, description, x, v);

    ListTranzactions[*l] = t;
    *l = *l + 1;
}

void calculateBalance(tranzaction ListTranzactions[], int numberTranzactions){
    //calculate the amount of money you have depending on the tranzactions from ListTranzactions
    float total = 0;
    for(int i = 0; i < numberTranzactions; i++){
        if(ListTranzactions[i].type == 0)
            total += ListTranzactions[i].amount;
        else total -= ListTranzactions[i].amount;
    }
    printf("%f\n\n", total);
}

void betweenMenu(tranzaction ListTranzactions[], int numberTranzactions){
    //shows all the tranzactions between date 1 and date 2 depending on the order of your list of tranzactions
    char date1[12], date2[12];
    int valid ;

    do{
        date1[0] = '\0';
        printf("From: ");
        fgets(date1, 12, stdin);
        date1[strlen(date1) - 1] = '\0';

        valid = validate_date(date1);

        if(!valid){
            printf("\nInvalid date!\n\n");
        }
    }while(!valid);

    do{
        date2[0] = '\0';
        printf("To: ");
        fgets(date2, 12, stdin);
        date2[strlen(date2) - 1] = '\0';

        valid = validate_date(date2);

        if(!valid){
            printf("\nInvalid date!\n\n");
        }
    }while(!valid);

    printf("\n");

    date Date1, Date2;
    int day, month, year;
    char number[10] = "";

    //creates date 1
    strncpy(number, date1, 2);
    day = transform_char_to_int(number);

    strncpy(number, date1 + 3, 2);
    month = transform_char_to_int(number);

    strncpy(number, date1 + 6, 4);
    year = transform_char_to_int(number);

    Date1 = create_date(day, month, year);

    //creates date 2
    strncpy(number, date2, 2);
    number[2] = '\0';
    day = transform_char_to_int(number);

    strncpy(number, date2 + 3, 2);
    month = transform_char_to_int(number);

    strncpy(number, date2 + 6, 4);
    year = transform_char_to_int(number);

    Date2 = create_date(day, month, year);

    //shows the tranzactions between date 1 and date 2
    for(int i = 0; i < numberTranzactions; i++){
        if(is_after(ListTranzactions[i].data, Date1) && is_before(ListTranzactions[i].data, Date2))
            printf_tranzaction(ListTranzactions[i]);
    }
}

void loadFile(tranzaction ListTranzactions[], int *numberTranzactions, FILE *fptr){
    //adds all the saved tranzactions from a file to your current list of tranzactions
    fptr = fopen("tranzactions.txt", "r");

    char cnr[301];
    int nr;

    fgets(cnr, 300, fptr);
    if(cnr[strlen(cnr) - 1] == '\n') 
        cnr[strlen(cnr) - 1] = '\0';
    
    nr = transform_char_to_int(cnr);

    char string[301];
    for(int i = 1; i <= nr; i++){
        //reads the Date line
        fgets(string, 300, fptr);
        fgets(string, 300, fptr);
        if(string[strlen(string) - 1] == '\n') 
            string[strlen(string) - 1] = '\0';

        //creates the date
        int day, month, year;
        char number[10] = "", Date[301];
        strcpy(Date, string + 6);

        strncpy(number, Date, 2);
        day = transform_char_to_int(number);

        strncpy(number, Date + 3, 2);
        month = transform_char_to_int(number);

        strncpy(number, Date + 6, 4);
        year = transform_char_to_int(number);

        date data = create_date(day, month, year);

        //reads description line
        string[0] = '\0';
        fgets(string, 300, fptr);
        if(string[strlen(string) - 1] == '\n') 
            string[strlen(string) - 1] = '\0';

        //creates description
        char description[301];
        strcpy(description, string + 13);

        //reads the amount line
        string[0] = '\0';
        fgets(string, 300, fptr);
        if(string[strlen(string) - 1] == '\n') 
            string[strlen(string) - 1] = '\0';

        //creates the amount
        char Camount[301];
        float amount;
        strcpy(Camount, string + 8);
        amount = transform_char_to_float(Camount);

        //reads the type line
        string[0] = '\0';
        fgets(string, 300, fptr);
        if(string[strlen(string) - 1] == '\n') 
            string[strlen(string) - 1] = '\0';

        //creates type
        char Ctype[301];
        int type;
        strcpy(Ctype, string+6);

        for(int i = 0; i < strlen(Ctype); i++)
            if('A' <= Ctype[i] && Ctype[i] <= 'Z')
                Ctype[i] = Ctype[i] + ('a' - 'A');

        if(strcmp(Ctype, "income") == 0)
            type = 0;
        else type = 1;

        //creates a tranzaction
        tranzaction t = create_tranzaction(data, description, amount, type);

        //adds tranzaction at the end of the list
        ListTranzactions[*numberTranzactions] = t;
        *numberTranzactions = *numberTranzactions + 1;
    }

    fclose(fptr);
}

void saveFile(tranzaction ListTranzactions[], int numberTranzactions, FILE *fptr){
    //all information from the ListTranzactions will be saved in a file
    fptr = fopen("tranzactions.txt", "w");

    fprintf(fptr, "%d\n\n", numberTranzactions);

    tranzaction x;
    
    for(int i = 0; i < numberTranzactions; i++){
        x = ListTranzactions[i];
        char type[10];

        if(x.type == 0){
            strcpy(type, "Income");
        }
        else{
            strcpy(type, "Expense");
        }

        int day, month, year;
        day = get_day(x.data);
        month = get_month(x.data);
        year = get_year(x.data);

        fprintf(fptr, "Date: ");
        if(1 <= day && day <=9)
            fprintf(fptr, "0%d/", day);
        else fprintf(fptr, "%d/", day);

        if(1 <= month && month <= 9)
            fprintf(fptr, "0%d/", month);
        else fprintf(fptr, "%d/", month);

        fprintf(fptr, "%d\nDescription: %s\nAmount: %f\nType: %s\n\n", year, x.description, x.amount, type);
    }
}
