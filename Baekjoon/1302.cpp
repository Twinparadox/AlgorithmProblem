#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct book
{
	string name;
	int sold;
};
bool compare(const struct book a, const struct book b)
{
	if (a.sold > b.sold)
		return true;
	else if (a.sold == b.sold)
	{
		if (a.name < b.name)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main(void)
{
	bool check = false;
	int n, size = 0;
	vector<struct book> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		check = false;
		for (int j = 0; j < size; j++)
			if (arr[j].name == tmp)
				arr[j].sold++, check = true;
		if (!check)
			arr.push_back({ tmp,0 }), size++;
	}
	sort(arr.begin(), arr.end(), compare);
	cout << arr[0].name;
}
