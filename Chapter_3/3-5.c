/**
 * 练习 3-5: 编写函数 itoa(n, s, b), 将整数 n 转换为以 b 为底的数，并将转换结果以字符的形式保存到字符串 s 中。例如，itob(n, s, 16) 把整数 n 格式化伟十六进制整数保存在 s 中。
 * */

void itob(int n, char s[], int b) {
    int i, j, sign;
    void reverse(char s[]);
    if ((sign = n) < 0) {
	n = -n;
    }
    i = 0;
    do {
	j = n % b;
	s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    }while ((n /= b) > 0);
    if (sign < 0) {
	s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
