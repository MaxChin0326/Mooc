// 5.4 常用算法-冒泡法排序
/*对含N个整数的数组a用冒泡法由小到大排序*/
/*1、从a[0]开始，对两两相邻的元素进行N-1次比较，若前面的元素
大于后面的元素，则交换这对元素。一次遍历后最大的数存放在a[N-1]中；
  2、对a[0]到a[N-2]的N-1个数进行同1、的操作，次大数放入a[N-2]元素
 内，完成第二趟排序；
  3、依次类推，进行N-1趟排序后，所有数均有序。*/

#define N 10
#include <iostream>
using namespace std;
int main()
{
    int a[N],i,t,j;
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 101;
        cout << a[i] << ' ';
    }
    for (i= 0; i< N - 1; i++) // 注意循环控制变量和相邻元素下标的表达
        for (j = 0; j < N-1-i; j++) //若相邻元素用a[j]和a[j+1]标识，循环变量初终值如何表示？
            if (a[j] > a[j + 1]) //初始i=0,j=0；j++循环，直至大小不同，将数挪动。
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j+1]=t;
            }
    cout << "\nAfter Sort:\n";
    for (i = 0; i < N; i++)
        cout << a[i] << ' ';
    system("pause");
    return 0;
}

