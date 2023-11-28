#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b)
{
	return a[2] < b[2];
}

void makeset(vector<int> &parent, vector<int> &rank, int n)
{
	for(int i=0; i<n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(vector<int> &parent, int node)
{
	if(parent[node] == node) 
	return node;

	return parent[node] = findParent(parent, parent [node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
	u = findParent(parent, u);
	v = findParent(parent, v);

	if(rank[u] < rank[v])
		parent[u] = v;

	else if(rank[v] < rank[u])
		parent[v] = u;

	else
	{ 
	 rank[u]++;
	}
}

int min_spanning_tree(vector <vector <int>> &edges, int n)
{
	sort(edges.begin(),edges.end(), cmp);

	vector <int> parent(n);
	vector <int> rank(n);
	makeset(parent, rank, n);

	int minWeight = 0;
	
	
	for (int i = 0; i<edges.size(); i++)
	{
		int u = findParent(parent, edges[i][0]); 
		int v = findParent(parent, edges[i][1]);

		int wt = edges[i][2];

		if(u != v)
		{
			minWeight += wt;
			unionSet(u, v, parent, rank); 
			printf("%d - %d = %d\n",edges[i][0], edges[i][1], wt);
		}
	}return minWeight; 
}


int main()
{
	vector <vector <int>> edge
			{{1,3,3},
			{3,2,10},
			{2,4,4},
			{4,5,1},
			{5,3,6},
			{4,3,2}};

	min_spanning_tree(edge,6);
}
	
	
	