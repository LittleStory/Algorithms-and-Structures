#include <iostream>
#include <stdlib.h>
using namespace std;


int main() {
    int n;
    cout << "Размер матрицы смежности: ";
    cin >> n;
    cout << endl;
    int **g = new int* [n];
    for(int i = 0; i < n; i++){
        g[i] = new int [n];
        for(int j = 0; j < n; j++){
           if(i != j)
                g[i][j] = rand() % 2;
            else
                g[i][j] = 0;
        }}

    cout << "__  ";
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

    int srcPeek;
    cout << "Введите вершину для рассмотрения: ";
    cin  >> srcPeek;
    srcPeek = srcPeek - 1;
    cout << "Не смежные с данной вершины: ";
    for(int i = 0; i < n; i++)
        if(g[srcPeek][i] == 0)
            cout << i + 1 << " ";

    for(int i = 0; i < n; i++)
        if(g[i][srcPeek] == 0)
            cout << i + 1 << " ";


}