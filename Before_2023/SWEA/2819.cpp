#include <iostream>
#include <set>
using namespace std;
const int boardSize = 4;
const int numSize = 7;
const int dirSize = 4;
int dir[dirSize][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int arr[boardSize][boardSize];
set<int> st;
bool validateCoord(int x, int y)
{
	return (x >= 0 && x < boardSize) && (y >= 0 && y < boardSize);
}
void dfs(int x, int y, int val, int cnt)
{
	if (cnt == numSize)
	{
		st.insert(val);
		return;
	}

	for (int i = 0; i < dirSize; i++)
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (validateCoord(nx, ny))
		{
			dfs(nx, ny, val * 10 + arr[nx][ny], cnt + 1);
		}
	}

}
int main(void)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				cin >> arr[i][j];
		st.clear();

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				dfs(i, j, arr[i][j], 1);

		cout << "#" << i << " " << st.size() << '\n';
	}
}