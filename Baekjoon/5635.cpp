#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct birth
{
	string name;
	int d, m, y;
};
bool compare(struct birth a, struct birth b)
{
	if (a.y > b.y)
		return true;
	else if (a.y == b.y)
	{
		if (a.m > b.m)
			return true;
		else if (a.m == b.m)
		{
			if (a.d > b.d)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
int main(void)
{
	int n;
	struct birth list[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> list[i].name >> list[i].d >> list[i].m >> list[i].y;
	sort(list, list + n, compare);
	cout << list[0].name << '\n' << list[n - 1].name;
}
