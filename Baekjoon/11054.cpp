#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	cin >> N;

	vector<int> arr(N + 1);
	vector<int> dpUp(N + 1, 1);
	vector<int> dpDown(N + 1, 1);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i])
				dpUp[i] = dpUp[i] < (dpUp[j] + 1) ? (dpUp[j] + 1) : dpUp[i];

	for (int i = N; i >= 1; i--)
		for (int j = N; j > i; j--)
			if (arr[j] < arr[i])
				dpDown[i] = dpDown[i] < (dpDown[j] + 1) ? (dpDown[j] + 1) : dpDown[i];

	int max = dpUp[1] + dpDown[1] - 1;
	for (int i = 2; i <= N; i++)
		if (max < (dpUp[i] + dpDown[i] - 1))
			max = dpUp[i] + dpDown[i] - 1;
	cout << max;
}