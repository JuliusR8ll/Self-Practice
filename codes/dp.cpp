#include<bits/stdc++.h>
using namespace std;
// int fib(vector<int> &memo,int n){
//     if(memo[n] == -1){
//         int res;
//         if(n == 0 || n == 1)res = n;
//         else res = fib(memo,n-2) + fib(memo,n-1);
//         memo[n] = res;
//     }
//     return memo[n];
// }
int fib(int n){ // tabulation
    vector<int> v(n+1);
    v[0] = 0,v[1] = 1;
    for(int i = 2;i<n+1;i++){
        v[i] = v[i-1] +v[i-1];
    }
    return v[n];
}
int main(){
    //vector<int> memo(6,-1);
    cout << fib(5);
}