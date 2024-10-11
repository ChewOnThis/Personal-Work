#include <stdio.h>

// ANSI color codes
#define ANSI_RESET          "\x1b[0m"
#define ANSI_BOLD           "\x1b[1m"
#define ANSI_DIM            "\x1b[2m"
#define ANSI_UNDERLINE      "\x1b[4m"
#define ANSI_BLINK          "\x1b[5m"
#define ANSI_REVERSE        "\x1b[7m"
#define ANSI_HIDDEN         "\x1b[8m"

#define ANSI_BLACK          "\x1b[30m"
#define ANSI_RED            "\x1b[31m"
#define ANSI_GREEN          "\x1b[32m"
#define ANSI_YELLOW         "\x1b[33m"
#define ANSI_BLUE           "\x1b[34m"
#define ANSI_MAGENTA        "\x1b[35m"
#define ANSI_CYAN           "\x1b[36m"
#define ANSI_WHITE          "\x1b[37m"

#define ANSI_BLACK_BG       "\x1b[40m"
#define ANSI_RED_BG         "\x1b[41m"
#define ANSI_GREEN_BG       "\x1b[42m"
#define ANSI_YELLOW_BG      "\x1b[43m"
#define ANSI_BLUE_BG        "\x1b[44m"
#define ANSI_MAGENTA_BG     "\x1b[45m"
#define ANSI_CYAN_BG        "\x1b[46m"
#define ANSI_WHITE_BG       "\x1b[47m"

int main() {
    printf(ANSI_BOLD "Bold:\n" ANSI_RESET);
    printf(ANSI_BOLD ANSI_BLACK "Black\n" ANSI_RESET);
    printf(ANSI_BOLD ANSI_RED "Red\n" ANSI_RESET);
    printf(ANSI_BOLD ANSI_GREEN "Green\n" ANSI_RESET);
        printf("\e[0;92mHHHHHHhhhhh");

    printf(ANSI_BOLD ANSI_YELLOW "Yellow\n" ANSI_RESET);
    printf(ANSI_BOLD ANSI_BLUE "Blue\n" ANSI_RESET);
    printf(ANSI_BOLD ANSI_MAGENTA "Magenta\n" ANSI_RESET);
    printf(ANSI_BOLD ANSI_CYAN "Cyan\n" ANSI_RESET);
    printf(ANSI_BOLD ANSI_WHITE "White\n" ANSI_RESET);

    printf("\n" ANSI_DIM "Dim:\n" ANSI_RESET);
    printf(ANSI_DIM ANSI_BLACK "Black\n" ANSI_RESET);
    printf(ANSI_DIM ANSI_RED "Red\n" ANSI_RESET);
    printf(ANSI_DIM ANSI_GREEN "Green\n" ANSI_RESET);
    printf(ANSI_DIM ANSI_YELLOW "Yellow\n" ANSI_RESET);
    printf(ANSI_DIM ANSI_BLUE "Blue\n" ANSI_RESET);
    printf(ANSI_DIM ANSI_MAGENTA "Magenta\n" ANSI_RESET);
    printf(ANSI_DIM ANSI_CYAN "Cyan\n" ANSI_RESET);
    printf(ANSI_DIM ANSI_WHITE "White\n" ANSI_RESET);

    printf("\n" ANSI_UNDERLINE "Underline:\n" ANSI_RESET);
    printf(ANSI_UNDERLINE ANSI_BLACK "Black\n" ANSI_RESET);
    printf(ANSI_UNDERLINE ANSI_RED "Red\n" ANSI_RESET);
    printf(ANSI_UNDERLINE ANSI_GREEN "Green\n" ANSI_RESET);
    printf(ANSI_UNDERLINE ANSI_YELLOW "Yellow\n" ANSI_RESET);
    printf(ANSI_UNDERLINE ANSI_BLUE "Blue\n" ANSI_RESET);
    printf(ANSI_UNDERLINE ANSI_MAGENTA "Magenta\n" ANSI_RESET);
    printf(ANSI_UNDERLINE ANSI_CYAN "Cyan\n" ANSI_RESET);
    printf(ANSI_UNDERLINE ANSI_WHITE "White\n" ANSI_RESET);

    printf("\n" ANSI_BLINK "Blink:\n" ANSI_RESET);
    printf(ANSI_BLINK ANSI_BLACK "Black\n" ANSI_RESET);
    printf(ANSI_BLINK ANSI_RED "Red\n" ANSI_RESET);
    printf(ANSI_BLINK ANSI_GREEN "Green\n" ANSI_RESET);
        printf("\e[0;92mHHHHHHhhhhh");

    printf(ANSI_BLINK ANSI_YELLOW "Yellow\n" ANSI_RESET);
    printf(ANSI_BLINK ANSI_BLUE "Blue\n" ANSI_RESET);
    printf(ANSI_BLINK ANSI_MAGENTA "Magenta\n" ANSI_RESET);
    printf(ANSI_BLINK ANSI_CYAN "Cyan\n" ANSI_RESET);
    printf(ANSI_BLINK ANSI_WHITE "White\n" ANSI_RESET);

    printf("\n" ANSI_REVERSE "Reverse:\n" ANSI_RESET);
    printf(ANSI_REVERSE ANSI_BLACK "Black\n" ANSI_RESET);
    printf(ANSI_REVERSE ANSI_RED "Red\n" ANSI_RESET);
    printf(ANSI_REVERSE ANSI_GREEN "Green\n" ANSI_RESET);
    printf(ANSI_REVERSE ANSI_YELLOW "Yellow\n" ANSI_RESET);
    printf(ANSI_REVERSE ANSI_BLUE "Blue\n" ANSI_RESET);
    printf(ANSI_REVERSE ANSI_MAGENTA "Magenta\n" ANSI_RESET);
    printf(ANSI_REVERSE ANSI_CYAN "Cyan\n" ANSI_RESET);
    printf(ANSI_REVERSE ANSI_WHITE "White\n" ANSI_RESET);

    printf("\n" ANSI_HIDDEN "Hidden:\n" ANSI_RESET);
    printf(ANSI_HIDDEN ANSI_BLACK "Black\n" ANSI_RESET);
    printf(ANSI_HIDDEN ANSI_RED "Red\n" ANSI_RESET);
    printf(ANSI_HIDDEN ANSI_GREEN "Green\n" ANSI_RESET);
    printf(ANSI_HIDDEN ANSI_YELLOW "Yellow\n" ANSI_RESET);
    printf(ANSI_HIDDEN ANSI_BLUE "Blue\n" ANSI_RESET);
    printf(ANSI_HIDDEN ANSI_MAGENTA "Magenta\n" ANSI_RESET);
    printf(ANSI_HIDDEN ANSI_CYAN "Cyan\n" ANSI_RESET);
    printf(ANSI_HIDDEN ANSI_WHITE "White\n" ANSI_RESET);

    printf("\e[0;92mHHHHHHhhhhh");

    return 0;
}
