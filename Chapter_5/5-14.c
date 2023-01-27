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
