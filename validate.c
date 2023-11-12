#include <string.h>
#include <stdio.h>
#include "infrastructure.h"

char listCommands[7][1001] = {"add", "print", "balance", "load", "save", "between", "exit"};

int valid_command(char command[1001]){
    //
    int i;

    for(i = 0; i < strlen(command); i++)
        if('A' <= command[i] && command[i] <= 'Z')
            command[i] = command[i] + ('a' - 'A');  

    for(i = 0 ; i < 7; i++)
        if(strcmp(command, listCommands[i]) == 0)
            return 1;

    return 0;
}

int numberDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int validate_date(char date[11]){
    //
    int i, day, month, year;
    char number[5] = "";

    for(i = 0; i < 2; i++){
        if(date[i] < '0' || '9' < date[i])
            return 0;
    }

    strncpy(number, date, 2);
    day = transform_char_to_int(number);

    if(date[i] != '/')
        return 0;

    for(i++; i < 5; i++){
        if(date[i] < '0' || '9' < date[i])
            return 0;
    }

    strncpy(number, date + 3, 2);
    month = transform_char_to_int(number);

    if(date[i] != '/')
        return 0;

    for(i++; i < 10; i++){
        if(date[i] < '0' || '9' < date[i])
            return 0;
    }

    strncpy(number, date+6, 4);
    year = transform_char_to_int(number);

    if(day*month*year == 0)
        return 0;

    int bisect = 0;
    if((year % 4 == 0 && year%100 != 0) || (year % 400 == 0))
        bisect = 1;

    if(bisect == 1)
        numberDays[2] = 29;
    else numberDays[2] = 28;

    if(month < 1 || 12 < month)
        return 0;

    if(day < 1 || numberDays[month] < day)
        return 0;

    return 1;
}

int validate_amount(char amount[301]){
    //
    int nrDot = 0, nrDigits = 0, i;

    for(i = 0; i < strlen(amount); i++){
        if(strchr("1234567890.", amount[i]) == NULL)
            return 0;

        if(amount[i] == '.'){
            nrDot++;

            if(nrDot == 2)
                return 0;
        }
        else nrDigits++;
    }

    if(nrDigits == 0)
        return 0;

    return 1;
}

char typesList[2][101] = {"income", "expense"};

int validate_type(char type[101]){
    int i;

    for(i = 0; i < strlen(type); i++)
        if('A' <= type[i] && type[i] <= 'Z')
            type[i] = type[i] + ('a' - 'A');        

    for(i = 0; i < 2; i++)
        if(strcmp(type, typesList[i]) == 0)
            return 1;

    return 0;
}