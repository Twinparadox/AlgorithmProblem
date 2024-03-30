#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int L;
		string ans, sub;
		cin >> L;
		cin >> ans >> sub;

		int wrong = 0;
		for (int j = 0; j < L; j++)
			if (ans[j] != sub[j])
				wrong++;

		cout << "Case " << i << ": " << wrong << '\n';
	}
}