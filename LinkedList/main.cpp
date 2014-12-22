#include "doubList.h"
using namespace std;

int main() {
    doubList listN;

    for(int i = 0; i < 10; i++)
        listN.add(rand() % 10);

    listN.print();

   cout << endl << listN.min() << endl;
    listN.insert(5, listN.min());
    listN.print();
}