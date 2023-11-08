//shortest remaining time first

#include<bits/stdc++.h>
using namespace std;
int main(){
    // cout<<"Enter the total number of processes"<<endl;
    int p;
    cin>>p;
    int arrival_time[1000];
    int burst_time[1000];
    vector<pair<int,int>>pr;
    // cout<<"Enter the Details of each process"<<endl;
    int sum=0;
    for(int i=0;i<p;i++){
        // cout<<"Enter the arrival time of the process "<<i+1<<endl;
        cin>>arrival_time[i];
        // cout<<"Enter the burst time of the process "<<i+1<<endl;
        cin>>burst_time[i];
        sum=sum+burst_time[i];
    }
    vector<int>gaant;
    map<int,int>m;
    int time=0;
    int cnt=0;
    int r=0;
    int min=-1;
    int fuck=0;
    int l=-1;
    while(1){
        for(int i=0;i<p;i++){
            if(time==arrival_time[i]){
                m[i]++;
            }
            }
            if(cnt==0){
                min=INT_MAX;
                 l=-1;
                for(int j=0;j<p;j++){
                    if(burst_time[j]<min and m[j]==1){
                        min=burst_time[j];
                        l=j;
                    }
                }
                fuck++;
                m[l]++;
                cnt=1;
            }
            min--;
            if(min==0){
                cnt=0;
            }
            gaant.push_back(l+1);

        time++;
        if(sum==time){
            break;
        }
        }

        for(int i=0;i<gaant.size();i++){
            cout<<gaant[i]<<" ";
        }
        cout<<endl;
    }




