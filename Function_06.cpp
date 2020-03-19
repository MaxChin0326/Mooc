// 9.2 作用域与生存期的概念
//作用域（可见性）：在什么范围内可以被访问，空间概念
//生存期：在什么时间内存在，时间概念
//自动局部变量
/*1、存储类别auto，可缺省；
  2、作用域：从定义点开始到所在的分程序结束；
  3、生存期：所在分程序执行期间。开始执行分程序就生成，分程序执行结束就消亡
  4、初始化：可以初始化，缺省值为随机值*/
//静态局部变量
/*1、存储类别static；
  2、作用域：从定义点开始到所在的分程序结束；
  3、生存期：程序的整个执行周期;
  4、初始化：可以初始化，缺省值为0或'\0';*/

#include <iostream>
#include <stdio.h>
using namespace std;

int digit(long x)  //x的作用域
{
    int k = 0;
    while (x != 0)
    {
        x /= 10;
        k += 1;
    }
    return k;
}

int main()
{
    long x; //x的作用域
    cin >> x;
    cout << digit(x) << endl;
    system("pause");
    return 0;
}

