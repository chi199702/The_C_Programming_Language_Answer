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
