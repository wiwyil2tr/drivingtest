#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义题目和答案
const char* questions[] = {
    "起步",
    "加减挡",
    "直线行驶",
    "直线行驶完毕",
    "前方路口右转弯",
    "前方完成超车动作",
    "前方变更车道",
    "前方选择合适地点掉头",
    "公交车站",
    "已通过公交车站",
    "前方直行通过路口",
    "学校",
    "前方路口左转弯",
    "人行横道",
    "会车",
    "前方靠边停车"
};

const char* answers[] = {
    "AIBZHCU4HGDU1HGEU",
    "2HGFU3HGEU",
    "8",
    "HGDU",
    "JLZN",
    "I3V4JOW5",
    "I3V4",
    "IZ6",
    "L",
    "I3V4",
    "L",
    "L",
    "ILZM",
    "L",
    "7",
    "JHGCUW5PHKRGSQXY"
};

// 题库总数
const int numQuestions = sizeof(questions) / sizeof(questions[0]);

// 显示题目
void displayQuestion(int index)
{
    printf("题目：%s\n", questions[index]);
    printf("请选择正确选项：\n");
    printf("A.系安全带\tB.放手刹\tC.挂一档\tD.挂二档\tE.挂三挡\n");
    printf("F.挂四档\tG.摘空挡\tH.踩离合\tI.打左转向灯\tJ.打右转向灯\n");
    printf("K.踩刹车\tL.轻点三下刹车\tM.左转弯\tN.右转弯\tO.过3条线\n");
    printf("P.对准点\tQ.解安全带\tR.拉手刹\tS.灭火\tT.点火\n");
    printf("U.松离合\tV.观察左后视镜\tW.观察右后视镜\tX.开门下车\n");
    printf("Y.关门\tZ.观察\t1.加到20\t2.加到30\t3.数5秒\n");
    printf("4.左变道\t5.右变道\t6.虚线方向盘打死\t7.无动作\n8.调整方向盘\n");
}

// 检查答案是否正确
int checkAnswer(int index, const char* answer)
{
    if (strcmp(answers[index], answer) == 0) {
        return 1;
    } else {
        printf("%s的答案为%s，扣100分，考试结束, 成绩不合格\n", questions[index], answers[index]);
        return 0;
    }
}

int main()
{
	int i, score = 100;

    // 依次出题
    for (i = 0; i < numQuestions; i++) {
        displayQuestion(i);
        char answer[100];
        scanf(" %s", answer);
        if (checkAnswer(i, answer)) {
            score -= 0;
        } else {
            printf("%s的答案为%s，扣100分，考试结束, 成绩不合格\n", questions[i], answers[i]);
            return 0;
        }
    }

    // 判断是否全部正确
    if (score >= 90) {
        printf("考试结束，成绩合格，请回中心打印成绩单\n");
    }

    return 0;
}

