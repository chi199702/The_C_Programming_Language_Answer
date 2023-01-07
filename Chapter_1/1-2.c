#include <stdio.h>

/**
 * 练习 1-2：做个实验，当 printf 函数的参数字符串包含 \c (其中 c 是上面的转义字符序列中未曾列出的某个字符)时，观察一下会出现什么情况。
 * */
int main(int argc, char* argv[]) {
    printf("hello,world\7\n");
    printf("hello,world\c\n");
    printf("hello,world\y\n");
    return 0;
}

/**
hello,world
hello,worldc
hello,worldy
 * */