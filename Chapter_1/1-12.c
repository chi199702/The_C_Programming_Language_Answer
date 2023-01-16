#include <stdio.h>

/**
 * 练习 1-12：编写一个程序，以每行一个单词的形式打印其输入
 * */

#define IN  1
#define OUT 0

int main(int argc, char* argv[]) {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {  // 到了单词尾部
                state = OUT;
                printf("\n");
            }
        }else if (state == OUT) {   // 一个单词的开端
            state = IN;
            putchar(c);
        }else { // 在单词内部
            putchar(c);
        }
    }
}