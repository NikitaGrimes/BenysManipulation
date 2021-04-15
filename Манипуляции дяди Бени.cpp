#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <string>   
#include <sstream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
	int n, m, u, v, w;
	cin >> n >> m;
	vector <vector<pair<int, int>>> Vertex(n);
	vector <long long int> mass_vertex(n, -1);
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		u--;
		v--;
		Vertex[u].push_back({ v, w });
	}
	mass_vertex[0] = 0;
	int num;
	set<pair<int, int>> next_steps;
	next_steps.insert({ 0, 0 });
	int j = 0;
	while (!next_steps.empty())
	{
		auto step = --next_steps.end();
		num = (*step).second;
		next_steps.erase(step);
		for (int i = 0; i < Vertex[num].size(); i++)
		{
			j = Vertex[num][i].first;
			long long int new_mass = mass_vertex[num] + Vertex[num][i].second;
			if (new_mass > mass_vertex[j])
			{
				mass_vertex[j] = new_mass;
				next_steps.insert({ new_mass, j });
			}
		}
	}
	cout << mass_vertex[n - 1];
}