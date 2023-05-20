#include<iostream>
using namespace std;

int nov;
int adjMatrix[20][20];
int dist[20][20];
int pred[20][20];

void readGraph(){
    FILE* fp;
    fp=fopen("graph_floyd.txt","r");
    if(fp==NULL){
        cout<<"File Open unsucessful !! "<<endl;
        return;
    }
    fscanf(fp,"%d",&nov);

    for(int i=0;i<nov;i++)
        for(int j=0;j<nov;j++)
            fscanf(fp,"%d",&adjMatrix[i][j]);
   fclose(fp);         
}

void displayGraph(){
    for(int i=0;i<nov;i++){
        for(int j=0;j<nov;j++)
            cout<<adjMatrix[i][j]<<"\t";
        cout<<endl;    
    }
}

void Floyd(){
    for(int i=0;i<nov;i++){
        for(int j=0;j<nov;j++){
            dist[i][j]=adjMatrix[i][j];
            if(adjMatrix[i][j]==0 || adjMatrix[i][j]==999)
                pred[i][j]=-1;
            else
                pred[i][j]=i;    
        }
    }

    for(int k=0;k<nov;k++){
        for(int i=0;i<nov;i++){
            for(int j=0;j<nov;j++){
                if(dist[i][k]!=999 && dist[k][j]!=999){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                        pred[i][j]=pred[k][j];
                    }
                }
            }
        }
    }
}

void APSP(int i,int j){
    if(i==j)
       printf("%c\t",i+'A');
    else if(pred[i][j]==-1)
        cout<<"No Path"<<endl;
    else{
        APSP(i,pred[i][j]);
        printf("%c\t",j+'A');
    }    
    
}

int main(void){
    char s,d;

    readGraph();
    displayGraph();

    Floyd();
    cout<<"Enter the source vertex:";
    cin>>s;
    cout<<"Enter the destination vertex:";
    cin>>d;
    cout<<"Path is:";
    APSP(s-'A',d-'A');
    return 0;
}