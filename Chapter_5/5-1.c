/**
 * 练习 5-1：在上面的例子中，如果符号 + 或 - 的后面紧跟的不是数字，getint 函数将把符号视为数字 0 的有效表达方式。修改该函数，将这种形式的 + 或 - 符号重新写回到输入流中。
 * */

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
	ungetch(c);
	return 0;
    }
    
    sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-') {
	int d = c;
	if (!isdigit(c = getch())) {
	    if (c != EOF) {
		ungetch(c);
	    }
	    ungetch(d);
	    return d;
	}
    }
    for (*pn = 0; isdigit(c); c = getch()) {
	*pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
	ungetch(c);
    }
    return c;
}
