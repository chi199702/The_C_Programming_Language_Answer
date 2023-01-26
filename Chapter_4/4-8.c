/**
 * 练习 4-8: 假定最多只压回一个字符，请相应地修改 getch 和 ungetch 这两个函数
 * */

#include <stdio.h>

char buf = 0;

int getch(void) {
    int c;
    if (buf != 0) {
	c = buf;
    }else {
	c = getchar();
    }
    buf = 0;
    return c;
}

void ungetch(int c) {
    if (buf != 0) {
	printf("ungetch: too many characters\n");
    }else {
	buf = c;
    }
}

