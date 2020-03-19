// SelectionSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//将N个学生成绩由大到小排序
/*1、从N个数的序列中选出最大的数，与第一个数交换位置；
  2、除第一个数外，其余N-1个数再按1的方法选出次大的数与第2个数交换位置；
  3、重复上述过程N-1遍，最后构成递减序列*/
//如何求N个成绩中的最高分
/*1、假设第一个学生成绩最高，将其赋予代表最高分的max；
  2、将max与后面所有的元素逐一比较，若遇到比其大的元素，max便被该元素取代
  */
#define N 20
#include <iostream>
using namespace std;
int main()
{
    int a[N], i, max,imax,j;
    /*随机分数*/
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 101; //rand()随机数范围0～32767，原型所在头文件stdlib.h，rand()%(a+1)产生0～a之间的随机数
        cout << a[i] << '\t';
    }
    max = a[0]; //假设第一元素最大
    for (i = 1; i < N; i++)
        if (a[i] > max)
            max = a[i]; //用更大的取代当前的最大值
    cout << "max=" << max << endl;
    /*求最高分是第几个学生*/
    imax = 0;   //假设imax代表最大元素下标
    for(j = 1; j < N; j++)
        if (a[j] > a[imax])   //比较元素，记录下标
            imax = j;
    cout << "imax=" << imax << endl;
    /*将最高分放在第一位，交换a[0]与a[imax]*/
    int t = a[0];
    for(i=0;i<N;i++)
    {
        a[0] = a[imax];
        a[imax] = t;
        cout << a[i] << '\t';
    }
    /*将成绩完全排序*/
    cout << "after sort:"<<'\n';
    int s,jmax;
    for (i = 0; i < N-1; i++)
    {
        jmax = i;
        for (j = i+1; j < N; j++)
            if (a[j] > a[jmax])
                jmax = j;
        s= a[jmax];
        a[jmax] = a[i];
        a[i] = s;
        cout<< a[i] << '\t';
    }
    system("pause");
    return 0;


}