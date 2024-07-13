#include <iomanip>
#include <iostream>


#include "AdjacencyList.h"

using namespace std;

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
void AdjacencyList::PageRank(int n){
    //First create Ranks by setting pageRanks to 1/dj and r(0) to 1/|V|
    vector<float> rt;



    int j = 0;
    for(auto &it: List) {
        rt.push_back(1.0/float(this->getV()));
        it.second.first.updateOrder(j);

        j++;
    }


    //Matrix multiplication
    vector<float> temp;
    float t = 0;
    for(int i = 0; i < n - 1; i++) {
        for(auto& it: List) {
            float x = 0;
            for(auto& z: List) {

                for(auto& w: z.second.second) {
                    if (w.Name() == it.second.first.Name() && z.second.first.Name() != it.second.first.Name()) {
                        x += rt[z.second.first.getOrder()] * float(1.0/z.second.first.getO());

                        t = x;
                    }
                }


            }
            if(t > 0) {
                temp.push_back(t);
            }
        }
        for(unsigned int x = 0; x < temp.size(); x++) {
            rt[x] = temp[x];
        }
        temp.clear();
    }




    for(auto& it : List) {
        cout << it.second.first.Name() << " " << fixed << setprecision(2) <<rt[it.second.first.getOrder()] << endl;
    }


    // optionally, store your output in a string/stringstream and then return it from this function after printing so that it is easier to test with Catc

    // do your page rank


}

void AdjacencyList::InsertEdge(string &from, string &to) {
    //Taken from Adjacacency List Implementation
    Vertex vFrom(from);
    Vertex vTo(to);
    //Adds to the map if it hasn't been added before
    if(List.find(from) == List.end()) {
        List[from].first = vFrom;
        updateV();
    }
    if(List.find(to) == List.end()) {
        List[to].first = vTo;
        updateV();
    }
    //Push back the vertexes and update the outDegree for each
    List[from].second.push_back(vTo);
    List[from].first.updateOut();

}



void AdjacencyList::updateV() {
    this->numVertex++;
}

int AdjacencyList::getV() {
    return this->numVertex;
}

