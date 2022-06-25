#include "bits/stdc++.h"
using namespace std;

class edge{
	public:
	int src ;
	int dest ;
	int weight;
};

bool cmp(edge e1 , edge e2)
{
	int w1 = e1.weight;
	int w2 = e2.weight;
	return w1 < w2;
}

int findparent(int v , int *parent)
{
	if(parent[v] == v)
	{
		return v;
	} 
	return parent[v] = findparent(parent[v] , parent);
}

void kruskal(edge *input , int n , int E)
{
	sort(input , input + E , cmp); // we will sort the array according to the weight of the edge
	edge *output = new edge[n-1];
	int *parent = new int[n];
	for(int i = 0 ; i<n ; i++)
	{
		parent[i] = i; // all the vertices are in defferent component so every vertix is parent of itself
	}
	int count = 0 ;
	int i = 0 ;
	// here n-1 is the number of edges;
	while (count != n-1)
	{
		edge curredge = input[i];
		int srcparent = findparent(curredge.src,parent);
		int destparent  = findparent(curredge.dest,parent);
		if(srcparent != destparent)
		{
			output[count] = curredge; // after we get the edge we will addd this in output array as a result
			count++;
			parent[srcparent] = destparent; // by unoin find algo 
			// union find algo 
			// 1) this algo will help to find the subset
			// 2) toconnect means including in the subset , so  we will make parent one of them 
		}
		i++;
	}

int weight = 0 ;
	for(int i = 0 ; i<n-1 ; i++) // number of edges
 	{
		 	edge curroutput = output[i];
				weight += curroutput.weight;
			 if(curroutput.src < curroutput.dest)
			 {
				 cout<<curroutput.src<<" "<<curroutput.dest<<" "<<endl;
			 }
			 else
			 {
				 cout<<curroutput.dest <<" "<<curroutput.src<<" "<<endl;
			 }
	}

	cout<<endl<<" "<<weight<<" "<<endl;
	return ;
}

int main()
{
	int n,E;
	cin>>n;
	cin>>E;
	edge *input = new edge[E];
	for(int i = 0 ; i<E ; i++)
	{
		int s,w,d;
		cin>>s;
		cin>>d;
		cin>>w;
		
		input[i].src = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	kruskal(input,n,E);

	return 0;
}
