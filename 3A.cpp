//shortest remaining time first

#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter the total number of processes"<<endl;
    int p;
    cin>>p;
    int arrival_time[1000];
    int burst_time[1000];
    vector<pair<int,int>>pr;
    cout<<"Enter the Details of each process"<<endl;
    for(int i=0;i<p;i++){
        cout<<"Enter the arrival time of the process "<<i+1<<endl;
        cin>>arrival_time[i+1];
        cout<<"Enter the burst time of the process "<<i+1<<endl;
        cin>>burst_time[i+1];
    }
    vector<int>v;
    vector<int>gaant;
    int cnt=0;
    while(1){
        for(int i=0;i<p;i++){
            if(arrival_time[i+1]==cnt){
                v.push_back(i+1);
            }
        }
        int min=INT_MAX;
        int l=-1;
        for(int i=0;i<v.size();i++){
            if(burst_time[v[i]]<min and burst_time[v[i]]!=0){
                min=burst_time[v[i]];
                l=v[i];
            }
        }
        if(min==INT_MAX){
            break;
        }
        if(l!=-1){
            burst_time[l]--;
        }
        
        gaant.push_back(l);
        cnt++;
    }
    
    cout<<endl;
    cout<<"The Gaant Chart"<<endl;
    for(int i=0;i<gaant.size();i++){
        cout<<gaant[i]<<" ";
    }
    cout<<endl;
    cout<<gaant.size()<<endl;

    cout<<"completion time"<<endl;
    vector<int>completion;
    for(int i=0;i<p;i++){
        int xoor=-1;
        for(int j=gaant.size()-1;j>=0;j--){
            if(gaant[j]==i+1){
                xoor=j;
                break;
            }
        }
        cout<<"process "<<i+1<<" completion time: "<<xoor+1<<endl;
        completion.push_back(xoor+1);
    }
    //similarly u can find turn around time and waiting time



}

