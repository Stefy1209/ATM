#include <stdio.h>
#include <string.h>

void get_command(char command[1001]){
    strcpy(command, "");
    scanf("%s", command);
}