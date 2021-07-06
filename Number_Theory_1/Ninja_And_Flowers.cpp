/*
Ninja and Flowers
Send Feedback
Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})
Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower is a prime divisor of another flower they needed to be of a different colour.
As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.
Input Format:
The only line of input will contain an integer N (number of flowers).
Output Format:
In first-line print K, the minimum number of different colour boxes that are needed to pack the flowers.
Next line contains K space-separated integers in sorted order denoting the counts of the different coloured boxes.
Constraints:
1 <= N <= 2*10^5
Sample Input:
4
Sample Output:
2
1 3
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mex = 1e6 + 1;

void solve(ll n) {

	bool isprime[mex];
	memset(isprime, true, sizeof(isprime));

	for (ll i = 2; i * i <= mex; i++) {
		if (isprime[i]) {
			for (ll j = i * i; j <= mex; j += i)
			{
				 

				isprime[j] = false;
			}
		}
	}
 
	ll count = 0;
 
	for (ll i = 2; i <= n+1; i++) {
		 
 	 if(isprime[i]){
         count++;
     }
	 
	}


 
	 cout<<2<<endl;
    cout<<min(count,n-count)<<" "<<max(count,n-count)<<endl;
}
int main(){
	ll n;
	cin>>n;
	 solve(n);
}
