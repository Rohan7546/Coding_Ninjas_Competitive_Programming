/*

Strange order
Send Feedback
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format
Input contains single integer n — the size of permutation p p.
Output format
Print n integers — array a .
Constraints:
1 <= N <= 10^5
Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1

*/

#include<bits/stdc++.h>
using namespace std;
bool vis[100001];
int isprime[100001];
vector<int>v;
void sieve() {
	memset(isprime, true, sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
	for (int i = 2; i * i < 100001; i++) {
		for (int j = i * i; j < 100001; j += i) {
			isprime[j] = false;
		}
	}
	v.push_back(2);
	for (int i = 3; i < 100001; i += 2) {
		if (isprime[i]) {
			v.push_back(i);
		}
	}

}

int main() {
	int n;
	cin >> n;
	sieve();

	int j = n;

	vector<int>ans;
	vector<int>ans2;
	while (j > 1) {

		if (!vis[j]) {
			for (int i = 0; v[i] <= j; i++) {

				if (j % v[i] == 0) {
					for (int k = j; k > 1; k -= v[i]) {
						if (!vis[k]) {
							vis[k] = true;

							ans2.push_back(k);
						}
					}
				}
			}

			int l = ans2.size();
			sort(ans2.rbegin(), ans2.rend());
			for (int ie = 0; ie < l; ie++) {
				ans.push_back(ans2[ie]);

			} ans2.clear();

		} j--;
	}
	ans.push_back(1);
	for (auto u : ans)cout << u << " ";
}