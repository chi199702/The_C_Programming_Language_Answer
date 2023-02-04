/**
 * 练习 7-9：类似于 isupper 这样的函数可以通过某种方式实现以达到节省空间或时间的目的。考虑节省空间或时间的实现方式。
 * */

int isupper(char c) {
    if (c >= 'A' && c <= 'Z') {
	return 1;
    }else {
	return 0;
    }
}
