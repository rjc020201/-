#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
** 文件名: experiment5
** 创建人: 容津程
** 日 期: 2020.11.1
** 修改人: 容津程
** 日 期: 2020.11.1
** 描 述: 学生成绩管理系统
*/
/*
输入数据的函数
** 函数名:Input 
** 输 入: 学号，分数，学生组，人数位置  
** 输 出: 无. 
** 功能描述:向学生组中插入人数
*/
void Input(int number,int score,int students[][2],int wai){
        students[wai][0]=number;
        students[wai][1]=score;
}
/*
算数据总数
** 函数名: Sum
** 输 入: 学生组 ，学号
** 输 出: 总分数
** 功能描述: 计算学生组总分数
*/
int Sum(int students[][2]){
    int i,j;
    int sum=0;
    for(i=0;i<30;i++){
        for(j=0;j<2;j++){
            if(j==1){
                sum+=students[i][j];
            }
        }
    }
    return sum;
}
/*
算数据的平均数
** 函数名: Ave
** 输 入: 学生组
** 输 出: 分数平均分
** 功能描述: 算分数平均分
** 调用模块: Sum
*/
double Ave(int students[][2]){
    int Isum=Sum(students);
    double studentNumber=(double)StudentNumber(students);
    double ave=Isum/(studentNumber*1.0);
    return ave;
}
/*
算学生的人数 
** 函数名:StudentNumber 
** 输 入: 学生组
** 输 出: 输出学生总人数 
** 功能描述: 算学生总人数
** 全局变量: 无
** 调用模块: 无

*/
int StudentNumber(int students[][2]){
    int i;
    int studentNumber=0;
    for(i=0;i<30;i++){
            if(students[i][0]!=0 || students[i][1]!=0){
            studentNumber++;
            }
    }
    return studentNumber;
}
/*
** 函数名: Sort
** 输 入: 学生组 
** 输 出: 无 
** 功能描述: 对学生组排序
** 全局变量: 无
** 调用模块: 调用指针函数asort
*/
void Sort(int students[][2],int (*compare)(int ,int )){
    int i,j;
    int studentNumber=StudentNumber(students);
    for(i=0;i<studentNumber-1;i++){
        for(j=0;j<studentNumber-i-1;j++){

            if((*compare)(students[j][1],students[j+1][1])){
                int temp=students[j+1][1];
                students[j+1][1]=students[j][1];
                students[j][1]=temp;
                int tem=students[j+1][0];
                students[j+1][0]=students[j][0];
                students[j][0]=tem;
                }
        }
    }

}
/* 
** 函数名: Numbersort
** 输 入: 学生组
** 输 出: 无 
** 功能描述: 对学生组学号排序
** 全局变量: 无
** 调用模块: 指针函数排序
*/
void NumberSort(int students[][2],int (*compare)(int ,int )){
    int i,j;
    int studentNumber=StudentNumber(students);
    for(i=0;i<studentNumber-1;i++){
        for(j=0;j<studentNumber-i-1;j++){

            if((*compare)(students[j][0],students[j+1][0])){
                int temp=students[j+1][1];
                students[j+1][1]=students[j][1];
                students[j][1]=temp;
                int tem=students[j+1][0];
                students[j+1][0]=students[j][0];
                students[j][0]=tem;
                }
        }
    }

}
/* 
** 函数名: 对学生组全输出
** 输 入:  学生组
** 输 出: 无  
** 功能描述: 输出全部学生组
** 全局变量: 无
** 调用模块: 无
*/
void Output(int students[][2]){
    int i;
    for(i=0;i<StudentNumber(students);i++){
        printf("news %d is :%d\t%d\n",i,students[i][0],students[i][1]);
    }

}
/* 
** 函数名: asort
** 输 入:  a,b
** 输 出: 比较a和b的大小并返回二者比较的大小
**　１：ａ大于ｂ
＊＊　０：ａ小于ｂ
** 功能描述: 比较a和b的大小并返回二者比较的大小
** 全局变量: 无
** 调用模块: 无
*/
int asort(int a,int b){
    return a>b;
}
/*
** 函数名: asort
** 输 入:  a,b
** 输 出: 比较a和b的大小并返回二者比较的大小
**　１：ａ小于ｂ
＊＊　０：ａ大于ｂ
** 功能描述: 比较a和b的大小并返回二者比较的大小
** 全局变量: 无
** 调用模块: 无
*/
int resort(int a,int b){
/*
** 函数名: Require
** 输 入: 查询的成绩大小
** 输 出: 查到的成绩和对应学号
** 功能描述: 查寻出成绩和对应学号
** 全局变量: 无
** 调用模块: 无
*/
    return a<b;
}
void Require(int WhatYouWant,int students[][2]){
    int i=0;
    int NO=1;
    int isture=0;
    for(i=0;i<StudentNumber(students);i++){
        if(students[i][0]==WhatYouWant){
            isture=1;
            printf("students:%d\t%d\n",students[i][0],students[i][1]);
            int j;
            for(j=0;i<StudentNumber(students);i++){
                if(students[j][1]>students[i][1]){
                    NO++;
                }
            }
            printf("its number is:%d\n",NO);
        }
    }
    if(isture==0){
    printf("sorry i can't find!\n");
    }
}
/*
** 函数名: Tongji
** 输 入: 学生组
** 输 出: 输出组中成绩大小的分组
** 功能描述: 统计组中成绩的大小
** 全局变量: 无
** 调用模块: 无
*/
void Tongji(int students[][2]){
    int i,j;
    double best=0,better=0,good=0,bad=0,worse=0,wuyong;
    double ibest=0,ibetter=0,igood=0,ibad=0,iworse=0;
    for(i=0;i<30;i++){
       int injudge;
       injudge=students[i][1]/10;
       switch(injudge){
            case 10:best++;
                    break;

            case 9:best++;
                    break;
            case 8:better++;
                    break;
            case 7:good++;
                    break;
            case 6:bad++;
                    break;
            case 0:wuyong++;
                    break;
            default:worse++;
                    break;
       }
    double studentNumber=(double)StudentNumber(students);
    ibest=best/studentNumber,ibetter=better/studentNumber,igood=good/studentNumber,ibad=bad/studentNumber,iworse=worse/studentNumber;

    }
    printf("best:%.2lf people:%.0lf\nbetter:%.2lf people:%.0lf\ngood:%.2lf people:%.0lf\nbad:%.2lf people:%.0lf\nworse:%.2lf people=%.0lf\n",ibest,best,ibetter,better,igood,good,ibad,bad,iworse,worse);
}
/*
** 函数名: Alloutput
** 输 入: 学生组
** 输 出: 学生组全体和对应的统计情况
** 功能描述: 输出学生组和对应的统计情况
** 全局变量: 无
** 调用模块: Tongji函数
*/
void Alloutput(int students[][2]){


    int i=0,j=0;
    for(i=0;i<30;i++){
        if(students[i][0]!=0 && students[i][1]!=0){
            printf("number:%d\tscorce:%d\n",students[i][0],students[i][1]);
        }
    }
    Tongji(students);
}
int main()
{
   /***
    请用户输入选项
    ****/
    int wai=0,allNumber;
    int choice=9,number;
    int scorce=0;
    int whatYouWant;
    int students[30][2]={{0}};
    char checki=0;
    int ExitThis=0;
    while(ExitThis==0){
    printf("1.Input record\n2.Calculate total and average score of course\n3.Sort in descending order by score\n4.Sort in ascending order by score\n5.Sort in ascending order by number\n6.Search by number\n7.Statistic analysis\n8.List record\n0.Exit\nPlease enter your choice:");
    while(1){
            scanf("%d",&choice);
            checki=getchar();
            if(checki=='\n'&&choice<9&&choice>-1){
                fflush(stdin);
                break;
            }else{
                printf("your enter is wrong!please enter again!\n");
                printf("please enter again:");
                fflush(stdin);
            }
    }
    switch(choice){
        case 1:
            printf("if you want to stop it please enter -1to any form\n");
            do{printf("please input the people's number:");
            scanf("%d",&allNumber);}
            while(allNumber>30||allNumber<=0);
            while(wai<allNumber){
                printf("please input student's number :");
                int number,scorce;
                int boolin=0;
                do{
                    boolin=0;
                    scanf("%d",&number);
                    int q=0;
                    for(q=0;q<wai;q++){
                        if(students[q][0]==number){
                            printf("this number you hava been input before.please input another number!\n");
                            boolin=1;
                            }
                        }
                }while(boolin==1);
                printf("and it's scorce:");
                scanf("%d",&scorce);
                if(scorce==-1||number==-1){
                    break;
                }

                if(scorce<101 && scorce>=0){
                    Input(number,scorce,students,wai);
                    wai++;
                }else{
                    printf("please input right score:");
                }

            }
                break;


        case 2:if(students[0][0]==0&&students[0][1]==0){
                    printf("please input you information firstly!\n");
                    break;
                }
                printf(" Calculate total and average score of course is:");
                int total=Sum(students);
                double average=Ave(students);
                printf("total is:%d\naverage is:%lf\n",total,average);
                break;

       case 3:if(students[0][0]==0&&students[0][1]==0){
                printf("please input data firstly!\n");
                }else{
                Sort(students,resort);
                Output(students);
                }
                break;

        case 4:if(students[0][0]==0&&students[0][1]==0){
                printf("please input data firstly!\n");
                }else{
                Sort(students,asort);
                Output(students);
                }
                break;

        case 5:if(students[0][0]==0&&students[0][1]==0){
                printf("please input data firstly!\n");
                }else{
                NumberSort(students,asort);
                Output( students);
                }
                break;

        case 6:if(students[0][0]==0&&students[0][1]==0){
                printf("please input data firstly!\n");
                }else{
                while(1){
                    printf("please input what you want to require:");
                    scanf("%d",&whatYouWant);
                    checki=getchar();
                    if(checki=='\n'&&choice<101&&choice>-1){
                        fflush(stdin);
                        break;
                    }else{
                    printf("your enter is wrong!please enter again!\n");
                    printf("please enter again:");
                    fflush(stdin);
                    }
                }
                Require(whatYouWant, students);
                }
                break;

        case 7:if(students[0][0]==0&&students[0][1]==0){
                printf("please input data firstly!\n");
                }else{Tongji(students);
                }
                break;

       case 8:if(students[0][0]==0&&students[0][1]==0){
                printf("please input data firstly!\n");
                }else{Alloutput(students);
                }
                break;
        case 0:ExitThis=1;
                break;

        }
    }
    printf("good bye");

    return 0;
}
