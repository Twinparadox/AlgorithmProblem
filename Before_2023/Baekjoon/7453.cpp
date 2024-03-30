#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	long long ans = 0;
	vector<int> A(N), B(N), C(N), D(N);
	vector<int> CD;


	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			CD.push_back(C[i] + D[j]);
	sort(CD.begin(), CD.end());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int AB = A[i] + B[j];
			int high = upper_bound(CD.begin(), CD.end(), -AB) - CD.begin();
			int low = lower_bound(CD.begin(), CD.end(), -AB) - CD.begin();

			if (AB == -CD[low])
				ans += (high - low);
		}
	}
	cout << ans;
}