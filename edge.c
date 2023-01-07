#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


pedge edge_alloc(int weight, pnode endpoint, pedge next)
{
    pedge p = (pedge)(malloc(sizeof(edge)));
    if(p == NULL)
    {
        return NULL;
    }
    p -> weight = weight;
    p -> endpoint = endpoint;
    p -> next = next;
    return p;
}

void free_edge(pedge edge)
{
    free(edge);
}