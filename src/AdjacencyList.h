#pragma once

#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

//Use to store vertex data
struct Vertex {
private:
    float pageRank = 0.0f;
    int in = 0;
    int order = 0;
    string name = "";
public:

    int out;
    Vertex() = default;

    Vertex(string& _name) {
        in = 0;
        out = 0;
        pageRank = 0;
        name = _name;
    }
    //Returns Name to help with Print function
    string Name() {
        return name;
    }
    //Updates the outDegree of the Vertex
    void updateOut() {
        out++;
    }
    void updatePageRank(float x) {
        pageRank += x;
    }
    float getPR() {
        return pageRank;
    }
    void updateOrder(int x) {
        order = x;
    }
    int getOrder() {
        return order;
    }
    int getO() {
        return out;
    }

};

class AdjacencyList {
    private:
    //Taken from Lecture 7 Adjacency List Implementation
    int numVertex = 0;
    map<string, pair<Vertex,vector<Vertex>>> List;

    public:
    //Think about what helper functions you will need in the algorithm
    void PageRank(int n);

    //Default Constructor
    AdjacencyList()  {
        this->numVertex = 0;
    };


    //Insert lists into the map
    void InsertEdge(string& from, string& to);
    //Helps Visualize the Adjacency List
    void Print();
    void updateV();
    int getV();

};

// This class and method are optional.
