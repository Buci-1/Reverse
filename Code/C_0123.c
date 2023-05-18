//定义一个函数，能够输出任意进制的第N个数:
//结果 = fn(进制，第N个数);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fn(int base, int n) {
    if (n == 0) {
        return;
    }
    fn(base, n / base);
    int remainder = n % base;
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", remainder - 10 + 'A');
    }
}

int main() {
    int base = 8;
    int n = 100;
    fn(base, n);
    printf("\n");
    return 0;
}