/**
 * 练习 2-3: 编写函数 htois(s), 把由十六进制数字组成的字符串(包含可选的前缀 0x 或 0X) 转换为与之等价的整型值。字符串中允许包含的数字包含：0~9、a~f 以及 A~F。
 * */

#define YES 1
#define NO  0

int htoi(char s[]) {
    int hexdight, i, inhex, n;
    i = 0;
    if (s[i] == '0') {
	++i;
	if (s[i] == 'x' || s[i] == 'X') {
	    ++i;
	}
    }
    n = 0;
    inhex = YES;
    for (; inhex == YES; ++i) {
	if (s[i] >= '0' && s[i] <= '9') {
	    hexdight = s[i] - '0';
	}else if (s[i] >= 'a' && s[i] <= 'f') {
	    hexdight = s[i] - 'a' + 10;
	}else if (s[i] >= 'A' && s[i] <= 'F') {
	    hexdight = s[i] - 'A' + 10;
	}else {
	    inhex = NO;
	}
	if (inhex == YES) {
	    n = 16 * n + hexdight;
	}
    }
    return n;
}
