// 6.4 字符串处理

#define N 100
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
 /*实现将字符串s的内容复制到字符串t中*/
/*1、复制字符串不能采用t=s的方式。数组名是地址常量，不能被赋值
  2、逐元素赋值*/
    char s[N], t[N];
    int i;
    cin.getline(s, 20);
    i = 0;
    while (s[i] != '\0')
    {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
    puts(t);

/*逐个比较两个字符串相对应位置的字符大小，输出
  1、找出持续比较的条件，相对应位置的字符相等且串还未结束；
  2、退出循环以后的再判断，何种情况代表相等；*/
    char  a[N], b[N];
    int j;
    cin.getline(a, 100);
    cin.getline(b, 100);
    j = 0;
    while (a[j] != '\0' && b[j] != '\0')
        if (a[j] == b[j])
            j++;
        else break;
    if (a[j] == '\0' && a[j] == '\0')
        cout << "两字符相等：" << endl;
    else
        cout << "两串相差" << a[j] - b[j];
    system("pause");
    return 0;
}

