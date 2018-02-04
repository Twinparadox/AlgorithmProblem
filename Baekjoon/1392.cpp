#include <iostream>
using namespace std;
int main(void)
{
	int n, q;
	int arr[101] = { 0, }, query[1000];
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = 0; i < q; i++)
		cin >> query[i];
	for (int i = 0; i < q; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (query[i] < arr[j] && query[i]>=arr[j-1])
			{
				cout << j << '\n';
				break;
			}
		}
	}
}
