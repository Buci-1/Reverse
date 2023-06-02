#include<stdio.h>
#include<string.h>
//1、写一个switch语句，不生产大表也不生产小表，贴出对应的反汇编.

void sw(int x) {
	switch (x) {
	case 1:
		printf("1");
		break;
	case 2:
		printf("2");
		break;
	case 3:
		printf("3");
		break;
	default:
		printf("error");
	}
}

/*
002F29A5  mov         eax,dword ptr [ebp+8]
002F29A8  mov         dword ptr [ebp+FFFFFF3Ch],eax
002F29AE  cmp         dword ptr [ebp+FFFFFF3Ch],1
002F29B5  je          002F29CB
002F29B7  cmp         dword ptr [ebp+FFFFFF3Ch],2
002F29BE  je          002F29DA
002F29C0  cmp         dword ptr [ebp+FFFFFF3Ch],3
002F29C7  je          002F29E9
002F29C9  jmp         002F29F8
	case 1:
		printf("1");
002F29CB  push        2FAB94h
002F29D0  call        002F10F5
002F29D5  add         esp,4
		break;
002F29D8  jmp         002F2A05
	case 2:
		printf("2");
002F29DA  push        2FAC84h
002F29DF  call        002F10F5
002F29E4  add         esp,4
		break;
002F29E7  jmp         002F2A05
	case 3:
		printf("3");
002F29E9  push        2FAB40h
002F29EE  call        002F10F5
002F29F3  add         esp,4
		break;
002F29F6  jmp         002F2A05
	default:
		printf("error");
002F29F8  push        2FAC90h
002F29FD  call        002F10F5
002F2A02  add         esp,4
	}
}
*/
//***********************************************************

//2、写一个switch语句，只生成大表,贴出对应的反汇编.
void sw1(int x) {
	switch (x) {
	case 1:
		printf("1");
		break;
	case 2:
		printf("2");
		break;
	case 3:
		printf("3");
		break;
	case 4:
		printf("4");
		break;
	case 5:
		printf("5");
		break;
	case 6:
		printf("6");
		break;
	case 7:
		printf("7");
		break;
	case 8:
		printf("8");
		break;
	default:
		printf("error");
	}
}
/*
005D8065  mov         eax,dword ptr [ebp+8]
005D8068  mov         dword ptr [ebp+FFFFFF3Ch],eax     //参数x存入局部变量
005D806E  mov         ecx,dword ptr [ebp+FFFFFF3Ch]		//参数减一(因为大表的地址从0开始，参数减一后从第0位开始查表)
005D8074  sub         ecx,1
005D8077  mov         dword ptr [ebp+FFFFFF3Ch],ecx		//减完1的参数存回局部变量
005D807D  cmp         dword ptr [ebp+FFFFFF3Ch],7		//因为上面Switch中最大的分支为8，而在前几步操作中又将参数-1，从而只要参数大于8，即直接跳到default
005D8084  ja          005D810F							//跳转default
005D808A  mov         edx,dword ptr [ebp+FFFFFF3Ch]		
005D8090  jmp         dword ptr [edx*4+005D8130h]       //查表
	case 1:
		printf("1");									//查完表jmp到的地址
005D8097  push        5DAB94h
005D809C  call        005D10F5
005D80A1  add         esp,4
		break;
005D80A4  jmp         005D811C
	case 2:
		printf("2");
005D80A6  push        5DAC84h
005D80AB  call        005D10F5
005D80B0  add         esp,4
		break;
005D80B3  jmp         005D811C
	case 3:
		printf("3");
005D80B5  push        5DAB40h
005D80BA  call        005D10F5
005D80BF  add         esp,4
		break;
005D80C2  jmp         005D811C
	case 4:
		printf("4");
005D80C4  push        5DAC88h
005D80C9  call        005D10F5
005D80CE  add         esp,4
		break;
005D80D1  jmp         005D811C
	case 5:
		printf("5");
005D80D3  push        5DAB5Ch
005D80D8  call        005D10F5
005D80DD  add         esp,4
		break;
005D80E0  jmp         005D811C
	case 6:
		printf("6");
005D80E2  push        5DAB6Ch
005D80E7  call        005D10F5
005D80EC  add         esp,4
		break;
005D80EF  jmp         005D811C
	case 7:
		printf("7");
005D80F1  push        5DAB8Ch
005D80F6  call        005D10F5
005D80FB  add         esp,4
		break;
005D80FE  jmp         005D811C
	case 8:
		printf("8");
005D8100  push        5DABB8h
005D8105  call        005D10F5
005D810A  add         esp,4
		break;
005D810D  jmp         005D811C
	default:
		printf("error");
005D810F  push        5DAC90h
005D8114  call        005D10F5
005D8119  add         esp,4
	}
}
*/
//***********************************************************

//3、写一个switch语句，生成大表和小表, 贴出对应的反汇编.
void sw2(int x) {
	switch (x) {
	case 1:
		printf("1");
		break;
	case 2:
		printf("2");
		break;
	case 3:
		printf("3");
		break;
	case 10:
		printf("4");
		break;
	case 11:
		printf("5");
		break;
	default:
		printf("error");
	}
}

/*
006829A5  mov         eax,dword ptr [ebp+8]
006829A8  mov         dword ptr [ebp+FFFFFF3Ch],eax
006829AE  mov         ecx,dword ptr [ebp+FFFFFF3Ch]
006829B4  sub         ecx,1
006829B7  mov         dword ptr [ebp+FFFFFF3Ch],ecx
006829BD  cmp         dword ptr [ebp+FFFFFF3Ch],0Ah
006829C4  ja          00682A25							//比较完跳转default
006829C6  mov         edx,dword ptr [ebp+FFFFFF3Ch]		//减完1的参数放入edx
006829CC  movzx       eax,byte ptr [edx+00682A60h]		//00682A60h为小表的地址，它是紧跟在大表后面的，取edx中的1字节，查小表，查到的值进行补零扩展指令存入eax
006829D3  jmp         dword ptr [eax*4+00682A48h]		//eax中保存的是小表中的数据，紧接着查大表
	case 1:
		printf("1");
006829DA  push        68AB94h
006829DF  call        006810F5
006829E4  add         esp,4
		break;
006829E7  jmp         00682A32
	case 2:
		printf("2");
006829E9  push        68AC84h
006829EE  call        006810F5
006829F3  add         esp,4
		break;
006829F6  jmp         00682A32
	case 3:
		printf("3");
006829F8  push        68AB40h
006829FD  call        006810F5
00682A02  add         esp,4
		break;
00682A05  jmp         00682A32
	case 10:
		printf("4");
00682A07  push        68AC88h
00682A0C  call        006810F5
00682A11  add         esp,4
		break;
00682A14  jmp         00682A32
	case 11:
		printf("5");
00682A16  push        68AB5Ch
00682A1B  call        006810F5
00682A20  add         esp,4
		break;
00682A23  jmp         00682A32
	default:
		printf("error");
00682A25  push        68AC90h
00682A2A  call        006810F5
00682A2F  add         esp,4
	}
}
*/
//***********************************************************

//4、为do..while语句生成的反汇编填写注释.
void do1(int x,int y) {
	do {
		printf("%d", x );
		x++;
	} while (x > y);
}
/*
void do1(int x,int y) {
002A8040  push        ebp
002A8041  mov         ebp,esp
002A8043  sub         esp,0C0h
002A8049  push        ebx
002A804A  push        esi
002A804B  push        edi
002A804C  mov         edi,ebp
002A804E  xor         ecx,ecx
002A8050  mov         eax,0CCCCCCCCh
002A8055  rep stos    dword ptr es:[edi]
002A8057  mov         ecx,2AF0D7h
002A805C  call        002A13CF
	do {
		printf("%d", x );
002A8061  mov         eax,dword ptr [ebp+8]					//第一次先运行do循环中的语句
002A8064  push        eax
002A8065  push        2AABD8h
002A806A  call        002A10F5
002A806F  add         esp,8
		x++;
002A8072  mov         eax,dword ptr [ebp+8]					//条件加1
002A8075  add         eax,1
002A8078  mov         dword ptr [ebp+8],eax
	} while (x > y);
002A807B  mov         eax,dword ptr [ebp+8]					//条件判断
002A807E  cmp         eax,dword ptr [ebp+0Ch]
002A8081  jg          002A8061								//跳转到循环体内
}
002A8083  pop         edi
002A8084  pop         esi
002A8085  pop         ebx
002A8086  add         esp,0C0h
002A808C  cmp         ebp,esp
002A808E  call        002A12BC
002A8093  mov         esp,ebp
002A8095  pop         ebp
002A8096  ret
*/

//***********************************************************

//5、为while语句生成的反汇编填写注释.
void whil(int x,int y) {
	while (x < y) {
		printf("%d", x);
		x++;
	}

}
/*
void whil(int x,int y) {
00BC1DB0  push        ebp
00BC1DB1  mov         ebp,esp
00BC1DB3  sub         esp,0C0h
00BC1DB9  push        ebx
00BC1DBA  push        esi
00BC1DBB  push        edi
00BC1DBC  mov         edi,ebp
00BC1DBE  xor         ecx,ecx
00BC1DC0  mov         eax,0CCCCCCCCh
00BC1DC5  rep stos    dword ptr es:[edi]
00BC1DC7  mov         ecx,0BCF0D7h
00BC1DCC  call        00BC13CF
	while (x < y) {
00BC1DD1  mov         eax,dword ptr [ebp+8]				//判断条件 <---------
00BC1DD4  cmp         eax,dword ptr [ebp+0Ch]                              |
00BC1DD7  jge         00BC1DF5                                             |
		printf("%d", x);		                                           |
00BC1DD9  mov         eax,dword ptr [ebp+8]				//执行循环语句      | 
00BC1DDC  push        eax                                                  |
00BC1DDD  push        0BCABD8h                                             |
00BC1DE2  call        00BC10F5                                             |
00BC1DE7  add         esp,8                                                |
		x++;                                                               |
00BC1DEA  mov         eax,dword ptr [ebp+8]                                |
00BC1DED  add         eax,1                                                |
00BC1DF0  mov         dword ptr [ebp+8],eax                                |			
	}                                                                      |
00BC1DF3  jmp         00BC1DD1							//跳转回条件判断----

}
*/
//***********************************************************

//6、为for语句生成的反汇编填写注释.
void for1(int x) {
	for (int i = 0; i < x; i++) {
		printf("%d", i);
	}
}	
/*
void for1(int x) {
00542980  push        ebp
00542981  mov         ebp,esp
00542983  sub         esp,0CCh
00542989  push        ebx
0054298A  push        esi
0054298B  push        edi
0054298C  lea         edi,[ebp-0Ch]
0054298F  mov         ecx,3
00542994  mov         eax,0CCCCCCCCh
00542999  rep stos    dword ptr es:[edi]
0054299B  mov         ecx,54F0D7h
005429A0  call        005413CF
	for (int i = 0; i < x; i++) {
005429A5  mov         dword ptr [ebp-8],0					//给i赋初值0
005429AC  jmp         005429B7								//跳转到循环体内部
005429AE  mov         eax,dword ptr [ebp-8]			<--------------------------------------------	
005429B1  add         eax,1																		|
005429B4  mov         dword ptr [ebp-8],eax														|
005429B7  mov         eax,dword ptr [ebp-8]					//判断是否进入循环体				  |
005429BA  cmp         eax,dword ptr [ebp+8]														|
005429BD  jge         005429D2																	|
		printf("%d", i);																		|
005429BF  mov         eax,dword ptr [ebp-8]														|
005429C2  push        eax																		|
005429C3  push        54ABD8h																	|
005429C8  call        005410F5																	|
005429CD  add         esp,8																		|
	}																							|
005429D0  jmp         005429AE								//跳回表达式3 ：i++  ----------------    
}
*/
int main() {
	for1(5);
}