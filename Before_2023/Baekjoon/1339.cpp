#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	vector<int> arr(26, 0);
	string str;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		int len = str.length();
		for (int j = 0; j < len; j++)
			arr[str[j] - 'A'] += (int)pow(10, len - j - 1);
	}

	int ans = 0, cnt = 9;
	vector<int> exist;
	for (int i = 0; i < 26; i++)
		if (arr[i])
			exist.push_back(arr[i]);

	sort(exist.begin(), exist.end(), greater<int>());
	int size = exist.size();
	for (int i = 0; i < size; i++)
	{
		ans += exist[i] * cnt;
		cnt--;
	}
	cout << ans;
}