#ifndef GRAPH_
#define GRAPH_
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_
{
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct queueNode
{
    pnode data;
    int priority;
    struct queueNode *next;
} qnode;

typedef struct GRAPH_NODE_
{
    int node_num;
    pedge edges;
    int index; // for TSP
    struct GRAPH_NODE_ *next;

} node, *pnode;

//********* helper for create node and edge *********

pedge create_new_edge(int weight, pedge next, pnode dest);
pnode create_new_node(int k);
pnode new_node(int k, pnode next);
pnode find_node(int data, pnode head);
void del_out(pnode here);
void rem_src(int data, pnode here);
pnode insert_node(int data, pnode *head);

// ****** algo function *******
void shortest_path_algorithm(int *arr, pnode source);
void permutation(int *cities, int start, int end, int size_of_nodes, int *ans, pnode head);
void swap(int *a, int *b);

// ****** command function *******

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); // for self debug
void deleteGraph_cmd(pnode *head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

// ****** queue function *******

qnode *create_new_queue_node(pnode data, int p);
pnode pop(qnode **head);
void push(qnode **head, pnode d, int p);
int is_empty(qnode **head);
int peek(qnode **head);

#endif
