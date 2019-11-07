#include "graph.h"
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>

#include<string.h>
#include<stdio.h>

Graph graph_new(uint32_t max)
{
	Graph graph;
	int i;
	graph.max_node=max;
	graph.neighbours=(Node**)malloc(graph.max_node*sizeof(Node*));

	for(i=0;i<graph.max_node;i++)
	{


		graph.neighbours[i]=NULL;
	
	}


	return graph;

}


static Node* _get_node_(int32_t data)
{



	Node *node=(Node*)malloc(sizeof(Node));
	node->nodeid=data;
	node->next=NULL;
	return node;

}


static int32_t _get_neighbour_(int32_t vertex)
{


	int32_t nodeid;
	printf("enter neighbour node of %d if no node enter 9999\n",vertex);
	scanf("%d",&nodeid);

	return nodeid;

}


Graph* graph_adjacency_list(Graph *graph)
{

	Node *vertex,*last_vertex;
	int32_t i,neighbour_id;
	for(i=0;i<graph->max_node;i++)
	{
		printf("\n\n");
		graph->neighbours[i]=_get_node_(i);
		neighbour_id=_get_neighbour_(i);
		while(neighbour_id !=9999)
		{

			vertex=_get_node_(neighbour_id);
			if(graph->neighbours[i]->next==NULL)
			{

				graph->neighbours[i]->next=vertex;
			}

			else
				
			{

				last_vertex->next=vertex;


			}
		last_vertex=vertex;
		neighbour_id=_get_neighbour_(i);

	}


	}


	return graph;
}



static void _dfs_(Graph *graph,int32_t v)
{


	Node *vertex;
	visited[v]=TRUE;

	printf("%d\t",v);

	for(vertex=graph->neighbours[v];vertex!=NULL;vertex=vertex->next)
	{

		if(!visited[vertex->nodeid])
		{
			_dfs_(graph,vertex->nodeid);
		}

	}



}

Graph* graph_dfs(Graph *graph , int32_t v)
{
	int i;

	for(i=0;i<graph->max_node;i++)
	{



		visited[i]=FALSE;

	}


	_dfs_(graph,v);

	return graph;
}


void main()
{

Graph g=graph_new(4);
graph_adjacency_list(&g);
graph_dfs(&g,0);


}
