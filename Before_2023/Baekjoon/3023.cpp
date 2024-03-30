#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
	int r, c, a, b;
	string parts[50];
	string card[100];
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> parts[i];
	cin >> a >> b;

	for (int i = 0; i < r; i++)
	{
		string tmp = parts[i];
		reverse(tmp.begin(), tmp.end());
		card[i] = parts[i] + tmp;
	}
	for (int i = 0; i < r; i++)
		card[r * 2 - 1 - i] = card[i];
	if (card[a - 1][b - 1] == '#')
		card[a - 1][b - 1] = '.';
	else
		card[a - 1][b - 1] = '#';

	for (int i = 0; i < r * 2; i++)
		cout << card[i] << '\n';
}
