/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#ifndef FENWICKTREE_H_GUARD
#define FENWICKTREE_H_GUARD

#define ll long long

using namespace std;

struct fenwickTree {
	vector<ll> tree;

	fenwickTree(int n) {
		tree.assign(n + 1, 0);
	}

	ll read(int id) {
		ll sum = 0;

		while (id > 0) {
			sum += tree.at(id);
			id -= (id & -id);
		}

		return sum;
	}

	ll add(int id, int sum) {
		//printf("adda %d på plats %d\n", sum, id);
		id++;
		while (id < tree.size()) {
			//printf("en till while, [%d]\n", id);
			tree.at(id) += sum;
			id += (id & -id);
		}
	}

};


#endif;