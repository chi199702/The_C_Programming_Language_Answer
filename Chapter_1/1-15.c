#include <stdio.h>

/**
 * 练习 1-15: 重新编写 1.2 节中的温度转换程序，使用函数实现温度转换计数。
 * */

float celsius(float fahr);

int main() {
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step  = 20;

    fahr = lower;
    while (fahr <= upper) {
	printf("%3.0f %6.1f\n", fahr, celsius(fahr));
	fahr += step;
    }
    return 0;
}

float celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}
