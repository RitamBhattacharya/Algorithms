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

class queue{
    public:
    node* head;
    queue(){
        head=NULL;
    }

    int isEmpty(){
        if(head==NULL) return 1;
        return 0;
    }

    int peek(){
        return head->data;
    }

    void insert(int item){
        node* ptr=new node(item);
        if(head==NULL){
            head=ptr;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=ptr;
    }

    void del(){
        head=head->next;
    }
};


int main(void){
    //Taking input from file
    FILE* fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL){
        cout<<"File openning Failed !! "<<endl;
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

    cout<<"Adjacency Matrix => "<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            printf("%-3d",adjMatrix[i][j]);
        cout<<endl;
    }    

    //BFS
    cout<<"BFS => ";
    int vertex=0;

    int* visited=new int[v];
    for(int i=0;i<v;i++)
        visited[i]=0;

    queue q;
    visited[vertex]=1;

    q.insert(vertex);
    while(!q.isEmpty()){
        vertex=q.peek();
        printf("%-3c",vertex+'A');
        q.del();

        for(int i=0;i<v;i++){
            if(adjMatrix[vertex][i]==1){
                if(visited[i]==0){
                    visited[i]=1;
                    q.insert(i);
                }
            }
        }
    }
    return 0;
}