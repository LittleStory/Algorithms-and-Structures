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



// Алгоритм Флойда
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (g[i][k] < INF && g[k][j] < INF)
                    g[i][j] = min (g[i][j], g[i][k] + g[k][j]);

    cout << "After Floid algorithm: \n";
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
    
 }