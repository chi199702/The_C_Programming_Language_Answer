/**
 * 练习 8-5：修改 fsize 程序，打印 i 结点项中包含的其他信息。
 * */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"

int stat(char*, struct stat*);
void dirwalk(char*, void (*fcn)(char*));

void fsize(char* name) {
    struct stat stbuf;
    if (stat(name, &stbuf) == -1) {
	fprintf(stderr, "fsize: can't access %s\n", name);
	return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
	dirwalk(name, fsize);
    }
    printf("%5u %6o %3u %8ld %s\n", stbuf.st_ino, stbuf.st_mode, stbuf.st_nlink, stbuf.st_size, name);
}
