#include <iostream>
using namespace std;
int main(void)
{
	int c, n, k, live, i, cnt;
	bool* isDie;

	cin >> n >> k;
	live = n;
	cnt = k - 1;

	isDie = new bool[n + 1];
	for (int i = 1; i <= n; i++)
		isDie[i] = false;
	cout<<"<";
	i=k;
	while (live > 0)
	{
		if (i > n)
			i %= n;
		if (isDie[i] == true)
		{
			i++;
			continue;
		}
		else
		{
			cnt++;
			if (cnt == k)
			{
				isDie[i] = true;
				cout<<i;
				live--;
				cnt = 0;
				if(live!=0)
					cout<<", ";
			}			
			i++;
		}
	}
	cout<<">";
	delete[] isDie;
}
