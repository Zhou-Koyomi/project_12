#include <stdio.h>
#define M 100

void work_01(){
    int n, i, j;
    int matrix[M][M];
	int checked = 1; // 标志变量，初始值为1，表示假设矩阵是对称的
    // 输入方阵的阶数
    printf("输入方阵的阶数 n: ");
    scanf_s("%d", &n);

    // 输入矩阵元素
    printf("请输入 %d×%d 矩阵的元素:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    // 判断是否为对称矩阵
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {  // 只检查下三角部分
            if (matrix[i][j] != matrix[j][i]) {
				checked = 0; // 如果发现不对称的元素，设置标志为0
                break;
            }
        }
    }
    // 输出原矩阵
    printf("\n输入的矩阵为:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // 输出判断结果
    if (checked) {
        printf("\n该矩阵是对称矩阵\n");
    }
    else {
        printf("\n该矩阵不是对称矩阵\n");
    }
}