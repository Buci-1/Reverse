//*******************************************第一题****************************************
void __declspec(naked) Re_if(int x, int y) {
    __asm{

    本节练习：						无

    调用处代码：

    push        5
    push        4
    call        0040100f
    add         esp,8

    函数内部：

                            函数内部功能分析：
    00401030   push        ebp
    00401031   mov         ebp,esp						            1、分析参数：
    00401033   sub         esp,44h                                     [ebp+8] ：x--4
    00401036   push        ebx                                         [ebp+0Ch] ：y--5
    00401037   push        esi
    00401038   push        edi						                2、分析局部变量
    00401039   lea         edi,[ebp-44h]                                mov dword ptr [ebp-4],eax=全局变量
    0040103C   mov         ecx,11h              
    00401041   mov         eax,0CCCCCCCCh
    00401046   rep stos    dword ptr [edi]
    00401048   mov         eax,[004225c4] 	*3*					    3、分析全局变量
    0040104D   mov         dword ptr [ebp-4],eax *2*					mov eax,[004225c4] =sum
    00401050   mov         ecx,dword ptr [ebp+8] *1*
    00401053   cmp         ecx,dword ptr [ebp+0Ch] *1*
    00401056   jg          00401064
    00401058   mov         edx,dword ptr [ebp+0Ch]					4、功能分析
    0040105B   add         edx,dword ptr [ebp-4]                        压入了2个参数x,y。然后比较x和y的大小，
    0040105E   mov         dword ptr [004225c4],edx                     如果x>y,即跳转到00401064，否则执行00401058，所以此处的if(x>=y)
    00401064   pop         edi                                          sum=sum+y;
    00401065   pop         esi						                5、返回值分析
    00401066   pop         ebx                                          无
    00401067   mov         esp,ebp
    00401069   pop         ebp
    0040106A   ret						                            6、还原成C函数
    }
}


//逆向成的C代码

#include<stdio.h>


int Sum;
void Re_if(int x, int y) {
	int Sum2 = Sum;
	
	if (x <= y) {
		Sum = y + Sum2;
	}
}


int main() {
	Re_if(4, 5);
}


//***************************************第二题******************************************

void __declspec(naked) Re_two(){
    __asm{						
004010B0   push        ebp							函数内部功能分析：	
004010B1   mov         ebp,esp								
004010B3   sub         esp,48h							        1、分析参数：	
004010B6   push        ebx								        [ebp+8]:y   
004010B7   push        esi								        [ebp+0Ch]:x
004010B8   push        edi								
004010B9   lea         edi,[ebp-48h]							2、分析局部变量	
004010BC   mov         ecx,12h								    [ebp-4]:a
004010C1   mov         eax,0CCCCCCCCh							[ebp-8]:b
004010C6   rep stos    dword ptr [edi]
//功能代码**********************************						
004010C8   mov         eax,[004225c4]								
004010CD   mov         dword ptr [ebp-4],eax					3、分析全局变量	
004010D0   mov         dword ptr [ebp-8],2						mov eax,[004225c4]:	Sum	
004010D7   mov         ecx,dword ptr [ebp+8]								
004010DA   cmp         ecx,dword ptr [ebp+0Ch]								
004010DD   jl          004010e8								
004010DF   mov         edx,dword ptr [ebp-8]					4、功能分析	
004010E2   add         edx,1								    比较X,Y的大小，如果x<y，则跳转到004010E8，否则执行004010DF，所以此处if(x>=y)
004010E5   mov         dword ptr [ebp-8],edx					b+=1 			
004010E8   mov         eax,dword ptr [ebp+8]					第二个if继续比较x和y的大小，如果x>=y，则跳转到004010FB，否则执行004010F0，所以此处if(x<y)
004010EB   cmp         eax,dword ptr [ebp+0Ch]					Sum = b	
004010EE   jge         004010fb								    else:
004010F0   mov         ecx,dword ptr [ebp-8]					Sum = a+b			
004010F3   mov         dword ptr [004225c4],ecx								
004010F9   jmp         00401107							        	
004010FB   mov         edx,dword ptr [ebp-4]								
004010FE   add         edx,dword ptr [ebp-8]					5、返回值分析			
00401101   mov         dword ptr [004225c4],edx                 无
//END***************************************					
00401107   pop         edi								        6、还原成C函数
00401108   pop         esi								        
00401109   pop         ebx								
0040110A   mov         esp,ebp								
0040110C   pop         ebp								
0040110D   ret								
    }
}



//逆向成的C代码
int Sum;
void Re_two(int x,int y) {
	int a = Sum;
	int b = 2;
	if (x>=y) {
		b++;
	}
	if (x < y) {
		Sum = b;
	}
	else {
		Sum = a + b;
	}
}

int main() {
	Re_two(4, 5);
	return 0;
}



//**************************************第三题**********************************************
void __declspec(naked) Re_three(){
    __asm{
004010B0   push        ebp						函数内部功能分析：	
004010B1   mov         ebp,esp							
004010B3   sub         esp,4Ch						                    1、分析参数：	
004010B6   push        ebx							                    [ebp+8]:x
004010B7   push        esi							                    [ebp+0Ch]:y
004010B8   push        edi							                    [ebp+10h]:z
004010B9   lea         edi,[ebp-4Ch]						            2、分析局部变量	
004010BC   mov         ecx,13h							                [ebp-4]:a=0
004010C1   mov         eax,0CCCCCCCCh							        [ebp-8]:b=1
004010C6   rep stos    dword ptr [edi]                                  [ebp-0Ch]:c=2
//功能代码**********************************							
004010C8   mov         dword ptr [ebp-4],0							
004010CF   mov         dword ptr [ebp-8],1						        3、分析全局变量	
004010D6   mov         dword ptr [ebp-0Ch],2							无
004010DD   mov         eax,dword ptr [ebp+8]							
004010E0   cmp         eax,dword ptr [ebp+0Ch]							
004010E3   jg         004010f0							
004010E5   mov         ecx,dword ptr [ebp-8]						    4、功能分析	
004010E8   sub         ecx,1							                第一个if分支，if(x>y)
004010EB   mov         dword ptr [ebp-4],ecx							else:
004010EE   jmp         00401123							                    第二个if分支,if(x>=y)
004010F0   mov         edx,dword ptr [ebp+0Ch]						            else:
004010F3   cmp         edx,dword ptr [ebp+10h]							            第三个if分支:(x<=y)
004010F6   jl          00401103							                                else:
004010F8   mov         eax,dword ptr [ebp-0Ch]							                     
004010FB   add         eax,1						                    	
004010FE   mov         dword ptr [ebp-4],eax							
00401101   jmp         00401123							                5、返回值分析
00401103   mov         ecx,dword ptr [ebp+8]							有： eax
00401106   cmp         ecx,dword ptr [ebp+10h]							
00401109   jle         00401116							
0040110B   mov         edx,dword ptr [ebp-8]							
0040110E   add         edx,dword ptr [ebp-0Ch]							
00401111   mov         dword ptr [ebp-4],edx							
00401114   jmp         00401123							
00401116   mov         eax,dword ptr [ebp-0Ch]							
00401119   mov         ecx,dword ptr [ebp-8]							6、还原成C函数
0040111C   lea         edx,[ecx+eax-1]							
00401120   mov         dword ptr [ebp-4],edx
//返回值*************************************							
00401123   mov         eax,dword ptr [ebp-4]							
00401126   add         eax,1
//END***************************************							
00401129   pop         edi							
0040112A   pop         esi							
0040112B   pop         ebx							
0040112C   mov         esp,ebp							
0040112E   pop         ebp							
0040112F   ret		  
    }
}					

//逆向成的C代码
int Re_three(int x, int y, int z) {
	int a = 0, b = 1, c = 2;
	if (x<=y) {
		a=b-1;
	}
	else {
		if(y>=z){
			a = c+1;
		}
		else {
			if (x>z) {
				a = b + c;
			}
			else {
				a = b + c - 1;
			}
		}
	}
	return a+1;
}

int main() {
	Re_three(4, 5, 6);
	return 0;
}