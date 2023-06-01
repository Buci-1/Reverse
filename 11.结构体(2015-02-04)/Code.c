#include<stdio.h>
#include<string.h>

//1、定义一个结构体Gamer用来存储一个游戏中的角色的信息，包括血值、等级、坐标等信息
    //(1) 具体包含哪些信息自由设计
    //(2) 但这些包含的类型中，必须要有一个成员是结构体类型

struct Position
{
    int x;
    int y;
};

struct Game
{
    char name[20]; //姓名
    int level;  //等级
    int exp;  //经验
    int hp;  //血量
    int mp;  //蓝
    Position xy;  //坐标

};

Game x;
//2、定义一个函数，用来给这个结构体变量赋值.
void setGame() {
    char name1[] = "sa";
    strcpy(x.name, name1);
    x.level = 100;
    x.exp = 56789;
    x.hp = 99;
    x.mp = 1000;
    x.xy.x = 1;
    x.xy.y = 2;
}

//3、定义一个函数，用来显示这个结构体变量的所有成员信息.
void disp() {
    printf("%d %d %d %d %d %d", x.level, x.exp, x.hp, x.mp, x.xy.x, x.xy.y);
}


int main() {
    setGame();
    disp();
}



