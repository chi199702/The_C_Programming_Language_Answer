/**
 * 练习 8-1：用 read、write、open 和 close 系统调用代替标准库中功能等价的函数，重写第 7 章的 cat 程序，并通过实验比较两个版本的相对执行速度。
 * */

#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"

void error(char* fmt, ...);

int main(int argc, char* argv[]) {
    int fd;
    void filecopy(int ifd, int ofd);

    if (argc == 1) {
	filecopy(0, 1);
    }else {
	while (--argc > 0) {
	    if ((fd = open(*++argv, O_RDONLY)) == -1) {
		error("cat: cant't open %s", *argv);
	    }else {
		filecopy(fd, 1);
		close(fd);
	    }
	}
    }
    return 0;
}

void filecopy(int ifd, int ofd) {
    int n;
    char buf[BUFSIZ];
    
    while ((n = read(ifd, buf, BUFSIZ)) > 0) {
	if (write(ofd, buf, n) != n) {
	    error("cat: write error");
	}
    }
}
