#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
stack<int> st;
vector<int> idxArr;
string str;
int calculate(int s, int e) {
	int ans = 0;
	for (int i = s; i < e; i++) {
		if (str[i] == '(') {
			int mul = str[i - 1] - '0';
			ans += mul * calculate(i + 1, idxArr[i]) - 1;
			i = idxArr[i];

			continue;
		}

		ans++;
	}

	return ans;
}
int main(void)
{
	int size;
	cin >> str;
	size = str.length();
	idxArr.resize(size, 0);

	for (int i = 0; i < size; i++) {
		if (str[i] == '(') {
			st.push(i);
		}
		else if (str[i] == ')') {
			idxArr[st.top()] = i;
			st.pop();
		}
	}

	cout << calculate(0, size);
}