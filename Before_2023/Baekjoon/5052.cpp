/* [G4] 5052 - 전화번호 목록 */
/*
Trie를 이용하라고 되어 있었지만,
substring을 map에 집어 넣어서 체크하는 방식으로 해결할 수 있음
map보다 unordered_map이 탐색 시간이 적음
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int T, N;
	cin >> T;
	while (T--)
	{
		bool flag = true;
		vector<string> arr;
		unordered_map<string, bool> ms;
		cin >> N;

		arr.resize(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		sort(arr.begin(), arr.end());

		ms[arr[0]] = true;

		for (int i = 1; i < N; i++)
		{
			int len = arr[i].length();
			for (int j = 1; j <= len; j++)
			{
				if (ms[arr[i].substr(0, j)])
				{
					flag = false;
					break;
				}
			}
			ms[arr[i]] = true;
		}

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}