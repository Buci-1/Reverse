#include <stdio.h>
#include <string.h>

void getSubstring(char *str, int n) {
    int i = 0, j = 0;
    while (i < strlen(str) && j < n) {
        if ((str[i] & 0x80) != 0) {
            i += 2;
        } else {
            i += 1;
        }
        j += 1;
    }
    if (j == n && (i % 2) == 1) {
        i -= 1;
    }
    str[i] = '\0';
    printf("%s\n", str);
}

int main() {
    char str[] = "china中国verygood天朝nice";
    char input[10];
    int n;
    printf("请输入要切割的长度：");
    fgets(input, 10, stdin);
    sscanf(input, "%d", &n);
    getSubstring(str, n);
    return 0;
}