#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

struct node_t{
	int val;
	std::vector<node_t*> bridge_to;
	// minimum distance from starting point
	int node_min_distance;

	node_t* last_node;
	//node(int val_l){val = val_l;}

	node_t() : node_min_distance(100000){}

	inline bool operator==(node_t a)
	{
		if(a.val == val)
			return true;
		else
			return false;
	}
};

int main() {

	int test_cases;

	std::cin >> test_cases;
	for (int i=0; i<test_cases; i++)
	{
#ifdef LOG
		printf("%d test case.\n", i);	
#endif
		int n_islands; int m_bridges;
		scanf("%d %d", &n_islands, &m_bridges);
#ifdef LOG
		printf("got %d islands, %d bridges\n", n_islands, m_bridges);
#endif

		std::vector<node_t> nodes;
		for (int j=1; j<=n_islands; j++)
		{
			node_t new_node;
			new_node.val = j;
			nodes.push_back(new_node);
		}
		nodes[0].last_node = NULL;
		for (int j=0; j<m_bridges; j++)
		{
			int from=0;
			int to = 0;
			scanf("%d %d", &from, &to);
			nodes[from-1].bridge_to.push_back(&(nodes[to-1]));
			nodes[to-1].bridge_to.push_back(&(nodes[from-1]));
#ifdef LOG
			printf("inserted bridge between %d and %d.\n", from, to);
#endif
		}

#ifdef GRAPH_ONLY
		continue;
#endif

#ifdef LOG
		printf("starting exploration.\n");
#endif

		std::stack<node_t*> bfs_stack;
		bfs_stack.push(&nodes[0]);
		node_t* finish_node = &nodes[nodes.size()-1];
		node_t* start_node = &nodes[0];

		start_node->node_min_distance = 0;

		while(!bfs_stack.empty())
		{
			node_t* curr_node = bfs_stack.top(); bfs_stack.pop();

#ifdef LOG
			printf("currently at %d.\n", curr_node->val);
#endif

#if 0

			if(*curr_node == *finish_node)
			{
#ifdef LOG
				printf("reached last node. backtracking...\n");
#endif
				int curr_distance = 0;
				node_t* back_track = curr_node;
				while(!(*back_track == *start_node))
				{
					back_track = back_track->last_node;
					curr_distance++;
				}
#ifdef LOG
				printf("got distance %d. current min_distance is %d.\n", curr_distance, min_distance);
#endif
				if (min_distance > curr_distance)
				{
					min_distance = curr_distance;
				}
				continue;
			}
#endif

#ifdef LOG
			printf("there are %d next islands.\n", curr_node->bridge_to.size());
#endif

			for(std::vector<node_t*>::iterator itr = curr_node->bridge_to.begin();
					itr != curr_node->bridge_to.end();
					itr++)
			{
				node_t *next_node = *itr;
				
#ifdef LOG
				printf("checking if we should explore %d.\n", next_node->val);
#endif

				if(next_node->node_min_distance > (curr_node->node_min_distance+1))
				{
#ifdef LOG
					printf("will_explore %d.\n", next_node->val);
#endif
					next_node->node_min_distance = curr_node->node_min_distance+1;
					bfs_stack.push(next_node);
				}

#if 0
				if(*curr_node == *next_node)
				{
					continue;
				}
				node_t* back_track = curr_node;
				bool skip = false;
				while(!(*back_track == *start_node))
				{
					back_track = back_track->last_node;
					if(*back_track == *next_node)
					{
						skip = true;
					}
				}
				if(skip)
				{
					continue;
				}

#ifdef LOG
				printf("will explore %d.\n", next_node->val);
#endif
				next_node->last_node = curr_node;
				bfs_stack.push(next_node);

#endif
			}
		}
		printf("%d\n", finish_node->node_min_distance);
	}


}
