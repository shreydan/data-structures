#include "graph.h"

#include <iostream>

template <class T>
void Graph<T>::add_edge(T src, T dest, int weight) {
    tuple<T, T, int> edge = {src, dest, weight};
    edges.push_back(edge);
}

template <class T>
void Graph<T>::print_graph() {
}