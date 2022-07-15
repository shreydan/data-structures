#pragma once
#ifndef GRAPH
#define GRAPH
#include <bits/stdc++.h>

template <class T>
class Graph {
   private:
    map<int, tuple<T, T, int>> edges;

   public:
    void add_edge(T src, T dest, int weight);
    void print_graph();
};

#endif