#include <stdio.h>

int *g_error;
char *g_input;

void main(){
    char *g_input = "( 10 + 2 ) * 3 / 4c";
    printf("    The input is: %s\n\n\n", g_input);

    while(!g_error){
        if(*g_input){
            while(*g_input){
                if(*g_input == ' '){
                    ++g_input;
                }
                else if(*g_input >= '0' && *g_input <= '9'){
                    int result = *g_input - 48;
                    ++g_input;
                    while(*g_input >= '0' && *g_input <= '9'){
                        result = result * 10;
                        int digit = *g_input - 48;
                        result = result + digit;
                        ++g_input;
                    }
                    printf("   Number found: %i\n", result);
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