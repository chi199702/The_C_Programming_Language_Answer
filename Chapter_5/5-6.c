/**
 * 练习 5-6：采用指针而非数组索引方式改写前面章节和练习中的某些程序，例如 getline(第 1、4 章)，atoi、itoa 以及它们的变体形式(第 2、3、4 章)、reverse(第 3 章)、strindex、getop(第 4 章)等等。
 * */
#include <stdio.h>

int getline(char* s, int lim) {
    int c;
    char* t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
	*s++ = c;
    }
    if (c == '\n') {
	*s++ = c;
    }
    *s = '\0';
    return s - t;
}

#include <ctype.h>

int atoi(char* s) {
    int n, sign;
    for (; isspace(*s); ++s);
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') {
	s++;
    }
    for (n = 0; isdigit(*s); s++) {
	n = 10 * n + *s - '0';
    }
    return sign * n;
}

void reverse(char* s);
void itoa(int n, char* s) {
    int sign;
    char* t = s;
    if ((sign = n) < 0) {
	n = -n;
    }
    do {
	*s++ = n % 10 + '0';
    }while ((n /= 10) > 0);
    if (sign < 0) {
	*s++ = '-';
    }
    *s = '\0';
    reverse(t);
}

#include <string.h>

void reverse(char* s) {
    int c;
    char* t;

    for (t = s + (strlen(s) - 1); s < t; s++, t--) {
	c = *s;
	*s = *t;
	*t = c;
    }
}

int strindex(char* s, char* t) {
    char* b = s;
    char* p, *r;

    for (; *s != '\0'; s++) {
	for (p = s, r = t; *r != '\0' && *p == *r; p++, r++);
	if (r > t && *r == '\0') {
	    return s - b;
	}
    }
    return -1;
}

#include <ctype.h>

double atof(char* s) {
    double val, power;
    int sign;

    for (; isspace(*s); s++);
    sign = *s == '-' ? -1 : 1;
    if (*s == '+' || *s == '-') {
	s++;
    }
    for (val = 0.0; isdigit(*s); s++) {
	val = val * 10.0 + (*s - '0');
    }
    if (*s == '.') {
	s++;
    }
    for (power = 1.0; isdigit(*s); s++) {
	val = val * 10.0 + (*s - '0');
	power *= 10.0;
    }
    return sign * val / power;
}

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
int ungetch(int);

int getop(char* s) {
    int c;
    
    while ((*s = c = getch()) == ' ' || c == '\t');
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.') {
	return c;
    }
    if (isdigit(c)) {
	while (isdigit(*++s = c = getch()));
    }
    if (c == '.') {
	while (isdigit(*++s = c = getch()));
    }

    *s = '\0';
    if (c != EOF) {
	ungetch(c);
    }
    return NUMBER;
}
