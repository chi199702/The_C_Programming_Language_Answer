#include <stdio.h>

/**
 * 练习 1-24: 编写一个程序，查找 C 语言程序中的基本语法错误，如圆括号、方括号以及花括号不配对等。要正确处理引号(包括单引号和双引号)、转义字符序列与注释。(如果读者想把该程序编写成完全通用的程序，难度会比较大。)
 * */

int brace, brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

int main() {
    int c;
    extern int brace, brack, paren;
    while ((c = getchar()) != EOF) {
	if (c == '/') {
	    if ((c = getchar()) == '*') {
		in_comment();
	    }else {
		search(c);
	    }
	}else if (c == '\'' || c == '"') {
	    in_quote(c);
	}else {
	    search(c);
	}

	if (brace < 0) {
	    printf("Unbalanced braces\n");
	    brace = 0;
	}else if (brack < 0) {
	    printf("Unbalanced brackets\n");
	    brack = 0;
	}else if (paren < 0) {
	    printf("Unbalanced parentheses\n");
	    paren = 0;
	}
    }
    if (brace > 0) {
	printf("Unbalanced braces\n");
    }
    if (brack > 0) {
	printf("Unbalanced brackets\n");
    }
    if (paren > 0) {
	printf("Unbalanced parentheses\n");
    }
    return 0;
}

void search(int c) {
    extern int brace, brack, paren;
    if (c == '{') {
	++brace;
    }else if (c == '}') {
	--brace;
    }else if (c == '[') {
	++brack;
    }else if (c == ']') {
	--brace;
    }else if (c == '(') {
	++paren;
    }else if (c == ')') {
	--paren;
    }
}

void in_comment(void) {
    int c, d;
    c = getchar();
    d = getchar();
    while (c != '*' || d == '/') {
	c = d;
	d = getchar();
    }
}

void in_quote(int c) {
    int d;
    while ((d = getchar()) != c) {
	if (d == '\\') {
	    getchar();
	}
    }
}
