#include <iostream>
using namespace std;
int main(void)
{
	int arr[100001], n;
	int cnt = 0, max1 = 1, max2 = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] <= arr[i + 1])
			cnt++;
		else
			cnt = 0;
		max1 = max1 < (cnt+1) ? (cnt+1) : max1;
	}
	cnt = 0;
	for(int i=0;i<n-1;i++)
	{
		if (arr[i] >= arr[i + 1])
			cnt++;
		else
			cnt = 0;
		max2 = max2 < (cnt+1) ? (cnt+1) : max2;
	}
	cout << (max1 < max2 ? max2 : max1);
}
