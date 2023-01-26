#include <stdio.h>

/**
 * 练习 2-2: 在不使用 && 或 || 的条件下编写一个与上面的 for 循环语句等价的循环语句。
 * */

// 原来的 for 循环语句
for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)

// 与之等价的循环语句
enum loop { NO, Yes };
enum loop okloop = YES;

i = 0;
while (okloop == YES) {
    if (i >= lim - 1) {
	okloop = NO;
    }else if ((c = getchar()) == '\n') {
	okloop = NO;
    }else if(c == EOF) {
	okloop = NO;
    }else {
	s[i] = c;
	++i;
    }
}
