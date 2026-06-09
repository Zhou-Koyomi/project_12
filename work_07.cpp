#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Candidate {
    char name[50];    // 候选人姓名
    int votes;        // 得票数
};

void init_candidates(struct Candidate* candidates, int n) {
    int i;

    printf("输入%d个候选人的姓名:\n", n);
    for (i = 0; i < n; i++) {
        printf("候选人%d: ", i + 1);
        scanf_s("%s", candidates[i].name, (unsigned)sizeof(candidates[i].name));
        candidates[i].votes = 0;  // 初始得票数为0
    }
    printf("\n");
}

void vote(struct Candidate* candidates, int candidate_count, int voter_count) {
    int i, j;
    char vote_name[50];
    int found;

    printf("共有%d人投票:\n\n", voter_count);

    for (i = 0; i < voter_count; i++) {
        printf("输入第%d位选民要投的候选人姓名: ", i + 1);
        scanf_s("%s", vote_name, (unsigned)sizeof(vote_name));

        found = 0;
        // 查找候选人并增加票数
        for (j = 0; j < candidate_count; j++) {
            if (strcmp(vote_name, candidates[j].name) == 0) {
                candidates[j].votes++;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("  无效票！没有找到候选人 %s\n", vote_name);
        }
        printf("\n");
    }
}

void display_results(struct Candidate* candidates, int n) {
    int i;
    int total_votes = 0;

    printf("%-15s %-10s\n", "候选人姓名", "得票数");

    // 计算总票数
    for (i = 0; i < n; i++) {
        total_votes += candidates[i].votes;
    }

    // 显示每个候选人的得票情况
    for (i = 0; i < n; i++) {
        printf("%-15s %-10d\n", candidates[i].name, candidates[i].votes);
    }

    printf("\n总投票数: %d\n", total_votes);

    // 找出得票最多的候选人
    int max_votes = 0;
    int winner_index = 0;
    for (i = 0; i < n; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    if (max_votes > 0) {
        printf("得票最多的候选人是: %s (得票数: %d)\n",
            candidates[winner_index].name, candidates[winner_index].votes);
    }
}

void work_07() {
    struct Candidate candidates[3];  // 3个候选人
    int n;  // 投票人数
    // 初始化候选人
    init_candidates(candidates, 3);

    // 输入投票人数
    printf("输入投票人数: ");
    scanf_s("%d", &n);
    printf("\n");

    // 进行投票
    vote(candidates, 3, n);

    // 显示结果
    display_results(candidates, 3);
}