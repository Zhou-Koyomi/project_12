#include<stdio.h>
#include<stdlib.h>
int jose(int n, int m, int* order) {
    int* people;     // 动态分配数组，标记每个人是否在圈内
    int* p;          // 遍历指针
    int count = 0;   // 退出人数计数
    int index = 0;   // 当前报数位置
    int num = 0;     // 当前报数

    // 分配内存并初始化（1表示在圈内，0表示已退出）
    people = (int*)malloc(n * sizeof(int));
    for (p = people; p < people + n; p++) {
        *p = 1;  // 初始都在圈内
    }

    // 模拟报数过程
    while (count < n - 1) {  // 直到只剩一个人
        // 跳过已退出的人
        while (people[index] == 0) {
            index = (index + 1) % n;
        }

        num++;  // 报数

        if (num == m) {  // 报到m的人退出
            people[index] = 0;  // 标记为退出
            order[count] = index + 1;  // 记录退出顺序（编号从1开始）
            count++;
            num = 0;  // 重置报数
        }

        index = (index + 1) % n;  // 移动到下一个人
    }

    // 找到最后留下的人
    int last = -1;
    for (p = people; p < people + n; p++) {
        if (*p == 1) {
            last = p - people + 1;  // 编号从1开始
            break;
        }
    }

    free(people);
    return last;
}

void work_04() {
    int n, m;
    int* order;   // 存储退出顺序
    int* p;       // 遍历指针
    int last;     // 最后留下的人
    printf("输入总人数 n: ");
    scanf_s("%d", &n);
    printf("输入报数值 m: ");
    scanf_s("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("错误：n和m必须大于0！\n");
        return;
    }

    // 分配存储退出顺序的数组
    order = (int*)malloc((n - 1) * sizeof(int));

    // 解决约瑟夫环问题
    last = jose(n, m, order);

    // 输出结果
    printf("退出顺序: ");
    for (p = order; p < order + n - 1; p++) {
        printf("%d", *p);
        if (p < order + n - 2) {
            printf("  ");
        }
    }
    printf("\n\n");

    printf("最后留下的是原来的第 %d 号\n", last);

    free(order);
}