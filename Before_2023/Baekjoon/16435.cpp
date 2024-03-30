#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, L;
	cin >> N >> L;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		if (L >= arr[i])
			L++;
		else
			break;
	}
	cout << L;
}