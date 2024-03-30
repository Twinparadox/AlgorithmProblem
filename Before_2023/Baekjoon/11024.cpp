#include <iostream>
#include <string>
#include <vector>
using namespace std;
void tokenizer(string& s, vector<int>& token, string delimiter)
{
	size_t endPos = s.find_first_not_of(delimiter, 0);
	size_t startPos = s.find_first_of(delimiter, endPos);
	while (string::npos != startPos || string::npos != endPos)
	{
		token.push_back(stoi(s.substr(endPos, startPos - endPos)));
		endPos = s.find_first_not_of(delimiter, startPos);
		startPos = s.find_first_of(delimiter, endPos);
	}
}
int main(void)
{
	int t, sum, len, size;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s, delimiter = " ";
		vector<int> arr;
		getline(cin, s);

		tokenizer(s, arr, delimiter);
		size = arr.size();
		sum = 0;

		for (int i = 0; i < size; i++)
			sum += arr[i];
		cout << sum << '\n';
	}
}