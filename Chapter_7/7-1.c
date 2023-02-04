/**
 * 练习 7-1：编写一个程序，根据它自身被调用时存放在 argv[0] 中的名字，实现将大写字母转换为小写字母或将小写字母转换为大写字母的功能。
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    int c;
    if (strcmp(argv[0], "lower") == 0) {
	while ((c = getchar()) != EOF) {
	    putchar(tolower(c));
	}
    }else {
	while ((c = getchar()) != EOF) {
	    putchar(toupper(c));
	}
    }
    return 0;
}
