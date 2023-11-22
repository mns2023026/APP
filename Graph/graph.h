#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Graph_Node {
    int val;
    struct Graph_Node *next;
};

struct Graph_list {
    int number_of_nodes;
    struct Graph_Node **List;
};

struct Graph_list *init_graph(int n);
void add_edge(int source, int destination, int directed, struct Graph_list *gl);
void del_edge(int source, int destination, int directed, struct Graph_list *gl);
void print_graph(struct Graph_list *gl);

#endif /* GRAPH_H */
