/**
 * 练习 2-8: 编写一个函数 rightrot(x, n), 该函数返回将 x 循环右移(即从最右端移出的位将从最左端移入) n(二进制)往后所得到的值。
 * */

unsigned rightrot(unsigned x, int n) {
    int wordlength(void);
    int rbit;
    while (n-- > 0) {
	rbit = (x & 1) << (wordlength() - 1);
	x = x >> 1;
	x = x | rbit;
    }
}

// 计算机器的字节长度
int wordlength(void) {
    int i;
    unsigned v = (unsigned)~0;
    v = ~0;
    for (i = 1; (v = (v >> 1)) > 0; ++i) {}
    return i;
}
