 #include<bits/stdc++.h>
using namespace std;

int isprime(int n){
   
    bool prime[n+1];
    for(int i=0;i<n+1;i++){
        prime[i]=true;
    }
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i*i<=n;i++){
        
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    
    
    int cnt=0;
    for(int j=0;j<=n;j++){
        if(prime[j])cnt++;
    }
    return cnt;
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    
 
    cout<<isprime(n)<<endl;
    return 0;
}
