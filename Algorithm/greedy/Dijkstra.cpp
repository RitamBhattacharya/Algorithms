#include<iostream>
using namespace std;

int nov;
int adjMatrix[20][20];
int dist[10];
int pred[10];
int sptSet[10];

void createGraph(){
    FILE* fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL){
        cout<<"File Open failed !! "<<endl;
        return;
    }
    fscanf(fp,"%d",&nov);
    //cout<<"No of vertices:"<<nov<<endl;
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
    int min=9999;
    int minIndex=-1;
    for(int i=0;i<nov;i++){
        if(sptSet[i]==0){
            if(dist[i]<min){
                min=dist[i];
                minIndex=i;
            }
        }
    }
    return minIndex;
}



void dijkstra(int r){
    for(int i=0;i<nov;i++){
        dist[i]=9999;
        pred[i]=-1;
        sptSet[1]=0;
    }
    dist[r]=0;
    for(int i=0;i<nov;i++){
        int u=minKey();
        sptSet[u]=1;
        for(int v=0;v<nov;v++){
            if(adjMatrix[u][v]!=0){
                if(sptSet[v]==0 && dist[u]+adjMatrix[u][v]<dist[v]){
                    dist[v]=dist[u]+adjMatrix[u][v];
                    pred[v]=u;
                }
            }
        }
    }
}


void showPath(int dest){
    if(dest==-1) return;
    else{
        showPath(pred[dest]);
        printf("%4c",dest+'A');
    }
}


int main(void){
    createGraph();
    displayGraph();

    dijkstra(0);
    for(int i=1;i<nov;i++){
        printf("Path From A to %c ::: ",i+'A');
        showPath(i);
        printf("\tcost=%d\n",dist[i]);
    }
    return 0;
}