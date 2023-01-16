#ifndef HEADER_
#define HEADER_


typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    pnode prev;
    int weight;
    int info;
} node, *pnode;

/* node Header */
void remove_edge(pnode pointN, int num);
pnode node_alloc(int num);
void free_node(pnode pointN);
void add_edge(pedge pointE, pnode pointN);
void remove_edges(pnode pointN);

/* edge Header */
pedge edge_alloc(int weight, pnode endpoint, pedge next);
void free_edge(pedge edge);


/* graph Header */
char build_graph_cmd(pnode * head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
int shortsPath_cmd(pnode head, int num1 , int num2);
int TSP_cmd(pnode head);

void dijkstra_algo(pnode other ,int num);
void set_defult_value(pnode other);
pnode find_node(pnode tempgr, int num);
pnode min_not_visited(pnode other);
void TSP_helper_cmd(pnode head, int *arr,int num, int curr,int *pmin);
void swap_place(int *arr, int num1, int num2);

#endif