#include <stdio.h>

/* enum declaration */
enum { Success, Failure}; /*General Sucess or failure*/


/* function declaration */
static void menu ();

void 
menu() {
    printf("This is testing the menu system.");
}


int 
main() {
    menu();

    return Success;
}
