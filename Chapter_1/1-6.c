#include <stdio.h>

/**
 * 练习 1-6：验证表达式 getchar() != EOF 的值是 0 还是 1
 * */
int main(int argc, char* argv[]) {
    printf("%d\n", getchar() != EOF);
}

/**
输入：A
输出：1

输入：CTRL + D（linux 下的使用该快捷键表示 EOF，windows 下使用 CTRL + Z）
输出：0
 * */