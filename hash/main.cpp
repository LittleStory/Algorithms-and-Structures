#include "hash.h"
using namespace std;

vector<int> randomArray(unsigned int size, unsigned int max)
{
    vector<int> startArray;
    for (unsigned int i = 0; i < size; i++)
        startArray.push_back(rand() % max);
    return startArray;
}

int main()
{
    vector<int> startArray = randomArray(50, 100);

    HashTable hashTable(100, startArray);
    hashTable.print();

    int val = 0;
    cout << endl << "Search: ";
    cin >> val;

    do
    {
        cout << endl << "Search - ";
        cout << val << " : ";
        if(hashTable.isExist(val))
            cout << "Exist" << endl;
        val++;
    } while (hashTable.isExist(val));
}