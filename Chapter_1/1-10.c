#include <stdio.h>

/**
 * 练习 1-10：编写一个将输入复制到输出的程序，并将其中的制表符替换为 \t，将回退符替换为 \b，将反斜杠替换为 \\。这样可以将制表符和回退符以可见的方式显示出来。
 * */
int main(int argc, char* argv[]) {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        }else if (c == '\b') {
            printf("\\b");
        }else if (c == '\\') {
            printf("\\\\");
        }else {
            putchar(c);
        }
    }
    return 0;
}