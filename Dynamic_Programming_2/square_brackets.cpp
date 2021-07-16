/*
Square Brackets
Send Feedback
You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:
[[]][[[]][]]
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Note: since result can be pretty large output the answer % mod (10^9 + 7).
Input Format:
The first line of the input file contains one integer T(number of test cases), each test case follows as.
The first line contains two integers n and k separated by single space.
The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
Output Format:
 For each test case print the number of balanced square bracket sequence % mod (10^9 + 7), that can be formed using the above rules in a new line.
Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= K <= N
Sample Input
5
1 1
1
1 1
2
2 1
1
3 1
2
4 2
5 7
Sample Output
1
0
2
3
2
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll dp[402][402];
ll open[202];
ll n;
ll brack(ll i, ll o) {
	if (o < 0)return 0;

	if (i == n) {
		if (o == 0) {
			return 1;
		}
		return 0;
	}
	if (dp[i][o] != -1) {
		return dp[i][o];
	}
	if (open[i] > 0) {
		return dp[i][o] = brack(i + 1, o + 1);
	}
	else {
		return dp[i][o] = (brack(i + 1, o + 1) + brack(i + 1, o - 1)) % mod;
	}
}
int main() {
	ll t;
	cin >> t;

	while (t--) {
		memset(dp, -1, sizeof(dp));
		memset(open, 0, sizeof(open));
		ll k;
		cin >> n >> k;
		n *= 2;
		for (ll i = 0; i < k; i++) {
			ll x;
			cin >> x;
			open[x - 1] = 1;
		}
		cout << brack(0, 0) % mod << "\n";

	}
}

/*
other approach

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll dp[402][402];
ll open[202];
ll n;
ll brack(ll o, ll c){
	if(o==n && c==n){
		return 1;
	}
	if(o>n || c>n){
		return 0;
	}
	if(dp[o][c]!=-1){
		return dp[o][c];
	}
	if(o==c || open[o+c]){
		return dp[o][c]=brack(o+1,c);
	}
	else if (o==n){
		return dp[o][c]=brack(o,c+1);
	}
    else{
	return dp[o][c]=(brack(o+1,c)+brack(o,c+1))%mod;
    }

}
int main(){
	ll t;
	cin>>t;

	while(t--){
	memset(dp,-1,sizeof(dp));
    memset(open,0,sizeof(open));
		ll k;
		cin>>n>>k;

		for(ll i=0;i<k;i++){
			ll x;
			cin>>x;
			open[x-1]=1;
		}
		cout<<brack(0,0)%mod<<"\n";

	}
}
*/