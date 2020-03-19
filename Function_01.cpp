// 8 函数：代码重用与模块化
/*已知五边形的各边及对角线长，求五边形面积*/

#include <iostream>
using namespace std;
float area(float x, float y, float z)
{
	float c, s;
	c = (x + y + z) / 2;
	s = sqrt(c * (c - x) * (c - y) * (c - z));
	return s;
}

//求最大公约数
int gcd(int m, int n)
{
	while(int r=m%n)
	{
		m = n; 
		n = r;
	}
	return (n);
}

//求最小公倍数
int sct(int m, int n)
{
	return(m * n / gcd(m, n));
}


int main()
{
	float a,  b, c, d, e, f, g, s;
	cin >> a >> b >> c >> d >> e >> f >> g ;
	s = area(a, b, c)  + area(c, d, e)+area(e,f,g);
	cout << s << endl;

	/*求正整数m，n的最大公约数和最小公倍数*/
	int m, n;
	cin >> m >> n;
	if (n > m)
	{
		int t = m; m = n; n = t;
	}
	cout << gcd(m, n) << endl;
	cout << sct(m, n) << endl;

	system("pause");
	return 0;
}

