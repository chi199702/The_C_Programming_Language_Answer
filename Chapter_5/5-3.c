/**
 * 练习 5-3：用指针方式实现第 2 章中的函数 strcat。函数 strcat(s, t) 将 t 指向的字符串复制到 s 指向的字符串的尾部。
 * */

void strcat(char* s, char* t) {
    while (*s) {
	++s;
    }
    while (*s++ = *t++);
}
