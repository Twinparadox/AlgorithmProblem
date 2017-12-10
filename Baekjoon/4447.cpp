#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct status
{
	string name;
	int mind;
};
int main(void)
{
	int n;
	vector<struct status> arr;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		int len, b = 0, g = 0;
		getline(cin, s);
		len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (s[i] == 'b' || s[i]=='B')
				b++;
			else if (s[i] == 'g' || s[i]=='G')
				g++;
		}
		arr.push_back({ s,g - b });
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].name << " is ";
		if (arr[i].mind > 0)
			cout << "GOOD\n";
		else if (arr[i].mind == 0)
			cout << "NEUTRAL\n";
		else
			cout << "A BADDY\n";
	}
}
