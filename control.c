/* Project started: 5/13/21
 * Name: Zachary Santamaria */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* marco declaration */
#define MAX_BUFFER_SIZE 1024

/* enum declaration */
enum { Success, Failure }; /*General Success or Failure*/

/* Structure declaration */
typedef struct {
    char *website;
    char *user;
    char *password;
    char *description;
} Account;

typedef struct Database Database;

struct Database { 
    int number_of_acc;
    int curr_size_of_acc;
    Account **accounts;
};

/* function declaration */
static void menu_startup();
static void menu_help();
/*static int write_database(Database *db, FILE *fp);*/
static int load_database(Database *db, FILE *fp);


void
menu_help() {
    printf("You have either entered in something incorrectly or asked for help.\n");
    printf("Usage: /control Will create a brand new database from sratch.\n");
    printf("Usage: /control <DATABASE> Will load the database\n");
}

void 
menu_startup() {
    /*printf("");*/
}

/*int write_database(Database *db, FILE *fp) {*/

    /*return Success;*/

/*}*/

int 
load_database(Database *db, FILE *fp) {
    char line[MAX_BUFFER_SIZE-1], website[MAX_BUFFER_SIZE-1], username[MAX_BUFFER_SIZE-1], password[MAX_BUFFER_SIZE-1], description[MAX_BUFFER_SIZE-1];
    Account acc;

    if (db->number_of_acc == 0)
        db->accounts = malloc(5*sizeof(acc));

    while(fscanf(fp, "%s %s %s", website, username, password ) == 3) {

        if(db->number_of_acc <= db->curr_size_of_acc) {
            db->accounts = realloc(db->accounts, 2*db->number_of_acc*sizeof(acc)); 
            db->number_of_acc = db->number_of_acc * 2;
        }


        acc.website = strdup(website);
        acc.user = strdup(username);
        acc.password = strdup(password);
        db->accounts[db->curr_size_of_acc] = malloc(sizeof(acc));
        db->accounts[db->curr_size_of_acc] = acc;


        db->curr_size_of_acc += 1;
    }

    return Success;
}


int 
main(int argc, char *argv[]) {
    FILE *fp;
    /*char *password;*/

    menu_startup();

    if (argc == 1) {
        printf("We will begin creating your database.\n");
        return Success;
        


    } else if (argc == 2) {
        if((fp = fopen(argv[1], "r+")) == NULL) {
            perror("");

            return Failure;
        } else {
            struct Database db = {0, 0, NULL};


            load_database(&db, fp);
            printf("number of accounts is %d\n", db.number_of_acc);
        }

    } else {
        menu_help();
        return Failure;
    }

    fclose(fp);

    return Success;
}
