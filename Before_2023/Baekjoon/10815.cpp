#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	set<int> s;
	cin >> N;

	int su;
	for (int i = 0; i < N; i++)
	{
		cin >> su;
		s.insert(su);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> su;
		set<int>::iterator it = s.find(su);
		if (it == s.end())
			cout << "0 ";
		else
			cout << "1 ";

	}
}