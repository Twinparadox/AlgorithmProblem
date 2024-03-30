#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, K;
	cin >> N >> K;
	vector<int> arr(K);
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		N -= (arr[i] + 1) / 2;
	}
	if (N <= 0)
		cout << "YES";
	else
		cout << "NO";
}