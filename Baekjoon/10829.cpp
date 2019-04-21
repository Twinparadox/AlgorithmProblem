#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	long long N;
	vector<int> bin;
	cin >> N;
	while (N > 0)
	{
		bin.push_back(N % 2);
		N /= 2;
	}

	int size = bin.size();
	for (int i = size - 1; i >= 0; i--)
		cout << bin[i];
}