#include <stdio.h>
#include "service.h"
#include "test.h"

int main(){
    int ok;
    ok = runTests();

    if(ok)
        run_menu();
    else printf("Tests Failed!\n");

    return 0;
}