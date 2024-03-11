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
struct Triplet{
    int val,apos,vpos;
    Triplet(int v,int ap,int vp){
        val = v;apos = ap;vpos = vp;
    }
};
struct MyCmp{
    bool operator()(Triplet &t1,Triplet &t2){
        return t1.val > t2.val;
    }
};
void mergeKsortedArray(vector<vector<int>> &v){
    priority_queue<Triplet,vector<Triplet>,MyCmp> pq;
    int k = v.size();
    for(int i = 0;i<k;i++){
        Triplet t(v[i][0],i,0);
        pq.push(t);
    }
    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top().val);
        int ap = pq.top().apos;
        int vp = pq.top().vpos;
        pq.pop();
        if(v[ap].size()>++vp){
            Triplet t(v[ap][vp],ap,vp);
            pq.push(t);
        } 
    }
    for(int i = 0;i<res.size();i++){
        cout << res[i] <<" ";
    }
}
void streamMedian(vector<int> &v){
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    vector<double> res;
    for(int &x:v){
        if(pq1.empty()){
            pq1.push(x);
        }
        else if(pq1.size() > pq2.size()){
            if(pq1.top() > x){
                pq1.push(x);
                pq2.push(pq1.top());
                pq1.pop();
            }
            else
                pq2.push(x);
        }
        else{
            if(pq2.top() < x){
                pq2.push(x);
                pq1.push(pq2.top());
                pq2.pop();
            }
            else
                pq1.push(x);
        }
        ((pq1.size() + pq2.size())%2)? res.push_back(pq1.top()) : res.push_back((double)(pq1.top() + pq2.top())/2.0);
    }
    for(int i = 0;i<res.size();i++){
        cout << res[i] <<" ";
    }
}
int main(){
    //priority_queue<int> pq;// max heap
    //priority_queue<int,vector<int>,greater<int>> pq;// min heap

    // pq.push(10);
    // pq.push(20);
    // pq.push(5);
    vector<int> v = {20,10,30,7};
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
    //kClosestElements(v,3,80);
    vector<vector<int>> vec = {{1,5},{2,8,9},{4,6,8,9}};
    //cout << vec.size() <<" "<< vec[2].size(); 
    //mergeKsortedArray(vec);
    streamMedian(v);
    return 0;
}