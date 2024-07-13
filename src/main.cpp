#include <iostream>

#include "AdjacencyList.h"


using namespace std;

int main() {
    AdjacencyList graph;
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;
    map<string,int> conversion;


    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        // Do Something

        graph.InsertEdge(from, to);
    }
    graph.PageRank(power_iterations);

    // Created_Graph.PageRank(power_iterations);}
}
