#include <stdio.h>

/**
 * 练习 1-19: 编写函数 reverse(s), 将字符 s 中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序。
 * */

#define MAXLINE 1000

int getaline(char line[], int maxvalue);
void reverse(char s[]);

int main() {
    int len;
    char line[MAXLINE]; 
    while ((len = getaline(line, MAXLINE)) > 0) {
	reverse(line);
	printf("%s", line);
    }
    return 0;
}

int getaline(char line[], int maxvalue) {
    char c;
    int i;
    for (i = 0; i < maxvalue - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;	
    }
    if (c == '\n') {
	line[i] = c;
	++i;
    }
    line[i] = '\0';
    return i;
}

void reverse(char s[]) {
    int j;
    j = 0;
    while (s[j] != '\0') {
	++j;
    }
    --j;
    
    int i;
    i = 0;
    while (i < j) {
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	++i;
	--j;
    }
}
