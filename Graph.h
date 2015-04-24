
#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct queueVertex{
    int distance; //total path distance
    std::vector<vertex*> path; //path including all the cities on that path
};

struct adjVertex{
    vertex *v; //storing a pointer to the vertex
    int weight; //distance between the two vertices
};

struct vertex{
    std::string name; //city name
    std::vector<adjVertex> adj; //vector of all the city's adjacent cities
    bool visited; //for the findShortestDistance method, whether the city has been checked or not
    int distance; //for the findShortestDistance method, keeps track of the total path distance
    vertex* previous; //for the findShortestDistance method
    bool chargeStation; //whether the city has a charging station or not
};

struct car{
    std::string model; //car model name
    int batRange; //battery range in miles of the car

    car(std::string m, int br){
        model = m;
        batRange = br;
    }
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void setCharge(std::string name, bool charge);
        void setBatteryRange(int range);
        void displayEdges();
        void planTrip(std::string v1, std::string v2); //called to plan the whole trip
        void findShortestPath(std::string v1, std::string v2); //not sure we need this method
        int findShortestDistance(std::string v1, std::string v2); //might want this to return the path, not the distance?
        bool compareDistances(int pathDist);
        //some method to determine whether cities along the given path have charging stations
    protected:
    private:
        std::vector<vertex> vertices;
        int batteryRange;
        std::vector<vertex> path; //to keep track of shortest distance path without having to print it out
                                    //in case the car cannot make it - need something to check for charging stations

};

#endif // GRAPH_H

