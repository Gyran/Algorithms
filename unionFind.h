#ifndef UNIONFIND_H_GUARD
#define UNIONFIND_H_GUARD

using namespace std;

struct unionFind {
	vector<int> e;

	unionFind(int n) {
		e.assign(n, -1);
	}

	bool same(int a, int b) {
		return find(a) == find(b);
	}

	void doUnion(int a, int b) {
		a = find(a);
		b = find(b);

		if (a == b) {
			return;
		}

		if (e.at(a) > e.at(b)) {
			swap(a, b);
		}
		e.at(a) += e.at(b);
		e.at(b) = a;
	}

	int find(int a) {
		if (e.at(a) < 0) {
			return a;
		}
		return e.at(a) = find(e.at(a));
	}

	void print() {
		for (vector<int>::iterator it = e.begin(); it != e.end(); ++it) {
			printf("%d ", *it);
		}
		printf("\n");
	}

};

#endif;