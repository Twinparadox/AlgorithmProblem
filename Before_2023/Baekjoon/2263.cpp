/* [G3] 2263 - Ʈ���� ��ȸ */
/*
inorder, postorder�� �Է¹޾� �� Ʈ���� preorder�� ���ϴ� ����
root�� �׻� preorder�� ù �׸�, postorder�� ������ �׸��̶�� ����
inorder���� root ������ ���� left_sub, ���Ĵ� right_sub�� ���� �̿�
Ʈ���� �������� �ʰ� ��� ����
inorder�� �������� �ۼ��߰�, inOrder�� index Ž���ð��� O(1)�� ����� ���� inPos �迭 ���
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int postIndex = 0;
vector<int> in, post, inPos;
int search(int data, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		if (in[i] == data)
			return i;
	return i;
}
void fillPre(int inStart, int inEnd, stack<int> &s, int n)
{
	if (inStart > inEnd)
		return;

	int val = post[postIndex];
	int inIndex = inPos[val];
	postIndex--;

	fillPre(inIndex + 1, inEnd, s, n);
	fillPre(inStart, inIndex - 1, s, n);
	s.push(val);
}
int main()
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	in.resize(n);
	post.resize(n);
	inPos.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
		inPos[in[i]] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> post[i];

	postIndex = n - 1;
	stack<int> s;
	fillPre(0, n - 1, s, n);
	while (s.size() > 0)
	{
		cout << s.top() << ' ';
		s.pop();
	}
}