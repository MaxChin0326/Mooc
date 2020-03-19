//将十进制整数n转换成r（2-16）进制形式。
/*n%r 得到r进制的最低位，将其存入整形数组a的第一个元素a[0]中*/
/*再将n/r的商赋值给n，继续执行n%r 得到r进制的次低位，并存入a的下一个元素中*/
/*以此类推，直到n为0，转换结束*/

#include <iostream>
using namespace std;
int main()
{
    int i = 0, n, r, a[10];
    char b[16] = { '0','1','2','3', '4','5' ,'6','7','8','9','A', 'B','C' ,'D','E' ,'F', };
    cin >> n >> r;
    do
    {
        a[i] = n % r;
        n = n / r;
        i++;
    } while (n != 0);
    for (--i; i >= 0; --i) //倒序输出
    {
        n = a[i];  //n为2～r-1之间的整数
        cout << b[n]; //转换成16进制以内的形式
    }
    system("pause");
    return 0;
}

