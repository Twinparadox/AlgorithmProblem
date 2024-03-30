/*
[P5] - 1305 ����
KMP�� failure function�� Ȱ��
http://blog.securekim.com/2018/12/kmp-failure-function.html

failure function���� ���ϴ� ����
���ڿ��� 1 ~ len���� �׸��� ����� ���, ���λ�� ���̻簡 ���� �ִ� ����
������ ���̿��� �� �ִ� ���̸� ���� ���� ������ �� �ִ� ���̿��� 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
vector<int> pi;
int len;
void failure()
{
	pi.resize(len);
	int idx = 0;
	for (int i = 1; i < len; i++)
	{
		while (idx > 0 && str[i] != str[idx])
			idx = pi[idx - 1];
		if (str[i] == str[idx])
			pi[i] = ++idx;
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int ans;

	cin >> len >> str;
	failure();

	ans = len - pi[len - 1];
	cout << ans;
}