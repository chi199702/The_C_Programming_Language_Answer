/**
 * 练习 4-10：另一种方法是通过 getline 函数读入整个输入行，这种情况下可以不使用 getch 与 ungetch 函数。请运用这一方法修改计算器程序。
 * */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define NUMBER  '0'

int mygetline(char line[], int limit);
int li = 0;
char line[MAXLINE];

int getop(char s[]) {
    int c, i;
    if (line[li] == '\0') {
	if (mygetline(line, MAXLINE) == 0) {
	    return EOF;
	}else {
	    li = 0;
	}
    }
    while ((s[0] = c = line[li++]) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
	return c;
    }
    i = 0;
    if (isdigit(c)) {
	while (isdigit(s[++i] = c = line[li++]));
    }
    if (c == '.') {
	while (isdigit(s[++i] = c = line[li++]));
    }
    s[i] = '\0';
    li--;
    return NUMBER;
}
