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
