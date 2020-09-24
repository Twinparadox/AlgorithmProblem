/*
이것이 코테다
정렬 - 기본문제
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	vector<int> arr;
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	for (int i = N - 1; i >= 0; i--)
		cout << arr[i] << ' ';
}