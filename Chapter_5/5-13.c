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
