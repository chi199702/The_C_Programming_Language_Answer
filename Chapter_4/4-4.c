/**
 * 练习 4-4: 在栈操作中添加几个命令，分别用于在不弹出元素的情况下打印栈顶元素；复制栈顶元素；交换栈顶两个元素的值。另外增加一个命令用于清空栈。
 * */
#include <stdio.h>
#include <math.h>

#define MAXOP  100
#define NUMBER '0'

int    getop(char []);
void   push(double);
double pop(void);
void clear(void);

int main() {
    int type;
    double op1, op2;
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
		push(pop() * pop());
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
	    case '?':
		op2 = pop();
		printf("\t%.8g\n", op2);
		push(op2);
		break;
	    case 'c':
		clear();
		break;
	    case 'd':
		op2 = pop();
		push(op2);
		push(op2);
		break;
	    case 's':
		op1 = pop();
		op2 = pop();
		push(op1);
		push(op2);
		break;
	    case '\n':
		printf("\t%.8g\n", pop());
		break;
	    default:
		printf("error: unknown command %s\n", s);
	}
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int c, i;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
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

void clear(void) {
    sp = 0;
}
