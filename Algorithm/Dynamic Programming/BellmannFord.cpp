#include<iostream>
using namespace std;

int nov,noe=0;
int adjMatrix[20][20];
int dist[20];
int pred[20];

struct Edge{
    int v1,v2,weight;
};

struct Edge x[20];

void readGraph(){
    FILE* fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL){
        cout<<"Graph open failed !! "<<endl;
        return;
    }
    fscanf(fp,"%d",&nov);
    for(int i=0;i<nov;i++){
        for(int j=0;j<nov;j++)
            fscanf(fp,"%d",&adjMatrix[i][j]);
    }

    for(int i=0;i<nov;i++){
        for(int j=0;j<nov;j++){
            if(adjMatrix[i][j]!=0){
                x[noe].v1=i;
                x[noe].v2=j;
                x[noe++].weight=adjMatrix[i][j];
            }
        }
    }
    noe/=2;
    cout<<"Total Edge : "<<noe<<endl;

    fclose(fp);
}

void showGraph(){
    for(int i=0;i<noe;i++)
        printf("[%c , %c] , %d\n",x[i].v1+'A',x[i].v2+'A',x[i].weight);
}



void bellmannFord(int r){
    for(int i=0;i<nov;i++){
        dist[i]=999;
        pred[i]=-1;
    }
    dist[r]=0;
    for(int i=1;i<nov;i++){
        for(int j=0;j<noe;j++){
            int u=x[j].v1;
            int v=x[j].v2;
            if(dist[u]+adjMatrix[u][v]<dist[v]){
                dist[v]=dist[u]+adjMatrix[u][v];
                pred[v]=u;
            }
        }
    }
}

void showPath(int i){
    if(i==-1) return;
    else{
        showPath(pred[i]);
        cout<<"    "<<(char)(i+'A');
    }
}


int main(void){
    readGraph();
    showGraph();   

    bellmannFord(0);
    for(int i=1;i<nov;i++){
        printf("Path from A to %c ::",i+'A');
        showPath(i);
        printf("\t cost = %d\n",dist[i]);
    }
    return 0;
}