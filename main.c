#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structures.h"
#include "headers.h"
int contacts=0;
int main()
{
    printf("\n");
    printf("\t\t\t\t    Telephone Book\\n");
    contacts=counter();
    load();
    menu();
    return 0;
}
