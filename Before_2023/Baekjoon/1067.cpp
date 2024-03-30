#include <algorithm>
#include <complex>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
const double PI = acos(-1);
typedef complex<double> Complex;

void DFT(vector<Complex>& p, Complex w)
{
	int n = p.size();
	if (n == 1)
		return;

	vector<Complex> even(n / 2), odd(n / 2);
	for (int i = 0; i < n / 2; i++)
	{
		even[i] = p[i * 2];
		odd[i] = p[i * 2 + 1];
	}

	DFT(even, w*w);
	DFT(odd, w*w);

	Complex w_power = 1;
	for (int i = 0; i < n / 2; i++)
	{
		Complex offset = w_power * odd[i];
		p[i] = even[i] + offset;
		p[i + n / 2] = even[i] - offset;
		w_power *= w;
	}
}
int roundUP(int n)
{
	int p2 = 1;
	while (p2 < n)
		p2 *= 2;
	return p2;
}
vector<int> operator * (const vector<int>& a, const vector<int>& b)
{
	int N = roundUP(max(a.size(), b.size())) * 2;

	vector<Complex> aComp(a.begin(), a.end());
	vector<Complex> bComp(b.begin(), b.end());
	aComp.resize(N);
	bComp.resize(N);

	Complex w = polar(1.0, 2 * PI / N);
	DFT(aComp, w);
	DFT(bComp, w);

	for (int i = 0; i < N; i++)
		aComp[i] *= bComp[i];

	DFT(aComp, polar(1.0, -2 * PI / N));
	for (int i = 0; i < N; i++)
		aComp[i] /= double(N);

	vector<int> ans(aComp.size() + 10);
	int aCompSize = aComp.size(), ansSize = ans.size();
	int carry = 0;
	for (int i = 0; i < ansSize; i++)
	{
		ans[i] = carry;
		if (i < aCompSize)
			ans[i] += int(round(aComp[i].real()));
	}

	return ans;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;
	vector<int> a(N * 2), b(N), ans;

	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = N - 1; i >= 0; i--)
		cin >> b[i];
	for (int i = 0; i < N; i++)
		a[i + N] = a[i];

	ans = a * b;
	int size = ans.size();
	int res = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (res < ans[i])
			res = ans[i];
	}
	cout << res;
}