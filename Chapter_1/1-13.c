#include <stdio.h>

/**
 * 练习 1-13：编写一个程序，打印输入中单词长度的直方图。水平方向的直方图比较容易绘制，垂直方向的直方图则要困难些。
 * */

#define MAXHIST 15  // 直方图的最大长度
#define MAXWORD 11  // 单词的最大长度
#define IN      1   // 单词内部
#define OUT     0   // 单词外部

int main(int argc, char* argv[]) {
    int c, i, nc, state;
    int len;            // 每一个直方图条的长度
    int maxvalue;       // 所统计单词的最大长度
    int ovflow;         // 超出 MAXWORD 长度的单词的数量
    int wl[MAXWORD];    // 每种长度的单词的出现次数

    state = OUT;
    nc = 0;             // 记录单词的长度
    ovflow = 0;
    for (i = 0; i < MAXWORD; ++i) {
        wl[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nc > 0) {  // 说明单词已结束
                if (nc < MAXWORD) {
                    ++wl[nc];
                }else {
                    ++ovflow;
                }
            }
            nc = 0;
        }else if (state == OUT) {
            state = IN;
            nc = 1;
        }else {
            ++nc;
        }
    }
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i) {
        if (wl[i] > maxvalue) {
            maxvalue = wl[i];
        }
    }
    for (i = 1; i < MAXWORD; ++i) {
        printf("%5d - %5d:", i, wl[i]);
        if (wl[i] > 0) {
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0) {  // 求比例
                len = 1;
            }
        }else {
            len = 0;
        }
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    if (ovflow > 0) {
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    }

    // 垂直打印直方图
    printf("垂直打印直方图\n");
    int j;
    for (i = MAXHIST; i > 0; --i) {
        for (j = 1; j < MAXWORD; ++j) {
            if (wl[j] * MAXHIST / maxvalue >= i) {
                printf(" * ");
            }else {
                printf("   ");
            }
        }
        putchar('\n');
    }
    for (i = 1; i < MAXWORD; ++i) {
        printf("%2d ", wl[i]);
    }
    putchar('\n');
    for (i = 1; i < MAXWORD; ++i) {
        printf("%2d ", i);
    }
    putchar('\n');
    if (ovflow > 0) {
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    }
    return 0;
}

/**
[cwm@kunpeng Chapter_1]$ ./test
123 1234 asdfsdf 12341234 123 11 2 13
    1 -     1:*******
    2 -     2:***************
    3 -     2:***************
    4 -     1:*******
    5 -     0:
    6 -     0:
    7 -     1:*******
    8 -     1:*******
    9 -     0:
   10 -     0:
垂直打印直方图
    *  *                      
    *  *                      
    *  *                      
    *  *                      
    *  *                      
    *  *                      
    *  *                      
    *  *                      
 *  *  *  *        *  *       
 *  *  *  *        *  *       
 *  *  *  *        *  *       
 *  *  *  *        *  *       
 *  *  *  *        *  *       
 *  *  *  *        *  *       
 *  *  *  *        *  *       
 1  2  2  1  0  0  1  1  0  0 
 1  2  3  4  5  6  7  8  9 10
 * */
