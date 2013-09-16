/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#ifndef SHORTEST_PATH_DIJKSRTAS_H_GUARD
#define SHORTEST_PATH_DIJKSRTAS_H_GUARD

#define MAXINT 2147483647

using namespace std;

struct node;
struct edge {
	//node* to;
	int to;
	int cost;
};

struct node {
	vector<edge> out;
	int curCost; // cost from src to this node
	//node* prev;
	int prev;
};

struct graph {
	vector<node> nodes;
	vector<edge> edges;
};

vector<int> shortestPath (vector<node>& nodes, int start, int end) {
	int cur = end;
	vector<int> path;

	while (cur != start) {
		path.push_back(cur);
		cur = nodes[cur].prev;
	}

	return path;

}

void shortestPathDijkstras(graph &g, int start) {
	//printf("inne i dijk..\n");
	g.nodes[start].curCost = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		//printf("pq är inte tom\n");
		//pair<int, node*> p = pq.top();
		pair<int, int> p = pq.top();
		//node* cur = p.second;
		int cur = p.second;
		pq.pop();

		//printf("cur %d har %d out \n", cur, g.nodes[cur].out.size());

		if (p.first != g.nodes[cur].curCost) {
			continue;
		}
		for (vector<edge>::iterator it = g.nodes[cur].out.begin();
			it != g.nodes[cur].out.end(); ++it)
		{
			//printf("out %d har edge %d till %d med kostnad %d\n", cur, cur, it->to, it->cost);
			//printf("curcost är %d\n", g.nodes[cur].curCost);


			int newCost = g.nodes[cur].curCost + it->cost;
			if (newCost < g.nodes[it->to].curCost) {
				//printf("är här inne\n");
			//if (newCost < it->to->curCost) {
				//it->to->curCost = newCost;
				//it->to->prev = cur;
				g.nodes[it->to].curCost = newCost;
				g.nodes[it->to].prev = cur;
				pq.push(make_pair(newCost, it->to));
			}
		}
	}

	/*
	int a = 0;
	for (vector<node>::iterator it = g.nodes.begin();
			it != g.nodes.end(); ++it) {

		printf("%d har minsta %d med längd %d\n", a, it->curCost, shortestPath(g.nodes, 0, a).size());
		a++;
	}*/

	//return g.nodes;

}


#endif;