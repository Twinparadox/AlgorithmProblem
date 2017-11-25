#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct party
{
	string name;
	int max;
};
bool compare(const struct party a, const struct party b)
{
	if (a.max > b.max)
		return true;
	else
		return false;
}
int main(void)
{
	int n;
	struct party arr[9] = { { "PROBRAIN" } ,{"GROW"},{"ARGOS"},{"ADMIN"},{"ANT"},{"MOTION"},{"SPG"},{"COMON"},{"ALMIGHTY"} };
	cin >> n;
	for (int i = 0; i < 9; i++)
	{
		arr[i].max = -1;
		for (int k, j = 0; j < n; j++)
		{
			cin >> k;
			arr[i].max = arr[i].max < k ? k : arr[i].max;
		}
	}
	sort(arr, arr + 9, compare);
	cout << arr[0].name;
}
