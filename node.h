typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    pnode prev;
    int weight;
    int info;
} node, *pnode;

void remove_edge(pnode pointN, int num);
pnode node_alloc(int num);
void free_node(pnode pointN);
void add_edge(pedge pointE, pnode pointN);
void remove_edges(pnode pointN);