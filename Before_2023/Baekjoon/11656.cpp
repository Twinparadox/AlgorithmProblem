#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int len;
	string s;
	vector<string> arr;
	cin >> s;
	len = s.length();

	for (int i = 0; i < len; i++)
		arr.push_back(s.substr(i, len));
	sort(arr.begin(), arr.end());
	for (int i = 0; i < len; i++)
		cout << arr[i] << '\n';
}
