#include <stdio.h>

/**
 * 练习 1-17: 编写一个程序，打印长度大于 80 个字符的所有输入行
 * */

#define MAXLINE 1000
#define LIMIT   80

int getaline(char line[], int maxvalue);

int main() {
    int len;
    char line[MAXLINE];
    while ((len = getaline(line, MAXLINE)) > 0) {
	if (len > 80) {
	    printf("%s", line);
	}
    }
    return 0;
}

int getaline(char line[], int maxvalue) {
    int i, c;
    for (i = 0; i < maxvalue - 1 && (c = getchar()) != EOF &&  c != '\n'; ++i) {
	line[i] = c;	
    }
    if (c == '\n') {
	line[i] = '\n';
	++i;
    }
    line[i] = '\0';
    return i;
}
