/*
이것이 코테다
이진 탐색 - 부품 찾기
기본 이진 탐색 문제
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> a, b;
bool binary_search(int start, int end, int target)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (a[mid] == target)
			return true;
		else if (a[mid] > target)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return false;
}
int main(void)
{
	int N, M;

	cin >> N;
	a.resize(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	cin >> M;
	b.resize(M);
	for (int i = 0; i < M; i++)
		cin >> b[i];

	sort(a.begin(), a.end());

	for (int i = 0; i < M; i++)
	{
		if (binary_search(0, N - 1, b[i]))
			cout << "yes ";
		else
			cout << "no ";
	}
}
