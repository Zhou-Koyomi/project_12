/*#include<stdio.h>
#include<string.h>

void work_08() {
    char colors[5][10] = { "红", "黄", "蓝", "白", "黑" };//二维数组，存储五种颜色的名称
	//printf("%s", colors[0]);//printf("%s", colors[1]);//输出二维数组中的元素
    //%s表示字符串，colors[0]表示第一行的字符串，即"红"，colors[1]表示第二行的字符串，即"黄"
    int count = 0;
    int i, j, k;
    printf("\n所有可能的取法：\n\n");

	for (i = 0; i < 5; i++) {//外层循环选择第一种颜色
		for (j = 0; j < 5; j++) {//中层循环选择第二种颜色
			if (j != i) {//确保第二种颜色与第一种颜色不同
				for (k = 0; k < 5; k++) {//内层循环选择第三种颜色
					if (k != i && k != j) {//确保第三种颜色与第一种和第二种颜色都不同
						count++;//计数器增加，记录不同取法的数量
						printf("第%2d种: %s  %s  %s\n",
                            count, colors[i], colors[j], colors[k]);
                        //输出当前的取法，%2d表示整数占两位宽度
                        //%s表示字符串，colors[i]、colors[j]、colors[k]分别表示选择的三种颜色
                    }
                }
            }
        }
    }

    printf("\n总共有 %d 种不同的取法\n", count);
}*/
#include<stdio.h>
#include<string.h>

// 定义枚举类型，表示五种颜色
enum Color { RED, YELLOW, BLUE, WHITE, BLACK };
// 对应的颜色名称字符串数组
const char* colorNames[] = { "红", "黄", "蓝", "白", "黑" };

void work_08() {
    int count = 0;
    enum Color i, j, k;  // 使用枚举变量作为循环变量

    printf("\n所有可能的取法：\n\n");

    for (i = RED; i <= BLACK; i = (enum Color)(i + 1)) {        // 外层循环选择第一种颜色
        for (j = RED; j <= BLACK; j = (enum Color)(j + 1)) {    // 中层循环选择第二种颜色
            if (j != i) {                   // 确保第二种颜色与第一种颜色不同
                for (k = RED; k <= BLACK; k = (enum Color)(k + 1)) {  // 内层循环选择第三种颜色
                    if (k != i && k != j) {       // 确保第三种颜色与前两种都不同
                        count++;  // 计数器增加，记录不同取法的数量
                        printf("第%2d种: %s  %s  %s\n",
                            count,
                            colorNames[i],  // 通过枚举值索引对应的颜色名称
                            colorNames[j],
                            colorNames[k]);
                    }
                }
            }
        }
    }

    printf("\n总共有 %d 种不同的取法\n", count);
}
