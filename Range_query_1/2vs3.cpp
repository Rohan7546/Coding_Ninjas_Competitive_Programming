/*
2 vs 3
Send Feedback
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input format:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output format:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5
1<= Q <= 10^5
0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void build(int *tree, int *arr, int s, int e, int i, int* powarr) {
	if (s == e) {
		tree[i] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	build(tree, arr, s, mid, 2 * i, powarr);
	build(tree, arr, mid + 1, e, 2 * i + 1, powarr);
	tree[i] = (tree[2 * i + 1] + tree[2 * i] * powarr[e - mid]) % 3;
}


void update(int *tree, int *arr, int s, int e, int i, int* powarr, int index) {
	if (s == e) {
		arr[index] = 1;
		tree[i] = 1;
		return;
	}
	int mid = (s + e) / 2;
	if (index > mid) {
		update(tree, arr, mid + 1, e, 2 * i + 1, powarr, index);
	}
	else {
		update(tree, arr, s, mid, 2 * i, powarr, index);
	}
	tree[i] = (tree[2 * i + 1] + tree[2 * i] * powarr[e - mid]) % 3;
}


int query(int *tree, int s, int e, int l, int r, int i, int *powarr) {
	if (s > r || e < l) {
		return 0;
	}

	if (s >= l && e <= r) {
		return (tree[i] * powarr[r - e]) % 3;
	}
	int mid = (s + e) / 2;
	int ans1 = query(tree, s, mid, l, r, 2 * i, powarr);
	int ans2 = query(tree, mid + 1, e, l, r, 2 * i + 1, powarr);
	return (ans1 + ans2) % 3;
}

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = s[i] - '0';
	}
	int *tree = new int[4 * n];
	int *powarr = new int[100000 + 1];
	powarr[0] = 1;
	for (int i = 1; i < 100000 + 1; i++) {
		powarr[i] = (2 * powarr[i - 1]) % 3;
	}
	build(tree, arr, 0, n - 1, 1, powarr);
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (x == 0) {
			int l, r;
			cin >> l >> r;
			cout << query(tree, 0, n - 1, l, r, 1, powarr) << endl;

		}
		else {
			int ind;
			cin >> ind;
			update(tree, arr, 0, n - 1, 1, powarr, ind);
		}
	}
}