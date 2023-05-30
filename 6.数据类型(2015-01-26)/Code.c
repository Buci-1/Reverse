#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// 1、定义4个int类型的全局变量，分别是g_x, g_y, g_z, g_r, 使用if..else..分支语句，将最大的值存储到g_r中

int g_x = 5;
int g_y = 4;
int g_z = 7;
int g_r = 0;

void Max() {
	if (g_x > g_y) {
		if (g_x > g_z) {
			g_r = g_x;
		}
		else {
			g_r = g_z;
		}
	}
	else {
		if (g_y > g_z) {
			g_r = g_y;
		}
		else {
			g_r = g_z;
		}
	}
}

//2、找出数组里面最大的值，并存储到全局变量中(if..esle或者wile)

int arr[4] = {2,5,7,9};

void Max2() {
	int i = 1;
	g_r = arr[0];
	while (i < 4) {
		if (arr[i] > g_r) {
			g_r = arr[i];
		}
		i++;
	}
	printf("max:%d\n",g_r);
}

//3、将数组所有的元素相加，将结果存储到g_r中

void ArrMax() {
	int arr2[10] = { 2,5,7,9,22,4,8,22,3,18 };
	int g_r = 0;
	int i = 0;
		while (i < 9) {
			g_r += arr2[i];
		}
		printf("ArrMax:%d\n", g_r);
}

//4、俩俩比较数组的值，将最大的一个存储到数组的最后一个位置(要求使用for循环实现)

void ArrMax2() {
	int arr2[10] = { 2,7,5,9,22,4,8,22,3,18 };
	int g_r = 0;
	for (int i = 1; i < 10; ++i) {
		if (arr2[i] < arr2[i - 1]) {			
			g_r = arr2[i];
			arr2[i] = arr2[i - 1];
			arr2[i - 1] = g_r;
		}
	}
	printf("max:%d\n", arr2[9]);
}

//5、有一个字符串是这样的：china中国verygood天朝nice,里面既含有中文又含义英文，请编写一个函数，能截取任意长度的字符串n(n<=总长度) ;fn(1)=c


void getSubstring(int n) {
	int i = 0, j = 0;
	char str[] = "china中国verygood天朝nice";

	while (i < strlen(str) && j < n) {
		if ((str[i] & 0x80) != 0) {       //判断中文字符还是英文字符
			i += 2;    
		}
		else {
			i += 1;
		}
		j += 1;
	}
	if (j == n && (i % 2) == 1) {
		i -= 1;
	}
	str[i] = '\0';
	printf("%s\n", str);
}

/*
int main() {  
	int n=6;
	getSubstring(n);
	return 0;
}

*/




