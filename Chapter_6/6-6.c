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
