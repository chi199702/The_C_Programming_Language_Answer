/**
 * 练习 5-5：实现库函数 strncpy、strncat 和 strncmp，它们最多对参数字符串中的前 n 个字符进行操作。例如，函数 strncpy(s, t, n) 将 t 中最多前 n 个字符复制到 s 中。更详细的说明请参见附录 B（见 K&R 原著第 249 页）。
 * */

void strncpy(char* s, char* t, int n) {
    while (*t && n-- > 0) {
	*s++ = *t++;
    }
    while (n-- > 0) {
	*s++ = '\0';
    }
}

void strncat(char* s, char* t, int n) {
    void strncpy(char* s, char* t, int n);
    int strlen(char*);
    strncpy(s + strlen(s), t, n);
}

int strncmp(char* s, char* t, int n) {
    for (; *s == *t; ++s, ++t) {
	if (*s == '\0' || --n <= 0) {
	    return 0;
	}
    }
    return *s - *t;
}
