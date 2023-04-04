# 《C程序设计语言》的课后习题答案
布莱恩·W.克尼汉(Brian W.Kernighan)<br/>
丹尼斯·M.里奇(Dennis M.Ritchie)<br/>
徐宝文 李志 译 尤晋元 审校<br/>

------

![image](https://raw.githubusercontent.com/chi199702/The_C_Programming_Language_Answer/main/IMG/book.jpg_.webp)

实验机器：<br/>
NAME="CentOS Linux"<br/>
VERSION="7 (AltArch)"<br/>
ID="centos"<br/>
ID_LIKE="rhel fedora"<br/>
VERSION_ID="7"<br/>
PRETTY_NAME="CentOS Linux 7 (AltArch)"<br/>
Linux kunpeng 5.4.0 #1 SMP Tue Dec 27 11:19:47 CST 2022 aarch64 aarch64 aarch64 GNU/Linux

------
[TOC]



## 第一章 导言

### 1.1

在你自己的系统中运行 “hello, world” 程序。再有意去掉程序中的部分内容，看看会得到什么出错信息。

```c
#include <stdio.h>

/**
 * 最伟大的程序
 * */

/**
 * 练习 1-1：在你自己的系统中运行 "hello, world" 程序。再有意去掉程序中的部分内容，看看会得到什么出错信息。
 * */
int main(int argc, char* argv[]) {
    printf("hello,world\n");
    return 0;
}

/**
hello,world
 * */
```

### 1-2

做个实验，当 printf 函数的参数字符串包含 \c (其中 c 是上面的转义字符序列中未曾列出的某个字符)时，观察一下会出现什么情况。

```c
#include <stdio.h>

/**
 * 练习 1-2：做个实验，当 printf 函数的参数字符串包含 \c (其中 c 是上面的转义字符序列中未曾列出的某个字符)时，观察一下会出现什么情况。
 * */
int main(int argc, char* argv[]) {
    printf("hello,world\7\n");
    printf("hello,world\c\n");
    printf("hello,world\y\n");
    return 0;
}

/**
hello,world
hello,worldc
hello,worldy
 * */
```

### 1-3

修改温度转换程序，使之能在转换表的顶部打印一个标题

```c
#include <stdio.h>

/**
 * 练习 1-3：修改温度转换程序，使之能在转换表的顶部打印一个标题
 * */
main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("温度转换表\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

/**
温度转换表
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
 * */
```

### 1-4

编写一个程序打印摄氏温度转换为相应华氏温度的转换表

```c
#include <stdio.h>

/**
 * 练习 1-4：编写一个程序打印摄氏温度转换为相应华氏温度的转换表
 * */
int main(int argc, char* argv[]) {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("摄氏度转换为华氏度\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 * celsius) / 5.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}

/**
氏度转换为华氏度
  0   32.0
 20   68.0
 40  104.0
 60  140.0
 80  176.0
100  212.0
120  248.0
140  284.0
160  320.0
180  356.0
200  392.0
220  428.0
240  464.0
260  500.0
280  536.0
300  572.0
 * */
```

### 1-5

修改温度转换程序，要求以逆序（即按照从 300 度到 0 度的顺序）打印温度转换表

```c
#include <stdio.h>

/**
 * 练习 1-5：修改温度转换程序，要求以逆序（即按照从 300 度到 0 度的顺序）打印温度转换表
 * */
main() {
    int fahr;
    for (fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    return 0;
}

/**
300  148.9
280  137.8
260  126.7
240  115.6
220  104.4
200   93.3
180   82.2
160   71.1
140   60.0
120   48.9
100   37.8
 80   26.7
 60   15.6
 40    4.4
 20   -6.7
  0  -17.8
 * */
```

### 1-6

验证表达式 getchar() != EOF 的值是 0 还是 1

```c
#include <stdio.h>

/**
 * 练习 1-6：验证表达式 getchar() != EOF 的值是 0 还是 1
 * */
int main(int argc, char* argv[]) {
    printf("%d\n", getchar() != EOF);
}

/**
输入：A
输出：1
输入：CTRL + D（linux 下的使用该快捷键表示 EOF，windows 下使用 CTRL + Z）
输出：0
 * */
```

### 1-7

编写一个打印 EOF 值的程序

```c
#include <stdio.h>

/**
 * 练习 1-7：编写一个打印 EOF 值的程序
 * */
int main(int argc, char* argv[]) {
    printf("%d\n", EOF);
    return 0;
}

/**
-1
 * */
```

### 1-8

编写一个统计空格、制表符与换行符个数的程序

```c
#include <stdio.h>

/**
 * 练习 1-8：编写一个统计空格、制表符与换行符个数的程序
 * */
int main(int argc, char* argv[]) {
    int c;  // 注意这里不能写成 char c; 否则 Ctrl + D 不会被识别成 EOF
    int space, tab, line;

    space = tab = line = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++space;
        }else if (c == '\t') {
            ++tab;
        }else if (c == '\n') {
            ++line;
        }
    }

    printf("%d, %d, %d\n", space, tab, line);
    return 0;
}

/**
输入：
1234    abc 567 def
hello,world
        111
123
输出：
14, 1, 4
 * */
```

### 1-9

编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替

```c
#include <stdio.h>

/**
 * 练习 1-9：编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替
 * */
#define NONBLANK 'a'

int main(int argc, char* argv[]) {
    int lastc = NONBLANK;
    int c;
    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastc != ' ') {
            putchar(c);
        }
        lastc = c;
    }
    return 0;
}
```

### 1-10

编写一个将输入复制到输出的程序，并将其中的制表符替换为 \t，将回退符替换为 \b，将反斜杠替换为 \\。这样可以将制表符和回退符以可见的方式显示出来。

```c
#include <stdio.h>

/**
 * 练习 1-10：编写一个将输入复制到输出的程序，并将其中的制表符替换为 \t，将回退符替换为 \b，将反斜杠替换为 \\。这样可以将制表符和回退符以可见的方式显示出来。
 * */
int main(int argc, char* argv[]) {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        }else if (c == '\b') {
            printf("\\b");
        }else if (c == '\\') {
            printf("\\\\");
        }else {
            putchar(c);
        }
    }
    return 0;
}
```

### 1-11

你准备如何测试单词计数程序？如果程序中存在某种错误，那么什么样的输入最可能发现这类错误呢？

```c
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
```

### 1-12

编写一个程序，以每行一个单词的形式打印其输入

```c
#include <stdio.h>

/**
 * 练习 1-12：编写一个程序，以每行一个单词的形式打印其输入
 * */

#define IN  1
#define OUT 0

int main(int argc, char* argv[]) {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {  // 到了单词尾部
                state = OUT;
                printf("\n");
            }
        }else if (state == OUT) {   // 一个单词的开端
            state = IN;
            putchar(c);
        }else { // 在单词内部
            putchar(c);
        }
    }
}
```

### 1-13

编写一个程序，打印输入中单词长度的直方图。水平方向的直方图比较容易绘制，垂直方向的直方图则要困难些。

```c
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
```

### 1-14

编写一个程序，打印输入中各个字符出现频度的直方图。

```c
#include <stdio.h>
#include <ctype.h>

/**
 * 练习 1-14：编写一个程序，打印输入中各个字符出现频度的直方图。
 * */

#define MAXHIST 15
#define MAXCHAR 128

int main(int argc, char* argv[]) {
    int c, i;
    int len;
    int maxvalue;
    int cc[MAXCHAR];

    for (i = 0; i < MAXCHAR; ++i) {
        cc[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c < MAXCHAR) {
            ++cc[c];
        }
    }
    maxvalue = 0;
    for (i = 1; i <MAXCHAR; ++i) {
        if (cc[i] > maxvalue) {
            maxvalue = cc[i];
        }
    }
    for (i = 1; i < MAXCHAR; ++i) {
        if (isprint(i)) {   // 判断 i 是不是可显字符
            printf("%5d - %c - %5d : ", i, i, cc[i]);
        }else {
            printf("%5d - - %5d : ", i, cc[i]);
        }
        if (cc[i] > 0) {
            if ((len = cc[i] * MAXHIST / maxvalue) <= 0) {
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
    return 0;
}
```

### 1-15

重新编写 1.2 节中的温度转换程序，使用函数实现温度转换计数。

```c
#include <stdio.h>

/**
 * 练习 1-15: 重新编写 1.2 节中的温度转换程序，使用函数实现温度转换计数。
 * */

float celsius(float fahr);

int main() {
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step  = 20;

    fahr = lower;
    while (fahr <= upper) {
	printf("%3.0f %6.1f\n", fahr, celsius(fahr));
	fahr += step;
    }
    return 0;
}

float celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}
```

### 1-16

修改打印最长文本行的程序的主程序 main，使之可以打印任意长度的输入行的长度，并尽可能多地打印文本。

```c
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
```

### 1-17

编写一个程序，打印长度大于 80 个字符的所有输入行

```c
#include <stdio.h>

/**
 * 练习 1-17: 编写一个程序，打印长度大于 80 个字符的所有输入行
 * */

#define MAXLINE 1000
#define LIMIT   80

int getaline(char line[], int maxvalue);

int main() {
    int len;
    char line[MAXLINE];
    while ((len = getaline(line, MAXLINE)) > 0) {
	if (len > 80) {
	    printf("%s", line);
	}
    }
    return 0;
}

int getaline(char line[], int maxvalue) {
    int i, c;
    for (i = 0; i < maxvalue - 1 && (c = getchar()) != EOF &&  c != '\n'; ++i) {
	line[i] = c;	
    }
    if (c == '\n') {
	line[i] = '\n';
	++i;
    }
    line[i] = '\0';
    return i;
}
```

### 1-18

编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行。

```c
#include <stdio.h>

/**
 * 练习 1-18: 编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行。
 * */

#define MAXLINE 1000

int mygetline(char line[], int maxvalue);
int myremove(char s[]);

int main() {
    char line[MAXLINE];
    while (mygetline(line, MAXLINE) > 0) {
	if (myremove(line) > 0) {
	    printf("%s", line);
	}
    } 
    return 0;
}

int mygetline(char line[], int maxvalue) {
    char c;
    int i;
    
    for (i = 0; i < maxvalue - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;
    }
    if (c == '\n') {
	line[i] = '\n';
	++i;
    } 
    line[i] = '\0';
    return i;
}

int myremove(char s[]) {
    int i = 0;
    while (s[i] != '\n') {
	++i;	
    }
    --i;
    while (i >=0 && (s[i] == ' ' || s[i] == '\t')) {
	--i;
    }
    if (i >= 0) {
	++i;
	s[i] = '\n';
	++i;
	s[i] = '\0';
    }
    return i; 
}
```

### 1-19

编写函数 reverse(s), 将字符 s 中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序。

```c
#include <stdio.h>

/**
 * 练习 1-19: 编写函数 reverse(s), 将字符 s 中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序。
 * */

#define MAXLINE 1000

int getaline(char line[], int maxvalue);
void reverse(char s[]);

int main() {
    int len;
    char line[MAXLINE]; 
    while ((len = getaline(line, MAXLINE)) > 0) {
	reverse(line);
	printf("%s", line);
    }
    return 0;
}

int getaline(char line[], int maxvalue) {
    char c;
    int i;
    for (i = 0; i < maxvalue - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;	
    }
    if (c == '\n') {
	line[i] = c;
	++i;
    }
    line[i] = '\0';
    return i;
}

void reverse(char s[]) {
    int j;
    j = 0;
    while (s[j] != '\0') {
	++j;
    }
    --j;
    
    int i;
    i = 0;
    while (i < j) {
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	++i;
	--j;
    }
}
```

### 1-20

请编写程序 detab, 将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方。假设制表符终止位的位置是固定的，比如每隔 n 列就会出现一个制表符终止位。n 应该作为变量还是符号常量呢？

```c
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
```

### 1-21

编写程序 entab，将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隔不变。假设制表符终止位的位置与练习 1-20 的 detab 程序的情况相同。当使用一个制表符或者一个空格都可以到达下一个制表符终止位时，选用哪种替换字符比较好？

```c
#include <stdio.h>

/**
 * 练习 1-21: 编写程序 entab，将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隔不变。假设制表符终止位的位置与练习 1-20 的 detab 程序的情况相同。当使用一个制表符或者一个空格都可以到达下一个制表符终止位时，选用哪种替换字符比较好？
 * */

#define TABINC 8

int main() {
    int c, nb, nt, pos;
    nb = 0;
    nt = 0;
    for (pos = 1; (c = getchar()) != EOF; ++pos) {
	if (c == ' ') {
	    if (pos % TABINC != 0) {
		++nb;
	    }else {
		nb = 0;
		++nt;
	    }
	}else {
	    for (; nt > 0; --nt) {
		putchar('\t');
	    }
	    if (c == '\t') {
		nb = 0;
	    }else {
		for (; nb > 0; --nb) {
		    putchar(' ');
		}
	    }
	    putchar(c);
	    if (c == '\n') {
		pos = 0;
	    }else if (c == '\t') {
		pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
	    }
	}
    }
}
```

### 1-22

编写一个程序，把较长的输入行"折"成短一些的两行或多行，折行的位置在输入法的第 n 列之间的最后一个非空格之后。要保证程序能够智能地处理输入法很长以及在指定的列前没有空格或制表符的情况。

```c
#include <stdio.h>

/**
 * 练习 1-22: 编写一个程序，把较长的输入行"折"成短一些的两行或多行，折行的位置在输入法的第 n 列之间的最后一个非空格之后。要保证程序能够智能地处理输入法很长以及在指定的列前没有空格或制表符的情况。
 * */

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];
int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

int main() {
    int c, pos;
    pos = 0;
    while ((c = getchar()) != EOF) {
	line[pos] = c;
	if (c == '\t') {
	    pos = exptab(pos);
	}else if (c == '\n') {
	    printl(pos);
	    pos = 0;
	}else if (++pos >= MAXCOL) {
	    pos = findblnk(pos); 
	    printl(pos);
	    pos = newpos(pos);
	}
    }
}

void printl(int pos) {
    int i;
    for (i = 0; i < pos; ++i) {
	putchar(line[i]);
    }
    if (pos > 0) {
	putchar('\n');
    }
}

int exptab(int pos) {
    line[pos] = ' ';
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos) {
	line[pos] = ' ';
    }
    if (pos < MAXCOL) {
	return pos;
    }else {
	printl(pos);
	return 0;
    }

}

int findblnk(int pos) {
    while (pos > 0 && line[pos] != ' ') {
	--pos;
    }
    if (pos == 0) {
	return MAXCOL;
    }else {
	return pos + 1;
    }
}

int newpos(int pos) {
    int i, j;
    if (pos <=0 || pos >= MAXCOL) {
	return 0;
    }else {
	i = 0;
	for (j = pos; j < MAXCOL; ++j) {
	    line[i] = line[j];
	    ++i;
	}
	return i;
    }
}
```

### 1-23

编写一个程序，删除 C 语言程序中所有的注释语句。要正确处理带引号的字符串与字符常量。在 C 语言程序中，注释不允许嵌套。

```c
#include <stdio.h>

/**
 * 练习 1-23: 编写一个程序，删除 C 语言程序中所有的注释语句。要正确处理带引号的字符串与字符常量。在 C 语言程序中，注释不允许嵌套。
 * */

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

int main() {
    int c, d;
    while ((c = getchar()) != EOF) {
	rcomment(c);
    }
    return 0;
}

void rcomment(int c) {
    int d;
    if (c == '/') {
	if ((d = getchar() == '*')) {
	    in_comment();
	}else if (d == '/') {
	    putchar(c);
	    rcomment(d);
	}else {
	    putchar(c);
	    putchar(d);
	}
    }else if (c == '\'' || c == '"') {
	echo_quote(c);
    }else {
	putchar(c);
    }
}

void in_comment(void) {
    int c, d;
    c = getchar();
    d = getchar();
    while (c != '*' || d != '/') {
	c = d;
	d = getchar();
    }
}

void echo_quote(int c) {
    int d;
    putchar(c);
    while ((d = getchar()) != c) {
	putchar(d);
	if (d == '\\') {
	    putchar(getchar());
	}
    }
    putchar(d);
}
```

### 1-24

编写一个程序，查找 C 语言程序中的基本语法错误，如圆括号、方括号以及花括号不配对等。要正确处理引号(包括单引号和双引号)、转义字符序列与注释。(如果读者想把该程序编写成完全通用的程序，难度会比较大。)

```c
#include <stdio.h>

/**
 * 练习 1-24: 编写一个程序，查找 C 语言程序中的基本语法错误，如圆括号、方括号以及花括号不配对等。要正确处理引号(包括单引号和双引号)、转义字符序列与注释。(如果读者想把该程序编写成完全通用的程序，难度会比较大。)
 * */

int brace, brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

int main() {
    int c;
    extern int brace, brack, paren;
    while ((c = getchar()) != EOF) {
	if (c == '/') {
	    if ((c = getchar()) == '*') {
		in_comment();
	    }else {
		search(c);
	    }
	}else if (c == '\'' || c == '"') {
	    in_quote(c);
	}else {
	    search(c);
	}

	if (brace < 0) {
	    printf("Unbalanced braces\n");
	    brace = 0;
	}else if (brack < 0) {
	    printf("Unbalanced brackets\n");
	    brack = 0;
	}else if (paren < 0) {
	    printf("Unbalanced parentheses\n");
	    paren = 0;
	}
    }
    if (brace > 0) {
	printf("Unbalanced braces\n");
    }
    if (brack > 0) {
	printf("Unbalanced brackets\n");
    }
    if (paren > 0) {
	printf("Unbalanced parentheses\n");
    }
    return 0;
}

void search(int c) {
    extern int brace, brack, paren;
    if (c == '{') {
	++brace;
    }else if (c == '}') {
	--brace;
    }else if (c == '[') {
	++brack;
    }else if (c == ']') {
	--brace;
    }else if (c == '(') {
	++paren;
    }else if (c == ')') {
	--paren;
    }
}

void in_comment(void) {
    int c, d;
    c = getchar();
    d = getchar();
    while (c != '*' || d == '/') {
	c = d;
	d = getchar();
    }
}

void in_quote(int c) {
    int d;
    while ((d = getchar()) != c) {
	if (d == '\\') {
	    getchar();
	}
    }
}
```

## 第二章 类型、运算符与表达式

### 2.1

编写一个程序以确定分别由 signed 和 unsigned 限定的 char、short、int 及 long 类型变量的取值范围。采用打印标准头文件的相应值以及直接计算两种方式实现。后一种方法的实现较困难一些，因为要确定各种浮点类型的取值范围。

```c
#include <stdio.h>
#include <limits.h>

/**
 * 练习 2-1: 编写一个程序以确定分别由 signed 和 unsigned 限定的 char、short、int 及 long 类型变量的取值范围。采用打印标准头文件的相应值以及直接计算两种方式实现。后一种方法的实现较困难一些，因为要确定各种浮点类型的取值范围。
 * */

int main() {
    // signed types
    printf("signed char min  = %d\n",  SCHAR_MIN);
    printf("signed char max  = %d\n",  SCHAR_MAX);
    printf("signed short min = %d\n",  SHRT_MIN);
    printf("signed short max = %d\n",  SHRT_MAX);
    printf("signed int min   = %d\n",  INT_MIN);
    printf("signed int max   = %d\n",  INT_MAX);
    printf("signed long min  = %ld\n", LONG_MIN);
    printf("singed long max  = %ld\n", LONG_MAX);
    // unsigned types
    printf("unsigned char max  = %u\n",  UCHAR_MAX);
    printf("unsigned short max = %u\n",  USHRT_MAX);
    printf("unsigned int max   = %u\n",  UINT_MAX);
    printf("unsigned long max  = %lu\n", ULONG_MAX);

    printf("manual count~~~\n");
    // manual count
    // signed types
    printf("signed char min = %d\n", -(char)((unsigned char) ~0 >> 1) - 1);	// 注意：减 1 是因为负数用补码表示后范围比正数大 1
    printf("signed char max = %d\n", (char)((unsigned char) ~0 >> 1));
    printf("signed short min = %d\n", -(short)((unsigned short) ~0 >> 1) - 1);
    printf("signed short max = %d\n", (short)((unsigned short) ~0 >> 1));
    printf("signed int min = %d\n", -(int)((unsigned int) ~0 >> 1) - 1);
    printf("signed int max = %d\n", (int)((unsigned int) ~0 >> 1));
    printf("signed long min = %ld\n", -(long)((unsigned long) ~0 >> 1) - 1);
    printf("signed long max = %ld\n", (long)((unsigned long) ~0 >> 1));

    // unsigned types
    printf("unsigned char max = %u\n", (unsigned char) ~0);
    printf("unsigned short max = %u\n", (unsigned short) ~0);
    printf("unsigned int max = %u\n", (unsigned int) ~0);
    printf("unsigned long max = %lu\n", (unsigned long) ~0);
    return 0;
}
```

### 2.2 

在不使用 && 或 || 的条件下编写一个与上面的 for 循环语句等价的循环语句。

```c
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
```

### 2.3

编写函数 htois(s), 把由十六进制数字组成的字符串(包含可选的前缀 0x 或 0X) 转换为与之等价的整型值。字符串中允许包含的数字包含：0~9、a~f 以及 A~F。

```c
/**
 * 练习 2-3: 编写函数 htois(s), 把由十六进制数字组成的字符串(包含可选的前缀 0x 或 0X) 转换为与之等价的整型值。字符串中允许包含的数字包含：0~9、a~f 以及 A~F。
 * */

#define YES 1
#define NO  0

int htoi(char s[]) {
    int hexdight, i, inhex, n;
    i = 0;
    if (s[i] == '0') {
	++i;
	if (s[i] == 'x' || s[i] == 'X') {
	    ++i;
	}
    }
    n = 0;
    inhex = YES;
    for (; inhex == YES; ++i) {
	if (s[i] >= '0' && s[i] <= '9') {
	    hexdight = s[i] - '0';
	}else if (s[i] >= 'a' && s[i] <= 'f') {
	    hexdight = s[i] - 'a' + 10;
	}else if (s[i] >= 'A' && s[i] <= 'F') {
	    hexdight = s[i] - 'A' + 10;
	}else {
	    inhex = NO;
	}
	if (inhex == YES) {
	    n = 16 * n + hexdight;
	}
    }
    return n;
}
```

### 2.4

重新编写函数 sequence(s1, s2), 将字符串 s1 中任何与字符串 s2 中的字符匹配的字符都删除。

```c
/**
 * 练习 2-4: 重新编写函数 sequence(s1, s2), 将字符串 s1 中任何与字符串 s2 中的字符匹配的字符都删除。
 * */

void sequence(char s1[], char s2[]) {
    int i, j, k;
    for (i = k = 0; s1[i] != '\0'; ++i) {
	for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j) {}
	if (s2[j] == '\0') {
	    s1[k++] = s1[i];
	}
    }
    s1[k] = '\0';
}
```

### 2.5

编写函数 any(s1,s2), 将字符串 s2 中的任一字符在字符串 s1 中第一次出现的位置作为结果返回。如果 s1 中不包含 s2 中的字符，则返回 -1。(标准库函数 strpbrk 具有同样的功能，但它返回的是指向该位置的指针。)

```c
/**
 * 练习 2-5: 编写函数 any(s1,s2), 将字符串 s2 中的任一字符在字符串 s1 中第一次出现的位置作为结果返回。如果 s1 中不包含 s2 中的字符，则返回 -1。(标准库函数 strpbrk 具有同样的功能，但它返回的是指向该位置的指针。)
 * */

int any(char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; ++i) {
	for (j = 0; s2[j] != '\0'; ++j) {
	    if (s1[i] == s2[j]) {
		return i;
	    }
	}
    }
    return -1;
}
```

### 2.6

编写一个函数 setbits(x, p, n, y), 该函数返回对 x 执行下列操作后的结果值: 将 x 中从第 p 位开始的 n 个(二进制)位设置为 y 中最右边 n 位的值，x 的其余各位保持不变。

```c
/**
 * 练习 2-6: 编写一个函数 setbits(x, p, n, y), 该函数返回对 x 执行下列操作后的结果值: 将 x 中从第 p 位开始的 n 个(二进制)位设置为 y 中最右边 n 位的值，x 的其余各位保持不变。
 * */

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}
```

### 2.7

编写一个函数 invert(x, p, n), 该函数返回对 x 执行下列操作后的结果值: 将 x 中从第 p 位开始的 n 个(二进制)位求反(即 1 变为 0，0 变为 1), x 的其余各位保持不变。

```c
/**
 * 练习 2-7: 编写一个函数 invert(x, p, n), 该函数返回对 x 执行下列操作后的结果值: 将 x 中从第 p 位开始的 n 个(二进制)位求反(即 1 变为 0，0 变为 1), x 的其余各位保持不变。
 * */

unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}
```

### 2.8

编写一个函数 rightrot(x, n), 该函数返回将 x 循环右移(即从最右端移出的位将从最左端移入) n(二进制)往后所得到的值。

```c
/**
 * 练习 2-8: 编写一个函数 rightrot(x, n), 该函数返回将 x 循环右移(即从最右端移出的位将从最左端移入) n(二进制)往后所得到的值。
 * */

unsigned rightrot(unsigned x, int n) {
    int wordlength(void);
    int rbit;
    while (n-- > 0) {
	rbit = (x & 1) << (wordlength() - 1);
	x = x >> 1;
	x = x | rbit;
    }
}

// 计算机器的字节长度
int wordlength(void) {
    int i;
    unsigned v = (unsigned)~0;
    v = ~0;
    for (i = 1; (v = (v >> 1)) > 0; ++i) {}
    return i;
}
```

### 2.9

在求二进制补码时，表达式 x&=(x - 1) 可以删除 x 中最右边值为 1 的一个二进制位。请解释这样做的道理。用这一方法重写 bitcount 函数，以加快其执行速度。

```c
/**
 * 练习 2-9: 在求二进制补码时，表达式 x&=(x - 1) 可以删除 x 中最右边值为 1 的一个二进制位。请解释这样做的道理。用这一方法重写 bitcount 函数，以加快其执行速度。
 * */

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= x - 1) {
	++b;
    }
    return b;
}
```

### 2.10

重新编写将大写字母转换为小写字母的函数 lower, 并用条件表达式替代其中的 if-else 结构

```c
/**
 * 练习 2-10: 重新编写将大写字母转换为小写字母的函数 lower, 并用条件表达式替代其中的 if-else 结构
 * */

int lower(int c) {
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
```

## 第三章 控制流

### 3.1

在上面有关折半查找的例子中，while 循环语句内共执行了两次测试，其实只要一次就足够(代价是将更多的测试在循环外执行)。重写该函数，使得在循环内部只执行一次测试。比较两种版本的函数的运行时间。

```c

#include <stdio.h>

/**
 * 练习 3-1: 在上面有关折半查找的例子中，while 循环语句内共执行了两次测试，其实只要一次就足够(代价是将更多的测试在循环外执行)。重写该函数，使得在循环内部只执行一次测试。比较两种版本的函数的运行时间。
 * */

int binarysearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
	if (x < v[mid]) {
	    high = mid - 1;
	}else {
	    low = mid + 1;
	}
	mid = (low + high) / 2;
    }
    if (x == v[mid]) {
	return mid;
    }else {
	return -1;
    }
}
```

### 3.2

编写一个函数 escape(s,t), 将字符串 t 复制到字符串 s 中，并在复制过程中将换行符、制表符等不可显示字符分别转换 \n、\t 等相应的可显示的转移字符序列。要求使用 switch 语句。再编写一个具有相反功能的函数，在复制过程中将转义字符序列转换为实际字符。

```c
#include <stdio.h>

/**
 * 练习 3-2: 编写一个函数 escape(s,t), 将字符串 t 复制到字符串 s 中，并在复制过程中将换行符、制表符等不可显示字符分别转换 \n、\t 等相应的可显示的转移字符序列。要求使用 switch 语句。再编写一个具有相反功能的函数，在复制过程中将转义字符序列转换为实际字符。
 * */

void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; ++i) {
	switch(t[i]) {
	    case '\n':
		s[j++] = '\\';
		s[j++] = 'n';
		break;
	    case '\t':
		s[j++] = '\\';
		s[j++] = 't';
		break;
	    default:
		s[j++] = t[i];
		break;
	}
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; ++i) {
	if (t[i] != '\\') { 
	    s[j++] = t[i];
	}else {
	    switch(t[++i]) {
		case 'n:
		    s[j++] = '\n';
		    break;
		case 't':
		    s[j++] = '\t';
		    break;
		default:
		    s[j++] = '\\';
		    s[j++] = t[i];
		    break;
	    }
	}
    }
    s[j] = '\0';
}
```

### 3.3

编写函数 expand(s1, s2), 将字符串 s1 中类似于 a-z 一类的速记符号在字符串 s2 中扩展为等价的完整列表 abc...xyz。该函数可以处理大小写字母和数字，并可以处理 a-b-c、a-z0-9 与 a-z 等类似的情况。作为前导和尾随的字符原样复制。

```c
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
```

### 3.4

在数的二进制补码表示中，我们编写的 itoa 函数不能处理最大的负数，即 n 等于 -(2^(字长-1))的情况。请解释其原因。修改该函数，使它在任何机器上运行时都能打印出正确的值。

```c
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
```

### 3.5

编写函数 itoa(n, s, b), 将整数 n 转换为以 b 为底的数，并将转换结果以字符的形式保存到字符串 s 中。例如，itob(n, s, 16) 把整数 n 格式化伟十六进制整数保存在 s 中。

```c
/**
 * 练习 3-5: 编写函数 itoa(n, s, b), 将整数 n 转换为以 b 为底的数，并将转换结果以字符的形式保存到字符串 s 中。例如，itob(n, s, 16) 把整数 n 格式化伟十六进制整数保存在 s 中。
 * */

void itob(int n, char s[], int b) {
    int i, j, sign;
    void reverse(char s[]);
    if ((sign = n) < 0) {
	n = -n;
    }
    i = 0;
    do {
	j = n % b;
	s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    }while ((n /= b) > 0);
    if (sign < 0) {
	s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
```

### 3.6

修改 itoa 函数，使得该函数可以接收三个参数。其中，第三个参数为最小字段宽度。为了保证转换后所得的结果至少具有第三个参数指定的最小宽度，在必要时应在所得结果的左边填充一定的空格

```c
/**
 * 练习 3-6: 修改 itoa 函数，使得该函数可以接收三个参数。其中，第三个参数为最小字段宽度。为了保证转换后所得的结果至少具有第三个参数指定的最小宽度，在必要时应在所得结果的左边填充一定的空格
 * */

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int w) {
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
    while (i < w) {
	s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}
```

## 第四章  函数与程序结构

### 4.1

编写函数 strrindex(s, t), 它将返回字符串 t 在 s 中最右边出现的位置。如果 s 中不包含 t，则返回 -1.

```c
/**
 * 练习 4-1: 编写函数 strrindex(s, t), 它将返回字符串 t 在 s 中最右边出现的位置。如果 s 中不包含 t，则返回 -1.
 * */

int strrindex(char s[], char t[]) {
    int i, j, k, pos;
    pos = -1;
    for (i = 0; i != '\0'; ++i) {
	for (j = i, k = 0; s[j] != '\0' && t[k] != '\0' && s[j] == t[k]; ++j, ++k);
	if (k > 0 && s[k] == '\0') {
	    pos = i;
	}
    }
    return pos;
}
```

### 4.2

对 atof 函数进行扩充，使它可以处理形如 123.45e-6 的科学表示法，其中，浮点数后面可能会紧跟一个 e 或 E 以及一个指数（可能有正负号）。

```c
/**
 * 练习 4-2: 对 atof 函数进行扩充，使它可以处理形如 123.45e-6 的科学表示法，其中，浮点数后面可能会紧跟一个 e 或 E 以及一个指数（可能有正负号）。
 **/
#include <ctype.h>

double atof(char s[]) {
    int i, sign;
    i = 0;
    if (s[i] == '+' || s[i] == '-') {
	sign = s[i] == '+' ? 1 : -1;
	++i;
    }
    double value;
    for (value = 0.0; isdigit(s[i]); ++i) {
	value = value * 10.0 + (s[i] - '0');
    }
    if (s[i] == '.') {
	++i;
    }
    double power;
    for (power = 1.0; isdigit(s[i]); ++i) {
	value = value * 10.0 + (s[i] - '0');
	power *= 10;
    } 
    value = sign * value / power;
    if (s[i] == 'e' || s[i] == 'E') {
	sign = s[++i] == '+' ? 1 : -1;
	if (s[i] == '+' || s[i] == '-') {
	    ++i;
	}
	int exp;
	for (exp = 0; isdigit(s[i]); ++i) {
	    exp = exp * 10 + (s[i] - '0');
	}
	if (sign == 1) {
	    while (exp-- > 0) {
		value *= 10;
	    }
	}else {
	    while (exp-- > 0) {
		value /= 10;
	    }
	}
    }
    return value;    
}
```

### 4.3

在有了基本框架后，对计算机程序进行扩充就比较简单了。在该程序中加入取模(%)运算符，并注意考虑负数的情况。

```c
/**
 * 练习 4-3: 在有了基本框架后，对计算机程序进行扩充就比较简单了。在该程序中加入取模(%)运算符，并注意考虑负数的情况。
 * */

#include <stdio.h>
#include <math.h>

#define MAXOP  100
#define NUMBER '0'

int    getop(char []);
void   push(double);
double pop(void);

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
	switch (type) {
	    case NUMBER:
		push(atof(s));
		break;
	    case '+':
		push(pop() + pop());
		break;
	    case '*':
		push(pop() + pop());
		break;
	    case '-':
		op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
		op2 = pop();
		if (op2 != 0.0) {
		    push(pop() / op2);
		}else {
		    printf("error: zero divisor\n");
		}
		break;
	    case '%':
		op2 = pop();
		if (op2 != 0.0) {
		    push(fmod(pop(), op2));
		}else {
		    printf("error: zero divisor\n");
		}
		break;
	    case '\n':
		printf("\t%.8g\n", pop());
		break;
	    default:
		printf("error: unknown command %s\n", s);
		break;
	}		
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int c, i;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-') {
	return c;
    }
    if (c == '-') {
	if (isdigit(c = getch()) || c == '.') {
	   s[++i] = c; 
	}else {
	    if (c != EOF) {
		ungetch(c);
	    }
	    return '-';
	}
    }
    if (isdigit(c)) {
	while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
	while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) { // 因为最后一个插入 s[] 的字符是多余的
	ungetch(c);
    }
    return NUMBER;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
	val[sp++] = f;
    }else {
	printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
	return val[--sp];
    }else {
	printf("error: stack empty\n");
	return 0.0;
    }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int  bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
	printf("ungetch: too many characters\n");
    }else {
	buf[bufp++] = c;
    }
}
```

### 4.4

在栈操作中添加几个命令，分别用于在不弹出元素的情况下打印栈顶元素；复制栈顶元素；交换栈顶两个元素的值。另外增加一个命令用于清空栈。

```c
/**
 * 练习 4-4: 在栈操作中添加几个命令，分别用于在不弹出元素的情况下打印栈顶元素；复制栈顶元素；交换栈顶两个元素的值。另外增加一个命令用于清空栈。
 * */
#include <stdio.h>
#include <math.h>

#define MAXOP  100
#define NUMBER '0'

int    getop(char []);
void   push(double);
double pop(void);
void clear(void);

int main() {
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
	switch (type) {
	    case NUMBER:
		push(atof(s));
		break;
	    case '+':
		push(pop() + pop());
		break;
	    case '*':
		push(pop() * pop());
		break;
	    case '-':
		op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
		op2 = pop();
		if (op2 != 0.0) {
		    push(pop() / op2);
		}else {
		    printf("error: zero divisor\n");
		}
		break;
	    case '?':
		op2 = pop();
		printf("\t%.8g\n", op2);
		push(op2);
		break;
	    case 'c':
		clear();
		break;
	    case 'd':
		op2 = pop();
		push(op2);
		push(op2);
		break;
	    case 's':
		op1 = pop();
		op2 = pop();
		push(op1);
		push(op2);
		break;
	    case '\n':
		printf("\t%.8g\n", pop());
		break;
	    default:
		printf("error: unknown command %s\n", s);
	}
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int c, i;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-') {
	return c;
    }
    if (c == '-') {
	if (isdigit(c = getch()) || c == '.') {
	   s[++i] = c; 
	}else {
	    if (c != EOF) {
		ungetch(c);
	    }
	    return '-';
	}
    }
    if (isdigit(c)) {
	while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
	while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) { // 因为最后一个插入 s[] 的字符是多余的
	ungetch(c);
    }
    return NUMBER;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
	val[sp++] = f;
    }else {
	printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
	return val[--sp];
    }else {
	printf("error: stack empty\n");
	return 0.0;
    }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int  bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
	printf("ungetch: too many characters\n");
    }else {
	buf[bufp++] = c;
    }
}

void clear(void) {
    sp = 0;
}
```

### 4.5

给计算器程序增加访问 sin、exp 和 pow 等库函数的操作。有关这些库函数的详细信息，请参见附录 B.4 节(《C程序设计语言(第2版·新版)》第 228 页)中的头文件<math.h>。

```c
/**
 * 练习 4-5: 给计算器程序增加访问 sin、exp 和 pow 等库函数的操作。有关这些库函数的详细信息，请参见附录 B.4 节(《C程序设计语言(第2版·新版)》第 228 页)中的头文件<math.h>。
 * */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXOP  100
#define NUMBER '0'
#define NAME   'n'

int    getop(char []);
void   push(double);
double pop(void);
void   mathfnc(char []);

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
	switch (type) {
	    case NUMBER:
		push(atof(s));
		break;
	    case '+':
		push(pop() + pop());
		break;
	    case '*':
		push(pop() + pop());
		break;
	    case '-':
		op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
		op2 = pop();
		if (op2 != 0.0) {
		    push(pop() / op2);
		}else {
		    printf("error: zero divisor\n");
		}
		break;
	    case NAME:
		mathfnc(s);
		break;
	    case '\n':
		printf("\t%.8g\n", pop());
		break;
	    default:
		printf("error: unknown command %s\n", s);
		break;
	}		
    }
    return 0;
}

void mathfnc(char s[]) {
    double op2;
    
    if (strcmp(s, "sin") == 0) {
	push(sin(pop()));
    }else if (strcmp(s, "cos") == 0) {
	push(cos(pop()));
    }else if (strcmp(s, "exp") == 0) {
	push(exp(pop()));
    }else if (strcmp(s, "pow") == 0) {
	op2 = pop();
	push(pow(pop(), op2));
    }else {
	printf("error: %s not supported\n", s);
    }
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME 'n'

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int c, i;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
    if (islower(c)) {
	while (islower(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF) {
	    ungetch(c);
	}
	if (strlen(s) > 1) {
	    return NAME;
	}else {
	    return c;
	}
	
    }
    if (!isdigit(c) && c != '.' && c != '-') {
	return c;
    }
    if (c == '-') {
	if (isdigit(c = getch()) || c == '.') {
	   s[++i] = c; 
	}else {
	    if (c != EOF) {
		ungetch(c);
	    }
	    return '-';
	}
    }
    if (isdigit(c)) {
	while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
	while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) { // 因为最后一个插入 s[] 的字符是多余的
	ungetch(c);
    }
    return NUMBER;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
	val[sp++] = f;
    }else {
	printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
	return val[--sp];
    }else {
	printf("error: stack empty\n");
	return 0.0;
    }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int  bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
	printf("ungetch: too many characters\n");
    }else {
	buf[bufp++] = c;
    }
}
```

### 4.6

给计算器程序增加处理变量的命令(提供 26 个具有单个英文字母变量名的变量会让你容易)。增加一个变量存放最近打印的值。

```c
/** 练习 4-6: 给计算器程序增加处理变量的命令(提供 26 个具有单个英文字母变量名的变量会让你容易)。增加一个变量存放最近打印的值。 */

#include <stdio.h>
#include <math.h>

#define MAXOP  100 
#define NUMBER '0'

int    getop(char []);
void   push(double);
double pop(void);

int main() {
    int i, type, var = 0;
    double op2, v;
    char s[MAXOP];
    double variable[26];

    for (i = 0; i < 26; ++i) {
	variable[i] = 0.0;
    }

    while ((type = getop(s)) != EOF) {
	switch (type) {
	    case NUMBER:
		push(atof(s));
		break;
	    case '+':
		push(pop() + pop());
		break;
	    case '*':
		push(pop() + pop());
		break;
	    case '-':
		op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
		op2 = pop();
		if (op2 != 0.0) {
		    push(pop() / op2);
		}else {
		    printf("error: zero divisor\n");
		}
		break;
	    case '=':
		pop();
		if (var >= 'A' && var <= 'Z') {
		    variable[var - 'A'] = pop();
		}else {
		    printf("error: no variable name\n");
		}
		break;
	    case '\n':
		v = pop();
		printf("\t%.8g\n", pop());
		break;
	    default:
		if (type >= 'A' && type <= 'Z') {
		    push(variable[type - 'A']);
		}else if (type == 'v') {
		    push(v);
		}else {
		    printf("error: unknown command %s\n", s);
		}
		break;
	}		
	var = type;
    }
    return 0;
}
```

### 4.7

编写一个函数 ungets(s)，将整个字符串 s 压回到输入中。ungets 函数需要使用 buf 和 bufp 吗？它是否仅使用 ungetch 函数？

```c
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
```

### 4.8

假定最多只压回一个字符，请相应地修改 getch 和 ungetch 这两个函数

```c
/**
 * 练习 4-8: 假定最多只压回一个字符，请相应地修改 getch 和 ungetch 这两个函数
 * */

#include <stdio.h>

char buf = 0;

int getch(void) {
    int c;
    if (buf != 0) {
	c = buf;
    }else {
	c = getchar();
    }
    buf = 0;
    return c;
}

void ungetch(int c) {
    if (buf != 0) {
	printf("ungetch: too many characters\n");
    }else {
	buf = c;
    }
}
```

### 4.9

以上介绍的 getch 和 ungetch 函数不能正确地处理压回的 EOF。考虑压回 EOF 时应该如何处理。请实现你的方案。

```c
/**
 * 练习 4-9: 以上介绍的 getch 和 ungetch 函数不能正确地处理压回的 EOF。考虑压回 EOF 时应该如何处理。请实现你的方案。
 * */

#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
	printf("ungetch: too many characters\n");
    }else {
	buf[bufp++] = c;
    }
}
```

### 4.10

另一种方法是通过 getline 函数读入整个输入行，这种情况下可以不使用 getch 与 ungetch 函数。请运用这一方法修改计算器程序。

```c
/**
 * 练习 4-10：另一种方法是通过 getline 函数读入整个输入行，这种情况下可以不使用 getch 与 ungetch 函数。请运用这一方法修改计算器程序。
 * */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define NUMBER  '0'

int mygetline(char line[], int limit);
int li = 0;
char line[MAXLINE];

int getop(char s[]) {
    int c, i;
    if (line[li] == '\0') {
	if (mygetline(line, MAXLINE) == 0) {
	    return EOF;
	}else {
	    li = 0;
	}
    }
    while ((s[0] = c = line[li++]) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
	return c;
    }
    i = 0;
    if (isdigit(c)) {
	while (isdigit(s[++i] = c = line[li++]));
    }
    if (c == '.') {
	while (isdigit(s[++i] = c = line[li++]));
    }
    s[i] = '\0';
    li--;
    return NUMBER;
}
```

### 4.11

修改 getop 函数，使其不必使用 ungetch 函数。提示：可以使用一个 static 类型的内部变量来解决问题。

```c
/**
 * 练习 4-11：修改 getop 函数，使其不必使用 ungetch 函数。提示：可以使用一个 static 类型的内部变量来解决问题。
 * */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);

int getop(char s[]) {
    int c, i;
    static int lastc = 0;

    if (lastc == 0) {
	c = getch();
    }else {
	c = lastc;
	lastc = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t') {
	c = getch();
    }

    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
	return c;
    }
    i = 0;
    if (isdigit(c)) {
	while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
	while (isdigit(s[++i] = c = getch()));
    } 
    s[i] = '\0';
    if (c != EOF) {
	lastc = c;
    }
    return NUMBER;
}
```

### 4.12

运用 printd 函数的设计思想编写一个递归版本的 itoa 函数。即通过递归调用把整数转换为字符串。

```c
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
```

### 4.13

编写一个递归版本的 reverse(s) 函数，以将字符串 s 倒置。

```c
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
```

### 4.14

定义宏 swap(t, x, y), 以交换 t 类型的两个参数。（使用程序块结构会对你有所帮助）

```c
/**
 * 练习 4-14：定义宏 swap(t, x, y), 以交换 t 类型的两个参数。（使用程序块结构会对你有所帮助）
 * */

#define swap(t, x, y) {	   \
    t _z;   \
    _z = y; \
    y = x;  \
    x = _z; \
}
```

## 第五章 指针与数组

### 5.1

在上面的例子中，如果符号 + 或 - 的后面紧跟的不是数字，getint 函数将把符号视为数字 0 的有效表达方式。修改该函数，将这种形式的 + 或 - 符号重新写回到输入流中。

```c
/**
 * 练习 5-1：在上面的例子中，如果符号 + 或 - 的后面紧跟的不是数字，getint 函数将把符号视为数字 0 的有效表达方式。修改该函数，将这种形式的 + 或 - 符号重新写回到输入流中。
 * */

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
	ungetch(c);
	return 0;
    }
    
    sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-') {
	int d = c;
	if (!isdigit(c = getch())) {
	    if (c != EOF) {
		ungetch(c);
	    }
	    ungetch(d);
	    return d;
	}
    }
    for (*pn = 0; isdigit(c); c = getch()) {
	*pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
	ungetch(c);
    }
    return c;
}
```

### 5.2

模仿函数 getint 的实现方法，编写一个读取浮点数的函数 getfloat。getfloat 函数的返回值应该是什么类型？

```c
/**
 * 练习 5-2：模仿函数 getint 的实现方法，编写一个读取浮点数的函数 getfloat。getfloat 函数的返回值应该是什么类型？
 * */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(float *pn) {
    int c, sign;
    float power;

    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
	ungetch(c);
	return 0;
    }
    sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-') {
	c = getch();
    }
    for (*pn = 0.0; isdigit(c); c = getch()) {
	*pn = *pn * 10 + (c - '0');
    }
    if (c == '.') {
	c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch()) {
	*pn = *pn * 10 + (c - '0');
	power *= 10;
    }
    *pn *= sign / power;
    if (c != EOF) {
	ungetch(c);
    }
    return c;
}
```

### 5.3

用指针方式实现第 2 章中的函数 strcat。函数 strcat(s, t) 将 t 指向的字符串复制到 s 指向的字符串的尾部。

```c
/**
 * 练习 5-3：用指针方式实现第 2 章中的函数 strcat。函数 strcat(s, t) 将 t 指向的字符串复制到 s 指向的字符串的尾部。
 * */

void strcat(char* s, char* t) {
    while (*s) {
	++s;
    }
    while (*s++ = *t++);
}
```

### 5.4

编写函数 strend(s, t)。如果字符串 t 出现在字符串 s 的尾部，该函数返回 1；否则返回 0。

```c
/**
 * 练习 5-4：编写函数 strend(s, t)。如果字符串 t 出现在字符串 s 的尾部，该函数返回 1；否则返回 0。
 * */
int strend(char* s, char* t) {
    char* bs = s;
    char* bt = t; 

    for (; *s; ++s);
    for (; *t; ++t);
    for (; *s == *t; --s, --t) {
	if (s == bs || t == bt) {
	    break;
	}
    }
    if (*s == *t && t == bt && *s != '\0') {
	return 1;
    }else {
	return 0;
    }
}
```

### 5.5

实现库函数 strncpy、strncat 和 strncmp，它们最多对参数字符串中的前 n 个字符进行操作。例如，函数 strncpy(s, t, n) 将 t 中最多前 n 个字符复制到 s 中。更详细的说明请参见附录 B（见 K&R 原著第 249 页）。

```c
/**
 * 练习 5-5：实现库函数 strncpy、strncat 和 strncmp，它们最多对参数字符串中的前 n 个字符进行操作。例如，函数 strncpy(s, t, n) 将 t 中最多前 n 个字符复制到 s 中。更详细的说明请参见附录 B（见 K&R 原著第 249 页）。
 * */

void strncpy(char* s, char* t, int n) {
    while (*t && n-- > 0) {
	*s++ = *t++;
    }
    while (n-- > 0) {
	*s++ = '\0';
    }
}

void strncat(char* s, char* t, int n) {
    void strncpy(char* s, char* t, int n);
    int strlen(char*);
    strncpy(s + strlen(s), t, n);
}

int strncmp(char* s, char* t, int n) {
    for (; *s == *t; ++s, ++t) {
	if (*s == '\0' || --n <= 0) {
	    return 0;
	}
    }
    return *s - *t;
}
```

### 5.6

采用指针而非数组索引方式改写前面章节和练习中的某些程序，例如 getline(第 1、4 章)，atoi、itoa 以及它们的变体形式(第 2、3、4 章)、reverse(第 3 章)、strindex、getop(第 4 章)等等。

```c
/**
 * 练习 5-6：采用指针而非数组索引方式改写前面章节和练习中的某些程序，例如 getline(第 1、4 章)，atoi、itoa 以及它们的变体形式(第 2、3、4 章)、reverse(第 3 章)、strindex、getop(第 4 章)等等。
 * */
#include <stdio.h>

int getline(char* s, int lim) {
    int c;
    char* t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
	*s++ = c;
    }
    if (c == '\n') {
	*s++ = c;
    }
    *s = '\0';
    return s - t;
}

#include <ctype.h>

int atoi(char* s) {
    int n, sign;
    for (; isspace(*s); ++s);
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') {
	s++;
    }
    for (n = 0; isdigit(*s); s++) {
	n = 10 * n + *s - '0';
    }
    return sign * n;
}

void reverse(char* s);
void itoa(int n, char* s) {
    int sign;
    char* t = s;
    if ((sign = n) < 0) {
	n = -n;
    }
    do {
	*s++ = n % 10 + '0';
    }while ((n /= 10) > 0);
    if (sign < 0) {
	*s++ = '-';
    }
    *s = '\0';
    reverse(t);
}

#include <string.h>

void reverse(char* s) {
    int c;
    char* t;

    for (t = s + (strlen(s) - 1); s < t; s++, t--) {
	c = *s;
	*s = *t;
	*t = c;
    }
}

int strindex(char* s, char* t) {
    char* b = s;
    char* p, *r;

    for (; *s != '\0'; s++) {
	for (p = s, r = t; *r != '\0' && *p == *r; p++, r++);
	if (r > t && *r == '\0') {
	    return s - b;
	}
    }
    return -1;
}

#include <ctype.h>

double atof(char* s) {
    double val, power;
    int sign;

    for (; isspace(*s); s++);
    sign = *s == '-' ? -1 : 1;
    if (*s == '+' || *s == '-') {
	s++;
    }
    for (val = 0.0; isdigit(*s); s++) {
	val = val * 10.0 + (*s - '0');
    }
    if (*s == '.') {
	s++;
    }
    for (power = 1.0; isdigit(*s); s++) {
	val = val * 10.0 + (*s - '0');
	power *= 10.0;
    }
    return sign * val / power;
}

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
int ungetch(int);

int getop(char* s) {
    int c;
    
    while ((*s = c = getch()) == ' ' || c == '\t');
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.') {
	return c;
    }
    if (isdigit(c)) {
	while (isdigit(*++s = c = getch()));
    }
    if (c == '.') {
	while (isdigit(*++s = c = getch()));
    }

    *s = '\0';
    if (c != EOF) {
	ungetch(c);
    }
    return NUMBER;
}
```

### 5.7

重写函数 readline，将输入的文本行存储到由 main 函数提供的一个数组中，而不是存储到调用 alloc 分配的存储空间中。该函数的运行速度比改写前快多少？

```c
/**
 * 练习 5-7：重写函数 readline，将输入的文本行存储到由 main 函数提供的一个数组中，而不是存储到调用 alloc 分配的存储空间中。该函数的运行速度比改写前快多少？
 * */

#define MAXLEN  1000
#define MAXSTOR 5000

int getline(char*, int);

int readline(char* lineptr[], char* linestor, int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    char* p = linestor;
    char* linestop = linestor + MAXSTOR;


    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
	if (nlines > maxlines || p + len > linestop) {
	    return -1;
	}else {
	    line[len - 1] = '\0';
	    strcpy(p, line);
	    lineptr[nlines++] = p;
	    p += len;
	}
    }
    return nlines;
}
```

### 5.8

函数 day_of_year 和 monty_day 中没有进行错误检查，请解决该问题。

```c
/**
 * 练习 5-8：函数 day_of_year 和 monty_day 中没有进行错误检查，请解决该问题。
 * */

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month < 1 || month > 12) {
	return -1;
    }
    if (day < 1 || day > daytab[leap][month]) {
	return -1;
    }
    for (i = 1; i < month; ++i) {
	day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday) {
    int i, leap;
    if (year < 1) {
	*pmonth = -1;
	*pday = -1;
	return;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i <= 12 && yearday > daytab[leap][i]; ++i) {
	yearday -= daytab[leap][i];
    }
    if (i > 12 && yearday > daytab[leap][12]) {
	*pmonth = -1;
	*pday = -1;
    }else {
	*pmonth = i;
	*pday = yearday;
    }
}
```

### 5.9

用指针方式替代数组下标方式改写函数 day_of_year 和 month_day。

```c
/**
 * 练习 5-9：用指针方式替代数组下标方式改写函数 day_of_year 和 month_day。
 * */

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;
    char* p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while (--month) {
	day += *++p;
    }
    return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday) {
    int leap;
    char* p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while (yearday > *++p) {
	yearday -= *p;
    }
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}
```

### 5.10

编写程序 expr，以计算从命令行输入的逆波兰表达式的值，其中每个运算符或操作数用一个单独的参数表示。例如命令：expr 2 3 4 + * 将计算表达式 2 x (3 + 4) 的值。

```c
/**
 * 练习 5-10：编写程序 expr，以计算从命令行输入的逆波兰表达式的值，其中每个运算符或操作数用一个单独的参数表示。例如命令：expr 2 3 4 + * 将计算表达式 2 x (3 + 4) 的值。
 * */

#include <stdio.h>
#include <math.h>

#define MAXOP  100
#define NUMBER '0'

int getop(char []);
void ungets(char []);
void push(double);
double pop(void);

int main(int argc, char* argv[]) {
    char s[MAXOP];
    double op2;

    while (--argc > 0) {
	ungets(" ");
	ungets(*++argv);
	switch (getop(s)) {
	    case NUMBER:
		push(atof(s));
		break;
	    case '+':
		push(pop() + pop());
		break;
	    case '-':
		op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
		op2 = pop();
		if (op2 != 0.0) {
		    push(pop() / op2);
		}else {
		    printf("error: zero divisor\n");
		}
		break;
	    default:
		printf("error: unknown command %s\n", s);
		argc = 1;
		break;
	}
    }
    printf("\t%.8g\n", pop());
    return 0;
}
```

### 5.11

修改程序 entab 和 detab（第 1 章练习中编写的函数），使它们接收一组作为参数的制表符停止位。如果启动程序时不带参数，则使用默认的制表符停止位设置。

```c
/**
 * 练习 5-11：修改程序 entab 和 detab（第 1 章练习中编写的函数），使它们接收一组作为参数的制表符停止位。如果启动程序时不带参数，则使用默认的制表符停止位设置。
 * */
#include <stdio.h>

#define MAXLINE 100
#define TABINC  8
#define YES     1
#define NO      0

void settab(int argc, char* argv[], char* tab);
void entab(char* tab);
int tabpos(int pos, char* tab);

int main(int argc, char* argv[]) {
    char tab[MAXLINE + 1];
    settab(argc, argv, tab);
    entab(tab);
    return 0;
}

void entab(char* tab) {
    int c, pos;
    int nb = 0;
    int nt = 0;

    for (pos = 1; (c = getchar()) != EOF; pos++) {
	if (c == ' ') {
	    if (tabpos(pos, tab) == NO) {
		++nb;
	    }else {
		nb = 0;
		++nt;
	    }
	}else {
	    for (; nt > 0; nt--) {
		putchar('\t');
	    }
	    if (c == '\t') {
		nb = 0;
	    }else {
		for (; nb > 0; nb--) {
		    putchar(' ');
		}
	    }
	    putchar(c);
	    if (c == '\n') {
		pos = 0;
	    }else if (c == '\t') {
		while (tabpos(pos, tab) != YES) {
		    ++pos;
		}
	    }
	}
    }
}

#include <stdlib.h>

void settab(int argc, char* argv[], char* tab) {
    int i, pos;
    if (argc <= 1) {
	for (i = 1; i <= MAXLINE; i++) {
	    if (i % TABINC == 0) {
		tab[i] = YES;
	    }else {
		tab[i] = NO;
	    }
	}
    }else {
	for (i = 1; i <= MAXLINE; i++) {
	    tab[i] = NO;
	}
	while (--argc > 0) {
	    pos = atoi(*++argv);
	    if (pos > 0 && pos <= MAXLINE) {
		tab[pos] = YES;
	    }
	}	
    }
}

int tabpos(int pos, char* tab) {
    if (pos > MAXLINE) {
	return YES;
    }else {
	return tab[pos];
    }
}
```

### 5.12

对程序 entab 和 detab 做一些扩充，以接受下列缩写的命令：entab -m + n 表示制表符从第 m 列开始，每隔 n 列停止。选择（对使用者而言）比较方便的默认行为。

```c
/**
 * 练习 5-12：对程序 entab 和 detab 做一些扩充，以接受下列缩写的命令：entab -m + n 表示制表符从第 m 列开始，每隔 n 列停止。选择（对使用者而言）比较方便的默认行为。
 * */

#include <stdio.h>

#define MAXLINE 100
#define TABINC  8
#define YES     1
#define NO      0

void esettab(int argc, char* argv[], char* tab);
void entab(char* tab);

int main(int argc, char* argv[]) {
    char tab[MAXLINE + 1];
    esettab(argc, argv, tab);
    entab(tab);
    return 0;
}

#include <stdlib.h>

void esettab(int argc, char* argv[], char* tab) {
    int i, inc, pos;
    if (argc <= 1) {
	for (i = 1; i <= MAXLINE; i++) {
	    if (i % TABINC == 0) {
		tab[i] = YES;
	    }else {
		tab[i] = NO;
	    }
	}
    }else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+') {
	pos = atoi(&(*++argv)[1]);
	inc = atoi(&(*++argv)[1]);
	for (i = 1; i <= MAXLINE; i++) {
	    if (i != pos) {
		tab[i] = NO;
	    }else {
		tab[i] = YES;
		pos += inc;
	    }
	}
    }else {
	for (i = 1; i <= MAXLINE; i++) {
	    tab[i] = NO;
	}
	while (--argc > 0) {
	    pos = atoi(*++argv);
	    if (pos > 0 && pos <= MAXLINE) {
		tab[pos] = YES;
	    }
	}
    }
}
```

### 5.13

编写程序 tail，将其输入中的最后 n 行打印出来。默认情况下，n 的值为 10，但可通过一个可选参数改变 n 的值，因此，命令 tail -n 将打印其输入的最后 n 行。无论输入或 n 的值是否合理，该程序都应该能正常运行。编写的程序要充分低利用存储空间，输入行的存储方式应该同 5.6 节中排序程序的存储方式一样，而不采用固定长度的二维数组。

```c
/**
 * 练习 5-13：编写程序 tail，将其输入中的最后 n 行打印出来。默认情况下，n 的值为 10，但可通过一个可选参数改变 n 的值，因此，命令 tail -n 将打印其输入的最后 n 行。无论输入或 n 的值是否合理，该程序都应该能正常运行。编写的程序要充分低利用存储空间，输入行的存储方式应该同 5.6 节中排序程序的存储方式一样，而不采用固定长度的二维数组。
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10
#define LINES    100
#define MAXLEN   100

void error(char*);
int getline(char*, int);

int main(int argc, char* argv[]) {
    char* p;
    char* buf;
    char* bufend;
    char line[MAXLEN];
    char* lineptr[LINES];
    int first, i, last, len, n, nlines;

    if (argc == 1) {
	n = DEFLINES;
    }else if (argc == 2 && (*++argv)[0] == '-') {
	n = atoi(argv[0] + 1);
    }else {
	error("usage: tail [-n]");
    }

    if (n < 1 || n > LINES) {
	n = LINES;
    }
    for (i = 0; i < LINES; i++) {
	lineptr[i] = NULL;
    }
    if ((p = buf = malloc(LINES * MAXLEN)) == NULL) {
	error("tail: cannot allocate buf");
    }
    bufend = buf + LINES * MAXLEN;
    last = 0;
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
	if (p + len + 1 >= bufend) {
	    p = buf;
	}	
	lineptr[last] = p;
	strcpy(lineptr[last], line);
	if (++last >= LINES) {
	    last = 0;
	}
	p += len + 1;
	nlines++;
    }
    if (n > nlines) {
	n = nlines;
    }
    first = last - n;
    if (first < 0) {
	first += LINES;
    }
    for (i = first; n-- > 0; i = (i + 1) % LINES) {
	printf("%s", lineptr[i]);
    }
    return 0;
}

void error(char* s) {
    printf("%s\n", s);
    exit(1);
}
```

### 5.14

修改排序程序，使它能处理 -r 标记。该标记表明，以逆序（递减）方式排序。要保证 -r 和 -n 能够组合在一起使用。

```c
/**
 * 练习 5-14：修改排序程序，使它能处理 -r 标记。该标记表明，以逆序（递减）方式排序。要保证 -r 和 -n 能够组合在一起使用。
 * */

#include <stdio.h>
#include <string.h>

#define NUMERIC 1
#define DECR    2
#define LINES   100

int numcmp(char*, char*);
int readlines(char* [], int);
void qsort(char* [], int, int, int (*)(void*, void*));
void writelines(char* [], int, int);

static char option = 0;

int main(int argc, char* argv[]) {
    char *lineptr[LINES];
    int nlines;
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
	while (c == *++argv[0]) {
	    switch (c) {
		case 'n':
		    option |= NUMERIC;
		    break;
		case 'r':
		    option |= DECR;
		    break;
		default:
		    printf("sort: illegal option %c\n", c);
		    argc = 1;
		    rc = -1;
		    break;
	    }
	}
    }
    if (argc) {
	printf("Usage: sort -nr \n");
    }else {
	if ((nlines = readlines(lineptr, LINES)) > 0) {
	    if (option & NUMERIC) {
		qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))numcmp);
	    }else {
		qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))strcmp);
	    }
	    writelines(lineptr, nlines, option & DECR);
	}else {
	    printf("input too big to sort \n");
	    rc = -1;
	}
    }
    return rc;
}

void writelines(char* lineptr[], int nlines, int desc) {
    int i;
    if (desc) {
	for (i = nlines - 1; i >= 0; --i) {
	    printf("%s\n", lineptr[i]);
	}
    }else {
	for (i = 0; i < nlines; i++) {
	    printf("%s\n", lineptr[i]);
	}
    }
}
```

### 5.15

增加选项 -f，使得排序过程不考虑字母大小写之间的区别。例如，比较 a 和 A 时认为它们相等。

```c
/**
 * 练习 5-15：增加选项 -f，使得排序过程不考虑字母大小写之间的区别。例如，比较 a 和 A 时认为它们相等。
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMERIC 1
#define DECR    2
#define FOLD    4
#define LINES   100

int charcmp(char*, char*);
int numcmp(char*, char*);
int readlines(char* lineptr[], int maxlines);
void qsort(char* v[], int left, int right, int (*comp)(void*, void*));
void writelines(char* lineptr[], int nlines, int order);

static char option = 0;

int main(int argc, char* argv[]) {
    char* lineptr[LINES];
    int nlines;
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
	while (c = *++argv[0]) {
	    switch (c) {
		case 'f':
		    option |= FOLD;
		    break;
		case 'n':
		    option |= NUMERIC;
		    break;
		case 'r':
		    option |= DECR;
		    break;
		default:
		    printf("sort: illegal option %c\n", c);
		    argc = 1;
		    rc = -1;
		    break;
	    }
	}
    }
    if (argc) {
	printf("Usage: sort -fnr \n");
    }else {
	if ((nlines = readlines(lineptr, LINES)) > 0) {
	    if (option & NUMERIC) {
		qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))numcmp);
	    }else if (option & FOLD) {
		qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))charcmp);
	    }else {
		qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))strcmp);
	    }
	    writelines(lineptr, nlines, option & DECR);
	}else {
	    printf("input too big to sort \n");
	    rc = -1;
	}
    }
    return rc;
}

int charcmp(char* s, char* t) {
    for (; tolower(*s) == tolower(*t); s++, t++) {
	if (*s == '\0') {
	    return 0;
	}
    }
    return tolower(*s) - tolower(*t);
}
```

### 5.16

增加选项 -d（代表目录顺序）。该选项表明，只对字母、数字和空格进行比较。要保证该选项可以和 -f 组合在一起使用。

```c
/**
 * 练习 5-16：增加选项 -d（代表目录顺序）。该选项表明，只对字母、数字和空格进行比较。要保证该选项可以和 -f 组合在一起使用。
 * */

#include <stdio.h>
#include <ctype.h>

#define NUMERIC 1
#define DECR    2
#define FOLD    4
#define DIR     8
#define LINES   100

int charcmp(char*, char*);
int numcmp(char*, char*);
int readlines(char* lineptr[], int maxlines);
void qsort(char* v[], int left, int right, int (*comp)(void*, void*));
void writelines(char* lineptr[], int nlines, int order);

static char option = 0;

int main(int argc, char* argv[]) {
    char* lineptr[LINES];
    int nlines;
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
	while (c = *++argv[0]) {
	    switch (c) {
		case 'd':
		    option |= DIR;
		    break;
		case 'f':
		    option |= FOLD;
		    break;
		case 'n':
		    option |= NUMERIC;
		    break;
		case 'r':
		    option |= DECR;
		    break;
		default:
		    printf("sort: illegal option %c\n", c);
		    argc = 1;
		    rc = -1;
		    break;
	    }
	}
    }
    
    if (argc) {
	printf("Usage: sort -dfnr \n");
    }else {
	if ((nlines = readlines(lineptr, LINES)) > 0) {
	    if (option & NUMERIC) {
		qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))numcmp);
	    }else {
		qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))charcmp);
	    }
	    writelines(lineptr, nlines, option & DECR);
	}else {
	    printf("input too big to sort \n");
	    rc = -1;
	}
    }
    return rc;
}

int charcmp(char* s, char* t) {
    char a, b;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & DIR) ? 1 : 0;
    
    do {
	if (dir) {
	    while (!isalnum(*s) && *s != ' ' && *s != '\0') {
		s++;
	    }
	    while (!isalnum(*t) && *t != ' ' && *t != '\0') {
		t++;
	    }
	}
	a = fold ? tolower(*s) : *s;
	s++;
	b = fold ? tolower(*t) : *t;
	t++;
	if (a == b && a == '\0') {
	    return 0;
	}
    }while (a == b);
    return a - b;
}
```

### 5.17

增加字段处理功能，以使得排序程序可以根据行内的不同字段进行排序，每个字段按照一个单独的选项集合进行排序。（在对英文原书索引进行排序时，索引条目使用了 -df 选项，而对页码排序时使用了 -n 选项。

```c
/**
 * 练习 5-17：增加字段处理功能，以使得排序程序可以根据行内的不同字段进行排序，每个字段按照一个单独的选项集合进行排序。（在对英文原书索引进行排序时，索引条目使用了 -df 选项，而对页码排序时使用了 -n 选项。
 * */

#include <stdio.h>
#include <ctype.h>

#define NUMERIC 1
#define DECR    2
#define FOLD    4
#define DIR     8
#define LINES   100

int charcmp(char*, char*);
void error(char*);
int numcmp(char*, char*);
void readargs(int argc, char* argv[]);
int readlines(char* lineptr[], int maxlines);
void qsort(char* v[], int left, int right, int (*comp)(void*, void*));
void writelines(char* lineptr[], int nlines, int order);

char option = 0;
int pos1 = 0;
int pos2 = 0;

int main(int argc, char* argv[]) {
    char* lineptr[LINES];
    int nlines;
    int rc = 0;

    readargs(argc, argv);
    if ((nlines = readlines(lineptr, LINES)) > 0) {
	if (option & NUMERIC) {
	    qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))numcmp);
	}else {
	    qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))charcmp);
	}
	writelines(lineptr, nlines, option & DECR);
    }else {
	printf("input too big to sort \n");
	rc = -1;
    }
    return rc;
}

void readargs(int argc, char* argv[]) {
    int c;
    int atoi(char*);

    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+') {
	if (c == '-' && !isdigit(*(argv[0] + 1))) {
	    while (c == *++argv[0]) {
		switch (c) {
		    case 'd':
			option |= DIR;
			break;
		    case 'f':
			option |= FOLD;
			break;
		    case 'n':
			option |= NUMERIC;
			break;
		    case 'r':
			option |= DECR;
			break;
		    default:
			printf("sort: illegal option %c\n", c);
			error("Usage: sort -dfnr [+pos1] [-pos2]");
			break;
		}
	    }
	}else if (c == '-') {
	    pos2 = atoi(argv[0] + 1);
	}else if ((pos1 = atoi(argv[0] + 1)) < 0) {
	    error("Usage: sort -dfnr [+pos1] [-pos2]");
	}
    }
    if (argc || pos1 > pos2) {
	error("Usage: sort -dfnr [+pos1] [-pos2]");
    }
}

#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXSTR 100

int numcmp(char* s1, char* s2) {
    double v1, v2;
    char str[MAXSTR];

    substr(s1, str, MAXSTR);
    v1 = atof(str);
    substr(s2, str, MAXSTR);
    v2 = atof(str);
    if (v1 < v2) {
	return -1;
    }else if (v1 > v2) {
	return 1;
    }else {
	return 0;
    }
}

#define FOLD 4
#define DIR  8

int charcmp(char* s, char* t) {
    char a, b;
    int i, j, endpos;
    extern char option;
    extern int pos1, pos2;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & DIR) ? 1 : 0;

    i = j = pos1;
    if (pos2 > 0) {
	endpos = pos2;
    }else if ((endpos = strlen(s)) > strlen(t)) {
	endpos = strlen(t);
    }
    do {
	if (dir) {
	    while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0') {
		i++;
	    }
	    while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0') {
		j++;
	    }
	}
	if (i < endpos && j < endpos) {
	    a = fold ? tolower(s[i]) : s[i];
	    i++;
	    b = fold ? tolower(t[j]) : t[j];
	    j++;
	    if (a == b && a == '\0') {
		return 0;
	    }
	}
    }while (a == b && i < endpos && j < endpos);
    return a - b;
}

#include <string.h>

void error(char*);

void substr(char* s, char* str) {
    int i, j, len;
    extern int pos1, pos2;

    len = strlen(s);
    if (pos2 > 0 && len > pos2) {
	len = pos2;
    }else if (pos2 > 0 && len < pos2) {
	error("substr: string too short");
    }
    for (j = 0, i = pos1; i < len; i++, j++) {
	str[j] = s[i];
    }
    str[j] = '\0';
}
```

### 5.18

修改 dcl 程序，使它能够处理输入中的错误。

```c
/**
 * 练习 5-18：修改 dcl 程序，使它能够处理输入中的错误。
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {NAME, PARENS, BRACKETS};
enum {NO, YES};

void dcl(void);
void dirdcl(void);
void errmsg(char*);
int gettoken(void);

extern int tokentype;
extern char token[];
extern char name[];
extern char out[];
extern int prevtoken;

void dcl(void) {
    int ns;
    for (ns = 0; qettoken() == '*'; ) {
	ns++;
    }
    dirdcl();
    while (ns-- > 0) {
	strcat(out, " pointer to");
    }
}

void dirdcl(void) {
    int type;
    
    if (tokentype == '(') {
	dcl();
	if (tokentype != ')') {
	    errmsg("error: missing )\n");
	}
    }else if (tokentype == NAME) {
	strcpy(name, token);
    }else {
	errmsg("error: expected name or (dcl)\n");
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS) {
	if (type == PARENS) {
	    strcat(out, " function returning");
	}else {
	    strcat(out, " array");
	    strcat(out, token);
	    strcat(out, " of");
	}
    }
}

void errmsg(char* msg) {
    printf("%s", msg);
    prevtoken = YES;
}

#include <ctype.h>
#include <string.h>

int prevtoken = NO;

int gettoken(void) {
    int c, getch(void);
    void ungetch(int);
    char* p = token;

    if (prevtoken == YES) {
	prevtoken = NO;
	return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t');
    if (c == '(') {
	if ((c = getch()) == ')') {
	    strcpy(token, "()");
	    return tokentype = PARENS;
	}else {
	    ungetch(c);
	    return tokentype = '(';
	}
    }else if (c == '[') {
	for (*p++ = c; (*p++ = getch()) != ']';);
	*p = '\0';
	return tokentype = BRACKETS;
    }else if (isalpha(c)) {
	for (*p++ = c; (*p++ = getch()) != ']';) {
	    *p++ = c;
	}
	*p = '\0';
	ungetch(c);
	return tokentype = NAME;
    }else {
	return tokentype = c;
    }
}
```

### 5.19

练习 undcl 程序，使它在把文字描述转换为声明的过程中不会生成多余的圆括号。

```c
/**
 * 练习 undcl 程序，使它在把文字描述转换为声明的过程中不会生成多余的圆括号。
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
int gettoken(void);
int nexttoken(void);

int tokentype;
char token[MAXTOKEN];
char out[1000];

int main() {
    int type;
    char temp[MAXTOKEN];
    
    while (gettoken() != EOF) {
	strcpy(out, token);
	while ((type = gettoken()) != '\n') {
	    if (type == PARENS || type == BRACKETS) {
		strcat(out, token);
	    }else if (type == '*') {
		if ((type = nexttoken()) == PARENS || type == BRACKETS) {
		    sprintf(temp, "(*%s)", out);
		}else {
		    sprintf(temp, "*%s", out);
		}
		strcpy(out, temp);
	    }else if (type == NAME) {
		sprintf(temp, "%s %s", token, out);
		strcpy(out, temp);
	    }else {
		printf("invalid input at %s\n", token);
	    }
	}
	printf("%s\n", out);
    }
    return 0;
}

enum {NO, YES};

int gettoken(void);

int nexttoken(void) {
    int type;
    extern int prevtoken;
    type = gettoekn();
    prevtoken = YES;
    return type;
}
```

### 5.20

扩展 dcl 程序的功能，使它能够处理包含其他成分的声明，例如带有函数参数类型的声明、带有类似于 const 限定符的声明等。

```c
/**
 * 扩展 dcl 程序的功能，使它能够处理包含其他成分的声明，例如带有函数参数类型的声明、带有类似于 const 限定符的声明等。
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {NAME, PARENS, BRACKETS};
enum {NO, YES};

void dcl(void);
void dirdcl(void);
void errmsg(char*);
int gettoken(void);

extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];
extern int prevtoken;

void dcl(void) {
    int ns;
    for (ns = 0; gettoken() == '*';) {
	ns++;
    }
    dirdcl();
    while (ns-- > 0) {
	strcat(out, " pointer to");
    }
}

void dirdcl(void) {
    int type;
    void parmdcl(void);

    if (tokentype == '(') {
	dcl();
	if (tokentype != ')') {
	    errmsg("error: missing )\n");
	}else if (tokentype == NAME) {
	    if (name[0] == '\0') {
		strcpy(name, token);
	    }
	}else {
	    prevtoken = YES;
	}
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(') {
	if (type == PARENS) {
	    strcat(out, "function returning");
	}else if (type == '(') {
	    strcat(out, "function expectiong");
	    parmdcl();
	    strcat(out, " and returning");
	}else {
	    strcat(out, " array");
	    strcat(out, token);
	    strcat(out, " of");
	}
    }
}

void errmsg(char* msg) {
    printf("%s", msg);
    prevtoken = YES;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXTOKEN 100

void dcl(void);
void errmsg(char*);
void dclspec(void);
int typespec(void);
int typequal(void);
int compare(char**, char**);
int gettoken(void);

extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];
extern int prevtoken;

void parmdcl(void) {
    do {
	dclspec();
    }while (tokentype == '.');
    if (tokentype != ')') {
	errmsg("missing ) in parameter declaration\n");
    }
}

void dclspec(void) {
    char temp[MAXTOKEN];
    temp[0] = '\0';
    gettoken();
    do {
	if (tokentype != NAME) {
	    prevtoken = YES;
	    dcl();
	}else if (typespec() == YES) {
	    strcat(temp, " ");
	    strcat(temp, token);
	    gettoken();
	}else if (typequal() == YES) {
	    strcat(temp, " ");
	    strcat(temp, token);
	}else {
	    errmsg("unknown type in parameter list\n");
	}
    }while (tokentype != ',' && tokentype != ')');
    strcat(out, temp);
    if (tokentype == ',') {
	strcat(out, ",");
    }
}

int typespec(void) {
    static char* types[] = {
	"char",
	"int",
	"void"
    };
    char* pt = token;
    if (bsearch(&pt, types, sizeof(types) / sizeof(char*), sizeof(char*), compare) == NULL) {
	return NO;
    }else {
	return YES;
    }
}

int typequal(void) {
    static char* typeq[] = {
	"const",
	"volatile"
    };
    char* pt = token;
    if (bsearch(&pt, typeq, sizeof(typeq) / sizeof(char*), sizeof(char*), compare) == NULL) {
	return NO;
    }else {
	return YES;
    }
}

int compare(char** s, char** t) {
    return strcmp(*s, *t);
}
```

## 第六章 结构

### 6.1

上述 getword 函数不能正确处理下划线、字符串常量、注释及预处理控制指令。请编写一个更完善的 getword 函数。

```c
/**
 * 练习 6-1：上述 getword 函数不能正确处理下划线、字符串常量、注释及预处理控制指令。请编写一个更完善的 getword 函数。
 * */

#include <stdio.h>
#include <ctype.h>

int getword(char* word, int lim) {
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char* w = word;

    while (isspace(c = getch()));
    if (c != EOF) {
	*w++ = c;
    }
    if (isalpha(c) || c == '_' || c == '#') {
	for (; --lim > 0; w++) {
	    if (!isalnum(*w = getch()) && *w != '_') {
		ungetch(*w);
		break;
	    }
	}
    }else if (c == '\'' || c == '"') {
	for (; --lim > 0; w++) {
	    if ((*w = getch()) == '\\') {
		*++w = getch();
	    }else if (*w == c) {
		w++;
		break;
	    }else if (*w == EOF) {
		break;
	    }
	}
    }else if (c == '/') {
	if ((d = getch()) == '*') {
	    c = comment();
	}else {
	    ungetch(d);
	}
    }

    *w = '\0';
    return c;
}

int comment(void) {
    int c;
    while ((c = getch()) != EOF) {
	if (c == '*') {
	    if ((c = getch()) == '/') {
		break;
	    }else {
		ungetch(c);
	    }
	}
    }
    return c;
}
```

### 6.2

编写一个程序，用以读入一个 C 语言程序，并按字母表顺序分组打印变量名，要求每一组内各变量名的前 6 个字符相同，其余字符不同。字符串和注释中的单词不予考虑。请将 6 作为一个可在命令行中设定的参数。

```c
/**
 * 练习 6-2：编写一个程序，用以读入一个 C 语言程序，并按字母表顺序分组打印变量名，要求每一组内各变量名的前 6 个字符相同，其余字符不同。字符串和注释中的单词不予考虑。请将 6 作为一个可在命令行中设定的参数。
 * */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode {
    char* word;
    int match;
    struct tnode* left;
    struct tnode* right;
};

#define MAXWORD 100
#define YES	1
#define NO	0

struct tnode* addtreex(struct tnode*, char*, int, int*);
void treexprint(struct tnode*);
int getword(char*, int);

int main(int argc, char* argv[]) {
    struct tnode* root;
    char word[MAXWORD];
    int found = NO;
    int num;

    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
	if (isalpha(word[0]) && strlen(word) >= num) {
	    root = addtreex(root, word, num, &found);
	}
	found = NO;
    }
    treexprint(root);
    return 0;
}

struct tnode* talloc(void);
int compare(char*, struct tnode*, int, int*);

struct tnode* addtreex(struct tnode* p, char* w, int num, int* found) {
    int cond;
    
    if (p == NULL) {
	p = talloc();
	p -> word = strdup(w);
	p -> match = *found;
	p -> left = p -> right = NULL;
    }else if ((cond = compare(w, p, num, found)) < 0) {
	p -> left = addtreex(p -> left, w, num, found);
    }else if (cond > 0) {
	p -> right = addtreex(p -> right, w, num, found);
    }
    return p;
}

int compare(char* s, struct tnode* p, int num, int* found) {
    int i;
    char* t = p -> word;
    for (i = 0; *s == *t; i++, s++, t++) {
	if (*s == '\0') {
	    return 0;
	}
    }
    if (i >= num) {
	*found = YES;
	p -> match = YES;
    }
    return *s - *t;
}

void treexprint(struct tnode* p) {
    if (p != NULL) {
	treexprint(p -> left);
	if (p -> match) {
	    printf("%s\n", p -> word);
	}
	treexprint(p -> right); 
    }
}
```

### 6.3

编写一个交叉引用程序，打印文档中所有单词的列表，并且每个单词都有一个列表，记录出现过该单词的行号。对 the、and 等非实义单词不予考虑。

```c
/**
 * 练习 6-3：编写一个交叉引用程序，打印文档中所有单词的列表，并且每个单词都有一个列表，记录出现过该单词的行号。对 the、and 等非实义单词不予考虑。
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100
struct linklist {
    int lnum;
    struct linklist* ptr;
};

struct tnode {
    char* word;
    struct linklist* lines;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* addtreex(struct tnode*, char*, int);
int getword(char*, int);
int noiseword(char*);
void treexprint(struct tnode*);

int main() {
    struct tnode* root;
    char word[MAXWORD];
    int linenum = 1;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
	if (isalpha(word[0]) && noiseword(word) == -1) {
	    root = addtreex(root, word, linenum);
	}else if (word[0] == '\n') {
	    linenum++;
	}
    }
    treexprint(root);
    return 0;
}

struct tnode* talloc(void);
struct linklist* lalloc(void);
void addln(struct tnode*, int);

struct tnode* addtreex(struct tnode* p, char* w, int linenum) {
    int cond;
    
    if (p == NULL) {
	p = talloc();
	p -> word = strdup(w);
	p -> lines = lalloc();
	p -> lines -> lnum = linenum;
	p -> lines -> ptr = NULL;
	p -> left = p -> right = NULL;
    }else if ((cond = strcmp(w, p -> word)) == 0) {
	addln(p, linenum);
    }else if (cond < 0) {
	p -> left = addtreex(p -> left, w, linenum);
    }else {
	p -> right = addtreex(p -> right, w, linenum);
    }
    return p;
}

void addln(struct tnode* p, int linenum) {
    struct linklist* temp;
    temp = p -> lines;
    while (temp -> ptr != NULL && temp -> lnum != linenum) {
	temp = temp -> ptr;
    }
    if (temp -> lnum != linenum) {
	temp -> ptr = lalloc();
	temp -> ptr -> lnum = linenum;
	temp -> ptr -> ptr = NULL;
    }
}

void treexprint(struct tnode* p) {
    struct linklist* temp;
    if (p != NULL) {
	treexprint(p -> left);
	printf("%10s: ", p -> word);
	for (temp = p -> lines; temp != NULL; temp = temp -> ptr) {
	    printf("%4d ", temp -> lnum);
	}
	printf("\n");
	treexprint(p -> right);
    }
}

struct linklist* lalloc(void) {
    return (struct linklist *)malloc(sizeof(struct linklist));
}

int noiseword(char* w) {
    static char* nw[] = {
	"a",
	"an",
	"and",
	"are",
	"in",
	"is",
	"of",
	"or",
	"that",
	"the",
	"this",
	"to"
    };
    
    int cond, mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(char*) - 1;

    while (low <= high) {
	mid = (low + high) / 2;
	if ((cond = strcmp(w, nw[mid])) < 0) {
	    high = mid - 1;
	}else if (cond > 0) {
	    low = mid - 1;
	}else {
	    return mid;
	}
    }
    return -1;
}
```

### 6.4

待补充～欢迎 pull request

### 6.5

编写函数 undef，它将从由 lookup 和 install 维护的表中删除一个变量名及其定义。

```c
/**
 * 练习 6-5：编写函数 undef，它将从由 lookup 和 install 维护的表中删除一个变量名及其定义。
 * */

#include <stdio.h>

#define HASHSIZE 101

unsigned hash(char*);

static struct nlist* hashtab[HASHSIZE];

struct nlist {
    struct nlist* next;
    char* name;
    char* defn;
};

void undef(char* s) {
    int h;
    struct nlist* prev, *np;
    
    prev = NULL;
    h = hash(s);
    for (np = hashtab[h]; np != NULL; np = np -> next) {
	if (strcmp(s, np -> name) == 0) {
	    break;
	}
	prev = np;
    }
    if (np != NULL) {
	if (prev == NULL) {
	    hashtab[h] = np -> next;
	}else {
	    prev -> next = np -> next;
	}
	free((void*)np -> name);
	free((void*)np -> defn);
	free((void*)np);
    }
}
```

### 6.6

以本节介绍的函数为基础，编写一个适合 C 语言程序使用的 #define 处理器的简单版本（即无参数的情况）。你会发现 getch 和 ungetch 函数非常有用。

```c
/**
 * 以本节介绍的函数为基础，编写一个适合 C 语言程序使用的 #define 处理器的简单版本（即无参数的情况）。你会发现 getch 和 ungetch 函数非常有用。
 * */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct nlist {
    struct nlist* next;
    char* name;
    char* defn;
};

void error(int, char*);
int getch(void);
void getdef(void);
int getword(char*, int);
struct nlist* install(char*, char*);
struct nlist* lookup(char*);
void skipblanks(void);
void undef(char*);
void ungetch(int);
void ungets(char*);

int main() {
    char w[MAXWORD];
    struct nlist* p;
    
    while (getword(w, MAXWORD) != EOF) {
	if (strcmp(w, "#") == 0) {
	    getdef();
	}else if (!isalpha(w[0])) {
	    printf("%s", w);
	}else if ((p = lookup(w)) == NULL) {
	    printf("%s", w);
	}else {
	    ungets(p -> defn);
	}
    }

    return 0;
}

void getdef(void) {
    int c, i;
    char def[MAXWORD], dir[MAXWORD], name[MAXWORD];

    skipblanks();
    if (!isalpha(getword(dir, MAXWORD))) {
	error(dir[0], "getdef: expecting a directive after #");
    }else if (strcmp(dir, "define") == 0) {
	skipblanks();
	if (!isalpha(getword(name, MAXWORD))) {
	    error(name[0], "getdef: non-alpha - name expected");
	}else {
	    skipblanks();
	    for (i = 0; i < MAXWORD - 1; i++) {
		if ((def[i] = getch()) == EOF || def[i] == '\n') {
		    break;
		}
	    }
	    def[i] = '\0';
	    if (i <= 0) {
		error('\n', "getdef: incomplete define");
	    }else {
		install(name, def);
	    }
	}
    }else if (strcmp(dir, "undef") == 0) {
	skipblanks();
	if (!isalpha(getword(name, MAXWORD))) {
	    error(name[0], "getdef: non-alpha in undef");
	}else {
	    undef(name);
	}
    }else {
	error(dir[0], "getdef: expecting a directive after #");
    }
}

void error(int c, char* s) {
    printf("error: %s\n", s);
    while (c != EOF && c != '\n') {
	c = getch();
    }
}

void skipblanks(void) {
    int c;
    while ((c = getch()) == ' ' || c == '\t');
    ungetch(c);
}
```

## 第七章 输入与输出

### 7.1

编写一个程序，根据它自身被调用时存放在 argv[0] 中的名字，实现将大写字母转换为小写字母或将小写字母转换为大写字母的功能。

```c
/**
 * 练习 7-1：编写一个程序，根据它自身被调用时存放在 argv[0] 中的名字，实现将大写字母转换为小写字母或将小写字母转换为大写字母的功能。
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    int c;
    if (strcmp(argv[0], "lower") == 0) {
	while ((c = getchar()) != EOF) {
	    putchar(tolower(c));
	}
    }else {
	while ((c = getchar()) != EOF) {
	    putchar(toupper(c));
	}
    }
    return 0;
}
```

### 7.2

编写一个程序，以合理的方式打印任何输入。该程序至少能根据用户的习惯以八进制或十六进制打印非显示字符，并截断长文本行。

```c
/**
 * 练习 7-2：编写一个程序，以合理的方式打印任何输入。该程序至少能根据用户的习惯以八进制或十六进制打印非显示字符，并截断长文本行。
 * */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define DCTLEN  6

int main() {
    int c, pos;
    int inc(int pos, int n);

    pos = 0;
    while ((c = getchar()) != EOF) {
	if (iscntrl(c) || c == ' ') {
	    pos = inc(pos, DCTLEN);
	    printf(" \\%03o ", c);
	    if (c == '\n') {
		pos = 0;
		putchar('\n');
	    }else {
		pos = inc(pos, 1);
		putchar(c);
	    }
	}
    }
    return 0;
}

int inc(int pos, int n) {
    if (pos + n < MAXLINE) {
	return pos + n;
    }else {
	putchar('\n');
	return n;
    }
}
```

### 7.3

改写 minprintf 函数，使它能完成 printf 函数的更多功能。

```c
/**
 * 练习 7-3：改写 minprintf 函数，使它能完成 printf 函数的更多功能。
 * */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT 100

void minprintf(char *fmt, ...) {
    va_list ap;
    char* p, *sval;
    char localfmt[LOCALFMT];
    int i, ival;
    unsigned uval;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
	if (*p != '%') {
	    putchar(*p);
	    continue;
	}
	i = 0;
	localfmt[i++] = '%';
	while (*(p + 1) && !isalpha(*(p + 1))) {
	    localfmt[i++] = *++p;
	}
	localfmt[i++] = *(p + 1);
	localfmt[i] = '\0';
	switch(*++p) {
	    case 'd':
	    case 'i':
		ival = va_arg(ap, int);
		printf(localfmt, ival);
		break;
	    case 'x':
	    case 'X':
	    case 'u':
	    case 'o':
		uval = va_arg(ap, unsigned);
		printf(localfmt, uval);
		break;
	    case 'f':
		dval = va_arg(ap, double);
		printf(localfmt, dval);
		break;
	    case 's':
		sval = va_arg(ap, char*);
		printf(localfmt, sval);
		break;
	    default:
		printf(localfmt);
		break;
	}
    }
    va_end(ap);
} 
```

### 7.4

类似于上一节中的函数 minprintf, 编写 scanf 函数的一个简化版本。

```c
/**
 * 类似于上一节中的函数 minprintf, 编写 scanf 函数的一个简化版本。
 * */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT 100

void minscanf(char* fmt, ...) {
    va_list ap;
    char* p, *sval;
    char localfmt[LOCALFMT];
    int c, i, *ival;
    unsigned *uval;
    double *dval;

    i = 0;
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
	if (*p != '%') {
	    localfmt[i++] = *p;
	}
    }
    localfmt[i++] = '%';
    while (*(p + 1) && !isalpha(*(p + 1))) {
	localfmt[i++] = *++p;
    }
    localfmt[i++] = *(p + 1);
    localfmt[i] = '\0';
    switch(*++p) {
	case 'd':
	case 'i':
	    ival = va_arg(ap, int*);
	    scanf(localfmt, ival);
	    break;
	case 'x':
	case 'X':
	case 'u':
	case 'o':
	    uval = va_arg(ap, unsigned*);
	    scanf(localfmt, uval);
	    break;
	case 'f':
	    dval = va_arg(ap, double*);
	    scanf(localfmt, dval);
	    break;
	case 's':
	    sval = va_arg(ap, char*);
	    scanf(localfmt, sval);
	    break;
	default:
	    scanf(localfmt);
	    break;
	i = 0;
    }
    va_end(ap);
}
```

### 7.5

编写一个程序，比较两个文件并打印它们第一个不相同的行

```c
/**
 * 练习 7-5：改写第 4 章中的后缀计数器程序，用 scanf 函数和（或）sscanf 函数实现输入以及数的转换
 * */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getop(char s[]) {
    int c, i, rc;
    static char lastc[] = " ";

    sscanf(lastc, "%c", &c);
    lastc[0] = ' ';
    while ((s[0] = c) == ' ' || c == '\t') {
	if (scanf("%c", &c) == EOF) {
	    c = EOF;
	}
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
	return c;
    } 
    if (isdigit(c)) {
	do {
	    rc = scanf("%c", &c);
	    if (!isdigit(s[++i] = c)) {
		break;
	    }
	}while (rc != EOF);
    }
    if (c == '.') {
	do {
	    rc = scanf("%c", &c);
	    if (!isdigit(s[++i] = c)) {
		break;
	    }
	}while (rc != EOF);
    }
    s[i] = '\0';
    if (rc != EOF) {
	lastc[0] = c;
    }
    return NUMBER;
}
```

### 7.6

编写一个程序，比较两个文件并打印它们第一个不相同的行

```c
/**
 * 编写一个程序，比较两个文件并打印它们第一个不相同的行
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

int main(int argc, char* argv[]) {
    FILE *fp1, *fp2;
    void filecomp(FILE* fp1, FILE* fp2);
    
    if (argc != 3) {
	fprintf(stderr, "comp: need two file names\n");
	exit(1);
    }else {
	if ((fp1 = fopen(*++argv, "r")) == NULL) {
	    fprintf(stderr, "comp: can't open %s\n", *argv);
	    exit(1);
	}else if ((fp2 = fopen(*++argv, "r")) == NULL) {
	    fprintf(stderr, "comp: cant't open%s\n", *argv);
	    exit(1);
	}else {
	    filecomp(fp1, fp2);
	    fclose(fp1);
	    fclose(fp2);
	    exit(0);
	}
    }
}

void filecomp(FILE* fp1, FILE* fp2) {
    char line1[MAXLINE], line2[MAXLINE];
    char* lp1, *lp2;

    do {
	lp1 = fgets(line1, MAXLINE, fp1);
	lp2 = fgets(line2, MAXLINE, fp2);
	if (lp1 == line1 && lp2 == line2) {
	    if (strcmp(line1, line2) != 0) {
		printf("first difference in line\n%s\n", line1);
		lp1 = lp2 = NULL;
	    }
	}else if (lp1 != line1 && lp2 == line2) {
	    printf("end of first file at line\n%s\n", line2);
	}else if (lp1 == line1 && lp2 != line2) {
	    printf("end of second file at line\n%s\n", line1);
	}
    }while (lp1 == line1 && lp2 == line2);
}
```

### 7.7

修改第 5 章的模式查找程序，使它从一个命令文件的集合中读取输入（有文件名参数时），如果没有文件名参数，则从标准输入中读取输入。当发现一个匹配行时，是否应该将相应的文件名打印出来？

```c
/**
 * 练习 7-7：修改第 5 章的模式查找程序，使它从一个命令文件的集合中读取输入（有文件名参数时），如果没有文件名参数，则从标准输入中读取输入。当发现一个匹配行时，是否应该将相应的文件名打印出来？
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int main(int argc, char* argv[]) {
    char pattern[MAXLINE];
    int c, except = 0, number = 0;
    FILE* fp;
    void fpat(FILE* fp, char* fname, char* pattern, int except, int number);
    while (--argc > 0 && (*++argv)[0] == '-') {
	while (c = *++argv[0]) {
	    switch(c) {
		case 'x':
		    except = 1;
		    break;
		case 'n':
		    number = 1;
		    break;
		default:
		    printf("find: illegal option %c\n", c);
		    argc = 0;
		    break;
	    }
	}
    } 
    if (argc >= 1) {
	strcpy(pattern, *argv);
    }else {
	printf("Usage: find [-x] [-n] pattern [file ...]\n");
	exit(1);
    }
    if (argc == 1) {
	fpat(stdin, "", pattern, except, number);
    }else {
	while (--argc > 0) {
	    if ((fp = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "find: can't open %s\n", *argv);
		exit(1);
	    }else {
		fpat(fp, *argv, pattern, except, number);
		fclose(fp);
	    }
	}
    }
    return 0;
}

void fpat(FILE* fp, char* fname, char* pattern, int except, int number) {
    char line[MAXLINE];
    long lineno = 0;

    while (fgets(line, MAXLINE, fp) != NULL) {
	++lineno;
	if ((strstr(line, pattern) != NULL) != except) {
	    if (*fname) {
		printf("%s - ", fname);
	    }
	    if (number) {
		printf("%ld ", lineno);
	    }
	    printf("%s", line);
	}
    }
}
```

### 7.8

编写一个程序，以打印一个文件集合，每个文件从新的一页开始打印，并且打印每个文件相应的标题和页数。

```c
/**
 * 练习 7-8：编写一个程序，以打印一个文件集合，每个文件从新的一页开始打印，并且打印每个文件相应的标题和页数。
 * */

#include <stdio.h>
#include <stdlib.h>

#define MAXBOT 3
#define MAXHDR 5
#define MAXLINE 100
#define MAXPAGE 66

int main(int argc, char* argv[]) {
    FILE* fp;
    void fileprintf(FILE* fp, char* fname);
    if (argc == 1) {
	fileprint(stdin, " ");
    }else {
	while (--argc > 0) {
	    if ((fp = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "print: can't open %s\n", *argv);
		exit(1);
	    }else {
		fileprint(fp, *argv);
		fclose(fp);
	    }
	}
    }
    return 0;
}

void fileprintf(FILE* fp, char* fname) {
    int lineno, pageno = 1;
    char line[MAXLINE];
    int heading(char* fname, int pageno);
    lineno = heading(fname, pageno++);
    while (fgets(line, MAXLINE, fp) != NULL) {
	if (lineno == 1) {
	    fprintf(stdout, "\f");
	    lineno = heading(fname, pageno++);
	}
	fputs(line, stdout);
	if (++lineno > MAXPAGE - MAXBOT) {
	    lineno = 1;
	}
    }
}

int heading(char* fname, int pageno) {
    int ln = 3;
    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s	page %d\n", fname, pageno);
    while (ln++ < MAXHDR) {
	fprintf(stdout, "\n");
    }
    return ln;
}
```

### 7.9

类似于 isupper 这样的函数可以通过某种方式实现以达到节省空间或时间的目的。考虑节省空间或时间的实现方式。

```c
/**
 * 练习 7-9：类似于 isupper 这样的函数可以通过某种方式实现以达到节省空间或时间的目的。考虑节省空间或时间的实现方式。
 * */

int isupper(char c) {
    if (c >= 'A' && c <= 'Z') {
	return 1;
    }else {
	return 0;
    }
}
```

## 第八章 UNIX系统接口

### 8.1

用 read、write、open 和 close 系统调用代替标准库中功能等价的函数，重写第 7 章的 cat 程序，并通过实验比较两个版本的相对执行速度。

```c
/**
 * 练习 8-1：用 read、write、open 和 close 系统调用代替标准库中功能等价的函数，重写第 7 章的 cat 程序，并通过实验比较两个版本的相对执行速度。
 * */

#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"

void error(char* fmt, ...);

int main(int argc, char* argv[]) {
    int fd;
    void filecopy(int ifd, int ofd);

    if (argc == 1) {
	filecopy(0, 1);
    }else {
	while (--argc > 0) {
	    if ((fd = open(*++argv, O_RDONLY)) == -1) {
		error("cat: cant't open %s", *argv);
	    }else {
		filecopy(fd, 1);
		close(fd);
	    }
	}
    }
    return 0;
}

void filecopy(int ifd, int ofd) {
    int n;
    char buf[BUFSIZ];
    
    while ((n = read(ifd, buf, BUFSIZ)) > 0) {
	if (write(ofd, buf, n) != n) {
	    error("cat: write error");
	}
    }
}
```

### 8.2

用字段代替显式的按位操作、重写函数 fopen 和 _fillbuf。比较相应代码的长度和执行速度。

```c
/**
 * 练习 8-2：用字段代替显式的按位操作、重写函数 fopen 和 _fillbuf。比较相应代码的长度和执行速度。
 * */

#include <fcntl.h>
#include "syscalls.h"

#define PERMS 0666

FILE* fopen(char* name, char* mode) {
    int fd;
    FILE* fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
	return NULL;
    }
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
	if (fp -> flag.is_read == 0 && fp -> flag.is_write == 0) {
	    break;
	}
    }
    if (fp >= _iob + OPEN_MAX) {
	return NULL;
    }

    if (*mode == 'w') {
	fd = creat(name, PERMS);
    }else if (*mode == 'a') {
	if ((fd = open(name, O_WRONLY, 0)) == -1) {
	    fd = creat(name, PERMS);
	}
	lseek(fd, 0L, 2);
    }else {
	fd = open(name, O_RDONLY, 0);
    }
    if (fd == -1) {
	return NULL;
    }
    fp -> fd = fd;
    fp -> cnt = 0;
    fp -> base = NULL;
    fp -> flag.is_unbuf = 0;
    fp -> flag.is_buf = 1;
    fp -> flag.is_eof = 0;
    fp -> flag.is.err = 0;
    if (*mode == 'r') {
	fp -> flag.is_read = 1;
	fp -> flag.is_write = 0;
    }else {
	fp -> flag.is_read = 0;
	fp -> flag.is_write = 1;
    }
    return fp;
}

int _fillbuf(FILE* fp) {
    int bufsize;
    if (fp -> flag.is_read == 0 || fp -> flag.is_eof == 1 || fp -> flag.is_err == 1) {
	return EOF;
    }
    bufsize = (fp -> flag.is_unbuf == 1) ? 1 : BUFSIZ;
    if (fp -> base == NULL) {
	if ((fp -> base = (char*)malloc(bufsize)) == NULL) {
	    return EOF;
	}
    }
    fp -> ptr = fp -> base;
    fp -> cnt = read(fp -> fd, fp -> ptr, bufsize);
    if (--fp -> cnt < 0) {
	if (fp -> cnt == -1) {
	    fp -> flag.is_eof = 1;
	}else {
	    fp -> flag.is_err = 1;
	}
	fp -> cnt = 0;
	return EOF;
    }
    return (unsigned char)*fp -> ptr++;
}
```

### 8.3

请设计并编写函数 _flushbuf、fflush 和 fclose。

```c
/**
 * 请设计并编写函数 _flushbuf、fflush 和 fclose。
 * */

#include "syscalls.h"

int _flushbuf(int x, FILE* fp) {
    unsigned nc;
    int bufsize;

    if (fp < _iob || fp >= _iob + OPEN_MAX) {
	return EOF;
    }
    if ((fp -> flag & (_WRITE | _ERR)) != _WRITE) {
	return EOF;
    }
    bufsize = (fp -> flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp -> base == NULL) {
	if ((fp -> base = (char*)malloc(bufsize)) == NULL) {
	    fp -> flag |= _ERR;
	    return EOF;
	}
    }else {
	nc = fp -> ptr - fp -> base;
	if (write(fp -> fd, fp -> base ,nc) != nc) {
	    fp -> flag |= _ERR;
	    return EOF;
	}
    }
    fp -> ptr = fp -> base;
    *fp -> ptr++ = (char)x;
    fp -> cnt = bufsize - 1;
    return x;
}

int fclose(FILE* fp) {
    int rc;
    if ((rc = fflush(fp)) != EOF) {
	free(fp -> base);
	fp -> ptr = NULL;
	fp -> cnt = 0;
	fp -> base = NULL;
	fp -> flag &= ~(_READ | _WRITE);
    }
    return rc;
}

int fflush(FILE* fp) {
    int rc = 0;
    if (fp < _iob || fp >= _iob + OPEN_MAX) {
	return EOF;
    }
    if (fp -> flag & _WRITE) {
	rc = _flushbuf(0, fp);
    }
    fp -> ptr = fp -> base;
    fp -> cnt = (fp -> flag & _UNBUF) ? 1 : BUFSIZ;
    return rc;
}
```

### 8.4

标准库函数`int fseek(FILE* fp, long offset, int origin)`类似于函数 lseek，所不同的是，该函数中的 fp 是一个文件指针而不是文件描述符，且返回值是一个 int 类型的状态而非位置值，编写函数 fseek，并确保该函数与库中其他函数使用的缓冲能够协同工作。

```c
/**
 * 练习 8-4：标准库函数
 * int fseek(FILE* fp, long offset, int origin)
 * 类似于函数 lseek，所不同的是，该函数中的 fp 是一个文件指针而不是文件描述符，且返回值是一个 int 类型的状态而非位置值，编写函数 fseek，并确保该函数与库中其他函数使用的缓冲能够协同工作。
 * */

#include "syscall.h"

int fseek(FILE* fp, long offset, int origin) {
    unsigned nc;
    long rc = 0;

    if (fp -> flag & _READ) {
	if (origin == 1) {
	    offset -= fp -> cnt;
	}
	rc = lseek(fp -> fd, offset, origin);
	fp -> cnt = 0;
    }else if (fp -> flag & _WRITE) {
	if ((nc = fp -> ptr - fp -> base) > 0) {
	    if (write(fp -> fd, fp -> base, nc) != nc) {
		rc = -1;
	    }
	}
	if (rc != -1) {
	    rc = lseek(fp -> fd, offset, origin);
	}
    }
    return (rc == -1) ? -1 : 0;
}
```

### 8.5

修改 fsize 程序，打印 i 结点项中包含的其他信息。

```c
/**
 * 练习 8-5：修改 fsize 程序，打印 i 结点项中包含的其他信息。
 * */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"

int stat(char*, struct stat*);
void dirwalk(char*, void (*fcn)(char*));

void fsize(char* name) {
    struct stat stbuf;
    if (stat(name, &stbuf) == -1) {
	fprintf(stderr, "fsize: can't access %s\n", name);
	return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
	dirwalk(name, fsize);
    }
    printf("%5u %6o %3u %8ld %s\n", stbuf.st_ino, stbuf.st_mode, stbuf.st_nlink, stbuf.st_size, name);
}

```

### 8.6

标准库函数 calloc(n, size) 返回一个指针，它指向 n 个长度为 size 的对象，且所有分配的存储空间都被初始化为 0.通过调用或修改 malloc 函数来实现 calloc 函数。

```c
/**
 * 练习 8-6：标准库函数 calloc(n, size) 返回一个指针，它指向 n 个长度为 size 的对象，且所有分配的存储空间都被初始化为 0.通过调用或修改 malloc 函数来实现 calloc 函数。
 * */

#include "syscall.h"

void *calloc(unsigned n, unsigned size) {
    unsigned i, nb;
    char* p, *q;

    nb = n * size;
    if ((p = q = malloc(nb)) != NULL) {
	for (i = 0; i < nb; i++) {
	    *p++ = 0;
	}
    }
    return q;
}

```

### 8.7

malloc 接收对存储空间的请求时，并不检查请求长度的合理性；而 free 则认为被释放的块包含一个有效的长度字段。改进这些函数，使它们具有错误检查的功能。

```c
/**
 * malloc 接收对存储空间的请求时，并不检查请求长度的合理性；而 free 则认为被释放的块包含一个有效的长度字段。改进这些函数，使它们具有错误检查的功能。
 * */

#include "syscalls.h"

#define MAXBYTES (unsigned) 10240

static unsigned maxalloc;
static Header base;
static Header *freep = NULL;

void *malloc(unsigned nbytes) {
    Header* p, *prevp;
    static Header *morecore(unsigned);
    unsigned nunits;

    if (nbytes > MAXBYTES) {
	fprintf(stderr, "alloc: can't allocate more than %u bytes\n", MAXBYTES);
	return NULL;
    }
    nunits = (nbytes * sizeof(Header) - 1) / sizeof(Header) + 1;
}

#define NALLOC 1024

static Header *morecore(unsigned nu) {
    char* cp, *sbrk(int);
    Header* up;

    if (nu < NALLOC) {
	nu = NALLOC;
    }
    cp = sbrk(nu * sizeof(Header));
    if (cp == (char*) - 1) {
	return NULL;
    }
    up = (Header*)cp;
    up -> s.size = nu;
    maxalloc = (up -> s.size > maxalloc) ? up -> s.size : maxalloc;
    free((void*)(up + 1));
    return freep;
}

void free(void* ap) {
    Header* bp, *p;
    
    bp = (Header*)ap - 1;
    if (bp -> s.size == 0 || bp -> s.size > maxalloc) {
	fprintf(stderr, "free: can't free %u unit\n", bp -> s.size);
	return;
    } 
    for (p = freep; !(bp > p && bp < p -> s.ptr); p = p -> s.ptr); 
}
```

### 8.8

编写函数 bfree(p, n), 释放一个包含 n 个字符的任意块 p， 并将它放入由 malloc 和 free 维护的空闲块链表中。通过使用 bfree，用户可以在任意时刻向空闲块链表中添加一个静态或外部数组。

```c
/**
 * 练习 8-8：编写函数 bfree(p, n), 释放一个包含 n 个字符的任意块 p， 并将它放入由 malloc 和 free 维护的空闲块链表中。通过使用 bfree，用户可以在任意时刻向空闲块链表中添加一个静态或外部数组。
 * */

unsigned bfree(char* p, unsigned n) {
    Header* hp;
    if (n < sizeof(Header)) {
	return 0;
    }
    hp = (Header*)p;
    hp -> s.size = n / sizeof(Header);
    free((void*)(hp + 1));
    return hp -> s.size;
}
```

