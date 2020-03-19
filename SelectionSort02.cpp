//5.3 常用算法-选择法排序
/*将成绩完全排序*/
#define N 20
#include <iostream>
using namespace std;
int main()
{
    int a[N], i, max, imax, j;
    int s, jmax;
    /*随机分数*/
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 101; //rand()随机数范围0～32767，原型所在头文件stdlib.h，rand()%(a+1)产生0～a之间的随机数
        cout << a[i] << '\t';
    }
    cout << "after sort:" << '\n';
   
    for (i = 0; i < N - 1; i++)
    {
        jmax = i;
        for (j = i + 1; j < N; j++)
            if (a[j] > a[jmax])
                jmax = j;
        s = a[jmax];
        a[jmax] = a[i];
        a[i] = s;
        cout << a[i] << '\t';
    }
    system("pause");
    return 0;
}


