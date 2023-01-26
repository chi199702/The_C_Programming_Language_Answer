/**
 * 练习 4-12：运用 printd 函数的设计思想编写一个递归版本的 itoa 函数。即通过递归调用把整数转换为字符串。
 * */

#include <math.h>

void itoa(int n, char s[]) {
    static int i;
    if (n / 10) {
	itoa(n / 10, s);
    }else {
	i = 0;
	if (n < 0) {
	    s[i++] = '-';
	}
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}
