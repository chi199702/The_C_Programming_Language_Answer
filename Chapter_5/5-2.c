/**
 * 练习 5-2：模仿函数 getint 的实现方法，编写一个读取浮点数的函数 getfloat。getfloat 函数的返回值应该是什么类型？
 * */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(float *pn) {
    int c, sign;
    float power;

    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
	ungetch(c);
	return 0;
    }
    sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-') {
	c = getch();
    }
    for (*pn = 0.0; isdigit(c); c = getch()) {
	*pn = *pn * 10 + (c - '0');
    }
    if (c == '.') {
	c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch()) {
	*pn = *pn * 10 + (c - '0');
	power *= 10;
    }
    *pn *= sign / power;
    if (c != EOF) {
	ungetch(c);
    }
    return c;
}
