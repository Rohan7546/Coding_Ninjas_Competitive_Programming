/*
Murder
Send Feedback
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input Format:
First line of input contains an integer T, representing number of test case.
For each test case, first line of input contains integer N, representing the number of stairs.
For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.
Constraints
T<=10^5
1<=N<=10^5
All numbers will be between 0 and 10^9
Sum of N over all test cases doesn't exceed 5*10^5
Output Format
For each test case output one line giving the final sum for each test case.
Sample Input 1:
1
5
1 5 3 6 4
Sample Output 1:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/

#include<iostream>
#include<climits>

#define ll long long

using namespace std;

ll count(int a[], int l, int mid, int r) {
	int c[r - l + 1];
	int ci = 0, i = l, j = mid + 1;
	ll sum = 0;
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) {
			sum += (ll)((ll)(r - j + 1) * (ll)a[i]);
			c[ci++] = a[i];
			i++;
		}
		else {
			c[ci++] = a[j];
			j++;
		}
	}
	while (i <= mid) {
		c[ci++] = a[i++];
	}
	while (j <= r) {
		c[ci++] = a[j++];
	}
	for (int i = 0; i < ci; i++) {
		a[l + i] = c[i];
	}
	return sum;
}

ll murder(int a[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		ll x = murder(a, l, mid);
		ll y = murder(a, mid + 1, r);
		ll z = count(a, l, mid, r);
		return x + y + z;
	}
	return 0;
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << murder(a, 0, n - 1) << "\n";
	}
	return 0;
}