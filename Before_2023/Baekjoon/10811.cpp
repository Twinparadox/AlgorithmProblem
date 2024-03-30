#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<int> arr(N + 1);
	for (int i = 1; i <= N; i++)
		arr[i] = i;

	vector<int>::iterator iter = arr.begin();
	int s, e;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		reverse((iter + s), (iter + e + 1));
	}
	for (int i = 1; i <= N; i++)
		cout << arr[i] << ' ';
}