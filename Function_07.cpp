// 9.3 递归函数
//用自身结构描述自身就称为“递归”；
#define N 100
#include <iostream>
#include <stdio.h>
using namespace std;

//阶乘：递归与迭代
//迭代求n!
int DieDai(int n)
{
    int i,s=1;
    for (i = 1; i <= n; i++)
        s = s * i;
    return 0;
}

//用递归的方法解决问题
//二分法查找
int Binary_Search(int low,int high,int key)
{
    int a[N];
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (key == a[mid])
        return mid;
    if (key < a[mid])
        return Binary_Search(low, mid - 1,key);
    else
        return Binary_Search(mid + 1, high,key);
}

//进制转换
//将十进制整数m转换成r（2<=r<=16)进制的数
void convert(int m, int r)
{
    char b[17] = "0123456789ABCEF";
    if (m != 0)
    {
        convert(m / r, r);
        cout << b[m % r];  //回归过程中执行该语句，后得到余数先输出
    }
}
int main()
{
    convert(100, 16);
    convert(6, 16);
    convert(0, 16);
}
