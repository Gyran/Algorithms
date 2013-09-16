/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#include "unionFind.h"

using namespace std;

struct edge {
	int to;
	int from;
	int cost;

	bool operator<(const edge& right) const {
		if (cost == right.cost) {
			if (from == right.from) {
				return to < right.to;
			}
			return from < right.from;
		}
		return cost < right.cost;
	}
};

struct node {
	vector<edge> out;
	int curCost; // cost from src to this node
	//node* prev;
	int prev;
	bool visited;
};

struct graph {
	vector<node> nodes;
	vector<edge> edges;
};


graph kruskal (graph& g) {
	graph tree;
	tree.nodes = g.nodes;


	unionFind sets(g.nodes.size());

	sort(g.edges.begin(), g.edges.end());

	for (int i = 0; i < g.edges.size(); ++i)
	{
		edge e = g.edges.at(i);

		if (!sets.same(e.from, e.to)) {
			tree.edges.push_back(e);
			sets.doUnion(e.from, e.to);

		}
	}

	if (tree.edges.size() != (tree.nodes.size() - 1)) {
		tree.edges.clear();
	}

	return tree;
}

