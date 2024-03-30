#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N, M, ans;
vector<vector<bool> > mat;
vector<vector<bool> > dest;
void changeMatrix(int x, int y)
{
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 3; j++)
			mat[i][j] = !mat[i][j];
}
bool checkMatrix(int i)
{
	for (int j = 0; j < M; j++)
		if (mat[i][j] != dest[i][j])
			return false;
	return true;
}
bool isFinish()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (mat[i][j] != dest[i][j])
				return false;
	return true;
}
int main(void)
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> N >> M;
	mat = vector<vector<bool> >(N, vector<bool>(M));
	dest = vector<vector<bool> >(N, vector<bool>(M));
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			if (str[j] == '1')
				mat[i][j] = true;
			else
				mat[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			if (str[j] == '1')
				dest[i][j] = true;
			else
				dest[i][j] = false;
		}
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (mat[i][j] != dest[i][j])
			{
				ans++;
				changeMatrix(i, j);
				if (isFinish())
				{
					cout << ans;
					return 0;
				}
			}
		}
		if (!checkMatrix(i))
		{
			cout << "-1";
			return 0;
		}
	}
	if (isFinish())
		cout << ans;
	else
		cout << "-1";
	return 0;
}