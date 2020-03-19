// 5.6 常用算法-二分法查找
//（折半查找）只适用于有序数组
/*在长度为N按递增顺序排列的数组a中用二分法查找数key*/
/*基本思想：
  1、假设low和high是查找区间的起终点下标，则初始状态下low=0，high=N-1；
  2、求待查区间中间元素的下表mid=（low+high）/2，然后通过a[mid]和x比较
  的结果决定后续查找范围；
  3、若x==a[mid]，则查找完毕，结束查找过程；
     若x>a[mid]，则只需再查找a[mid]后面的元素，修改区间下届low=mid+1；
     若x<a[mid]，则只需再查找a[mid]前面的元素，修改区间上界high=mid-1;
  4、重复2、3两步知道找到x；或再无查找区域（low>high)。*/
#define N 10
#include <iostream>
using namespace std;
int main()
{
    int a[N], i,j,t, mid;
    /*随机分数*/
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 101; //rand()随机数范围0～32767，原型所在头文件stdlib.h，rand()%(a+1)产生0～a之间的随机数
        cout << a[i] << ' ';
    }
    cout << '\n';
    for (i = 0; i < N-1; i++) // 注意循环控制变量和相邻元素下标的表达
        for (j = 0; j < N - 1 - i; j++) //若相邻元素用a[j]和a[j+1]标识，循环变量初终值如何表示？
            if (a[j] > a[j + 1]) //初始i=0,j=0；j++循环，直至大小不同，将数挪动。
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    for (i = 0; i < N; i++)
        cout << a[i] << ' ';
    int low = 0,x;
    int high = N - 1;
    cout <<'\n'<< "请输入x：";
    cin >> x;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == a[mid])  //找到退出查找
            break;
        else if (x > a[mid])  //继续查找后半区间
            low = mid + 1;
        else
            high = mid - 1;  //继续查找前半区间
    }
    if (low > high)
        cout << "未找到" << endl;
    else
        cout << mid+1 << endl;
    system("pause");
    return 0;
}
