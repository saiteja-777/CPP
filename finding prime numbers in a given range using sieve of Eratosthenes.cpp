#include<bits/stdc++.h>
using namespace std;

vector<int> sieveofEratosthenes(int n){
    vector<bool> isPrime(n+1, true);
    
    isPrime[0]= isPrime[1] = false;
    
    for(int i=2; i<=sqrt(n); i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    
    vector<int> result;
    for(int i=2; i<=n; i++){
        if(isPrime[i]) result.push_back(i);
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    
    vector<int> primes = sieveofEratosthenes(n);
    for(int i=0; i<primes.size(); i++){
    	cout<<primes[i]<<" ";
	}
    cout<<endl;
    
    return 0;
}
