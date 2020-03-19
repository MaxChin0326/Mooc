// 10 结构体
//结构变量的访问
/*1、不能整体访问；
  2、通过结构变量访问成员：结构变量.成员名；
  3、通过指向结构的指针访问成员：
     （*指向结构的指针).成员名  括号不能省略
     指向结构的指针->成员名*/
//结构数组的应用
/*1、数据结构的选取；
  2、处理数据时正确理清层次关系；
  3、明确输入、输出、赋值等操作数据的访问要求。*/

#define N 5
#include <iostream>
#include <stdio.h>
using namespace std;

struct date
{
    int month;
    int day;
    int year;
};

struct Student
{
    char name[20];
    char no[7];
    double Chinese, English, math, avg;
    int age;
    struct date birthday;
}p1,*p=&p1;

int main()
{
    int i, j;
    Student s[N], t;
    for (i = 0; i < N; i++)
    {
        cout << i<<" 请输入：";
        cin >> s[i].name>> s[i].no >> s[i].Chinese >> s[i].English >> s[i].math;
        s[i].avg = (s[i].Chinese + s[i].English + s[i].math) / 3;
    }
    for (i = 0; i < N - 1; i++)
        for (j = 0; j < N - 1 - i; j++)
            if (s[j].avg > s[j + 1].avg)
            {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
    for (i = 0; i < N; i++)
    {
        cout << s[i].name << " " << s[i].no << " " << s[i].Chinese << " ";
        cout << s[i].English << " " << s[i].math << " " << s[i].avg << endl;
    }
    system("pause");
    return 0;
    // p1.age = 21;
    //strcpy(p->name, "Fang Min");   //p->name是字符数组，赋值要用strcpy函数
   // p->birthday.month = 8;   //此处注意用“.”运算，不能用“->”云端
}

