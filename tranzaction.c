#include <stdio.h>
#include <string.h>
#include "date.h"

struct tranzaction{
    date date;
    char description[301];
    float amount;
    int type; // False/0 == income ; True/1 == expense
};

typedef struct tranzaction tranzaction;

tranzaction create_tranzaction(date data, char description[301], float amount, int type){
    // creates a tranzaction
    tranzaction a;

    a.date = data;
    strcpy(a.description, description);
    a.amount = amount;
    a.type = type;

    return a;
}

void printf_tranzaction(tranzaction x){
    // prints a tranzaction in console
    char type[10];

    if(x.type == 0){
        strcpy(type, "Income");
    }
    else{
        strcpy(type, "Expense");
    }

    printf("Date: %d/%d/%d\nDescription: %s\nAmount: %f\nType: %s\n", get_day(x.date), get_month(x.date), get_year(x.date), x.description, x.amount, type);
}