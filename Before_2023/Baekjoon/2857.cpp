#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int n = 5;
	vector<int> arr;
	
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		if (str.find("FBI", 0) != string::npos)
			arr.push_back(i);
	}

	if (arr.empty())
		cout << "HE GOT AWAY!";
	else
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << ' ';
}
