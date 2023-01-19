#include <stdio.h>

/**
 * 练习 1-18: 编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行。
 * */

#define MAXLINE 1000

int mygetline(char line[], int maxvalue);
int myremove(char s[]);

int main() {
    char line[MAXLINE];
    while (mygetline(line, MAXLINE) > 0) {
	if (myremove(line) > 0) {
	    printf("%s", line);
	}
    } 
    return 0;
}

int mygetline(char line[], int maxvalue) {
    char c;
    int i;
    
    for (i = 0; i < maxvalue - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;
    }
    if (c == '\n') {
	line[i] = '\n';
	++i;
    } 
    line[i] = '\0';
    return i;
}

int myremove(char s[]) {
    int i = 0;
    while (s[i] != '\n') {
	++i;	
    }
    --i;
    while (i >=0 && (s[i] == ' ' || s[i] == '\t')) {
	--i;
    }
    if (i >= 0) {
	++i;
	s[i] = '\n';
	++i;
	s[i] = '\0';
    }
    return i; 
}
