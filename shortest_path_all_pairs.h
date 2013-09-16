/*************
Gustav Ahlberg
gusah849@student.liu.se
**************/

#define MAXINT 2147483647
#define MININT -2147483648

using namespace std;


void shortest_path_all_pairs(int graph[][155], int num) {

	/*
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	*/

	for (int node = 0; node < num; ++node)
	{
		for (int from = 0; from < num; ++from)
		{
			for (int to = 0; to < num; ++to)
			{
				if (graph[from][node] != MAXINT && 
					graph[node][to] != MAXINT) {

					int newCost = graph[from][node] + graph[node][to];

					if (newCost < graph[from][to]) {
						//printf("sätter\n");
						graph[from][to] = newCost;
					}
				}
			}
		}
	}

	for (int a = 0; a < num; ++a)
	{
		for (int b = 0; b < num; ++b)
		{
			for (int c = 0; graph[a][b] != MININT && c < num; ++c)
			{

				if (graph[a][c] != MAXINT &&
					graph[c][b] != MAXINT && 
					graph[c][c] < 0) {

					//printf("sätter minint\n");
					graph[a][b] = MININT;
				}
			}
		}
	}
}
