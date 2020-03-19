// 8.3 函数间的参数传递
/**/

#define N 100
#include <iostream>
using namespace std;

//随机生成10个1～100之间的数，放在一维数组中，求其平均值及最大的元素值，并在主函数中显示结果
/*分析：1、怎么把数组传递给函数用于计算：传递数组的首地址，
         对应的形参为指针变量；
      2、怎么传回2个值给主函数：平均值和最大值？使用指针参数或引用参数*/
void fun(float *p, float *p1, float *p2) //指针参数
{
    float sum, max;
    sum = max = *p++;  //初始化
    for (int i = 1; i < N; i++)
    {
        if (max < *p) max = *p;
        sum = sum + *p;
        p++;
    }
    *p1 = sum / N;     //修改形参指针指向内存单元的内容就是修改对应实参值
    *p2 = max;
}

int main()
{
    float a[10], aver, max1, x;
    for (int i = 0; i < 10; i++)
    {
        x = rand() % 100 + 1; //随机生产10个1～100之间的数
        a[i] = x;   //放入数组中
    }
    fun(a, &aver, &max1);  //实参
    cout << aver << max1 << endl;
    system("pause");
    return 0;
}
