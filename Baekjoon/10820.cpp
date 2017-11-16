#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int size, small, capital, num, blank;
	string s;
	while(getline(cin,s))
	{
		size = s.size();
		small = capital = num = blank = 0;
		for (int i = 0; i < size; i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				capital++;
			else if (s[i] >= 'a' && s[i] <= 'z')
				small++;
			else if (s[i] == ' ')
				blank++;
			else if (s[i] >= '0' && s[i] <= '9')
				num++;
		}
		cout << small << " " << capital << " " << num << " " << blank << "\n";
	}
}
