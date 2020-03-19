// 5.5 常用算法-插入与删除
/*查找数据x是否是数组a中的元素，若是，删除第一次出现的该元素；否则提示“未找到*/
    /*1、查找待删除元素的位置k；
      2、若找到要删除的数据，则从第K+1个元素开始到最后一个元素依次前移一位；*/
#define N 10
#include <iostream>
using namespace std;
int main()
{
    int i, k, n, a[N], x;
    cout << "递增输入数组中现有元素个数：";
    cin >> n;
    cout << "请输入数组：";
    for (i = 0; i < n; i++)
        cin >> a[i]; //输入数组；
    cout << "输入待删除的数据：";
    cin >> x;
    for (i = 0; i < n; i++)
        if (x ==a[i])
            break;
    k = i;
    if (i == n)
        cout << "未找到删除数据\n";
    else
    {
        for (i = k; i <n-1; i++)
            a[i] = a[i+1];
        for (i = 0; i < n -1; i++)
            cout << a[i] << ' ';
    }
    system("pause");
    return 0;
}
