/**
 * 练习 4-1: 编写函数 strrindex(s, t), 它将返回字符串 t 在 s 中最右边出现的位置。如果 s 中不包含 t，则返回 -1.
 * */

int strrindex(char s[], char t[]) {
    int i, j, k, pos;
    pos = -1;
    for (i = 0; i != '\0'; ++i) {
	for (j = i, k = 0; s[j] != '\0' && t[k] != '\0' && s[j] == t[k]; ++j, ++k);
	if (k > 0 && s[k] == '\0') {
	    pos = i;
	}
    }
    return pos;
}
