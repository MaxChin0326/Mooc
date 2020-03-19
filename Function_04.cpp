// 8.4 数组名做函数参数
//
#define N 10
#include <iostream>
#include <stdio.h>
using namespace std;
//对含有n个元素的整形数组a，从大到小进行排序
void sort(int a[], int n)  //数值型数组，数组中元素数n一般作为参数
{
    int i, j, k, w;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (a[k] < a[j])
                k = j;
        if (i != k)
        {
            w = a[i];
            a[i] = a[k];
            a[k] = w;
        }
    }
}

//求字符串长度，并调用之
int len(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

int main()
{
    int a[N],i;
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 101;
        cout << a[i] << ' ';
   }
    cout << '\n';

    sort(a, 10);
    for (i = 0; i < N; i++) 
    {
        cout << a[i] << ' ';
    }
    cout << '\n';

    char str[N];
    cin >> str;
    cout << str<<'\n';
    cout << len(str);

    system("pause");
    return 0;
}
