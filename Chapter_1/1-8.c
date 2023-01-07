#include <stdio.h>

/**
 * 练习 1-8：编写一个统计空格、制表符与换行符个数的程序
 * */
int main(int argc, char* argv[]) {
    int c;  // 注意这里不能写成 char c; 否则 Ctrl + D 不会被识别成 EOF
    int space, tab, line;

    space = tab = line = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++space;
        }else if (c == '\t') {
            ++tab;
        }else if (c == '\n') {
            ++line;
        }
    }

    printf("%d, %d, %d\n", space, tab, line);
    return 0;
}

/**
输入：
1234    abc 567 def
hello,world
        111
123

输出：
14, 1, 4
 * */