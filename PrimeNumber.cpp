//输出2～100之间的所有素数，每行输出5个素数。
/*for(k=2;k<m;k++)
    if(m%k==0)
	break;
if(k==m)
    cout<<m<<"是素数"<<endl;*/
#include<iostream>
using namespace std;
int main()
{
	int m, i, countm(0);
	for (m = 2; m <= 100; m++)
	{
		for (i = 2; i < m; i++)
			if (m % i == 0)
				break;
		if (i == m)
		{
			cout << m << '\t';
			countm++;
			if (countm % 5 == 0)
				cout << endl;
		}
	}
	system("pause");
	return 0;
}