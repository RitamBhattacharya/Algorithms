#include<iostream>
using namespace std;

struct Edge{
    int v1, v2,weight;
};
struct Edge x[50];
int noe=0,nov;

int parent[10];
int Rank[10];
int adjMatrix[10][10];

void createGraph(){
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL){
        printf("File open failed\n");
        exit(1);
    }
    fscanf(fp,"%d",&nov);
    printf("nov=%d\n",nov);
    int i,j;
    for(i=0;i<nov;i++)
        for(j=0;j<nov;j++)
            fscanf(fp,"%d",&adjMatrix[i][j]);

    for(int i=0;i<nov;i++){
        for(int j=0;j<=i;j++){
            if(adjMatrix[i][j]!=0){
                x[noe].v1=i;
                x[noe].v2=j;
                x[noe++].weight=adjMatrix[i][j];
            }
        }
    }

    printf("noe=%d\n",noe);
}

void displayGraph(){
    int i;
    for(i=0;i<noe;i++){
        printf("%c->%c,%d\n",x[i].v1+'A',x[i].v2+'A',x[i].weight);
    }
}

void Sort(){
    int i,j;
    for(i=0;i<noe-1;i++){
        for(j=0;j<noe-1-i;j++){
            if(x[j].weight>x[j+1].weight){
                struct Edge temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }                
        }
    }
}

void  makeset(){
    for(int v=0;v<nov;v++){
        parent[v]=v;
        Rank[v]=0;
    }
}

int find(int i){
    if(parent[i]==i)
        return i;
    else
        return parent[i]=find(parent[i]);
}

void Union(int i,int j){
    int u=find(i);
    int v=find(j);
    if(Rank[u]<Rank[v])
        parent[u]=v;
    else if(Rank[v]<Rank[u])
        parent[v]=u;    
    else{
        parent[v]=u;
        Rank[u]++;
    }    
}

void Kruskal(){
    Sort();
    makeset();
    int Cost=0;

    for(int i=0;i<noe;i++){
        int v1=find(x[i].v1);
        int v2=find(x[i].v2);
        int wt=x[i].weight;

        if(v1!=v2){
            Union(v1,v2);
            printf("Edges[%c,%c] = %d \n",v1+'A',v2+'A',wt);
            Cost+=wt;
        }
    }
    cout<<"Minimum Cost= "<<Cost<<endl;
}

int main(void){
    createGraph();
    displayGraph();
    Kruskal();
    return 0;
}