/*
Legion of Doom
Send Feedback
Lex Luthor’s Legion of Doom is a tough organization to get into, even for greatest supervillains. Recently, a spot has opened up because The Mad Hatter has retired. Harley Quinn doesn't want to waste this opportunity, and jumps at the chance of the interview. But she has a PhD in psychology, not in Computer Science. She has kidnapped you and will let you go only if you are able to solve the evil questions of Lex Luthor.
You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.
1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input Format:
In the first line you'll be given T, number of test cases.

Each test case will start with N and C. After that you'll be given C commands in the format as mentioned above
Constraints:
 1 <= T <= 10
 1 <= N, C <= 10000
 1 <= val <= 10^8
 1 <= p <= q <= N
Output Format:
Print the answers of the queries in new line for each test case.
Sample Input 1:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8
0 5 7 14
1 4 8
Sample Output 1:
80
508
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
	ll value;
	ll lazy;
};

void buildtree(node *tree, ll *arr, ll s, ll e, ll i) {
	if (s == e) {
		tree[i].value = arr[s];
		tree[i].lazy = 0;
		return;
	}

	tree[i].lazy = 0;
	ll mid = (s + e) / 2;
	buildtree(tree, arr, s, mid, 2 * i);
	buildtree(tree, arr, mid + 1, e, 2 * i + 1);
	tree[i].value = tree[2 * i].value + tree[2 * i + 1].value;
}

void update(node *tree, ll s, ll e, ll i, ll l, ll r, ll inc) {
	if (s > e)return;
	if (tree[i].lazy != 0) {
		tree[i].value += (e - s + 1) * tree[i].lazy;
		if (s != e) {
			tree[2 * i].lazy += tree[i].lazy;
			tree[2 * i + 1].lazy += tree[i].lazy;
		}
		tree[i].lazy = 0;
	}


	if (s > r || e < l)return;

	if (s >= l && e <= r) {
		tree[i].value += (e - s + 1) * inc;
		if (e != s) {
			tree[2 * i].lazy += inc;
			tree[2 * i + 1].lazy += inc;
		}
		return;
	}
	ll mid = (s + e) / 2;
	update(tree, s, mid, 2 * i, l, r, inc);
	update(tree, mid + 1, e, 2 * i + 1, l, r, inc);
	tree[i].value = tree[2 * i].value + tree[2 * i + 1].value;


}

node query(node *tree, ll s, ll e, ll i, ll l, ll r) {
	if (s > e)return{0, 0};
	if (tree[i].lazy != 0) {
		tree[i].value += (e - s + 1) * tree[i].lazy;
		if (s != e) {
			tree[2 * i].lazy += tree[i].lazy;
			tree[2 * i + 1].lazy += tree[i].lazy;
		}
		tree[i].lazy = 0;
	}
	if (s > r || e < l) {
		return {0, 0};
	}
	if (s >= l && e <= r) {
		return tree[i];
	}

	ll mid = (s + e) / 2;
	node ans1 = query(tree, s, mid, 2 * i, l, r);
	node ans2 = query(tree, mid + 1, e, 2 * i + 1, l, r);
	node ans;
	ans.value = ans1.value + ans2.value;
	ans.lazy = ans1.lazy + ans2.lazy;
	return ans;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, c;
		cin >> n >> c;
		ll arr[n] = {0};
		node tree[4 * n];
		buildtree(tree, arr, 0, n - 1, 1);
		while (c--) {
			ll x, y, z;
			cin >> x >> y >> z;
			if (x == 0) {
				ll v;
				cin >> v;
				update(tree, 0, n - 1, 1, y - 1, z - 1, v);
			}
			else {
				node ans = query(tree, 0, n - 1, 1, y - 1, z - 1);
				cout << ans.value << endl;
			}
		}

	}
}