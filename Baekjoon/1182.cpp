#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, S, cnt = 0;
vector<int >arr;
void findSub(int idx, int sum)
{
	if (idx == N)
		return;
	sum += arr[idx];
	if (sum == S)
		cnt++;

	findSub(idx + 1, sum - arr[idx]);
	findSub(idx + 1, sum);
}
int main(void)
{
	cin >> N >> S;

	arr = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	findSub(0, 0);

	cout << cnt;
}