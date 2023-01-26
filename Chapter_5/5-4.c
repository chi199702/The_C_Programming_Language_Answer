/**
 * 练习 5-4：编写函数 strend(s, t)。如果字符串 t 出现在字符串 s 的尾部，该函数返回 1；否则返回 0。
 * */
int strend(char* s, char* t) {
    char* bs = s;
    char* bt = t; 

    for (; *s; ++s);
    for (; *t; ++t);
    for (; *s == *t; --s, --t) {
	if (s == bs || t == bt) {
	    break;
	}
    }
    if (*s == *t && t == bt && *s != '\0') {
	return 1;
    }else {
	return 0;
    }
}
