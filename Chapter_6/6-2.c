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
