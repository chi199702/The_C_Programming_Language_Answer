#include <stdio.h>

/**
 * 练习 1-9：编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替
 * */
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