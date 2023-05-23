#include<iostream>
using namespace std;

void display(int arr[], int n) {
    for(int i=1;i<=n;i++) {
        printf("%-3d",arr[i]);
    }
    cout<<endl;
}

bool placeQueen(int* x,int k,int i){
    for(int j=1;j<=k-1;j++){
        if(x[j]==i || abs(j-k)==abs(x[j]-i))
            return false;
    }
    return true;
}
int c=0;
void nQueen(int* x,int k,int n){
    // k row no         n col no
    for(int i=1;i<=n;i++){
        if(placeQueen(x,k,i)){
            x[k]=i;
            if(k==n){
                c++;
                display(x,n);
            }
            else{
                nQueen(x,k+1,n);
            }
        }
    }
}

int main(void){
    int n;
    cout<<"Enter the no of queens:";
    cin>>n;
    int* arr=new int[n+1];
    for(int i=0;i<n;i++)
        arr[i]=0;
    nQueen(arr,1,n);    
    return 0;
}