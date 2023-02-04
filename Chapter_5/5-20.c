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
