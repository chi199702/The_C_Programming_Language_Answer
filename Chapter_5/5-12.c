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
