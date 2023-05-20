#include<bits/stdc++.h>
using namespace std;

void JSD(string* name,int* profit,int* deadline,int n){
    int totalProfit=0;
    string* names=new string[n];

    // find the maximum deadline
    int max=INT_MIN;
    for(int i=0;i<n;i++)
        if(deadline[i]>max)
            max=deadline[i];

    // create a slot array and initialise with 0
    int* slot=new int[max];
    for(int i=0;i<max;i++)
        slot[i]=0;

    //JSD logic
    for(int i=0;i<n;i++){
        for(int j=deadline[i]-1;j>=0;j--){
            if(slot[j]==0){
                slot[j]=1;
               names[j]=name[i];
                totalProfit+=profit[i];
                break;
            }
        }
    }
    cout<<"Jobs are to be done in the order:";
    for(int i=0;i<n;i++) cout<<names[i]<<"  ";
    cout<<"\nTotal Profit = "<<totalProfit<<endl;
}

int main(void){
    int n;
    cout<<"Enter the No of jobs:";
    cin>>n;

    int* profit=new int[n];
    int* deadline=new int[n];
    string* name=new string[n];

    //I/P of name[] , profit[] and deadline[]
    for(int i=0;i<n;i++){
        cout<<"Enter the name of job #"<<i+1<<":";
        cin>>name[i];
        cout<<"Enter the profit of job #"<<i+1<<":";
        cin>>profit[i];
        cout<<"Enter the deadline of job #"<<i+1<<":";
        cin>>deadline[i];
    }

    //sort w r to profit
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(profit[i]<profit[j]){
                swap(profit[i],profit[j]);
                swap(deadline[i],deadline[j]);
                swap(name[i],name[j]);
            }
        }
    }
  

    JSD(name,profit,deadline,n);
    return 0;
}