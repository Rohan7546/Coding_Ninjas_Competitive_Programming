/*
This is Sparta!
Send Feedback
King Leonidas of Sparta is preparing his men and country for a war against the Persian King Xerxes. He has N soldiers with him and he has arranged them in a line at The Hot Gates. Let us number them from 1 to N. Leonidas will fight Xerxes' army for Q days, and each day he can send only one of his men to fight.
For each warrior, we know 2 traits: Strength and Cowardice. These are given to us in a form of integer. Each day, Leonidas can choose his warrior from a range Li to Ri, and he will choose the warrior with maximum Strength value. If there is more than one warrior having the same maximum Strength value, he will choose the warrior with minimum Cowardice value. If there is still more than 1 warrior with the same maximum Strength value and same minimum Cowardice value, he chooses the one with lower index in line.
King Leonidas is ready to lay his life for Sparta. You, his right hand man, have to help him save Sparta by helping him choose a warrior for each day.
Input Format:
First line contains a single integer N, denoting the number of warriors Leonidas has.
Second line contains N space separated integers, representing Strength of ith warrior.
Third line contains N space separated integers, representing Cowardice of ith warrior
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior.
Each of the next Q lines contains 2 integers Li and Ri.
Constraints:
1 ≤ N,Q ≤ 10^5
1 ≤ Ai,Bi ≤ 10^9
1 ≤ Li ≤ Ri
Output Format:
For each Li and Ri, print the index of the warrior that King Leonidas should choose.
Sample Input 1:
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output 1:
2
2
4
5
*/
#include<bits/stdc++.h>
using namespace std;
struct node {
	int power;
	int coward;
	int index;
};

void buildtree(node *arr, node* tree, int start, int end, int treenode) {
	if (start == end) {
		tree[treenode] = arr[start];
		return;
	}



	int mid = (start + end) / 2;
	buildtree(arr, tree, start, mid, 2 * treenode);
	buildtree(arr, tree, mid + 1, end, 2 * treenode + 1);

	if (tree[2 * treenode].power > tree[2 * treenode + 1].power) {
		tree[treenode] = tree[2 * treenode];
	}
	else if (tree[2 * treenode].power < tree[2 * treenode + 1].power) {
		tree[treenode] = tree[2 * treenode + 1];
	}
	else {
		if (tree[2 * treenode].coward == tree[2 * treenode + 1].coward) {
			if (tree[2 * treenode].index < tree[2 * treenode + 1].index) {
				tree[treenode] = tree[2 * treenode];
			}
			else {
				tree[treenode] = tree[2 * treenode + 1];
			}
		}
		else if (tree[2 * treenode].coward < tree[2 * treenode + 1].coward) {
			tree[treenode] = tree[2 * treenode];
		}
		else {
			tree[treenode] = tree[2 * treenode + 1];

		}
	}


}



node query(node *arr, node *tree, int start, int end, int left, int right, int treenode) {

	if (start > right || end < left) {
		return {0, 0, 0};
	}
	if (start >= left && end <= right) {
		return tree[treenode];
	}

	int mid = (start + end) / 2;
	node ans1 = query(arr, tree, start, mid, left, right, 2 * treenode);
	node ans2 = query(arr, tree, mid + 1, end, left, right, 2 * treenode + 1);


	if (ans1.power > ans2.power) {
		return ans1;
	}
	else if (ans1.power < ans2.power) {
		return ans2;
	}
	else {
		if (ans1.coward == ans2.coward) {
			if (ans1.index < ans2.index) {
				return ans1;
			}
			else {
				return ans2;
			}
		}
		else if (ans1.coward < ans2.coward) {
			return ans1;
		}
		else {
			return ans2;

		}
	}

}

int main() {
	int n;
	cin >> n;
	node *arr = new node[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].power;
		arr[i].index = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i].coward;
	}
	node *tree = new node[4 * n];
	buildtree(arr, tree, 0, n - 1, 1);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		node ans;
		ans = query(arr, tree, 0, n - 1, l - 1, r - 1, 1);
		cout << ans.index + 1 << endl;
	}
}