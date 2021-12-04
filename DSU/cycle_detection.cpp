#include<bits/stdc++.h>


using namespace std;



class Graph{
    int V;
    list<pair<int,int>>l;
    
public:
    Graph(int v){
        this->V = v;
    }

    int addEdge(int u,int v){
        l.push_back({u,v});
    }

    int findSet(int i,int parent[]){
        if(parent[i] == -1)return i;
        else return findSet(parent[i] , parent);
    }

    void union_set(int x,  int y,int parent[]){
        int parent1 = findSet(x,parent);
        int parent2 = findSet(y,parent);
        if(parent1 != parent2){
            parent[y] = x; 
        }
    }

    bool contains_cycle(){
        int parent[V + 1];
        memset(parent,-1,sizeof(parent));
        for(auto edge : l){
            int x = edge.first;
            int y = edge.second;

            int s1 = findSet(x,parent);
            int s2 = findSet(y,parent);
            if(s1 != s2){
                union_set(s1,s2,parent);
            }else{
                retur true;
            }
        }
        
        return false;

    }


}