#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	vector<int> science(4);
	vector<int> social(2);
	int sum = 0;
	for (int i = 0; i < 4; i++)
		cin >> science[i];
	for (int i = 0; i < 2; i++)
		cin >> social[i];
	sort(science.begin(), science.end());
	sort(social.begin(), social.end());
	sum += social[1];
	for (int i = 3; i > 0; i--)
		sum += science[i];
	cout << sum;
}
