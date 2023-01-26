#include <stdio.h>

/**
 * 练习 3-4: 在数的二进制补码表示中，我们编写的 itoa 函数不能处理最大的负数，即 n 等于 -(2^(字长-1))的情况。请解释其原因。修改该函数，使它在任何机器上运行时都能打印出正确的值。
 * */

// 原因: 负数表示范围中正数范围 < 负数范围

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[]) {
    int i, sign;
    void reverse(char s[]);
    sign = n;
    i = 0;
    do {
	s[i++] = abs(n % 10) + '0';
    }while ((n /= 10) != 0);
    if (sign < 0) {
	s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

