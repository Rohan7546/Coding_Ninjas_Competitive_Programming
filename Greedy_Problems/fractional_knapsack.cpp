/*

Fractional Knapsack
Send Feedback
You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
Note: You are allowed to break the items in parts.
Input Format:
The first line of input contains two space separated integers, that denote the value of N and W.
Each of the following N lines contains two space separated integers, that denote value and weight, respectively, of the N items.
Constraints:
1 <= N = 2*10^5
1 <= W <= 10^9
1 <= value, weight <= 10^5
Time Limit: 1 sec
Output Format:
Print the maximum total value upto six decimal places.
Sample Input 1:
4 22
6 4
6 4
4 4
4 4
Sample Output 1:
20.000000
Explanation:
The total weight of all the items is 16 units, which is less than the total capacity of knapsack, i.e 22 units. Hence, we will add all the items in the knapsack and total value will be 20 units.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct item {
	ll weight, value;
};

bool compare(item i1, item i2) {
	double value1 = ((double)i1.value) / i1.weight;
	double value2 = ((double)i2.value) / i2.weight;
	return value1 > value2;
}

double fknapsack(item arr[], ll n, ll totalW) {
	ll curw = 0;
	double fvalue = 0;
	for (ll i = 0; i < n; i++) {
		if (arr[i].weight + curw <= totalW) {
			fvalue += (arr[i].value);
			curw += (arr[i].weight);
		}
		else {
			ll remw = totalW - curw;
			fvalue += ((((double)arr[i].value) / arr[i].weight) * remw);
			break;
		}
	}
	return fvalue;
}

int main() {
	ll n, W;
	cin >> n >> W;
	item arr[n];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].value;
		cin >> arr[i].weight;

	}

	sort(arr, arr + n, compare);
	cout << fixed << setprecision(6) << fknapsack(arr, n, W);
}