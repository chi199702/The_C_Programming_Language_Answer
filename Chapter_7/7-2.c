/**
 * 练习 7-2：编写一个程序，以合理的方式打印任何输入。该程序至少能根据用户的习惯以八进制或十六进制打印非显示字符，并截断长文本行。
 * */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define DCTLEN  6

int main() {
    int c, pos;
    int inc(int pos, int n);

    pos = 0;
    while ((c = getchar()) != EOF) {
	if (iscntrl(c) || c == ' ') {
	    pos = inc(pos, DCTLEN);
	    printf(" \\%03o ", c);
	    if (c == '\n') {
		pos = 0;
		putchar('\n');
	    }else {
		pos = inc(pos, 1);
		putchar(c);
	    }
	}
    }
    return 0;
}

int inc(int pos, int n) {
    if (pos + n < MAXLINE) {
	return pos + n;
    }else {
	putchar('\n');
	return n;
    }
}
