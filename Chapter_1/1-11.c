#include <stdio.h>

/**
 * 练习 1-11：你准备如何测试单词计数程序？如果程序中存在某种错误，那么什么样的输入最可能发现这类错误呢？
 * */

#define IN  1
#define OUT 0

int main(int argc, char* argv[]) {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d, %d, %d\n", nl, nw, nc);
    return 0;
}

/**
 * 输入可以是：
 * 1. 无输入
 * 2. 没有单词，只有换行符
 * 3. 没有单词，只有空格、制表符、换行符
 * 4. 每个单词各占一行的情况
 * 5. 单词出现与文本行行首的情况
 * 6. 单词出现于一串空格之后的情况
 * */