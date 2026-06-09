#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tTime{
    int hour;
    int min;
    int sec;
};

void input_times(struct tTime* times, int n) {
    printf("输入%d位同学的耗时:\n\n", n);
    for (int i = 0; i < n; i++) {
        printf("第%d位同学:\n", i + 1);
        printf("  小时: ");
        scanf_s("%d", &times[i].hour);
        printf("  分钟: ");
        scanf_s("%d", &times[i].min);
        printf("  秒: ");
        scanf_s("%d", &times[i].sec);
        printf("\n");
    }
}
struct tTime calculate_total(struct tTime* times, int n) {
    struct tTime total = { 0, 0, 0 };

    for (int i = 0; i < n; i++) {
        total.hour += times[i].hour;
        total.min += times[i].min;
        total.sec += times[i].sec;
    }

    // 处理进位
    total.min += total.sec / 60;
    total.sec %= 60;
    total.hour += total.min / 60;
    total.min %= 60;

    return total;
}
void work_06() {
    struct tTime times[10];
    struct tTime a;

    input_times(times, 10);
    // 计算总时间
    a = calculate_total(times, 10);

    // 输出结果
    printf("总耗时: %d小时 %d分钟 %d秒\n", a.hour, a.min, a.sec);
}