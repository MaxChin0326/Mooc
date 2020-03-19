// 5.5 常用算法-插入与删除
/*在递增排序的数组a中插入数x，使得插入后数组仍保持有序*/
/*1、查找待插入数据在数组中应插入的位置k；
  2、从最后一个元素开始向前知道下标为k的元素依次往后移动
  一个位置；
  3、将欲插入的数据x插入第k个元素的位置*/
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
    cout << "输入待插入的数据：";
    cin >> x;
    for (i = 0; i < n; i++)
        if (x < a[i])
            break;
    k = i;
    for (i = n - 1; i >= k; i--)
        a[i + 1] = a[i];
    a[k] = x;
    for (i = 0; i < n + 1; i++)
        cout << a[i] << ' ';
    system("pause");
    return 0;
}
