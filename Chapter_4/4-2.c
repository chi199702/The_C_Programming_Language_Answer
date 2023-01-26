/**
 * 练习 4-2: 对 atof 函数进行扩充，使它可以处理形如 123.45e-6 的科学表示法，其中，浮点数后面可能会紧跟一个 e 或 E 以及一个指数（可能有正负号）。
 **/
#include <ctype.h>

double atof(char s[]) {
    int i, sign;
    i = 0;
    if (s[i] == '+' || s[i] == '-') {
	sign = s[i] == '+' ? 1 : -1;
	++i;
    }
    double value;
    for (value = 0.0; isdigit(s[i]); ++i) {
	value = value * 10.0 + (s[i] - '0');
    }
    if (s[i] == '.') {
	++i;
    }
    double power;
    for (power = 1.0; isdigit(s[i]); ++i) {
	value = value * 10.0 + (s[i] - '0');
	power *= 10;
    } 
    value = sign * value / power;
    if (s[i] == 'e' || s[i] == 'E') {
	sign = s[++i] == '+' ? 1 : -1;
	if (s[i] == '+' || s[i] == '-') {
	    ++i;
	}
	int exp;
	for (exp = 0; isdigit(s[i]); ++i) {
	    exp = exp * 10 + (s[i] - '0');
	}
	if (sign == 1) {
	    while (exp-- > 0) {
		value *= 10;
	    }
	}else {
	    while (exp-- > 0) {
		value /= 10;
	    }
	}
    }
    return value;    
}
