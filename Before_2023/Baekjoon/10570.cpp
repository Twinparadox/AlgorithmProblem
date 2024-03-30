#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct num
{
	int su, cnt = 0;
};
bool compare(struct num a, struct num b)
{
	if (a.cnt > b.cnt)
		return true;
	else if (a.cnt == b.cnt)
	{
		if (a.su < b.su)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main(void)
{
	int n;
	cin >> n;
	while (n--)
	{
		int v;
		vector<struct num> arr;
		cin >> v;
		for (int i = 0, s; i < v; i++)
		{
			bool check = false;
			cin >> s;
			for (int j = 0; j < arr.size(); j++)
			{
				if (arr[j].su == s)
				{
					arr[j].cnt++, check = true;
					break;
				}
			}
			if (!check)
				arr.push_back({ s,1 });
		}
		sort(arr.begin(), arr.end(), compare);
		cout << arr[0].su << endl;
	}
}
