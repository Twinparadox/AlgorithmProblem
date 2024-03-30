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
		carry = ans[i] / 10;
		ans[i] %= 10;
	}

	return ans;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string sa, sb;
	int alen, blen;

	cin >> sa >> sb;
	alen = sa.length();
	blen = sb.length();
	vector<int> a, b, ans;

	for (int i = alen - 1; i >= 0; i--)
		a.push_back(sa[i] - '0');
	for (int i = blen - 1; i >= 0; i--)
		b.push_back(sb[i] - '0');

	ans = a * b;
	int size = ans.size();
	bool check = true;
	for (int i = size - 1; i >= 0; i--)
	{
		if (check && ans[i] == 0)
			continue;
		check = false;
		cout << ans[i];
	}
	if (check)
		cout << 0;
}