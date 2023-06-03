#include<stdio.h>
//**********************************************************
//1、int strlen(char* s)
	//返回值是字符串s的长度。不包括结束符'/0'。

int strlen(char* s) {
	int len = 0;
	while (*s != 0) {
		len++;
		s++;
	}
	return len;
}
//**********************************************************
//2、char* strcpy (char* dest, char* src);			
	// 复制字符串src到dest中。返回指针为dest的值。

char* strcpy(char* dest, char* src) {
	char* ret = dest;
	while ((*dest++) = (*src++));//遇0即停止，当复制到*src字符串中的0自然while也停止
	return ret;

}
//**********************************************************

//3、char* strcat (char* dest, char* src);			
	//将字符串src添加到dest尾部。返回指针为dest的值。

char* strcat(char* dest, char* src) {
	char* ret = dest;
	do {
		(*dest++);
	} while (*dest != 0);

	//or{
	//while ((*dest++) != 0);
	//(*dest--);

	while ((*dest++) = (*src++));
	return ret;
}
//**********************************************************
//4、int strcmp(char* s1, char* s2);
	//一样返回0  不一样返回1

int strcmp(char* s1, char* s2) {
	//int sum1, sum2;
	while ((*s1++) == (*s2++)) {
		if ((*s1) == 0 && (*s2) == 0)
			return 0;
	}
	return 1;
}
//**********************************************************

//test 
char arr1[] = "china";
char arr2[] = "niubi";
//test

//模拟实现CE的数据搜索功能：						
	//这一堆数据中存储了角色的名字信息(WOW)，请列出角色名的内存地址.

char wow[100] = {
		0x00,0x01,0x57,0x4F,0x57,0x00,0x06,0x07,0x07,0x09,
		0x00,0x20,0x10,0x03,0x03,0x0C,0x00,0x00,0x44,0x00,
		0x00,0x33,0x00,0x47,0x0C,0x0E,0x00,0x0D,0x00,0x11,
		0x00,0x00,0x00,0x02,0x64,0x00,0x00,0x00,0xAA,0x00,
		0x00,0x00,0x64,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x02,0x00,0x74,0x0F,0x41,0x00,0x00,0x00,
		0x01,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x0A,0x00,
		0x00,0x02,0x57,0x4F,0x57,0x00,0x06,0x08,0x00,0x00,
		0x00,0x00,0x00,0x64,0x00,0x0F,0x00,0x00,0x0D,0x00,
		0x00,0x00,0x23,0x00,0x00,0x64,0x00,0x00,0x64,0x00
};

void FindRoleNameAddr(char* pData, char* pRoleName) {    //wow *pRoleName = 'w',(*pRoleName+1) = 'o',(pRoleName+2) = 'w'

	char* pRoleName_a;		//初始化
	char* pData_a;

	int len = strlen(pRoleName);                //获取需要查询的字符串长度 
	int j = 0;  
	for (int i = 0; i < 100; i++) {             //遍历整个数组，     
		if ((*pData++) == (*pRoleName)) {       //这里只查询第一个ASCll码，如果首位字符和查询的字符一样则进入IF
			pRoleName_a = pRoleName;            //保存原始字符串
			pData_a = pData-1;                  //因为if中的条件是*pData++，所以在进入if后会自增一，而这里需要将自增的1减掉
			j = 0;                      
			while (j <= len) {                  //进入循环判断是不是在第一个相同的字符后，后续字符也相同
				if ((*pData_a) == 0 && (*pRoleName_a) == 0) {       //如果字符位0，则比较到了结束符，下面就可以打印查询到的地址和字符串 
					printf("%08X %c", pData - 1,(*(pData-1)));      //由于直接打印%s字符串会报错，在多次尝试无果后决定循环打印单个字符
					//pData--;              
					for (int k = 0; k < len;k++) {                  //在地址和首字符打印完后，打印接下来的字符    
						printf("%c",(*(pData+k)));
					}
					printf("\n");
				}
				//printf("\n");
				(*pData_a++);                                       
				(*pRoleName_a++);
				j++;
			}
		}
	}
}


char arr3[] = "WOW";

int main() {
	FindRoleNameAddr(wow,arr3);
}