/*
Fill the Matrix
Send Feedback
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.
You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input Format:
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Constraints:
1 ≤ T ≤ 20
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^5
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Output Format:
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Sample Input 1:
1
5 4
1 2 0
2 2 0
5 2 1
2 1 1
Sample Output 1:
no
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int par[100001];

int getpar(int a, int *array) {
	if (par[a] < 0) {
		return a;
	}
	int pt = getpar(par[a], array);
	array[a] ^= array[par[a]];
	par[a] = pt;
	return pt;
}

void merge(int i, int j, int w, int *array) {
	int a = getpar(i, array);
	int b = getpar(j, array);
	if (a == b) {
		return;
	}
	par[a] = b;
	array[a] = array[i] ^ array[j] ^ w;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, q, i, j, w, a, b;
		cin >> n >> q;
		int array[n + 1];
		for (i = 0; i <= n; i++ ) {
			par[i] = -1;
			array[i] = 0;
		}
		int flag = 0;
		while (q--) {
			cin >> i >> j >> w;
			if (flag) {
				continue;
			}
			a = getpar(i, array);

			b = getpar(j, array);

			if (a != b) {
				merge(i, j, w, array);
			}

			else {
				if (array[i]^array[j]^w) {
					flag = 1;
				}
			}

		}
		if (flag) {
			cout << "no\n";
		}
		else {
			cout << "yes\n";
		}
	}
}