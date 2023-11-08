//disc scheduling
#include<bits/stdc++.h>
using namespace std;

void sstf(vector<int>v,int x,vector<int>&a){
    map<int,int>m;
    int cnt=0;
    int curr=x;
    while(cnt!=v.size()){
        int min=INT_MAX;
        int r;
        for(int i=0;i<v.size();i++){
            if(m[v[i]]==0 and min>abs(v[i]-curr)){
                min=abs(v[i]-curr);
                r=v[i];
            }
        }
        cnt++;
        m[r]++;
        curr=r;
        a.push_back(curr);
    }
}

void scan(vector<int>v,int x, vector<int>&a,int end){
    v.push_back(x);
    v.push_back(end);
    sort(v.begin(),v.end());
    int cnt=-1;
    
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            cnt=i;
        }
        if(cnt!=-1){
            a.push_back(v[i]);
        }
    }
    
    for(int i=cnt-1;i>=0;i--){
            a.push_back(v[i]);
        
    }
}
void clook(vector<int>v,int x,vector<int>&a){
    v.push_back(x);
    sort(v.begin(),v.end());
    int cnt=-1;
    
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            cnt=i;
        }
        if(cnt!=-1){
            a.push_back(v[i]);
        }
    }
    
    for(int i=0;i<cnt;i++){
            a.push_back(v[i]);
    }
    
}
int main(){

    cout<<"Enter the number of requests"<<endl;
    int n;
    cin>>n;
    vector<int>v;

    cout<<"Enter the request sequence"<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<"Enter initial track position"<<endl;
    int x;
    cin>>x;
    
    
    vector<int>r;
    
    int choice;
    cout<<"1:sstf"<<endl;
    cout<<"2:scan"<<endl;
    cout<<"3:c-look"<<endl;
    cin>>choice;
    
    
    if(choice==1){
    sstf(v,x,r);
    for(int i=0;i<r.size();i++){
        cout<<r[i]<<" ";
    }
    cout<<endl;}
    else if(choice==2){
        cout<<"Enter the range of our"<<endl;
        int f;
        cin>>f;
        scan(v,x,r,f);
        
        for(int i=0;i<r.size();i++){
            cout<<r[i]<<" ";
        }
        cout<<endl;
    }
    else if(choice==3){
        clook(v,x,r);
        for(int i=0;i<r.size();i++){
            cout<<r[i]<<" ";
        }
        cout<<endl;
    }


}

