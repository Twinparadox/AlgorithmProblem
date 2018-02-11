#include <iostream>
#include <algorithm>
using namespace std;
struct nation
{
	int id, gold, silver, bronze, rank;
};
bool compare(struct nation a, struct nation b)
{
	if (a.gold > b.gold)
		return true;
	else if (a.gold == b.gold)
	{
		if (a.silver > b.silver)
			return true;
		else if (a.silver == b.silver)
		{
			return a.bronze > b.bronze ? true : false;
		}
		else
			return false;
	}
	else
		return false;
}
int main(void)
{
	int n, k, rank = 1, idx = 0;
	struct nation arr[1000];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i].id >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
	
	sort(arr, arr + n, compare);

	arr[0].rank = rank;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].gold == arr[idx].gold && arr[i].silver == arr[idx].silver && arr[i].bronze == arr[idx].bronze);
		else
			idx = i;
		while (arr[i].gold == arr[idx].gold && arr[i].silver == arr[idx].silver && arr[i].bronze == arr[idx].bronze)
		{
			arr[i].rank = rank;
			i++;
		}
		rank = i + 1;
		i--;
	}
	for(int i=0;i<n;i++)
		if (arr[i].id == k)
			cout << arr[i].rank;
}
