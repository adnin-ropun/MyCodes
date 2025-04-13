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

    // vector<string>cities={"dhaka","sylhet","comilla","feni","chitagong"};
    // graph g(cities);

    // g.addEdge("dhaka","sylhet");
    // g.addEdge("dhaka","comilla");
    // g.addEdge("comilla","feni");
    // g.addEdge("feni","chitagong");

    // g.printAdjList();


}