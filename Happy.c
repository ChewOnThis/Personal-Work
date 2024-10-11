#include <cs50.h>
#include <stdio.h>
int main(){./
    string b = get_string("Please enter your name\n");
    printf("hello, %s,\n",b);
    int a = get_int("How are you today? Enter 1 if you are happy or 2 if you are sad: \n");


    if (a == 1) {
        printf("I am happy that you are happy\n");
    } else if (a == 2){
        printf("I hope your day will get better");
    }



    return 0;
}
