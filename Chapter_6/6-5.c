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
