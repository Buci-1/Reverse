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

int main(){
    reverseArray;
}