#include <stdio.h>
#include <cs50.h>

int main()
{


    //“How are you today? Enter 1 if you are happy or 2 if you are sad”
int a = get_int("Enter a number: \n");
int b = get_int("Enter another number: \n");

int answer = a + b;

/*
if (a > 0) {
    printf("I am happy that you are happy\n");
} else {
    printf("I hope your day will get better");
}

printf("The answer to %i + %i is %i. \n",a,b,answer);
*/

return 0;
}
