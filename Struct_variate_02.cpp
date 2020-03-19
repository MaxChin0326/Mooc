// 10.2 结构变量在函数中的应用
//定义包含小时、分钟、秒三个成员的时间结构类型，编写一个转换函数，将24小时计时制的时间转换成12小时计时制。
/*1、函数参数：函数接受一个24小时计时制的时间，参数淫威一结构类型变量；
  2、函数返回值：函数转换的结果为12小时计时制的时间，故返回值也应为结构类型；
  3、为方便输出处理，将是否转换的判断放在主函数，而不是转换函数里进行。 */

#include <iostream>
using namespace std;

struct time
{
    int hour;
    int minumte;
    int second;
};
struct time change(struct time t) //允许结构变量整体做参数
{
    t.hour = t.hour % 12;
    return t; //返回结构类型
}
int main()
{
    struct time t;
    cin >> t.hour >> t.minumte >> t.second;
    if (t.hour > 12)
    {
        t = change(t);
        cout << t.hour << ":" << t.minumte << ":" << t.second << "pm";
    }
    else
        cout << t.hour << ":" << t.minumte << ":" << t.second << "am";
    system("pause");
    return 0;
}
