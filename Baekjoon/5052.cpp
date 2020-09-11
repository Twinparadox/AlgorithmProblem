/* [G4] 5052 - ��ȭ��ȣ ��� */
/*
Trie�� �̿��϶�� �Ǿ� �־�����,
substring�� map�� ���� �־ üũ�ϴ� ������� �ذ��� �� ����
map���� unordered_map�� Ž�� �ð��� ����
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