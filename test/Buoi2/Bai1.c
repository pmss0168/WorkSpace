#include <stdio.h>
#include <stdlib.h>

// #include "DFS.h"
#include "check1.c"
int main()
{
	freopen("dt.txt", "r", stdin);
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++)
	{
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	if (contains_cycle(&G))
		printf("YES");
	else
		printf("NO");
	return 0;
}
