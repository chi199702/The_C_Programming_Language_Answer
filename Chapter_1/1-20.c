#include <stdio.h>

/**
 * 练习 1-20: 请编写程序 detab, 将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方。假设制表符终止位的位置是固定的，比如每隔 n 列就会出现一个制表符终止位。n 应该作为变量还是符号常量呢？
 **/

#define TABINC 8

int main() {
    int c, nb, pos;
    nb = 0;
    pos = 1;
    while ((c = getchar()) != EOF) {
	if (c == '\t') {
	    nb = TABINC - (pos - 1) % TABINC;
	    while (nb > 0) {
		putchar(' ');
		++pos;
		--nb;
	    }
	} else if (c == '\n') {
	    putchar(c);
	    pos = 1;
	} else {
	    putchar(c);
	    ++pos;
	}
    }
    return 0;
}
