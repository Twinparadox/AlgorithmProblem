#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct student
{
	string name;
	int kor, eng, mat;
};
bool compare(const struct student a, const struct student b)
{
	if (a.kor > b.kor)
		return true;
	else if (a.kor == b.kor)
	{
		if (a.eng < b.eng)
			return true;
		else if (a.eng == b.eng)
		{
			if (a.mat > b.mat)
				return true;
			else if (a.mat == b.mat)
				return a.name.compare(b.name) < 0;
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
	vector<struct student> list;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string n;
		int k, e, m;
		cin >> n >> k >> e >> m;
		list.push_back({ n,k,e,m });
	}
	sort(list.begin(), list.end(), compare);
	for (int i = 0; i < n; i++)
		cout << list[i].name << '\n';
}
