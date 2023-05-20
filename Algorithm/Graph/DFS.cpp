#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int item){
        data=item;
        next=NULL;
    }
};

class stack{
    public:
    node* head;
    stack(){
        head=NULL;
    }

    int isEmpty(){
        if(head==NULL) return 1;
        return 0;
    }

    int peek(){
        return head->data;
    }

    void push(int item){
        node* ptr=new node(item);
        if(head==NULL){
            head=ptr;
            return;
        }
        ptr->next=head;
        head=ptr;
    }

    void pop(){
        head=head->next;
    }
};

int main(void){
    FILE* fp=NULL;
    fp=fopen("graph.txt","r");
    if(fp==NULL){
        cout<<"File open failed !! "<<endl;
        return 0;
    }
    int v;
    fscanf(fp,"%d",&v);

    int adjMatrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            fscanf(fp,"%d",&adjMatrix[i][j]);
        }
    }

    //Adjacency Matrix
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<adjMatrix[i][j]<<"  ";
        }
        cout<<endl;
    }

    //dfs
    cout<<"BFS ==> ";
    int vertex=0;
    int* visited=new int[v];
    for(int i=0;i<v;i++)
        visited[i]=0;
    visited[vertex]=1;
    stack s;
    s.push(vertex);
    while(!s.isEmpty()){
        vertex=s.peek();
        printf("%3c",vertex+'A');
        s.pop();
        
        for(int i=0;i<v;i++){
            if(adjMatrix[vertex][i]==1){
                if(visited[i]==0){
                    visited[i]=1;
                    s.push(i);
                }
            }
        }
    }    
    return 0;
}