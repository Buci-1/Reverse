#include<stdio.h>

int Stack(int a, int b, int c, int d, int e);
int Stack2(int a,int b,int c,int d);
int Stack3(int a,int b,int c);

//1
int Stack(int a, int b, int c, int d, int e){ //3,4,5,6,7
    int a=2 ,int b=3;
    int Sum = Stack2();        //Sum = C
    Sum = a+b+e+Sum;
    return Sum;

}
//2
int Stack2(int a,int b,int c,int d){ //3,4,5,6
    int a=2;
    int Sum = Stack3(a,b,c); //3,4,5
    Sum = Sum+a+d;
    return Sum;

}
//3
int Stack3(int a,int b,int c){ //3,4,5
    int sum = a+b+c;
    return sum;
}


//程序入口
int main(){
    int Sum = Stack(3,4,5,6,7);
    printf("hello:%d",Sum);
}