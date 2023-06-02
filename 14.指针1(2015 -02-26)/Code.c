#include<stdio.h>
#include<string.h>

//1、char类型占几字节？char * 类型占几字节？int *****占几字节？
//char类型占1字节，char *占4字节，int *****

//2、char** arr[10] 占多少个字节？
//40字节

struct Student {
	int x;
	int y;
};


void Stu1() {
	Student*** s;			//4字节 
	s = (Student***)100;	
	s++;					//104	一个*//108
	printf("%d\n", s);
	s = (Student***)100;
	s = s + 2;				//108	一个*//116
	printf("%d\n", s);
	s = (Student***)100;
	s = s - 3;				//88	一个*//76
	printf("%d\n", s);

}
//公式:
	//加法:带*类型变量 + N  =  带*类型变量 + N*(乘)(去掉一个*后类型的宽度)
	//减法:带*类型变量 - N  =  带*类型变量 - N*(乘)(去掉一个*后类型的宽度)

void Stu22() {
	Student**** s1;
	Student**** s2;
	int x;
	s1 = (Student****)200;
	s2 = (Student****)100;
	x = s1 - s2;			//(200-100)/4(去掉一个*的宽度) = 100/4 =25
	printf("%d", x);
}

void Stu33() {
	Student* s;			//8字节
	s = (Student*)100;
	s++;				//108
	s = s + 2;			//116
	s = s - 3;			//76
}


void Stu44() {
	Student* s1;
	Student* s2;
	int x;
	s1 = (Student*)200;
	s2 = (Student*)100;
	x = s1 - s2;		//12
	printf("%d", x);
}

void Stu55() {
	float*** x;
	x = (float***)100;
	printf("%d", x);

}
/*
int main() {
	Stu55();
}
*/



