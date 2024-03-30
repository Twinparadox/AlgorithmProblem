#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
int N, K, ans = -1;
vector<bool> check(100001, false);
bool isValid(int x)
{
	return x >= 0 && x <= 1e5;
}
void bfs()
{
	queue<pair<int, int> > q;
	q.push(make_pair(N, 0));
	check[N] = true;

	while (!q.empty())
	{
		int curX = q.front().first, curC = q.front().second;
		q.pop();

		check[curX] = true;

		if (ans == -1 && curX == K)
			ans = curC;
		else if (ans > curC && curX == K)
			ans = curC;

		int next = curX + 1;
		if (isValid(next) && !check[next])
			q.push(make_pair(next, curC + 1));
		next = curX - 1;
		if (isValid(next) && !check[next])
			q.push(make_pair(next, curC + 1));
		next = curX * 2;
		if (isValid(next) && !check[next])
			q.push(make_pair(next, curC));
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	bfs();
	cout << ans;
}