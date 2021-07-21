/*

Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N].
A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, write a program that outputs the results of these queries.
Input Format:
The first line of input contains an integer N.
In the second line contains N space separated integers.
The third line contains the integer M.
Next M lines contains 2 integers x and y.
Output Format:
For each query, print the answer in a new line.
Constraints:
1 <= N <= 10^5
1 < = Q <= 10^5
-10^4 <= arr[i] <= 10^4
Sample Input 1:
3
-1 2 3
1
1 2
Sample Output 1:
2

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll NI = -1e6;
struct node {
	ll sum;
	ll bpsum;
	ll bssum;
	ll max_sum;

};

void buildtree(node *tree, ll *arr, ll s, ll e, ll i) {
	if (s == e) {
		tree[i].sum = arr[s];
		tree[i].bpsum = arr[s];
		tree[i].bssum = arr[s];
		tree[i].max_sum = arr[s];
		return;

	}

	ll mid = (s + e) / 2;
	buildtree(tree, arr, s, mid, 2 * i);
	buildtree(tree, arr, mid + 1, e, 2 * i + 1);

	tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
	tree[i].bpsum = max(tree[2 * i].bpsum, tree[2 * i].sum + tree[2 * i + 1].bpsum);
	tree[i].bssum = max(tree[2 * i].bssum + tree[2 * i + 1].sum, tree[2 * i + 1].bssum);
	tree[i].max_sum = max(tree[2 * i].max_sum, max(tree[2 * i + 1].max_sum,
	                      max(tree[2 * i].sum + tree[2 * i + 1].bpsum, max(tree[2 * i + 1].sum + tree[2 * i].bssum,
	                              tree[2 * i].bssum + tree[2 * i + 1].bpsum))));

}

node query(node *tree, ll *arr, ll s, ll e, ll i, ll l, ll r) {
	if (s > r || e < l) {
		return {NI, NI, NI, NI};
	}

	if (s >= l && e <= r) {
		return tree[i];
	}

	ll mid = (s + e) / 2;
	node ans1 = query(tree, arr, s, mid, 2 * i, l, r);
	node ans2 = query(tree, arr, mid + 1, e, 2 * i + 1, l, r);
	node ans;
	ans.sum = ans1.sum + ans2.sum;
	ans.bpsum = max(ans1.bpsum, ans1.sum + ans2.bpsum);
	ans.bssum = max(ans1.bssum + ans2.sum, ans2.bssum);
	ans.max_sum = max(ans1.max_sum, max(ans2.max_sum, max(ans1.sum + ans2.bpsum,
	                                    max(ans2.sum + ans1.bssum, ans1.bssum + ans2.bpsum))));
	return ans;
}

int main() {
	ll n;
	cin >> n;
	ll arr[n];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}

	node tree[4 * n];
	buildtree(tree, arr, 0, n - 1, 1);
	ll m;
	cin >> m;
	while (m--) {
		ll l, r;
		cin >> l >> r;
		l--, r--;
		cout << query(tree, arr, 0, n - 1, 1, l, r).max_sum << endl;
	}
}