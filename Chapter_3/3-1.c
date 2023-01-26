#include <stdio.h>

/**
 * 练习 3-1: 在上面有关折半查找的例子中，while 循环语句内共执行了两次测试，其实只要一次就足够(代价是将更多的测试在循环外执行)。重写该函数，使得在循环内部只执行一次测试。比较两种版本的函数的运行时间。
 * */

int binarysearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
	if (x < v[mid]) {
	    high = mid - 1;
	}else {
	    low = mid + 1;
	}
	mid = (low + high) / 2;
    }
    if (x == v[mid]) {
	return mid;
    }else {
	return -1;
    }
}

