// 8.3 函数间参数的传递
//形参是基本数据类型的变量
/*实参与形参结合过程
  1、函数调用时，系统为形参分配新的存储单元，将实参的值传递给形参；
  2、被调函数中的操作都是在形参的存储单元中进行，与实参无关
  3、当函数调用结束，释放形参所占用的存储单元，返回主调函数*/

//引用参数
/*引用是一种特殊的变量，可认为是另一个变量的别名
  例如：int x=3,&a=x;  //a是x的引用*/
/*如果a是x的引用，a和x使用同一内存单元，a改变了，意味着x也改变了，x改变了，a也改变*/

#include <iostream>
using namespace std;

  /*交换两个整数的值*/
void swap1(int a, int b)
{
    int temp;
    temp = a; a = b; b = temp;
}

void swap2(int &a,int &b)  //引用参数
{
    int temp;
    temp = a; a = b; b = temp;
}

/*判别一个自然数N是降序数，同时求该数各位数和，
加以调用，若是降序数输出“yes”，否则“no”*/
//返回两个值给主函数
/*是否是降序数，可通过return语句返回*/

bool drop(int Drop, int& sum)
{
    int x = Drop;
    bool flag = 1;
    while (Drop >= 10 && flag)
        if (Drop / 10 % 10 < Drop % 10)
            flag = 0; 
        else Drop /= 10;
    while (x)
    {
        sum += x % 10; x /= 10;
    }
    return flag;
}

int main()
{
    int x, y;
    cout << "请输入x，y" << endl;
    cin >> x >> y;
    swap1(x, y);  //函数调用，实参不变，形参变化。
    cout << "交换后x=" << x << " y=" << y << endl;

    swap2(x, y);  //函数调用，实参不变，形参变化。
    cout << "交换后x=" << x << " y=" << y << endl;
    system("pause");
    return 0;
}
