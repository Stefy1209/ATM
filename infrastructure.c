#include <stdio.h>
#include <string.h>

void get_command(char command[1001]){
    //
    strcpy(command, "");
    fgets(command, 1001, stdin);
    command[strlen(command) - 1] = '\0';
}

char listActions[4][1001] = {"add", "print", "balance", "load", "save", "exit"};

int action(char command[1001]){
    //
    for(int i = 0 ; i < 6; i++)
        if(strcmp(command, listActions[i]) == 0)
            return i;
}

int transform_char_to_int(char string[]){
    //
    int number = 0, powerOf10 = 1;

    for(int i = strlen(string) - 1; i >=0 ; i--){
        number = number + (string[i] - '0') * powerOf10;
        powerOf10 *= 10;
    }

    return number;
}

float transform_char_to_float(char string[]){
    if(strchr(string, '.') == NULL){
        float number = 0, powerOf10 = 1;

        for(int i = strlen(string) - 1; i >=0 ; i--){
            number = number + (string[i] - '0') * powerOf10;
            powerOf10 *= 10;
        }

        return number;
    }
    else{
        float number1 = 0, powerOf10_1 = 1;

        for(int i = strchr(string, '.') - string - 1; i >=0 ; i--){
            number1 = number1 + (string[i] - '0') * powerOf10_1;
            powerOf10_1 *= 10;
        }

        float number2 = 0, powerOf10_2 = 0.1;

        for(int i = strchr(string, '.') - string + 1; i < strlen(string); i++){
            number2 = number2 + (string[i] - '0') * powerOf10_2;
            powerOf10_2 /= 10;
        }

        return number1 + number2;
    }
}