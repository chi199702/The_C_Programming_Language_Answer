/**
 * 练习 8-8：编写函数 bfree(p, n), 释放一个包含 n 个字符的任意块 p， 并将它放入由 malloc 和 free 维护的空闲块链表中。通过使用 bfree，用户可以在任意时刻向空闲块链表中添加一个静态或外部数组。
 * */

unsigned bfree(char* p, unsigned n) {
    Header* hp;
    if (n < sizeof(Header)) {
	return 0;
    }
    hp = (Header*)p;
    hp -> s.size = n / sizeof(Header);
    free((void*)(hp + 1));
    return hp -> s.size;
}
