#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000;
vector<vector<int> > power(vector<vector<int> > mat, int N, long long B)
{
	if (B == 1)
	{
		vector<vector<int> > m = mat;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				m[i][j] = mat[i][j] % MOD;

		return m;
	}
	else if (B % 2 == 0)
	{
		vector<vector<int> > s(N, vector<int>(N, 0));
		vector<vector<int> > square(N, vector<int>(N, 0));

		s = power(mat, N, B / 2);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					square[i][j] = (square[i][j] + (s[i][k] * s[k][j]) % MOD) % MOD;

		return square;
	}
	else
	{
		vector<vector<int> > s(N, vector<int>(N, 0));
		vector<vector<int> > ret(N, vector<int>(N, 0));

		s = power(mat, N, B - 1);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					ret[i][j] = (ret[i][j] + (mat[i][k] * s[k][j]) % MOD) % MOD;

		return ret;
	}
}
int main(void)
{
	int N;
	long long B;
	vector<vector<int> > A;
	vector<vector<int> > ans;

	cin >> N >> B;

	A = vector<vector<int> >(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	ans = power(A, N, B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}