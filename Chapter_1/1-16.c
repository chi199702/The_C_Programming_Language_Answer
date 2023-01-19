#include <stdio.h>

/**
 *  练习 1-16: 修改打印最长文本行的程序的主程序 main，使之可以打印任意长度的输入行的长度，并尽可能多地打印文本。
 * */

#define MAXLINE 1000

int getaline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;	    // 当前行长度
    int max;	    // 目前为止发现的最长行的长度
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getaline(line, MAXLINE)) > 0) {
	printf("%s\n", line);
	if (len > max) {
	    max = len;
	    copy(longest, line);
	}
    }
    if (max > 0) {
	printf("%s", longest);
    }
    return 0;
}

int getaline(char line[], int maxvalue) {
    int c, i;
    for (i = 0; i < maxvalue - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {		// 注意：这里 i 的循环范围，必须留 1 个位置放置 '\0'
	line[i] = c;
    }
    if (c == '\n') {
	line[i] = '\n';
	++i;
    }
    line[i] = '\0';	// 对于初学者来说，容易忘记为字符数组添加结束符号 '\0'
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
	++i;
    }
}
