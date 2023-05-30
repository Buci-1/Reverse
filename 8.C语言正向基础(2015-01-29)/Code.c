#include<stdio.h>
//1、将两个变量的值交换.
void swap(int x,int y){
    int temp = x;
     x = y;
     y = temp;
}

//2、将一个数组中的数倒序输出.
void reverseArray(){
    int size[10]={0,1,2,3,4,5,6,7,8,9};
    for(int i=10;i>=0;i--){
        printf("%d\n",size[i]);
    }
}

//3、找出数组里面最大的值，并返回
int MaxArray() {
    int size[10] = { 0,1,2,3,4,5,6,7,8,9};
    int Max = size[0];
    for (int i = 1; i < 10; i++) {
        if (i > Max) {
            Max = size[i];
        }
    }
    return Max;
}

//4、将数组所有的元素相加，将结果返回
int SumArray(){
    int size[10] = {0,1,2,3,4,5,6,7,8,9};
    int Sum = 0,i = 0;
    do{
        Sum +=size[i];
        i++
    }while(i<10);
    printf("out:%d\n",Sum);
    return Sum;
}

//5、将两个等长数组相同位置的值相加，存储到另外一个等长的数组中
void CopySumArray() {
    int size1[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int size2[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int Sum[10] = { 0 };
    int i = 0;
    do {
        Sum[i] = size1[i] + size2[i];
        i++;
    } while (i < 10);
    for (i = 0; i < 10; i++) {
        printf("%d\n", Sum[i]);
    }
}

//6、写一个函数int prime(int x)，如果x是素数返回值为1，否则返回0。
//垃圾
int prime(int x) {
    int y = x;
    int Sum = 0;
    do {
        if (x%y == 0 ) {
            Sum++;
        }
        y--;
    } while (y != 0);
      return Sum == 2 ? 1: 0;
}
//示例
int prime2(int x){
    int r = 1;
    int n = 2;
    while(n<x){
        if(x%n==0){
            r = 0;
            break;
        }
        n++;
    }
    return r;
}

//7、俩俩比较数组的值，将最大的一个存储到数组的最后一个位置 
void put_max_to_end() {
    int size[10] = { 1,2,4,6,9,2,3,5,1,2 };
    int Max = 0;
    int i = 1;
    while (i < 10) {
        if (size[i] < size[i-1]) {
            Max = size[i];
            size[i] = size[i - 1];
            size[i-1] = Max;
        }
        i++;
    }
    printf("%d\n", size[9]);
}

//8、编写程序实现一个冒泡排序的算法.
void bubble_sort(int arr[],int len) {
    int i,j,temp;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1] = temp;
			}
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
}

//1、判断数组是否是对称的，如果是返回1，不是返回0.
int is_symmectric() {
    int size[10] = { 1,2,3,4,5,5,4,3,2,1 };
    for (int i = 0, j = 9; i < 5; i++, j--) {
        if (size[i] != size[j]) {
            return 0;
        }
    }
    return 1;
}





int main(){
    //
}