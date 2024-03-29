#include <stdio.h>
#include <limits.h>

/**
 * 练习 2-1: 编写一个程序以确定分别由 signed 和 unsigned 限定的 char、short、int 及 long 类型变量的取值范围。采用打印标准头文件的相应值以及直接计算两种方式实现。后一种方法的实现较困难一些，因为要确定各种浮点类型的取值范围。
 * */

int main() {
    // signed types
    printf("signed char min  = %d\n",  SCHAR_MIN);
    printf("signed char max  = %d\n",  SCHAR_MAX);
    printf("signed short min = %d\n",  SHRT_MIN);
    printf("signed short max = %d\n",  SHRT_MAX);
    printf("signed int min   = %d\n",  INT_MIN);
    printf("signed int max   = %d\n",  INT_MAX);
    printf("signed long min  = %ld\n", LONG_MIN);
    printf("singed long max  = %ld\n", LONG_MAX);
    // unsigned types
    printf("unsigned char max  = %u\n",  UCHAR_MAX);
    printf("unsigned short max = %u\n",  USHRT_MAX);
    printf("unsigned int max   = %u\n",  UINT_MAX);
    printf("unsigned long max  = %lu\n", ULONG_MAX);

    printf("manual count~~~\n");
    // manual count
    // signed types
    printf("signed char min = %d\n", -(char)((unsigned char) ~0 >> 1) - 1);	// 注意：减 1 是因为负数用补码表示后范围比正数大 1
    printf("signed char max = %d\n", (char)((unsigned char) ~0 >> 1));
    printf("signed short min = %d\n", -(short)((unsigned short) ~0 >> 1) - 1);
    printf("signed short max = %d\n", (short)((unsigned short) ~0 >> 1));
    printf("signed int min = %d\n", -(int)((unsigned int) ~0 >> 1) - 1);
    printf("signed int max = %d\n", (int)((unsigned int) ~0 >> 1));
    printf("signed long min = %ld\n", -(long)((unsigned long) ~0 >> 1) - 1);
    printf("signed long max = %ld\n", (long)((unsigned long) ~0 >> 1));

    // unsigned types
    printf("unsigned char max = %u\n", (unsigned char) ~0);
    printf("unsigned short max = %u\n", (unsigned short) ~0);
    printf("unsigned int max = %u\n", (unsigned int) ~0);
    printf("unsigned long max = %lu\n", (unsigned long) ~0);
    return 0;
}
