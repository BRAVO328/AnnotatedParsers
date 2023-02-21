#include <stdio.h>
#include <stdlib.h>

//  Declaring global variables.
//  the 'g_' at the start indicates a global variable as opposed to a local variable.
char *g_cp, *g_error;
int g_result;

//  These functions have the following roles:
//  'expression'    Used for positive and negative integer values.
//  'term'          Used for multiplication and division.
//  'factor'        Used for parenthesis, addition, subtraction, and converting strings to integers.
//  'trivia'        Used for skipping spaces in text string.
void expression();
void term();
void factor();
void trivia();

void main()
{
    //  Defining the input value.
    g_cp = "(10 + 2 * 3) / 4";
    //  Defining an g_error as a null value.
    g_error = NULL;
    //  Defining the g_result value as 0.
    g_result = 0;

    // Running the expression function.
    expression();

    if (g_error)
    {
        printf("Error: %s\n", g_error);   
    }
    else
    {
        printf("Result: %i\n", g_result);
    }
}

void expression(){
    //  Starting the term function to check for division/multiplication.
    term();

    //  While a character is present, check for '+' and '-'.
    //  If found move pointer along.
    //  Start the term function.
    //  + or - the g_result from subtotal.
    //  If none found break the operation.
    while(!g_error){
        int left = g_result;
        if(*g_cp == '+'){
            ++g_cp;
            term();
            g_result = left + g_result;
        }

        else if(*g_cp == '-'){
            ++g_cp;
            term();
            g_result = left - g_result;
        }

        else{
            break;
        }
    }
}

void term(){
    //  Starting the factor function to check for brackets.
    factor();

    //  While a character is present.
    //  Assign left to g_result.
    //  Start the trivia function to check for spaces.
    //  Check for '*' or '/'.
    //  If '*':
        //  Move pointer along.
        //  Start the factor function.
        //  Times g_result by subtotal.
    //  If '/';
        //  Move pointer along.
        //  Start the factor function.
        //  Check if g_result is 0.
        //  If 0, throw an g_error and exit the program.
    while(!g_error){
        int left = g_result;
        trivia();
        
        if (*g_cp == '*'){
            ++g_cp;
            factor();
            g_result = left * g_result;
        }
        else if(*g_cp == '/'){
            ++g_cp;
            factor();
            if(g_result != 0){
                g_result = left / g_result;
            }
            else{
                g_error = "Divide by zero";
            }
        }
        else{
            break;
        }
    }
}

void factor(){
    //  Open the trivia function to check for spaces.
    //  Check for symbols.
    //  If '(' found:
        //  Move pointer along.
        //  Start expression function for grouping text inside brackets.
        //  When finished check for ')'.
        //  If found move pointer forward.
        //  If not found throw an g_error.
    //  If '+' found:
        //  Move pointer along.
        //  Open factor function to check for parenthesis.
        //  Add g_result to subtotal.
    //  If '-' found:
        //  Move pointer along.
        //  Open factor function to check for parenthesis.
        //  Subract g_result to subtotal.
    //  Check for numbers.
        //  Convert character to integer by subtracting 48 from value.
        //  Assign resulting integer to g_result.
        //  Move pointer along.
        //  While still the same number (no other characters found):
            //  Convert character to integer by subtracting 48 from value.
            //  Multiply subtotal by 10.
            //  Add resulting integer to subtotal.
            //  Move Character pointer along.
    //  If no number found throw an g_error.
    trivia();
    int left = g_result;
    if(*g_cp == '('){
        ++g_cp;
        expression();
        if(*g_cp == ')'){
            ++g_cp;
        }
        else{
            g_error = "No closing parenthesis";
        }
    }
    else if(*g_cp == '+'){
        ++g_cp;
        factor();
        g_result = left + g_result;
    }
    else if(*g_cp == '-'){
        ++g_cp;
        factor();
        g_result = left - g_result;
    }
    else if(*g_cp >='0' && *g_cp<= '9'){
        g_result = *g_cp - 48;
        ++g_cp;
        while(*g_cp >='0' && *g_cp<= '9'){
            g_result = (g_result*10) + *g_cp - 48;
            ++g_cp;
        }
    }
}

void trivia(){
    //  While the character pointer is ' ', move the pointer forward.
    while(*g_cp==' '){
        ++g_cp;
    }
}