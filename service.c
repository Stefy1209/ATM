#include <stdio.h>
#include <string.h>
#include "validate.h"
#include "date.h"
#include "infrastructure.h"
#include "tranzaction.h"

void read_command();

void run_menu(){
    tranzaction v[1000];
    int l = 0, finished = 0, valid;
    char command[1001];

    while(!finished){
        do{
            read_command(command);

            valid = valid_command(command);
            if(valid == 0)
                printf("Invalid comand!\n");

        }while(!valid);

        if(strcmp(command, "exit") == 0)
            finished = 1;
    }
}

void read_command(char command[1001]){
    printf(">>> ");
    get_command(command);
}