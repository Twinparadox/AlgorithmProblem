/* [G3] 2263 - 트리의 순회 */
/*
inorder, postorder를 입력받아 그 트리의 preorder를 구하는 문제
root는 항상 preorder의 첫 항목, postorder는 마지막 항목이라는 점과
inorder에서 root 이전의 값은 left_sub, 이후는 right_sub인 점을 이용
트리를 재현하지 않고도 출력 가능
inorder를 기준으로 작성했고, inOrder의 index 탐색시간을 O(1)로 만들기 위해 inPos 배열 사용
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