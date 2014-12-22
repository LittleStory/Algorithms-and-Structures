#include "iostream"
#include "cmath"
#include "stdlib.h"
using namespace std;
class doubList{
public:
    struct Node{
        int key;
        Node *prev, *next;
    };
    Node *head;
    int number;


    doubList() {
        head   = NULL;
        number = 0;
    }

    ~doubList(){}


    inline void add(int value){
        Node *x = new Node;
        x->key = value;
        x->next = this->head;

        if(this->head != NULL){
            this->head->prev = x;
        }

        this->head = x;
        x->prev = NULL;
    }

    inline void print() {
        Node *x = this->head;
        cout << "Список: ";
        while(x->key != NULL){
            cout << x->key << " ";
            x = x->next;
        }
    }

    void del(int value){
        Node* x = search(value);
        if(x->prev != NULL)
            x->prev->next = x->next;
        else
            this->head = x->next;

        if(x->next != NULL)
            x->next->prev = x->prev;
    }

    Node* search(int value) {
         Node*  x = this->head;
         while(x != NULL && x->key != value)
               x = x->next;

        return x;
    }

    int min(){
        Node* x = this->head;
        int minimal = NULL;
        while(x->key != NULL) {
            if (minimal > x->key || minimal == NULL)
                minimal = x->key;
            x = x->next;
        }

        return minimal;
    }


   void insert(int ins, int value){
       Node *x = search(value);
       Node *insert = new Node;
       insert->key  = ins;
       insert->next = x;
       insert->prev = x->prev;
       x->prev = insert;
       if(insert->prev != NULL)
           insert->prev->next = insert;
       number++;
   }
};




