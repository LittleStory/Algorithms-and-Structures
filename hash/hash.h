#include "iostream"
#include "iomanip"
#include "fstream"
#include "vector"
#include "cmath"
#include "stdlib.h"

using namespace std;

class HashTable {
private:
    vector<vector<int>> table;

    unsigned int tableColumns;
    unsigned int tableRows;
    unsigned int tableCells;


    unsigned int methodMultiplication(unsigned int val) {
        float a = (sqrt(5.0) - 1) / 2;
        double x, y;
        y = modf(val * a, &x);
        return (int) (this->tableColumns * y);
    }


    unsigned int maxOfSeveral(vector<int> array) {
        unsigned int max = 0;
        for (unsigned int i = 0; i < array.size(); i++)
            if (array[i] > max)
                max = array[i];
        return max;
    }

    vector<vector<int>> makeTable(vector<int> inputArray) {
        vector<vector<int>> table(this->tableColumns);
        for (unsigned int i = 0; i < this->tableCells; i++) {
            table[methodMultiplication(inputArray[i])].push_back(inputArray[i]);
        }

        vector<int> columnsLengthes(this->tableColumns);
        for (unsigned int i = 0; i < tableColumns; i++)
            columnsLengthes[i] = table[i].size();
        this->tableRows = maxOfSeveral(columnsLengthes);

        return table;
    }

public:
    HashTable(unsigned int columns, vector<int> inputArray);
    ~HashTable();

    inline void print();
    inline bool isExist(unsigned int val);
    unsigned int getRowsCount();
    unsigned int getColumnsCount();
    unsigned int getCellsCount();
};

HashTable::HashTable(unsigned int columns, vector<int> inputArray) {
    tableCells = inputArray.size();
    tableColumns = columns;
    table = makeTable(inputArray);
}

HashTable::~HashTable() {}

inline void HashTable::print() {
    for (unsigned int i = 0; i < tableRows; i++, cout << endl)
        for (unsigned int j = 0; j < tableColumns; j++, cout << "\t") {
            if (table[j].size() > i)
                cout << " " << table[j][i];
            else
                cout << " " << "-";
        }
}


inline bool HashTable::isExist(unsigned int val) {
    unsigned int m = 0;
    m = methodMultiplication(val);
    for (unsigned int i = 0; i < this->table[m].size(); i++)
        if (this->table[m][i] == val)
            return true;
    return false;
}

unsigned int HashTable::getRowsCount() {
    return tableRows;
}

unsigned int HashTable::getColumnsCount() {
    return tableColumns;
}

unsigned int HashTable::getCellsCount() {
    return tableCells;
}