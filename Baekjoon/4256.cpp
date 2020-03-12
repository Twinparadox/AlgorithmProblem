#include <iostream>
#include <vector>
using namespace std;
vector<int> preorder, inorder;
void PostOrder(int start, int end, int root)
{
	for (int i = start; i < end; i++)
	{
		if (inorder[i] == preorder[root])
		{
			PostOrder(start, i, root + 1);
			PostOrder(i + 1, end, root + i - start + 1);
			cout << preorder[root] << ' ';
		}
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		preorder = vector<int>(N);
		inorder = vector<int>(N);
		for (int i = 0; i < N; i++)
			cin >> preorder[i];
		for (int i = 0; i < N; i++)
			cin >> inorder[i];

		PostOrder(0, N, 0);
		cout << '\n';
	}
}