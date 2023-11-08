#include<bits/stdc++.h>
using namespace std;

void lru(vector<int>v,int frames){
    queue<int>q;
    map<int,int>m;
    for(int i=0;i<v.size();i++){
        if(q.size()!=frames and m[v[i]]==0){
            q.push(v[i]);
            m[v[i]]++;
        }
        else if(q.size()!=frames and m[v[i]]==1){
            vector<int>dq;

            while(q.empty()){
                if(q.front()!=v[i]){
                dq.push_back(q.front());
                }
                q.pop();
            }
            for(int j=0;j<dq.size();j++){
                q.push(dq[j]);
            }
            q.push(v[i]);
        }
        else if(q.size()==frames and m[v[i]]==0){
            m[q.front()]=0;
            q.pop();
            q.push(v[i]);
            m[v[i]]=1;

        }
        else if(q.size()==frames and m[v[i]]==1){
            vector<int>dq;

            while(q.empty()){
                if(q.front()!=v[i]){
                dq.push_back(q.front());
                }
                q.pop();
            }
            for(int j=0;j<dq.size();j++){
                q.push(dq[j]);
            }
            m[q.front()]=0;
            q.pop();
            q.push(v[i]);
        }
        cout<<"for "<<v[i]<<" ";
        vector<int>ans;

        while(!q.empty()){
            cout<<q.front()<<" ";
            ans.push_back(q.front());
            q.pop();
        }
        for(int k=0;k<ans.size();k++){
            q.push(ans[k]);
        }
    }
}
int main(){
    cout<<"Enter the total number of enteries"<<endl;
    int n;
    cin>>n;
    cout<<"Entert the enteries"<<endl;
    vector<int>v;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter the number of frames"<<endl;
    int frames;
    cin>>frames;
    lru(v,frames);
    
}