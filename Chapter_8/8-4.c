/**
 * 练习 8-4：标准库函数
 * int fseek(FILE* fp, long offset, int origin)
 * 类似于函数 lseek，所不同的是，该函数中的 fp 是一个文件指针而不是文件描述符，且返回值是一个 int 类型的状态而非位置值，编写函数 fseek，并确保该函数与库中其他函数使用的缓冲能够协同工作。
 * */

#include "syscall.h"

int fseek(FILE* fp, long offset, int origin) {
    unsigned nc;
    long rc = 0;

    if (fp -> flag & _READ) {
	if (origin == 1) {
	    offset -= fp -> cnt;
	}
	rc = lseek(fp -> fd, offset, origin);
	fp -> cnt = 0;
    }else if (fp -> flag & _WRITE) {
	if ((nc = fp -> ptr - fp -> base) > 0) {
	    if (write(fp -> fd, fp -> base, nc) != nc) {
		rc = -1;
	    }
	}
	if (rc != -1) {
	    rc = lseek(fp -> fd, offset, origin);
	}
    }
    return (rc == -1) ? -1 : 0;
}
