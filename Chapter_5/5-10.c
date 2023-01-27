/**
 * 练习 5-10：编写程序 expr，以计算从命令行输入的逆波兰表达式的值，其中每个运算符或操作数用一个单独的参数表示。例如命令：expr 2 3 4 + * 将计算表达式 2 x (3 + 4) 的值。
 * */

#include <stdio.h>
#include <math.h>

#define MAXOP  100
#define NUMBER '0'

int getop(char []);
void ungets(char []);
void push(double);
double pop(void);

int main(int argc, char* argv[]) {
    char s[MAXOP];
    double op2;

    while (--argc > 0) {
	ungets(" ");
	ungets(*++argv);
	switch (getop(s)) {
	    case NUMBER:
		push(atof(s));
		break;
	    case '+':
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
	    default:
		printf("error: unknown command %s\n", s);
		argc = 1;
		break;
	}
    }
    printf("\t%.8g\n", pop());
    return 0;
}
