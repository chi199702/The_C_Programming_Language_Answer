/**
 * 练习 4-7: 编写一个函数 ungets(s)，将整个字符串 s 压回到输入中。ungets 函数需要使用 buf 和 bufp 吗？它是否仅使用 ungetch 函数？
 * */

#include <string.h>

void ungets(char s[]) {
    int len = strlen(s);
    void ungetch(int);
    while (len > 0) {
	ungetch(s[--len]);
    }
}
