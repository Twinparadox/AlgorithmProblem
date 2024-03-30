/*
이것이 코테다
정렬 - 기본문제
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	vector<pair<int, string> > arr;
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].second >> arr[i].first;

	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
		cout << arr[i].second << ' ';
}