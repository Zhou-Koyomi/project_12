#include<stdio.h>

void work_02() {
    // 字符指针数组
    const char* months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };//定义一个字符串指针数组months，包含12个月份的英文名称。每个元素都是一个指向字符串的指针。
    int month;
    printf("输入月份数字(1-12): ");
    do {
        scanf_s("%d", &month);
        if (month >= 1 && month <= 12) {
            printf(" %s\n\n", months[month - 1]);
        }
        else {
            printf("输入无效！输入1-12之间的数字。\n\n");
        }
	} while (month < 1 || month > 12); // 输入验证，确保输入为1-12之间的数字
   
}