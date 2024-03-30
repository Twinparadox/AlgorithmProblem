#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	cin.ignore();
	string s;
	int cnt = 0;
	while (getline(cin, s))
		cnt++;
	cout << cnt;
}
