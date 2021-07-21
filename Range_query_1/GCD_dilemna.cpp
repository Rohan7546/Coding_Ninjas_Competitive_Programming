/*
The GCD Dillema
Send Feedback
Dwight is always bragging about how amazing he is at solving complicated problems with much ease. Jim got tired of this and gave him an interesting problem to solve.
Jim gave Dwight a sequence of integers a1, a2, ..., an and q queries x1, x2, ..., xq on it. For each query xi Dwight has to count the number of pairs (l, r) such that 1 ≤ l ≤ r ≤ n and GCD(al, al + 1, ..., ar) = xi. Dwight is feeling out of his depth here and asked you to be his Secret Assistant to the Regional Manager. Your first task is to help him solve the problem. Are you up to it?
Input Format:
First line of input contains an integer N, representing the number of elements in the sequence.
Second line contains N space-separated integers denoting the elements of the sequence.
Third line of input contains an integer Q, representing the number of queries.
Next Q line contains an integer X.
Constraints:
1 < = N <= 10^4
1 <= arr[i] <= 10^9
1 <= Q <= 10^4
1 <= X <= 10^9
Output Format:
For each query, print the answer in a new line.
Sample Input:
2
8 12
3
8
12
4
Sample Output:
1
1
1
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	auto v = readVector<int>(n);

	map<int, long long> results;

	map<int, int> divisors;
	map<int, int> nextDivisors;
	for (int i = 0 ; i < n ; i++) {
		nextDivisors.clear();
		for (auto &p : divisors) {
			nextDivisors[gcd(p.first, v[i])] += p.second;
		}
		nextDivisors[v[i]]++;

		swap(nextDivisors, divisors);
		for (auto &p : divisors)
			results[p.first] += p.second;
	}

	int q; cin >> q;
	while (q -- > 0) {
		int x; cin >> x;
		cout << results[x] << endl;
	}
}
// codeforces problem 475-D