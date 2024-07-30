#include<bits/stdc++.h>
using namespace std;

vector<int> sieveofEratosthenes(int n){
    vector<bool> isPrimes(n+1, true);
    
    for(int i=2; i<=n; i++){
        if(isPrimes[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrimes[j] = false;
            }
        }
    }
    
    vector<int> result;
    for(int i=2; i<=n; i++){
        if(isPrimes[i]) result.push_back(i);
    }
    
    return result;
}

void printPrimeFactors(vector<int> primes, int num){
    for(int i=0; i<primes.size(); i++){
        while(num % primes[i] == 0){
            cout<<primes[i]<<" ";
            num /= primes[i];
        }
        if(num == 1) break;
    }
    
    if(num>1){
        cout<<num<<endl;
    }
}

void printPrimeFactorsInRange(int start, int end){
    int limit = sqrt(end);
    vector<int> primes = sieveofEratosthenes(limit);
    
    for(int num=start; num<=end; num++){
        cout<<"Prime factors of "<<num<<"are: ";
        printPrimeFactors(primes, num);
        cout<<endl;
    }
}

int main(){
    int start, end;
    cin>>start>>end;
    
    printPrimeFactorsInRange(start, end);
    
    return 0;
}
