#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main()
{
    char ch = 'q';
    pnode graph =NULL;
    while(ch != '\n' && !feof(stdin))
    {
        
        scanf("%c", &ch);
        while(ch == 'A')
        {
            deleteGraph_cmd(&graph);
            ch = build_graph_cmd(&graph);
            // printGraph_cmd(graph);
            // printf("\n");
        }

        if(ch == 'B')
        {
            insert_node_cmd(&graph);
        }

        if(ch == 'D')
        {
            delete_node_cmd(&graph);
        }
        
        if(ch == 'S')
        {
            int num1;
            int num2;
            scanf("%d %d",&num1 , &num2);
            int ans = shortsPath_cmd( graph, num1 , num2);
            if(ans == __INT_MAX__)
            {
                printf("Dijsktra shortest path: -1 \n");
            }
            else
            {
                printf("Dijsktra shortest path: %d \n",ans);
            }
        }

        if(ch == 'T')
        {
            int ans = TSP_cmd(graph);
            if(ans == __INT_MAX__)
            {
                printf("TSP shortest path: -1 \n");
            }
            else
            {
                printf("TSP shortest path: %d \n",ans);
            }
        }

    }
   deleteGraph_cmd(&graph); 
}