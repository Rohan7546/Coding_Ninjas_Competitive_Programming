/*

Activity Selection
Send Feedback
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input Format
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Output Format
Output one integer, the maximum number of activities that can be performed
Sample Input 1
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output 1
4
Explanation:
The four activities will be done at following time intervals:
1. 1 2
2. 3 4
3. 5 7
4. 8 9

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {

	// write your code here
	int n;
	cin >> n;
	vector<pair<ll, ll>>v;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());

	ll strt1 = v[0].first;
	ll strt2 = v[0].second;
	ll cnt = 1;
	for (int i = 1; i < n; i++) {
		if (strt2 <= v[i].first) {
			cnt++;
			strt2 = v[i].second;
		}
		else {
			if (strt2 > v[i].first && strt2 > v[i].second) {
				strt2 = v[i].second;
			}
			else {
				continue;
			}

		}

	}
	cout << cnt << endl;

	return 0;
}