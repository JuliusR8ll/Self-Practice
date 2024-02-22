#include<bits/stdc++.h>
using namespace std;

int main(){
    //priority_queue<int> pq;// max heap
    //priority_queue<int,vector<int>,greater<int>> pq;// min heap

    // pq.push(10);
    // pq.push(20);
    // pq.push(5);
    vector<int> v = {10,20,5};
    priority_queue<int> pq(v.begin(),v.end());
    cout << pq.size()<<endl;
    cout << pq.top() <<endl;
    while(pq.empty() == false){
        cout << pq.top()<<" ";
        pq.pop();
    }
    return 0;
}