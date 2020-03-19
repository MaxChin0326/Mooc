// 9.1 返回指针值的函数
/*1、函数的返回值可以是变量的地址、数组名或指针变量等。
  2、在说明或定义返回值为指针值的函数时，只须在函数名
  前加一指针类型说明符即可。*/

#include <iostream>
#include <stdio.h>
using namespace std;

//函数：将字符串s中ASCII码最大字符的地址返回，主程序中输出最大字符之后的子串
/*1、如何定义函数类型？
    函数返回值是s中ASCII码最大字符的地址，函数类型为指针
    char *getmax(char s[])
  2、如何表示s中最大字符地址？
     用该数组元素地址 &s[imax]或 s+imax表示imax是最大字符在数组中的位置*/
char *getmax(char s[])
{
    char *m = new char; //增加了指针变量

    int i = 1, imax = 0;
    while (s[i] != '\0')
    {
        if (s[i] > s[imax])
            imax = i;
        i++;
    }
    *m = s[imax];
    return m;
   // return s + imax;  //return &s[imax];
}
int main()
{
    char s[20];
    char *max;
    cin.getline(s, 20);
    max = getmax(s);
    cout << max << endl;
    system("pause");
    return 0;
}

