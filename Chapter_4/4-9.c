/**
 * 练习 4-9: 以上介绍的 getch 和 ungetch 函数不能正确地处理压回的 EOF。考虑压回 EOF 时应该如何处理。请实现你的方案。
 * */

#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
	printf("ungetch: too many characters\n");
    }else {
	buf[bufp++] = c;
    }
}
