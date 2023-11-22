#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Graph_Node{
	int val;
	struct Graph_Node *next;
};

struct Graph_list{
	int number_of_nodes;
	struct Graph_Node ** List;
};


struct Graph_list * init_graph(int n)
{
	struct Graph_list * gl = (struct Graph_list *) malloc (sizeof(struct Graph_list));
	if (gl == NULL) {
        perror("Can't acquire memory");
        exit(1);
    }
	gl -> number_of_nodes = n;
	gl -> List = (struct Graph_Node **) malloc (n * sizeof(struct Graph_Node*));

	for (int i = 0; i < n; i++) {
		gl->List [i] = NULL;
	}

	return gl;
}

void add_edge(int source, int destination, int directed, struct Graph_list *gl)
{

	struct Graph_Node * cn = (struct Graph_Node *) malloc (sizeof(struct Graph_Node));
	cn->val = destination;
	cn->next = gl -> List[source];
 	gl -> List[source] =  cn;

	if (!directed) {
		struct Graph_Node *cn2 = (struct Graph_Node *) malloc (sizeof(struct Graph_Node));
		cn2->val = source;
		cn->next = gl -> List[destination];
 		gl -> List[destination] =  cn;


	}
}

void del_edge(int source, int destination,int directed,struct Graph_list *gl)
{

	struct Graph_Node * cn =  gl -> List[source];
	struct Graph_Node * tmp =  NULL;

	if (cn -> val == destination) {
		gl->List[source] = cn -> next;
	}
	else {
		tmp =  cn;
		cn= cn->next;

		while(cn) {

			if( cn ->val ==  destination) {
				tmp  ->next = cn->next;
				break;
			}

			tmp = cn;
			cn = cn -> next;
		}
	}

	if(!directed)
	{
		del_edge(destination , source , 0, gl);
	}

}

void print_graph(struct Graph_list * gl)
{
	printf("-----------Graph----------\n");
	for(int i=0; i< gl-> number_of_nodes; i++)
	{
		struct Graph_Node * cn =  gl -> List[i];

		printf("%d -",i);
		while(cn) {
			printf("%d ",cn->val);
			cn = cn-> next;
		 }
		printf("\n");
	}
	printf("---------------------------\n");
}

// void main()
// {
// 	int n;
// 	struct Graph_list * gh =  init_graph(3);
// 	add_edge(1,2,1,gh);
// 	print_graph(gh);
// 	del_edge(1,2,1,gh);
// 	print_graph(gh);
	

// }
