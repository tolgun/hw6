#include <iostream>
#include <vector>
#include <fstream>
#include <list>
using namespace std;

class Graph {
public:
    int numberNodes;
    vector< list<int> > outlist;
    vector< list<int> > inlist;
    Graph(string filePath) {
        ifstream ifs;
        int s;
        int t;
        ifs.open(filePath, std::ifstream::in);
        if (! ifs.is_open() ) {
            cout << "Failed to open the file" << endl;
        } else {
            cout << "File: OK" << endl;
        }
        ifs >> numberNodes;
        ifs >> s >> t;
        outlist.resize(numberNodes);
        inlist.resize(numberNodes);

        while (ifs.good()) {
            outlist[s].push_back(t);
            inlist[t].push_back(s);

            ifs >> s >> t;
        }
        ifs.close();
    }

     void GetInbound(int i) {
         cout << i << ". inbound: ";
        for(list<int>::iterator ip=outlist[i].begin(); ip!=outlist[i].end(); ip++) {
            cout << *ip << " " ;
        }
         cout << endl;
    }
    void GetOutbound(int i) {
        cout << i << ". outbound: ";
        for(list<int>::iterator ip=inlist[i].begin(); ip!=inlist[i].end(); ip++) {
            cout << *ip << " " ;
        }
        cout << endl;
    }
    // return degree of not just total but for particular node
    void Degree(vector< list<int> >& li){
        cout << "Size is " << li.size() << endl;
    }

    //Is neighbour fuction // either one node is pointing

//    bool Dfs(int target, int source, bool visited[]) {
//        visited[source] = true;
//        for (list<int>::iterator ip=outlist[source].begin(); ip!=outlist[source].end(); ip++) {
//            if (*ip == target) {
//                return true;
//            } else if (!visited[source]) {
//                visited[source] = true;
//                Dfs(target, *ip, false);
//            }
//        }
//    }

    void addEdge(int s, int t) {
        outlist[s].push_back(t);
        inlist[t].push_back(s);
    }

    int isReachable(int target, int source) {
        for (list<int>::iterator ip=outlist[source].begin(); ip!=outlist[source].end(); ip++) {
            if ( *ip == target) {
                return true;
            } else {
                isReachable(*ip, source);
            }
        }

    }

};

void PrintBounds(vector< list<int> > &outlist, vector< list<int> > &inlist) {
    for (int i = 0; i < outlist.size(); ++i) {
        cout << i << ": ";
        cout << " inbound size: " <<inlist[i].size() << " outbound size: " << outlist[i].size() << endl;
    }
}

void PrintThis(vector< list<int> > &outlist) {
    for (int i = 0; i < outlist.size(); ++i) {
        cout << i << ": ";
        for(list<int>::iterator ip=outlist[i].begin(); ip!=outlist[i].end(); ip++) {
            cout << *ip << " " ;
        }
        cout << endl;
    }
}


int main() {
    Graph graph("C:\\Users\\tugcan\\test.txt");
    cout << "#############################" << endl;
    PrintThis(graph.outlist);
    cout << "#############################" << endl;
    PrintThis(graph.inlist);
    cout << "#############################" << endl;
    PrintBounds(graph.inlist, graph.outlist);
    cout << "#############################" << endl;
    graph.GetInbound(0);
    graph.GetOutbound(3);
    graph.Degree(graph.outlist);
    if (graph.isReachable(0,2) ) {
        cout << "it's reachable" << endl;
    }


    return 0;
}