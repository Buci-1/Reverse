#include<stdio.h>
#include<string.h>

//1、列出每一行的反汇编代码：
void p1() {
	char a = 10;			//mov byte ptr [ebp-9],0Ah;
	short b = 20;			//mov eax,14h;		mov word ptr [ebp-18h],ax
	int c = 30;				//mov dword ptr [ebp-24h],1Eh;

	char* pa = &a;			//lea eax,[ebp-9](取的是[ebp-9]计算完的值这个地方的内存地址)；mov dword ptr [ebp-30h],eax(将eax中存的数据放入[ebp-30]的这个地址对应的地方)
	short* pb = &b;			//lea eax,[ebp-18h]；mov dword ptr [ebp-3Ch],eax
	int* pc = &c;			//lea eax,[ebp-24h]；mov dword ptr [ebp-48h],eax

	char** ppa = &pa;		//lea eax,[ebp-30h]；mov dword ptr [ebp-54h],eax
	short** ppb = &pb;		//lea eax,[ebp-3Ch]；mov dword ptr [ebp-60h],eax
	int** ppc = &pc;		//lea eax,[ebp-48h]；mov dword ptr [ebp-6Ch],eax
}

//2、列出每一行的反汇编代码：
void p2() {
	int p = 10;				//mov dword ptr [ebp-0Ch],0Ah
	int******* p7;			
	int****** p6;		
	int***** p5;
	int**** p4;
	int*** p3;
	int** p2;
	int* p1;

	p1 = &p;				//lea eax,[p];mov dword ptr[p1],eax
	p2 = &p1;				//lea eax,[p1];mov dword ptr[p2],eax
	p3 = &p2;				//lea eax,[p2];mov dword ptr[p3],eax
	p4 = &p3;				//lea eax,[p3];mov dword ptr[p4],eax
	p5 = &p4;				//lea eax,[p4];mov dword ptr[p5],eax
	p6 = &p5;				//lea eax,[p5];mov dword ptr[p6],eax
	p7 = &p6;				//lea eax,[p6];mov dword pte[p7],eax

}

//4、完成代码，实现数组值的互换
void Function()
{
	int arr[5] = { 1,2,3,4,5 };

	//..此处添加代码，使用指针，将数组的值倒置				

	int* p = arr;
	int size = (sizeof(arr) / sizeof(int));
	int temp;
	for (int i = 0,j = size-1; i < (size/2); i++,j--) {
		temp = *(p + i);						//这里的*是声明告诉编译器(p+i)中的值是一个地址，现在需要拿出这个地址指向的值
		*(p + i) = *(p + j);
		*(p + j) = temp;
	}
	

	//打印数组值的代码已经写完，不需要修改				
	for (int k = 0; k < 5; k++)
	{
		printf("%d\n", *(p + k));
	}

}


/*
int main() {
	Function();
}
*/