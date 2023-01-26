/**
 * 练习 4-5: 给计算器程序增加访问 sin、exp 和 pow 等库函数的操作。有关这些库函数的详细信息，请参见附录 B.4 节(《C程序设计语言(第2版·新版)》第 228 页)中的头文件<math.h>。
 * */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXOP  100
#define NUMBER '0'
#define NAME   'n'

int    getop(char []);
void   push(double);
double pop(void);
void   mathfnc(char []);

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
	switch (type) {
	    case NUMBER:
		push(atof(s));
		break;
	    case '+':
		push(pop() + pop());
		break;
	    case '*':
		push(pop() + pop());
		break;
	    case '-':
		op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
		op2 = pop();
		if (op2 != 0.0) {
		    push(pop() / op2);
		}else {
		    printf("error: zero divisor\n");
		}
		break;
	    case NAME:
		mathfnc(s);
		break;
	    case '\n':
		printf("\t%.8g\n", pop());
		break;
	    default:
		printf("error: unknown command %s\n", s);
		break;
	}		
    }
    return 0;
}

void mathfnc(char s[]) {
    double op2;
    
    if (strcmp(s, "sin") == 0) {
	push(sin(pop()));
    }else if (strcmp(s, "cos") == 0) {
	push(cos(pop()));
    }else if (strcmp(s, "exp") == 0) {
	push(exp(pop()));
    }else if (strcmp(s, "pow") == 0) {
	op2 = pop();
	push(pow(pop(), op2));
    }else {
	printf("error: %s not supported\n", s);
    }
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME 'n'

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int c, i;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
    if (islower(c)) {
	while (islower(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF) {
	    ungetch(c);
	}
	if (strlen(s) > 1) {
	    return NAME;
	}else {
	    return c;
	}
	
    }
    if (!isdigit(c) && c != '.' && c != '-') {
	return c;
    }
    if (c == '-') {
	if (isdigit(c = getch()) || c == '.') {
	   s[++i] = c; 
	}else {
	    if (c != EOF) {
		ungetch(c);
	    }
	    return '-';
	}
    }
    if (isdigit(c)) {
	while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
	while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) { // 因为最后一个插入 s[] 的字符是多余的
	ungetch(c);
    }
    return NUMBER;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
	val[sp++] = f;
    }else {
	printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
	return val[--sp];
    }else {
	printf("error: stack empty\n");
	return 0.0;
    }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int  bufp = 0;

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
