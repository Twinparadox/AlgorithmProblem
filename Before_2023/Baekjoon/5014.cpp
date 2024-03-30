#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int F, S, G, U, D;
vector<int> cnt;
bool isValid(int stair)
{
	return stair >= 1 && stair <= F;
}
void bfs()
{
	queue<pair<int, int> > q;
	q.push(make_pair(S, 0));
	while (!q.empty())
	{
		int cur = q.front().first;
		int c = q.front().second;
		q.pop();

		if (cur == G)
		{
			if (cnt[cur] == -1)
				cnt[cur] = c;
			else
				cnt[cur] = cnt[cur] < c ? cnt[cur] : c;
		}

		int up = cur + U, down = cur - D;
		if (isValid(up))
		{
			if (cnt[up] == -1)
			{
				cnt[up] = c + 1;
				q.push(make_pair(up, c + 1));
			}
		}
		if (isValid(down))
		{
			if (cnt[down] == -1)
			{
				cnt[down] = c + 1;
				q.push(make_pair(down, c + 1));
			}
		}
	}
}
int main(void)
{
	cin >> F >> S >> G >> U >> D;

	cnt.resize(F + 1, -1);

	cnt[S] = 0;

	bfs();

	if (cnt[G] == -1)
		cout << "use the stairs";
	else
		cout << cnt[G];
}