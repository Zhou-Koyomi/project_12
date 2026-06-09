#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student {
    char name[50];
    char id[20];
    float score;
};

void input_students(struct Student stu[], int n) {
    printf("输入%d个学生的信息:\n\n", n);
    for (int i = 0; i < n; i++) {
        printf("第%d个学生:\n", i + 1);
        printf("  姓名: ");
        scanf_s("%s", stu[i].name, (unsigned)sizeof(stu[i].name));
        printf("  学号: ");
        scanf_s("%s", stu[i].id, (unsigned)sizeof(stu[i].id));
        printf("  成绩: ");
        scanf_s("%g", &stu[i].score);
        printf("\n");
    }
}

float cal_aver(struct Student* stu, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += stu[i].score;    }
    return sum / n;
}

struct Student* f_high(struct Student stu[], int n) {//struct Student* 指针类型，指向一个Student结构体。
    //函数返回一个指向Student结构体的指针。
    int i;
	struct Student* highest = &stu[0];//初始化最高分学生指针，指向第一个学生

    for (i = 1; i < n; i++) {//从第二个学生开始比较成绩
        if (stu[i].score > (*highest).score) {//如果当前学生的成绩高于最高分学生的成绩
            highest = &stu[i];//更新最高分学生指针，指向当前学生
        }
    }
    return highest;
}

void print_student(struct Student* stu) {//struct Student* stu是一个指向Student结构体的指针，表示要打印的学生信息
	printf("  姓名: %s\n", (*stu).name);
    //使用(*stu).name访问学生的姓名，(*stu)解引用指针，获取指针指向的Student结构体，然后访问其中的name成员。
    printf("  学号: %s\n", (*stu).id);
    //(*stu)解引用指针，获取指针指向的Student结构体，然后访问其中的id成员。
    printf("  成绩: %.2f\n", (*stu).score);
}

void work_05() {
    int n;
    struct Student* students;
    //定义一个指向Student结构体的指针变量students，用于动态分配内存存储学生信息。
    struct Student* highest;
    //定义一个指向Student结构体的指针变量highest，用于存储最高分学生的信息。
    float average;

    printf("输入学生人数: ");
    scanf_s("%d", &n);

    // 动态分配内存
    students = (struct Student*)malloc(n * sizeof(struct Student));
	//malloc函数返回一个void*类型的指针，需要强制转换为struct Student*类型。
    // 分配的内存大小是n乘以每个Student结构体的大小。
    if (students == NULL) {
        printf("内存分配失败！\n");
        return;
    }

    // 输入学生信息
    input_students(students, n);

    // 1) 计算并输出平均成绩
    average = cal_aver(students, n);
    printf("1) 平均成绩: %.2f\n\n", average);

    // 2) 输出最高分学生的全部信息
    highest = f_high(students, n);
    printf("2) 最高分学生信息:\n");
    print_student(highest);
    printf("\n");

    free(students);
}