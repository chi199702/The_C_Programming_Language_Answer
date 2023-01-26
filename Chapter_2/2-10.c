/**
 * 练习 2-10: 重新编写将大写字母转换为小写字母的函数 lower, 并用条件表达式替代其中的 if-else 结构
 * */

int lower(int c) {
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
