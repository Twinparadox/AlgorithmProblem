#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int G, P, ans = 0, cur;
	vector<int> gates, planes;

	cin >> G >> P;
	gates.resize(G + 1, 0);
	planes.resize(P);

	bool flag = true;
	for (int i = 0; i < P; i++)
	{
		cin >> planes[i];

		cur = planes[i];
		while (cur > 0 && gates[cur] > 0)
		{
			int tmp = gates[cur];
			gates[cur] = gates[cur] + 1;
			cur -= tmp;
		}

		if (cur <= 0)
			flag = false;
		else if (flag)
		{
			gates[cur] = 1;
			ans++;
		}
	}
	cout << ans;
}