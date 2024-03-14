#include<bits/stdc++.h>
using namespace std;
int fib(vector<int> &memo,int n){
    if(memo[n] == -1){
        int res;
        if(n == 0 || n == 1)res = n;
        else res = fib(memo,n-2) + fib(memo,n-1);
        memo[n] = res;
    }
    return memo[n];
}
int main(){
    vector<int> memo(6,-1);
    cout << fib(memo,5);
}