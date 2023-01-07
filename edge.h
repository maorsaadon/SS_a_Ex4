
typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


pedge edge_alloc(int weight, pnode endpoint, pedge next);
void free_edge(pedge edge);