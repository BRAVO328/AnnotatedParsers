#include <stdio.h>

int *g_error;
char *g_input;

void main(){
    char *g_input = "( 10 + 2 ) * 3 / 4";
    printf("    The input is: %s\n\n\n", g_input);

    while(!g_error){
        if(*g_input){
            while(*g_input){
                /*The following code:
                        Reads the character,
                        Prints the type of character,
                        Moves the pointer along.
                    If the character is a space it moves the pointer along to skip it.
                */
                if(*g_input == ' '){
                    ++g_input;
                }
                else if(*g_input >= '0' && * g_input <= '9'){
                    printf("Number found: %c\n", *g_input);
                    ++g_input;
                }
                else if (*g_input == '*' || *g_input == '/' || *g_input == '+' || *g_input == '-' || *g_input == '(' || *g_input == ')'){
                    printf(" Operator found: %c\n", *g_input);
                    ++g_input;
                }
                else{
                printf("Character found: %c\n", *g_input);
                ++g_input;
                }
            }
        }
        else{
            break;
        }
    }
    printf("\n\n***** END *****\n");
}