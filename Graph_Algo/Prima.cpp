#include <iostream>
#include <stdlib.h>
#include "vector"
using namespace std;
const int INF = 1000000000;

int main() {
// Создание матрицы смежности
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    cout << endl << endl << "Filling in random order... \n";
    vector< vector<int>> g(n);

    for(int i = 0; i < n; i++){
        g.push_back(vector<int>(n));
        for(int j = 0; j < n; j++){
            if(i != j)
                g[j].push_back(rand()%7);
            else
                g[j].push_back(0);
        }
    }

// Вывод матрицы смежности
    cout << endl << "__  ";
    for(int i = 0; i < n; i++)
        cout <<  i + 1 << " ";
    cout << endl;

    for(int i = 0; i < n; i++){
        cout << i + 1 << " | ";
        for(int j = 0; j < n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
 
// алгоритм
vector<bool> used (n);
vector<int> min_e (n, INF), sel_e (n, -1);
min_e[0] = 0;
for (int i=0; i<n; ++i) {
	int v = -1;
	for (int j=0; j<n; ++j)
		if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
			v = j;
	if (min_e[v] == INF) {
		cout << "No MST!";
		exit(0);
	}
 
	used[v] = true;
	if (sel_e[v] != -1)
		cout << v << " " << sel_e[v] << endl;
 
	for (int to=0; to<n; ++to)
		if (g[v][to] < min_e[to]) {
			min_e[to] = g[v][to];
			sel_e[to] = v;
		}
}
}