// at least 1700ms 
/*
#include <iostream>
#include <set>
using namespace std;
int main(void)
{
	int n, c;
	set<int> fire;
	set<int> time;
	cin >> n >> c;
	for (int tmp, i = 0; i < n; i++)
	{
		cin >> tmp;
		fire.insert(tmp);
	}

	for (set<int>::iterator it = fire.begin(); it != fire.end(); it++)
	{
		for (int i = *it; i <= c; i += *it)
		{
			time.insert(i);
		}
	}
	cout << time.size();
}
*/

// at least 20ms
#include <iostream>
using namespace std;
int arr[2000001];
int main(void)
{
	int n, c, ans = 0;
	cin >> n >> c;
	for (int tmp, i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = tmp; j <= c; j += tmp)
			if (!arr[j])
				arr[j]++, ans++;
	}
	cout << ans;
}
