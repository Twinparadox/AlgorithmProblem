#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, M, sum = 0;

	cin >> N >> M;
	vector<int> arr(M);
	vector<int> su(N + 1, 0);
	for (int i = 0; i < M; i++)
		cin >> arr[i];

	for (int i = 0; i < M; i++)
		for (int j = 1; j*arr[i] <= N; j++)
			su[j*arr[i]]++;

	for (int i = 1; i <= N; i++)
		if (su[i])
			sum += i;

	cout << sum;
}