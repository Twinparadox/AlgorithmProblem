/* [G4] 생태학
G4로 분류되긴 하나, 트라이로 접근할 때 그 난이도고,
STL map 같은 기본 map구조로 나무를 key로 삼고 나무의 수를 value로 하면,
쉽게 문제를 풀 수 있음
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	double cnt = 0;
	map<string, int> tree;
	string str;
	while (getline(cin, str))
	{
		if (tree[str] == 0)
			tree[str] = 1;
		else
			tree[str]++;
		cnt += 1;
	}
	cout.precision(4);
	for (auto it = tree.begin(); it != tree.end(); it++)
		cout << fixed << it->first << ' ' << (double)it->second / cnt * 100 << '\n';
}