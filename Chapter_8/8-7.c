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
