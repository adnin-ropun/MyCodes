#include<bits/stdc++.h>
using namespace std;

class Graph{

    int V;
    list<int> *l;
public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }

    void addEdge(int i,int j,int undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"-> ";
            for(auto node:l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }

    void bfs(int source,bool dest=-1){
        queue<int> q;
        bool* visited=new bool[V]{0};
        int* dist=new int[V]{0};
        int* parent=new int[V];

        q.push(source);
        visited[source]=true;

        while(!q.empty()){

            int f=q.front();
            cout<<f<<endl;
            q.pop();

            for(auto nbr:l[f]){
                if(!visited[nbr]){
                    q.push(nbr);

                    parent[nbr]=f;
                    dist[nbr]=dist[f]+1;

                    visited[nbr]=true;
                }
            }

        }
        for(int i=0;i<V;i++){
            cout<<"Shortest dist to "<<i<<" is "<<dist[i]<<endl;
        }
        if(dest!=-1){
            int temp=dest;
            while(temp!=source){
                cout<<temp<<" -- ";
                temp=parent[temp];
            }
            cout<<source<<endl;
        }
    }
    void dfsHelper(int node, bool *visited){
        visited[node]=true;
        cout<<node<<",";

        for(int nbr:l[node]){
            if(!visited[nbr])
            dfsHelper(nbr,visited);
        }
    }
    void dfs(int source){
        bool* visited=new bool[V]{0};
        dfsHelper(source,visited);
    }

};

class Node{

public:
    string name;
    list<string> nbrs;
 
    Node(string name){
        this->name = name;
    }

};

class graph{
    unordered_map<string,Node*> m;
public:
    graph(vector<string> cities){
        for(auto city:cities){
            m[city]=new Node(city);
        }
    }

    void addEdge(string x,string y,bool undir=false){
        m[x]->nbrs.push_back(y);

        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjList(){
        for(auto cityPair:m){
            auto city=cityPair.first;
            Node* node=cityPair.second;
            cout<<city<<"->";

            for(auto nbr:node->nbrs){
                cout<<nbr<<",";            
            }
                cout<<endl;
        }

    }
};

int main(){

    Graph g(5);

    g.addEdge(1,2);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(0,2);
    g.addEdge(2,4);

    g.printAdjList();
    g.bfs(1,4);
    g.dfs(1);

    // vector<string>cities={"dhaka","sylhet","comilla","feni","chitagong"};
    // graph g(cities);

    // g.addEdge("dhaka","sylhet");
    // g.addEdge("dhaka","comilla");
    // g.addEdge("comilla","feni");
    // g.addEdge("feni","chitagong");

    // g.printAdjList();


}