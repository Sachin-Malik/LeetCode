
int N=1e5+9;
vector<int> parent[N];
vector<int> rank[N];

void makeSet(int x){
    parent[x]=x;
    rank[x]=0;
}
int findSet(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}
void unionSet(int a,int b){
   
    a=findSet(a);
    b=findSet(b);

    if(a!=b){

    if(rank[a]<rank[b])
      swap(a,b);
    
    parent[b]=a;

    if(rank[a]==rank[b])
      rank[a]++;

    }
}


