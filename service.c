#include <stdio.h>
#include <string.h>
#include "validate.h"
#include "date.h"
#include "infrastructure.h"
#include "tranzaction.h"

void read_command();
void addMenu();
void calculateBalance();

void run_menu(){
    tranzaction v[1000];
    int l = 0, finished = 0, valid;
    char command[1001];

    while(!finished){
        //validare comand
        do{
            read_command(command);

            valid = valid_command(command);
            if(valid == 0)
                printf("Invalid comand!\n");

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

            case 3://exit program
                finished = 1;
                break;
        }
    }
}

void read_command(char command[1001]){
    printf(">>> ");
    get_command(command);
}

void addMenu(tranzaction ListTranzactions[], int *l){
    //
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
            printf("Invalid date!\n");
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
            printf("Invalid number!\n");
        }
    }while(!valid);

    do{
        printf("Type: ");
        fgets(type, 100, stdin);
        type[strlen(type) - 1] = '\0';

        valid = validate_type(type);

        if(!valid){
            printf("Invalid type!\n");
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
    for(int i = 0; i < strlen(amount); i++)
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
    float total = 0;
    for(int i = 0; i < numberTranzactions; i++){
        if(ListTranzactions[i].type == 0)
            total += ListTranzactions[i].amount;
        else total -= ListTranzactions[i].amount;
    }
    printf("%f\n\n", total);
}