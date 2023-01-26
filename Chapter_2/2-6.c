/**
 * 练习 2-6: 编写一个函数 setbits(x, p, n, y), 该函数返回对 x 执行下列操作后的结果值: 将 x 中从第 p 位开始的 n 个(二进制)位设置为 y 中最右边 n 位的值，x 的其余各位保持不变。
 * */

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}
