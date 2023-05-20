#include<iostream>
using namespace std;
int nov;
int adjMatrix[20][20];
int key[10];
int parent[10];
int mstSet[10];

void createGraph(){
    FILE* fp;
    fp=fopen("graph.txt","r");
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

int minKey(){
    int min=999;
    int minIndex=-1;
    for(int i=0;i<nov;i++){
        if(mstSet[i]==0){
            if(key[i]<min){
                min=key[i];
                minIndex=i;
            }
        }
    }
    return minIndex;
}

void prims(int r){
    for(int i=0;i<nov;i++){
        key[i]=999;
        parent[i]=-1;
        mstSet[i]=0;
    }

    key[r]=0;
    for(int i=0;i<nov;i++){
        int u=minKey();
        mstSet[u]=1;
        for(int v=0;v<nov;v++){
            if(adjMatrix[u][v]!=0){
                if(mstSet[v]==0 && key[v]>adjMatrix[u][v]){
                    key[v]=adjMatrix[u][v];
                    parent[v]=u;
                }
            }
        }
    }
}

void showTree(){
    for(int i=0;i<nov;i++){
        if(parent[i]!=-1){
            printf("[%c,%c] , %d\n",parent[i]+'A',i+'A',adjMatrix[parent[i]][i]);
        }
    }
}

int main(void){
    createGraph();
    displayGraph();

    prims(0);
    showTree();
    return 0;
}