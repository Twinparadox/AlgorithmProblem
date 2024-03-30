#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct vote
{
	int one;
	int two;
	int three;
	int sum;
	int idx;
};
bool compare(const struct vote& a, const struct vote& b)
{
	if (a.sum > b.sum)
		return true;
	else
	{
		if (a.three > b.three)
			return true;
		else if (a.three == b.three)
		{
			if (a.two > b.two)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}
int main(void)
{
	int n, tmp;
	cin >> n;
	vector<struct vote> arr(n, { 0,0,0,0,0 });
	for (int i = 0; i < 4; i++)
		arr[i].idx = i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> tmp;
			if (tmp == 1)
				arr[j].one++;
			else if (tmp == 2)
				arr[j].two++;
			else
				arr[j].three++;
			arr[j].sum += tmp;
		}
	}
	sort(arr.begin(), arr.end(), compare);

	if (arr[0].sum == arr[1].sum)
	{
		if (arr[0].three == arr[1].three)
		{
			if (arr[0].two == arr[1].two)
				cout << "0" << " " << arr[0].sum;
			else if (arr[0].two > arr[1].two)
				cout << arr[0].idx << " " << arr[0].sum;
			else
				cout << arr[1].idx << " " << arr[1].sum;
		}
		else if (arr[0].three > arr[1].three)
		{
			cout << arr[0].idx << " " << arr[0].sum;
		}
		else
		{
			cout << arr[1].idx << " " << arr[1].sum;
		}
	}
	else
		cout << arr[0].idx << " " << arr[0].sum;
}