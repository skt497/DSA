#ifndef _INCLUDED_GRAPH_
#define _INCLUDED_GRAPH_

#include<stdint.h>
#define MAX 20
#define TRUE 1
#define FALSE 0

typedef struct graph_node Node;
typedef struct graph_list_ Graph;

struct graph_node
{

int32_t nodeid;
Node *next;

};
uint32_t visited[MAX]={0};
struct graph_list_ {



	uint32_t max_node;
	Node **neighbours;
};

Graph graph_new(uint32_t size);

Graph* graph_adjacency_list(Graph *graph);
Graph* graph_dfs(Graph *graph,int32_t v);

#endif
