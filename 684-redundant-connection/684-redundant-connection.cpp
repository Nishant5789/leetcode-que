class Solution 
{
    int parent[3005];
int size[3005];
void make( int v){
    parent[v]=v;
    size[v]=1;}
int find(int v){
    if(v==parent[v]){return v;}
    return parent[v]=find(parent[v]);
}
bool Union( int a, int b){
    a =find(a);
    b= find(b);
    if(a==b){return true;}
    parent[b]=a;
    return false;
}


public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
    int n= edges.size();
    for(int i=1;i<=n;i++){
        make(i);
    }
    for( auto edge: edges){
        if(Union(edge[0],edge[1])){
            return {edge[0],edge[1]};
        }
    }
    return {-1,-1};
    }
};