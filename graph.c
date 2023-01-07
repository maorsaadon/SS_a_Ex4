#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


pnode find_node(pnode tempgr, int num)
{
    while(tempgr!=NULL)
    {
        if(tempgr->node_num == num)
        {
            return tempgr;
        }
        tempgr=tempgr->next;
    }
    return tempgr;
}

void insert_node_cmd(pnode *head)
{
    int num;
    int dist;
    int weight;
    scanf("%d", &num);
    pnode pointN = find_node(*head, num);
    if(pointN == NULL)
    {
        pointN = node_alloc(num);
        pointN->next=(*head);
        *head = pointN;
    }
    else{
    remove_edges(pointN);
    }
    while((!feof(stdin)) && (scanf("%d" , &dist)))
    {
        scanf("%d", &weight);
        pnode tempn = find_node(*head, dist);
        add_edge(edge_alloc(weight,tempn,NULL), pointN);
    }
}
void delete_node_cmd(pnode *head)
{
    int num;
    pnode startnode;
    scanf("%d",&num);
    if((*head)==NULL)
    {
        return;
    }
    if((*head)->node_num == num)
    {
        startnode = *head;
        *head=(*head)->next;
    }
    else
    {
        startnode = *head;
        pnode temp = (*head)->next;
        while(temp!=NULL)
        {
            if(temp->node_num == num)
            {
                startnode->next=temp->next;
                startnode = temp;
                break;
            }
            else
            {
                startnode= startnode->next;
                temp = temp->next;
            }
        }
    }
    pnode runnodes = *head;
    while(runnodes!=NULL)
    {
        remove_edge(runnodes,num);
        runnodes=runnodes->next;
    }
    free_node(startnode);
}
void printGraph_cmd(pnode head) //for self debug
{
    
    while(head!=NULL)
    {
        printf("%d :", head->node_num);
        if(head->prev!=NULL)
        {
            printf("prev %d", head->prev->node_num);
        }
        printf(" weigth %d", head->weight);
        printf(" info %d\n", head->info);
        pedge pointE= head->edges;
        while(pointE!=NULL)
        {
            printf("%d - ", pointE->endpoint->node_num);
            printf("%d  ", pointE->weight);
            pointE = pointE->next;
        }
        printf("\n");
       head = head->next; 
    }
}

void deleteGraph_cmd(pnode* head)
{
    pnode temp;
    while((*head) != NULL)
    {
        temp = (*head)->next;
        free_node((*head));
        *head = temp;
    }
}

char build_graph_cmd(pnode * head)
{
    char ch = 0;
    int size;
    int node_src;
    int weight;
    int node_dest;
    pnode src;
    pnode dest;
    pedge edge = NULL;

    if((*head) != NULL)
    {
        deleteGraph_cmd(head);
    }

    scanf("%d", &size);
    (*head)= node_alloc(--size);

    if((*head) == NULL)
    {
        return 'A';
    }

    while(size != 0)
    {
        pnode temp = node_alloc(--size);
        temp->next = (*head);
        (*head) = temp;
    }

    while(ch != '\n' && !feof(stdin) && ch != 'B' && ch != 'D' && ch != 'S' && ch != 'T' && ch != 'A')
    {
        scanf("%c", &ch);
        if(ch == 'n')
        {
            scanf("%d", &node_src);
            src = find_node((*head), node_src);
            while((!feof(stdin)) && scanf("%d", &node_dest))
            {
                dest = find_node((*head), node_dest);
                scanf("%d", &weight);
                edge = edge_alloc(weight, dest, edge);
                add_edge(edge, src);
            }
        }
    }
    return ch;
}
void set_defult_value(pnode other)
{
    while(other!=NULL)
    {  
        other->prev = NULL;
        other->info = 0;
        other-> weight = __INT_MAX__;
        other = other->next;
    }
}
pnode min_not_visited(pnode other)
{
    pnode ans = NULL;
    while(other!=NULL)
    {
        if(other->info == 0)
        {
            if(other->weight!=__INT_MAX__)
            {
                if(ans == NULL)
                {
                    ans = other;
                }
                if(other->weight<ans->weight)
                {
                    ans = other;
                }
            }
        }
        other = other->next;
    }
    return ans;
}
void dijkstra_algo(pnode other ,int num)
{
    set_defult_value(other);
    pnode runNod = find_node(other, num);
    runNod->weight = 0;
    while(runNod!=NULL)
    {
        runNod->info = 1;
        pedge nedges = runNod->edges;
        while(nedges!=NULL)
        {
            pnode destN = nedges->endpoint;
            if(destN->info==0)
            {
                if((destN->weight)>((runNod->weight)+(nedges->weight)))
                {
                    destN->weight = ((runNod->weight)+(nedges->weight));
                    destN->prev = runNod;
                }
            }
            nedges = nedges->next;
        }
        runNod = min_not_visited(other);

    }


}
int shortsPath_cmd(pnode head,int num1,int num2)
{
    
    dijkstra_algo(head,num1);
    pnode ans = find_node(head, num2);
    if(ans == NULL)
    {
        return __INT_MAX__;
    }
    else
    {
        if(ans->weight == __INT_MAX__)
        {
            return __INT_MAX__;
        }
        else
        {
            return ans->weight;
        }
    }
}
void swap_place(int *arr, int num1, int num2)
{
    int temp = arr[num1];
    arr[num1]=arr[num2];
    arr[num2]=temp;
}
int TSP_cmd(pnode head)
{
    int num;
    scanf("%d", &num);
    int *arr = (int*)(malloc(sizeof(int)*num));
    int min = __INT_MAX__;
    int * pmin=&min;
    for(int i =0 ; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<num;i++)
    {
        swap_place(arr,0,i);
        TSP_helper_cmd(head,arr,num,0,pmin);
        swap_place(arr,i,0);
    }
    free(arr);
    return *pmin;
}
void TSP_helper_cmd(pnode head, int *arr,int num, int curr,int *pmin)
{
    if(num==2)
    {
        int finshdist = shortsPath_cmd(head,arr[0],arr[1]);
        if(finshdist!=__INT_MAX__)
        {
            if((curr + finshdist)<*pmin)
            {
                *pmin = (curr+finshdist);
            }
        }
        return;
    }
    for(int i=1;i<num;i++)
    {
        swap_place(arr,1,i);
        int dist = shortsPath_cmd(head,arr[0],arr[1]);
        if(dist==__INT_MAX__)
        {
            return;
        }
        TSP_helper_cmd(head,arr+1,num-1,curr+dist,pmin);
        swap_place(arr,i,1);
    }
}