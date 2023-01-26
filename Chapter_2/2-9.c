/**
 * 练习 2-9: 在求二进制补码时，表达式 x&=(x - 1) 可以删除 x 中最右边值为 1 的一个二进制位。请解释这样做的道理。用这一方法重写 bitcount 函数，以加快其执行速度。
 * */

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= x - 1) {
	++b;
    }
    return b;
}
