/**
 * 练习：编写一个递归版本的 reverse(s) 函数，以将字符串 s 倒置。
 * */

#include <string.h>

void reverse(char s[]) {
    void reverser(char s[], int i, int len);
    reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len) {
    int c, j;
    j = len - (i + 1);
    if (i < j) {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
	reverser(s, ++i, len);
    }
}
