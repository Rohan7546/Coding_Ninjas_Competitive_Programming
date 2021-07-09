/*
Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1. Start Time
2. Finish Time
3. Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input Format:
The first line of input contains an integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job.
Constraints:
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Output Format:
Output one integer, the maximum profit that can be achieved.
Sample Input 1
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output 1
250 */

#include<bits/stdc++.h>
using namespace std;
struct job {
	int start, finish, profit;
};

bool compare (job a, job b) {
	return a.finish < b.finish;
}
int binarysearch(job arr[], int n) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid].finish <= arr[n].start) {
			if (arr[mid + 1].finish <= arr[n].start) {
				low = mid + 1;
			}
			else {
				return mid;
			}
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int findmprofit(job arr[], int n) {
	sort(arr, arr + n, compare);
	int dp[n];
	dp[0] = arr[0].profit;
	for (int i = 1; i < n; i++) {


		int including = arr[i].profit;
		int lninclude = binarysearch(arr, i);
		if (lninclude != -1) {
			including += dp[lninclude];
		}
		dp[i] = max(including, dp[i - 1]);
	}
	return dp[n - 1];
}


int main() {
	int n;
	cin >> n;
	job arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].start;
		cin >> arr[i].finish;
		cin >> arr[i].profit;
	}
	cout << findmprofit(arr, n);
}