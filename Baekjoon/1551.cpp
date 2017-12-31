#include <iostream>
#include <string>
#include <vector>
using namespace std;
void tokenizer(string& str, vector<string>& token, string delimiter)
{
	size_t lastPos = str.find_first_not_of(delimiter, 0);
	size_t pos = str.find_first_of(delimiter, lastPos);
	while (string::npos != pos || string::npos != lastPos)
	{
		token.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiter, pos);
		pos = str.find_first_of(delimiter, lastPos);
	}
}
int main(void)
{
	vector<string> token;
	string s;
	int n, k, arr[20];
	cin >> n >> k;
	cin >> s;

	tokenizer(s, token, ",");
	for (int i = 0; i < n; i++)
		arr[i] = stoi(token[i]);
	for(int i=1;i<=k;i++)
		for(int j = 0; j < n-i; j++)
			arr[j] = arr[j + 1] - arr[j];
	for (int i = 0; i < n - k - 1; i++)
		cout << arr[i] << ',';
	cout << arr[n - k - 1];
}
