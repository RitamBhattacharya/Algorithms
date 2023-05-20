#include<iostream>
using namespace std;

void knapsack(double* profit,double* weight,int n,int w){
    int capacity=w;
    double totalProfit=0.0;
    int i;

    //knapsack logic
    for( i=0;i<n;i++){
        if(weight[i]>capacity)
            break;
        else{
            capacity=capacity-weight[i];
            totalProfit=totalProfit+profit[i];
        }    
    }    

    //if weight[i]>capacity then take the portion of it
    if(i<n)
        totalProfit+=profit[i] * (capacity/weight[i]);
    
    //print the total profit
    cout<<"Total Profit is :"<<totalProfit<<endl;
}

int main(void){
    int n,w;
    //input of the no of items
    cout<<"Enter the number of items:";
    cin>>n;

    double* profit=new double[n];
    double* weight=new double[n];

    //taking the inputs of profit[] and weight[]
    for(int i=0;i<n;i++){
        cout<<"Enter the profit of item #"<<i+1<<":";
        cin>>profit[i];
        cout<<"Enter the weight of item #"<<i+1<<":";
        cin>>weight[i];
    }

    //Input of the capacity of the sack
    cout<<"Enter the capacity of the knapsack:";
    cin>>w;

    //prepare the profit/weight array
    double* ratio=new double[n];
    for(int i=0;i<n;i++)
        ratio[i]=profit[i]/weight[i];

    //now sort the ratio[] in decreasing order and prepare profit[] and weight[] accordingly
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                swap(ratio[i],ratio[j]);
                swap(profit[i],profit[j]);
                swap(weight[i],weight[j]);
            }
        }
    }     
 
    //call the knapsack function
   knapsack(profit,weight,n,w);
    return 0;
}