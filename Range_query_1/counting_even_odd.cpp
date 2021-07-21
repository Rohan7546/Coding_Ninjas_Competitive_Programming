/*
Counting Even/Odd
Send Feedback
Tanmay and Rohit are best buddies. One day Tanmay gives Rohit a problem to test his intelligence and skills. He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0:
0 x y
This operation modifies the element present at index i to x.
Query 1:
1 x y
This operation counts the number of even numbers in range l to r inclusive.
Query 2:
2 x y
This operation counts the number of odd numbers in range l to r inclusive.
Input Format:
First line of the input contains the number N.
Next line contains N natural numbers.
Next line contains an integer Q followed by Q queries.
0 x y - modify the number at index x to y.
1 x y - count the number of even numbers in range l to r inclusive.
2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5
1<=l<=r<=N
0<=Ai<=10^9
1<=x<=N
0<=y<=10^9
Output Format:
 For each query, print the answer in a new line.
Note: Indexing starts from 1
Sample Input 1:
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output 1:
2
2
4
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
	ll odd;
	ll even;
};

void buildtree(ll *arr, node *tree, ll start, ll end, ll treenode) {
	if (start == end) {
		if (arr[start] % 2) {
			tree[treenode].odd = 1;
			tree[treenode].even = 0;
		}
		else {
			tree[treenode].even = 1;
			tree[treenode].odd = 0;
		}
		return;
	}

	ll mid = (start + end) / 2;
	buildtree(arr, tree, start, mid, 2 * treenode);
	buildtree(arr, tree, mid + 1, end, 2 * treenode + 1);

	tree[treenode].odd = tree[2 * treenode].odd + tree[2 * treenode + 1].odd;
	tree[treenode].even = tree[2 * treenode].even + tree[2 * treenode + 1].even;


}


void update(node * tree, ll *arr, ll start, ll end, ll treenode, ll index, ll value) {
	if (start == end) {
		arr[index] = value;
		if (value % 2) {
			if (tree[treenode].odd == 0) {
				swap(tree[treenode].odd, tree[treenode].even);
			}

		}
		else {
			if (tree[treenode].even == 0) {
				swap(tree[treenode].odd, tree[treenode].even);
			}
		}


		return;
	}







	ll mid = (start + end) / 2;
	if (index > mid) {
		update(tree, arr, mid + 1, end, 2 * treenode + 1, index, value);
	}
	else {
		update(tree, arr, start, mid, 2 * treenode, index, value);
	}

	tree[treenode].odd = tree[2 * treenode].odd + tree[2 * treenode + 1].odd;
	tree[treenode].even = tree[2 * treenode].even + tree[2 * treenode + 1].even;


}

node query(node *tree, ll start, ll end, ll left, ll right, ll treenode) {
	if (start > right || end < left) {
		return {0, 0};
	}

	if (start >= left && end <= right) {
		return tree[treenode];
	}
	ll mid = (start + end) / 2;
	node ans1 = query(tree, start, mid, left, right, 2 * treenode);
	node ans2 = query(tree, mid + 1, end, left, right, 2 * treenode + 1);

	node ans;
	ans.even = ans1.even + ans2.even;
	ans.odd = ans1.odd + ans2.odd;
	return ans;
}


int main()
{

	ll n;
	cin >> n;
	ll arr[n];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	node *tree = new node[4 * n];
	buildtree(arr, tree, 0, n - 1, 1);
	ll q;
	cin >> q;
	while (q--) {
		ll x, y, z;
		cin >> x >> y >> z;
		if (x == 0) {
			update(tree, arr, 0, n - 1, 1, y - 1, z);
		}
		else if (x == 1) {
			cout << query(tree, 0, n - 1, y - 1, z - 1, 1).even << endl;
		}
		else {
			cout << query(tree, 0, n - 1, y - 1, z - 1, 1).odd << endl;
		}
	}
}

