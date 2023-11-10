#include <string.h>

int valid_command(char command[1001]){
    if(strcmp(command, "add") != 0 && strcmp(command, "exit") != 0)
        return 0;

    return 1;
}