#include <stdio.h>
#include <string.h>

int main() {
    // char *haystack = "655131001";
    // char *needle = "5555";

    // ตรวจสอบว่า needle มีอยู่ใน haystack หรือไม่
    // if (strstr(haystack, needle)) {
    //     printf("Yes\n");
    // }
    char needle[50];
    char str[50] = "123456789";

    scanf("%s", needle);
    printf("%d, %c\n", strlen(needle), needle[strlen(needle) - 1]);
    
    if (needle[strlen(needle) - 1] == str[strlen(str) - 1]) {
        printf("Yes\n");
    }

    return 0;
}
