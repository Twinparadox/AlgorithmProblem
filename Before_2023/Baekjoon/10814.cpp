#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct inform
{
	int idx, age;
	string name;
};
bool compare(const struct inform a, const struct inform b)
{
	if (a.age < b.age)
		return true;
	else if (a.age == b.age)
	{
		if (a.idx < b.idx)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main(void)
{
	struct inform* list;
	int n;
	cin >> n;
	list = new struct inform[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list[i].age >> list[i].name;
		list[i].idx = i;
	}
	sort(list, list + n, compare);
	for (int i = 0; i < n; i++)
		cout << list[i].age << ' ' << list[i].name << '\n';
}
