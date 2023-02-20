#include <stdio.h>
#include <stdlib.h>

char *cp, *error;
int result;

void expression();
void term();
void factor();
void trivia();

void main()
{
    printf("Main function start\n");
    //  Defining the input value.
    cp = "(10 + 2 * 3) * 4";
    //  Defining an error as a null value.
    error = NULL;
    //  Defining the result value as 0.
    result = 0;

    // Running the expression function.
    expression();

    if (error)
    {
        printf("error: %s\n", error);
    }
    else
    {
        printf("result: %i\n", result);
    }
}

void expression(){
    //  Starting the term function to check for division/multiplication.
    printf("Expression function start\n");
    term();

    //  While a character is present, check for '+' and '-'.
    //  If found move pointer along.
    //  Start the term function.
    //  + or - the result from subtotal.
    //  If none found break the operation.
    while(!error){
        int left = result;
        if(*cp == '+'){
            ++cp;
            term();
            result = left + result;
        }

        else if(*cp == '+'){
            ++cp;
            term();
            result = left - result;
        }

        else{
            break;
        }
    }
}

void term(){
    printf("Term function start\n");
    //  Starting the factor function to check for brackets.
    factor();

    //  While a character is present.
    //  Assign left to result.
    //  Start the trivia function to check for spaces.
    //  Check for '*' or '/'.
    //  If '*':
        //  Move pointer along.
        //  Start the factor function.
        //  Times result by subtotal.
    //  If '/';
        //  Move pointer along.
        //  Start the factor function.
        //  Check if result is 0.
        //  If 0, throw an error and exit the program.
    while(!error){
        int left = result;
        trivia();
        
        if (*cp == '*'){
            ++cp;
            factor();
            result = left * result;
        }
        else if(*cp == '/'){
            ++cp;
            factor();
            if(result != 0){
                result = left / result;
            }
            else{
                error = "Divide by zero";
            }
        }
        else{
            break;
        }
    }
}

void factor(){
    printf("factor function start\n");
    //  Open the trivia function to check for spaces.
    //  Check for symbols.
    //  If '(' found:
        //  Move pointer along.
        //  Start expression function for grouping text inside brackets.
        //  When finished check for ')'.
        //  If found move pointer forward.
        //  If not found throw an error.
    //  If '+' found:
        //  Move pointer along.
        //  Open factor function to check for parenthesis.
        //  Add result to subtotal.
    //  If '-' found:
        //  Move pointer along.
        //  Open factor function to check for parenthesis.
        //  Subract result to subtotal.
    //  Check for numbers.
        //  Convert character to integer by subtracting 48 from value.
        //  Assign resulting integer to result.
        //  Move pointer along.
        //  While still the same number (no other characters found):
            //  Convert character to integer by subtracting 48 from value.
            //  Multiply subtotal by 10.
            //  Add resulting integer to subtotal.
            //  Move Character pointer along.
    //  If no number found throw an error.
    trivia();
    int left = result;
    if(*cp == '('){
        ++cp;
        expression();
        if(*cp == ')'){
            ++cp;
        }
        else{
            error = "No closing parenthesis";
        }
    }
    else if(*cp == '+'){
        ++cp;
        factor();
        result = left + result;
    }
    else if(*cp == '-'){
        ++cp;
        result = left - result;
    }
    else if(*cp >='0' && *cp<= '9'){
        result = *cp - 48;
        ++cp;
        while(*cp >='0' && *cp<= '9'){
            result = (result*10) + *cp - 48;
            ++cp;
        }
    }
}

void trivia(){
    printf("Trivia function start\n");
    //  While the character pointer is ' ', move the pointer forward.
    while(*cp==' '){
        ++cp;
    }
}