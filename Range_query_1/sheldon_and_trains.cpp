/*
Sheldon and Trains
Send Feedback
Sheldon always tells people, “When you have only one day to visit Los Angeles, make it a Train Day”. He loves spending time while travelling in trains and considers it a fun activity. Sheldon’s mom has come to visit him and he decides to take her out on a train tour of the city of Pasadena, along with his friend Howard. There are n train stations in the city. Howard knows how irritating Sheldon can be during a train ride. So, to keep him busy, Howard gives Sheldon a problem so interesting that he just cannot do anything else other than devote his entire mind to solving it. The problem goes like this. At the i-th station it's possible to buy only tickets to stations from i + 1 to ai (inclusive). No tickets are sold at the last station.
Let ρi, j be the minimum number of tickets one needs to buy in order to get from stations i to station j. Sheldon’s task is to compute the sum of all values ρi, j among all pairs 1 ≤ i < j ≤ n. As brilliant as he may be, he asked for your help.
Input Format:
First line of input will contain N number of trains
Second line will contain N-1 space-separated integers denoting the values of ai
Output Format:
Print the answer as mentioned above
Constraints:
2 < = N <= 10^5
i + 1 <=arr[i] <= N
Sample Input 1:
7
2 7 5 7 6 7
Sample Output 1:
29
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
	ll value, ind;
};
bool comp(node n1, node n2) {
	return n1.value < n2.value;
}
void buildtree(node *tree, ll *arr, ll s, ll e, ll i) {
	if (s == e) {
		tree[i].value = arr[s];
		tree[i].ind = -s;
		return;
	}

	ll mid = (s + e) / 2;
	buildtree(tree, arr, s, mid, 2 * i);
	buildtree(tree, arr, mid + 1, e, 2 * i + 1);
	tree[i] = max(tree[2 * i], tree[2 * i + 1], comp);
}

node query(node *tree, ll s, ll e, ll i, ll l, ll r, ll n) {
	if (s > r || e < l) {
		return {0, -n};
	}
	if (s >= l && e <= r) {
		return tree[i];
	}
	ll mid = (s + e) / 2;
	node ans1 = query(tree, s, mid, 2 * i, l, r, n);
	node ans2 = query(tree, mid + 1, e, 2 * i + 1, l, r, n);
	return max(ans1, ans2, comp);
}

int main() {
	ll n;
	cin >> n;
	ll arr[n];
	for (ll i = 1; i < n; i++) {
		cin >> arr[i];
	}
	node tree[4 * n];
	ll dp[n + 1] = {0};
	buildtree(tree, arr, 1, n, 1);

	ll res = 0;
	for (ll i = n - 1; i >= 1; i--) {
		node ans = query(tree, 1, n, 1, i + 1, arr[i], n);
		ans.ind *= -1;
		dp[i] = (n - i) - (arr[i] - ans.ind) + dp[ans.ind];
		res += dp[i];

	}

	cout << res << endl;
}
