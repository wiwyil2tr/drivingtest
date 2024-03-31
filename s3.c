#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义题库和答案
const char* questions[] = {
    "请开启前照灯",
    "在照明良好的道路行驶",
    "在有信号灯控制路口转弯",
    "会车",
    "同方向近距离跟车行驶",
    "在照明不良的道路上行驶",
    "在无照明的道路行驶",
    "超车",
    "通过没有交通信号灯控制的路口",
    "通过坡路",
    "通过急弯",
    "通过拱桥",
    "通过人行横道",
    "模拟夜间灯光的考试结束，请在关闭所有灯光后起步"
};

const char* answers[] = {
    "D.前照灯(拧两下)",
    "B.近光灯(无动作)",
    "B.近光灯(无动作)",
    "B.近光灯(无动作)",
    "B.近光灯(无动作)",
    "A.远光灯(按住)",
    "A.远光灯(按住)",
    "C.远近交替",
    "C.远近交替",
    "C.远近交替",
    "C.远近交替",
    "C.远近交替",
    "C.远近交替",
    "F.关灯光(拧两下)"
};

// 题库总数
const int numQuestions = sizeof(questions) / sizeof(questions[0]);

// 生成随机题目索引
void generateRandomIndexes(int* indexes, int numIndexes, int maxIndex)
{
    int i, j;
    srand(time(NULL));
    
    for (i = 0; i < numIndexes; i++) {
        indexes[i] = rand() % maxIndex;
        
        // 检查是否已经生成过这个题目索引
        for (j = 0; j < i; j++) {
            if (indexes[i] == indexes[j]) {
                i--;
                break;
            }
        }
    }
}

// 显示题目
void displayQuestion(int index)
{
    printf("题目：%s\n", questions[index]);
    printf("请选择正确选项：\n");
    printf("A.远光灯(按住)\n");
    printf("B.近光灯(无动作)\n");
    printf("C.远近交替\n");
    printf("D.前照灯(拧两下)\n");
    printf("E.示廓灯(回一下)\n");
    printf("F.关灯光(拧两下)\n");
}

// 检查答案是否正确
int checkAnswer(int index, char answer)
{
    if (answers[index][0] == answer) {
        return 1;
    } else {
        printf("%s的答案为: %s，扣100分，考试结束, 成绩不合格!\n", questions[index], answers[index]);
        return 0;
    }
}

int main()
{
	printf("下面将进行模拟夜间灯光使用的考试,请根据播报的驾驶场景,在播报后5秒内做出相应的灯光操作\n");
    int indexes[5];
    int i, score = 0;

    // 第一题必须是"请开启前照灯"
    displayQuestion(0);
    char answer;
    scanf(" %c", &answer);
    if (checkAnswer(0, answer)) {
        score -= 0;
    } else {
//        printf("%s的答案为%s，扣100分，考试结束, 成绩不合格\n", questions[0], answers[0]);
        return 1;
    }

    // 生成随机题目索引
    generateRandomIndexes(indexes, 4, numQuestions-2);

    // 随机抽取4个题目
    for (i = 0; i < 5; i++) {
        displayQuestion(indexes[i]);
        scanf(" %c", &answer);
        if (checkAnswer(indexes[i], answer)) {
            score -= 0;
        } else {
            //printf("%s的答案为%s，扣100分，考试结束, 成绩不合格\n", questions[indexes[i]], answers[indexes[i]]);
            return 1;
        }
    }

    // 最后一题 "模拟夜间灯光的考试结束，请在关闭所有灯光后起步"
    displayQuestion(numQuestions-1);
    scanf(" %c", &answer);
    if (checkAnswer(numQuestions-1, answer)) {
        score -= 0;
		printf("请起步!\n");
		system("./start");
	}
	else{}

            //printf("%s的答案为%s，扣100分，考试结束, 成绩不合格\n", questions[numQuestions-1], answers[numQuestions-1]);return 1;
	    // 判断是否全部正确
/*    if (score == 100) {
        printf("请起步！\n");
    }

    return 0;*/
}

