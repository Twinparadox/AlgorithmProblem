#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> check(2001, 0);
int N, ans;
void emozi(int cur, int ans, int copy)
{
	if (check[cur] > ans || check[cur] == 0)
		check[cur] = ans;

	if (cur > 1 && (check[cur - 1] == 0 || check[cur - 1] > ans + 1))
		emozi(cur - 1, ans + 1, copy);

	if (cur * 2 < 2000 && copy > 0)
		emozi(cur + copy, ans + 1, copy);

	if (cur * 2 < 2000 && cur > 0)
		emozi(cur * 2, ans + 2, cur);
}
int main(void)
{
	cin >> N;
	check[1] = 0;
	emozi(2, 2, 1);
	cout << check[N];
}