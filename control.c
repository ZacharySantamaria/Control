/* Project started: 5/13/21
 * Name: Zachary Santamaria */

#include <stdio.h>
#include <stdlib.h>

/* enum declaration */
enum { Success, Failure }; /*General Sucess or Failure*/


/* function declaration */
static void menu_startup();
static void menu_help();


void
menu_help() {
    printf("You have either entered in something incorrectly or asked for help.\n");
    printf("Usage: /control Will create a brand new database from sratch.\n");
    printf("Usage: /control <DATABASE> Will load the database\n");
}

void 
menu_startup() {
    printf("");
}


int 
main(int argc, char *argv[]) {
    FILE *fp;

    menu_startup();

    if (argc == 1) {
        printf("What would you like the keyword to be?");

    } else if (argc == 2) {
        if((fp = fopen(argv[1], "r+")) == NULL) {
            perror("");

            return Failure;
        }

    } else {
        menu_help();
    }

    fclose(fp);

    return Success;
}
