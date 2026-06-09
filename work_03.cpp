#include<stdio.h>
#include <cmath>
void work_03() {
	const int n = 4;
	double A[n][n], B[n][n];
	double (*pA)[n] = A; // 定义指向4维矩阵A的指针
	double (*pB)[n] = B; // 定义指向4维矩阵B的指针
	// 输入矩阵A
	printf("输入4维矩阵A的元素:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%lf", &pA[i][j]);
		}
	}
	// 输入矩阵B
	printf("输入4维矩阵B的元素:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%lf", &pB[i][j]);
		}
	}
	// 计算1-范数
	double normA = 0, normB = 0, normSum = 0;
	for (int j = 0; j < n; j++) {
		double sumA = 0, sumB = 0, sumSum = 0;
		for (int i = 0; i < n; i++) {
			sumA += fabs(pA[i][j]);
			sumB += fabs(pB[i][j]);
			sumSum += fabs(pA[i][j] + pB[i][j]);
		}
		if (sumA > normA) normA = sumA;
		if (sumB > normB) normB = sumB;
		if (sumSum > normSum) normSum = sumSum;
	}
	// 输出结果
	printf("矩阵A的1-范数: %g\n", normA);
	printf("矩阵B的1-范数: %g\n", normB);
	printf("矩阵A+B的1-范数: %g\n", normSum);
	// 验证不等式
	if (normSum <= normA + normB) {
		printf("%g + %g = %g\n", normA, normB, normA + normB);
		printf("%g <= %g\n", normSum, normA + normB); 
		printf("A+B的1-范数小于等于A的1-范数加上B的1-范数\n");
	}
	else {
		printf("A+B的1-范数大于A的1-范数加上B的1-范数\n");
	}
}