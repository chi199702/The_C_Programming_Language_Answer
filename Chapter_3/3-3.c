#include <stdio.h>

/**
 * 练习 3-3: 编写函数 expand(s1, s2), 将字符串 s1 中类似于 a-z 一类的速记符号在字符串 s2 中扩展为等价的完整列表 abc...xyz。该函数可以处理大小写字母和数字，并可以处理 a-b-c、a-z0-9 与 a-z 等类似的情况。作为前导和尾随的字符原样复制。
 * */

void expand(char s1[], char s2[]) {
    char c;
    int i, j;
    i = j = 0;
    while ((c = s1[i++]) != '\0') {
	if (s1[i] == '-' && s1[i + 1] >= c) {
	    i++;
	    while (c < s1[i]) {
		s2[j++] = c++;
	    }
	}else {
	    s2[j++] = c;
	}
    }
    s2[j] = '\0';
}
