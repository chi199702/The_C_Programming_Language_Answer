/**
 * 练习 4-11：修改 getop 函数，使其不必使用 ungetch 函数。提示：可以使用一个 static 类型的内部变量来解决问题。
 * */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);

int getop(char s[]) {
    int c, i;
    static int lastc = 0;

    if (lastc == 0) {
	c = getch();
    }else {
	c = lastc;
	lastc = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t') {
	c = getch();
    }

    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
	return c;
    }
    i = 0;
    if (isdigit(c)) {
	while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
	while (isdigit(s[++i] = c = getch()));
    } 
    s[i] = '\0';
    if (c != EOF) {
	lastc = c;
    }
    return NUMBER;
}
