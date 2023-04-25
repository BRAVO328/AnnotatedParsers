#include <stdio.h>

/*  The error and input variables are loaded globally.
    This is so you don't have to pass them through repeatedly.
*/
int *g_error;
char *g_input;

void main(){
    /*  Assigning a value to the input.
        Later on I'll show you how to add user input but it's not important at this stage.
        It then prints the input all one one line.
    */
    char *g_input = "( 10 + 2 ) * 3 / 4";
    printf("    The input is: %s\n", g_input);

    /*  As we didn't assign a value to *g_error it's null.
        "!g_error" means the value does not exist.
        As a result it will run as long as no value is assigned to it.
    */
    while(!g_error){
        /*  This loop runs as long as a value exists.
            At the end of a string there is a null value.
            When the pointer hits the value the script will end.
        */
        if(*g_input){
            while(*g_input){
                /*  This prints the character and then moves the character along.
                    "++g_input" adds one to the pointer position.
                */
                printf("Character found: %c\n", *g_input);
                ++g_input;
            }
        }
        else{
            break;
        }
    }
    printf("***** END *****\n");
}