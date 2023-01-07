#include <stdio.h>

#define NONBLANK 'a'

int main(int argc, char* argv[]) {
    int lastc = NONBLANK;
    int c;
    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastc != ' ') {
            putchar(c);
        }
        lastc = c;
    }
    return 0;
}