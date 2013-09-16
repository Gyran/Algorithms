/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#ifndef LIS_H_GUARD
#define LIS_H_GUARD

using namespace std;


vector<int> lis(vector<int> &sequence) {
	vector<int> ret;
	vector<int> indexes(sequence.size());
	int v,u;
	int top, bottom, mid;
	vector<int>::iterator low;


	if (sequence.empty()) {
		return ret;
	}

	ret.push_back(0);

	for (int i = 1; i < sequence.size(); ++i)
	{
		// element is bigger then the last, add it and continue
		if (sequence[ret.back()] < sequence[i]) {
			indexes[i] = ret.back();
			ret.push_back(i);
			continue;
		}

		// find the value amongst the indexes that is smaller then a previous value
		for (bottom = 0, top = ret.size() - 1; bottom < top;) {
			mid = (top + bottom) / 2;
			if (sequence[ret[mid]] < sequence[i]) {
				bottom = mid + 1;
			} else {
				top = mid;
			}
		}
		u = bottom;

		// update the return vector if we found a smaller value
		if (sequence[i] < sequence[ret[u]]) {
			if (u > 0) {
				indexes[i] = ret[u - 1];
			}
			ret[u] = i;
		}
	}

	// build the return vector
	for (u = ret.size(), v = ret.back(); u--; v = indexes[v]) 
	{
		ret[u] = v;
	}

}


#endif