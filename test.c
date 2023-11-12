#include <string.h>
#include <stdio.h>
#include "date.h"
#include "validate.h"
#include "infrastructure.h"
#include "service.h"

int valid_command_test(){
    char command[7][301] = {"add","Add", "aDD", "ADd", "add", "EXIT", "exit"};
    for(int i = 0; i < 7; i++)
        if(valid_command(command[i]) == 0)
            return 0;

    return 1;
}

int validate_amount_test(){
    char amount[4][301] = {"23", "23.09", "0.009", "9.0"};
    for(int i = 0; i < 4; i++)
        if(validate_amount(amount[i]) == 0)
            return 0;

    return 1;
}

int validate_date_test(){
    char date[3][301] = {"12/09/2004", "28/02/2004", "29/02/2004"};
    for(int i = 0; i < 3; i++)
        if(validate_date(date[i]) == 0)
            return 0;

    return 1;
}

int validate_type_test(){
    char type[4][301] = {"income", "expense", "INCOme", "EXpEnse"};
    for(int i = 0; i < 4; i++)
        if(validate_type(type[i]) == 0)
            return 0;

    return 1;
}

int validateTest(){
    return (valid_command_test() + validate_amount_test() + validate_date_test() + validate_type_test()) / 4;
}

int runTests(){
    validateTest();
}