/*
Minimum In SubArray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] of N numbers ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are Q queries, and each query is defined in either of the following two ways:
Query on range:
You are given two numbers i and j; the answer to each query is the minimum number between the range (i, j) (including both i and j). Note that in this query, i and j lies in the range: [1, N].
Update query:
You are given two numbers i and B; update A[i] to B. Note that in this query, i lies in the range: [1, N].
Input Format:
The first line of input contains two integers: N and Q, representing the length of the sequence and the number of queries.
The second line of input contains N space-separated integers, A[i].
Next, Q lines contain the queries. Each line contains one character, followed by two space-separated integers. For the query on range, the character will be q and for the update query, the character will be u.
Constraints:
1 ≤ i ≤ N
0 ≤ B ≤ 10^8
1 ≤ i <= j ≤ N
Output Format:
For each query on range, print the minimum number between the range, in a new line.
Sample Input 1:
4 3
5 2 4 3
q 1 3
u 1 1
q 3 4
Sample Output 1:
2
3

*/

#include<bits/stdc++.h>
using namespace std;

void buildtree(int *tree, int *arr, int i, int s, int e) {
	if (s == e) {
		tree[i] = arr[s];
		return;
	}

	int mid = (s + e) / 2;
	buildtree(tree, arr, 2 * i, s, mid);
	buildtree(tree, arr, 2 * i + 1, mid + 1, e);
	tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

void update(int *tree, int*arr, int i, int s, int e, int idx, int val) {
	if (s == e) {
		tree[i] = val;
		arr[idx] = val;
		return;
	}



	int mid = (s + e) / 2;

	if (idx > mid) {
		update(tree, arr, 2 * i + 1, mid + 1, e, idx, val);
	}
	else {
		update(tree, arr, 2 * i, s, mid, idx, val);
	}

	tree[i] = min(tree[2 * i], tree[2 * i + 1]);

}

int query(int *tree, int i, int s, int e, int l, int r) {

	if (s > r || e < l) {
		return INT_MAX;
	}

	if (s >= l && e <= r) {
		return tree[i];
	}

	int mid = (s + e) / 2;
	int ans1 = query(tree, 2 * i, s, mid, l, r);
	int ans2 = query(tree, 2 * i + 1, mid + 1, e, l, r);
	return min(ans1, ans2);
}

int main() {
	int n, q;
	cin >> n >> q;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int tree[4 * n];
	buildtree(tree, arr, 1, 0, n - 1);
	while (q--) {
		char x;
		cin >> x;
		if (x == 'q') {
			int y, z;
			cin >> y >> z;
			y--, z--;
			cout << query(tree, 1, 0, n - 1, y, z) << endl;
		}
		else {
			int y, z;
			cin >> y >> z;
			y--;
			update(tree, arr, 1, 0, n - 1, y, z);
		}
	}
}