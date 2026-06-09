#include<stdio.h>  

void work_01();
void work_02();
void work_03();
void work_04();
void work_05();
void work_06();
void work_07();
void work_08();

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}//while((c=getchar())!= '\n' && c!= EOF)用来清空输入缓冲区，直到遇到换行符或文件结束符。  
//防止之前输入的残留数据干扰后续的输入操作。  

int main() {
    int question = 0;//题号选择变量  
    char chioce = 'N';//是否继续执行的选择变量  
    do {
        printf("选择要执行的题目（1-8）：");
        scanf_s("%d", &question);
        clear_buffer();  // 清空残留换行  
        while (true) {
            if (question < 1 || question>8) {
                printf("输入无效，请输入1-8之间的数字：");
                scanf_s("%d", &question);
                clear_buffer();  // 清空残留换行  
                continue;//输入无效，继续循环要求输入  
            }
            else break;
        }
        switch (question) {
        case 1:
            work_01();
            break;
        case 2:
            work_02();
            break;
        case 3:
            work_03();
            break;
        case 4:
            work_04();
            break;
        case 5:
           work_05();
            break;
        case 6:
            work_06();
            break;
        case 7:
            work_07();
            break;
        case 8:
            work_08();
            break;
        default:
            printf("重新输入题号");
        }
        printf("看其他题吗？(y/n): ");
        scanf_s(" %c", &chioce, 1);//注意前面有一个空格，避免读取到之前输入的换行符  
    } while (chioce == 'y' || chioce == 'Y');
    return 0;
}
