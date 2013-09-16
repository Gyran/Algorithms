/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#ifndef KNAPSACK_H_GUARD
#define KNAPSACK_H_GUARD

#define MAX_CAPACITY 2005
#define MAX_OBJECTS 2005

using namespace std;

int dp[MAX_CAPACITY][MAX_OBJECTS];
int picks[MAX_CAPACITY][MAX_OBJECTS];

// Transforms the picks array to an vector with the choosen items
vector<int> buildItemsVector(int capacity, vector<int> weights) {
	vector<int> answer;
	int item = weights.size();

	while(item > 0) {
		if (picks[item][capacity] == 1) {
			answer.push_back(--item);

			capacity -= weights.at(item);
		} else {
			--item;
		}
	}

	return answer;

}

vector<int> knapsack(int maxCapacity, vector<int> values, vector<int> weights) {
	memset(dp, 0, sizeof(dp));
	memset(picks, 0, sizeof(picks));

	for (int item = 1; item <= values.size(); ++item) {
		// Choose between 1, 2... items
		for (int capacity = 0; capacity <= maxCapacity; ++capacity) {
			// Create subproblems for each capacaty from 0 to maxCapacity

			if (weights.at(item - 1) <= capacity) { // if the item fits
				if (values.at(item - 1) + dp[item - 1][capacity - weights.at(item - 1)]
					> dp[item - 1][capacity]) {

					dp[item][capacity] = values.at(item - 1) + 
						dp[item - 1][capacity - weights.at(item - 1)];
					picks[item][capacity] = 1;
				} else {
					dp[item][capacity] = dp[item - 1][capacity];
					picks[item][capacity] = -1;
				}
			} else {
				picks[item][capacity] = -1;
				dp[item][capacity] = dp[item - 1][capacity];
			}
		}
	}

	/*
	for (int i = 0; i <= values.size(); ++i)
	{
		for (int j = 0; j <= maxCapacity; ++j)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	*/

	return buildItemsVector(maxCapacity, weights);

}

#endif