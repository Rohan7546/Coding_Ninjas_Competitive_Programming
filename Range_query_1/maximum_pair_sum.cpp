/*

Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input of a 'U' followed by space and then two integers i and x.
U i x
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input of a 'Q' followed by a single space and then two integers i and j.
Q x y
You must find two integers i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input Format:
The first line of input contains an integer N, representing the length of the sequence.
The second line of input contains of N space separated integers, A[i].
The third line of input contains an integer Q, Q ≤ 10^5, representing the number of operations.
Next Q lines contain the operations.
Constraints:
1 ≤ i ≤ N
0 ≤ x ≤ 10^8
1 ≤ x < y ≤ N
Output Format:
For each query, print the maximum sum mentioned above, in a new line.
Sample Input 1:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Sample Output 1:
7
9
11
12

*/
#include<bits/stdc++.h>
using namespace std;
struct node {
	int fmax;
	int smax;
};


void buildtree(node *tree, int *arr, int s, int e, int i) {
	if (s == e) {
		tree[i].fmax = arr[s];
		tree[i].smax = 0;
		return;
	}

	int mid = (s + e) / 2;
	buildtree(tree, arr, s, mid, 2 * i);
	buildtree(tree, arr, mid + 1, e, 2 * i + 1);
	tree[i].fmax = max(tree[2 * i].fmax, tree[2 * i + 1].fmax);
	tree[i].smax = min(max(tree[2 * i].fmax, tree[2 * i + 1].smax), max(tree[2 * i + 1].fmax, tree[2 * i].smax));

}

void update(node *tree, int *arr, int s, int e, int i, int idx, int val) {

	if (s == e) {
		arr[idx] = val;
		tree[i].fmax = arr[s];
		tree[i].smax = 0;
		return;
	}


	int mid = (s + e) / 2;
	if (idx > mid) {
		update(tree, arr, mid + 1, e, 2 * i + 1, idx, val);
	}
	else {
		update(tree, arr, s, mid, 2 * i, idx, val);
	}

	tree[i].fmax = max(tree[2 * i].fmax, tree[2 * i + 1].fmax);
	tree[i].smax = min(max(tree[2 * i].fmax, tree[2 * i + 1].smax), max(tree[2 * i + 1].fmax, tree[2 * i].smax));
}

node query(node *tree, int *arr, int s, int e, int i, int l, int r) {



	if (e < l || s > r) {
		return {0, 0};
	}

	if (s >= l && e <= r) {
		node x;
		x.fmax = tree[i].fmax;
		x.smax = tree[i].smax;
		return x;
	}

	int mid = (s + e) / 2;
	node ans1 = query(tree, arr, s, mid, 2 * i, l, r);
	node ans2 = query(tree, arr, mid + 1, e, 2 * i + 1, l, r);
	node ans;
	ans.fmax = (max(ans1.fmax, ans2.fmax));
	ans.smax = min(max(ans1.fmax, ans2.smax), max(ans2.fmax, ans1.smax));
	return ans;

}

int main() {

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	node tree[4 * n];
	buildtree(tree, arr, 0, n - 1, 1);
	int q;
	cin >> q;
	while (q--) {
		char x;
		int y, z;
		cin >> x >> y >> z;
		if (x == 'U') {
			update(tree, arr, 0, n - 1, 1, y - 1, z);
		}
		else {
			node res = query(tree, arr, 0, n - 1, 1, y - 1, z - 1);
			cout << res.fmax + res.smax << endl;
		}
	}
}