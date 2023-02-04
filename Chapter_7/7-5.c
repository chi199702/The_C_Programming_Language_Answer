/**
 * 练习 7-5：改写第 4 章中的后缀计数器程序，用 scanf 函数和（或）sscanf 函数实现输入以及数的转换
 * */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getop(char s[]) {
    int c, i, rc;
    static char lastc[] = " ";

    sscanf(lastc, "%c", &c);
    lastc[0] = ' ';
    while ((s[0] = c) == ' ' || c == '\t') {
	if (scanf("%c", &c) == EOF) {
	    c = EOF;
	}
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
	return c;
    } 
    if (isdigit(c)) {
	do {
	    rc = scanf("%c", &c);
	    if (!isdigit(s[++i] = c)) {
		break;
	    }
	}while (rc != EOF);
    }
    if (c == '.') {
	do {
	    rc = scanf("%c", &c);
	    if (!isdigit(s[++i] = c)) {
		break;
	    }
	}while (rc != EOF);
    }
    s[i] = '\0';
    if (rc != EOF) {
	lastc[0] = c;
    }
    return NUMBER;
}
