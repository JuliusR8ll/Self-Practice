#include<bits/stdc++.h>
using namespace std;
vector<int> kSorted(vector<int> &v,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    int idx = 0;
    for(int i = 0;i<=k;i++){
        pq.push(v[i]);
    }
    v[idx++] = pq.top();
    pq.pop();
    for(int i = k+1;i<v.size();i++){
        pq.push(v[i]);
        v[idx++] = pq.top();
        pq.pop();
    }
    while(pq.empty() == 0){
        v[idx++] = pq.top();
        pq.pop();
    }
    return v;
}
int maxItem(vector<int> &v,int sum){
    priority_queue<int,vector<int>,greater<int>> pq(v.begin(),v.end());
    int res = 0;
    while(pq.empty() == 0 && pq.top() <= sum){
        res++;
        sum -= pq.top();
        pq.pop();
    }
    return res;
}
/*
void kLargestElements(vector<int> &v,int k){ // O(n + klogn)
    priority_queue<int> pq(v.begin(),v.end());
    while(k--){
        cout << pq.top()<< " ";
        pq.pop();
    }
}
*/
void kLargestElements(vector<int> &v,int k){ // O(k + (n-k)logk)
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0;i<k;i++){
        pq.push(v[i]);
    }
    for(int i = k;i<v.size();i++){
        if(v[i] > pq.top()){
            pq.pop();
            pq.push(v[i]);
        }
    }
    while(pq.size()){
        cout << pq.top() <<" ";
        pq.pop();
    }
}
void kClosestElements(vector<int> &v,int k,int x){
    priority_queue<pair<int ,int>> pq;
    for(int i = 0;i<k;i++){
        pq.push({abs(v[i] - x),i});
    }
    for(int i =k;i<v.size();i++){
        if((abs(v[i] - x)) < pq.top().first){
            pq.pop();
            pq.push({abs(v[i] - x),i});
        }
    }
    for(int i = 0;i<k;i++){
        cout << v[pq.top().second] <<" ";
        pq.pop();
    }
}
int main(){
    //priority_queue<int> pq;// max heap
    //priority_queue<int,vector<int>,greater<int>> pq;// min heap

    // pq.push(10);
    // pq.push(20);
    // pq.push(5);
    vector<int> v = {100,95,75,80,40,70,50,60};
    // priority_queue<int> pq(v.begin(),v.end());
    // cout << pq.size()<<endl;
    // cout << pq.top() <<endl;
    // while(pq.empty() == false){
    //     cout << pq.top()<<" ";
    //     pq.pop();
    // }
    //kSorted(v,4);
    //for(int x:v)cout <<x<<" ";
    //cout << maxItem(v,35);
    //kLargestElements(v,4);
    kClosestElements(v,3,80);
    return 0;
}