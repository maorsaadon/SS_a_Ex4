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


pedge edge_alloc(int weight, pnode endpoint, pedge next);
void free_edge(pedge edge);

void remove_edge(pnode pointN, int num);
pnode node_alloc(int num);
void free_node(pnode pointN);
void add_edge(pedge pointE, pnode pointN);
void remove_edges(pnode pointN);

pnode find_node(pnode tempgr, int num);
char build_graph_cmd(pnode * head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void set_defult_value(pnode other);
pnode min_not_visited(pnode other);
void dijkstra_algo(pnode other ,int num);
int shortsPath_cmd(pnode head, int num1 , int num2);
int TSP_cmd(pnode head);
void TSP_helper_cmd(pnode head, int *arr,int num, int curr,int *pmin);