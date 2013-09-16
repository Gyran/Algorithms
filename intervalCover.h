/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#ifndef INTERVALCOVER_H_GUARD
#define INTERVALCOVER_H_GUARD

using namespace std;

bool compareInterval(pair<double, double>* a, pair<double, double>* b) {
	//printf("a: [%lf], b: [%lf]\n", a->first, b->first);
	//printf("%s\n", typeid(a).name());
	return (*a) < (*b);
}

vector<size_t> cover(pair<double, double> coverThis, vector<pair<double, double> >& intervals) {
	vector<pair<double, double>*> sortedIntervals;
	vector<size_t> answer;

	double current = coverThis.first;
	size_t largestSpan;
	double largest = 0;
	double tmp;
	int i = 0;

	sortedIntervals.reserve(intervals.size());
	for (int i = 0; i < intervals.size(); ++i)
	{
		sortedIntervals.push_back(&intervals.at(i));
	}
	sort(sortedIntervals.begin(), sortedIntervals.end(), compareInterval);

	while (answer.empty() || current < coverThis.second) {
		largestSpan = (size_t) -1;
		largest = -1;

		for (;i < sortedIntervals.size() && sortedIntervals.at(i)->first <= current;++i)
		{
			tmp = sortedIntervals.at(i)->second - current;
			if (tmp > largest) {
				largest = tmp;
				largestSpan = sortedIntervals.at(i) - &(intervals.front());
			}
		}
		if (largestSpan == -1) {
			// No interval matched. It is impossible to cover the interval
			return vector<size_t>();
		}

		answer.push_back(largestSpan);
		current = intervals.at(largestSpan).second;
	}

	return answer;
}

#endif