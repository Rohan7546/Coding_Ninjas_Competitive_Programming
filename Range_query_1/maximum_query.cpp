/*
Maximum Query
Send Feedback
You are given an array of integet of size N and Q queries in form of (l, r). You are supposed to find the maximum value of array between index l and r (both inclusive)
Input Format:
First line of input contain an integer N (number of elements in the array)
Second line contain N space-separated integers denoting the elements of the array
Third line contain an integer Q (number of queries to be processed)
Next Q line contain two space-separated integers denoting l and r.
Output Format:
For each test case print the output in newline.
Constraints:
1 <= N <= 10^4
1 <= Q <= 10^6
1 <= arr[i] <= 10^9
0 <= l <= r < N
Sample Input:
5
1 2 3 5 4
2
0 1
3 4
Sample Output:
2
5
*/
#include<bits/stdc++.h>
using namespace std;
void buildtree(int *arr, int *tree, int start, int end, int treenode) {
	if (start == end) {
		tree[treenode] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	buildtree(arr, tree, start, mid, 2 * treenode);
	buildtree(arr, tree, mid + 1, end, 2 * treenode + 1);
	tree[treenode] = max(tree[treenode * 2], tree[treenode * 2 + 1]);
}

int query(int *tree, int start, int end, int left, int right, int treenode) {
	if (start > right || end < left) {
		return INT_MIN;
	}
	if (start >= left && end <= right) {
		return tree[treenode];
	}
	int mid = (start + end) / 2;
	int ans1 = query(tree, start, mid, left, right, 2 * treenode);
	int ans2 = query(tree, mid + 1, end, left, right, 2 * treenode + 1);
	return max(ans1, ans2);
}



int main() {

	// write your code here
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int *tree = new int[4 * n];
	buildtree(arr, tree, 0, n - 1, 1);
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << query(tree, 0, n - 1, x, y, 1) << endl;
	}
	return 0;
}