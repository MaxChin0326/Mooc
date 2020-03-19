//6.1 矩阵转置
//输入、输出、批量处理时需使用双重循环，外循环控制行的变化，内循环控制列的变化
//2020-03-05
#include <iostream>
using namespace std;
int main()
{
	int a[3][3] = { {1,2,3},{4,5,6},{9,8,7} };
	int max, imax, jmax, i, j;
	/*求一个3×3方阵的最大元素及下标*/
	max = a[0][0];
	imax = jmax = 0; //记录最大元素行列下标
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			if (a[i][j] > max)
			{						//与后面逐元素比较、替换最大值，并记录其行列下标
				max = a[i][j];
				imax = i;
				jmax = j;
			}
	cout <<"max="<< max << '\n';
	cout <<"imax="<< imax << '\n';
	cout << "jmax=" << jmax << '\n';
	cout<<"i="<< i << '\t'<<"j=" << j << '\n';
	cout << '\n';
	/*图形输出*/
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j <3; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	cout << '\n';

	/*将一个3×3的方阵进行转置--
	1、把矩阵A的第i行转换成第j行；
	2、对方针而言，求转置矩阵即是将矩阵以主对角线为轴线，对调轴线两侧对应位置的元素；
	3、一次对调a[i][j]和a[j][i]两个元素，所以只能以下三角元素做参照,去和上三角的元素对调*/
	int s;
	for(i=0;i<3;i++)
		for (j = 0; j < i; j++)
		{
			s = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = s;
		}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j <3; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	cout << '\n';

	/*n<10，输出杨辉三角型*/
	/*特点：
	1、第一列和主对角线元素均为1。
	2、其余各项：a[i][j]=a[i-1][j-1]+a[i-1][j];
	*/
	int n=6, b[6][6] = {};
	for (i = 0; i < n; i++)
		b[i][0] = b[i][i] = 1;  //第一列和主对角线元素赋值；
	for (i = 2; i < n; i++)
		for (j = 1; j < i; j++)
			b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <=i; j++)
			cout << b[i][j] << ' ';
		cout << endl;
	}
	system("pause");
	return 0;
}