#include "iostream"
#include "cmath"
#include "assert.h"

template <typename T>
        class Stack{
        private:
            T *StackInit;
            const int size;
            int stackTop;
        public:
            Stack(int = 10);
            Stack(const Stack<T> &);
            ~Stack();

            inline void stackPush(const T &);
            inline void stackPrint();
            inline T    stackDel();
            inline int  stackSize() const ;
            inline int  stackGetTop() const ;
            inline T    *stackLink() const;
            inline const T &Peek(int) const;
        };

template <typename T>
    Stack<T>::Stack(int sizeOfStack):
    size(sizeOfStack)
    {
        StackInit = new T [size];
        stackTop  = 0;
    }

template <typename T>
    Stack<T>::~Stack()
    {
        delete [] StackInit;
    }

template <typename T>
    Stack<T>::Stack(const Stack<T> & otherStack) :
        size(otherStack.stackSize())
    {
    StackInit = new T[size];
    stackTop = otherStack.stackGetTop();

    for(int i = stackTop - 1; i >= 0; i--)
        StackInit[i] = otherStack.stackLink()[i];
    }


//Optional functions for operations on stack

template <typename T>
    inline void Stack<T>::stackPush(T const &value)
    {
        if(stackTop < size);
            StackInit[stackTop++] = value;
    }

template <typename T>
    inline void Stack<T>::stackPrint()
    {
        for(int i = stackTop - 1; i >= 0; i--)
            std::cout << StackInit[i] << std::endl;
    }

template <typename T>
   inline T Stack<T>::stackDel()
    {
        assert(stackTop > 0);
            StackInit[stackTop--];
    }

template <class T>
    inline const T &Stack<T>::Peek(int n) const
    {
        assert(n <= stackTop);
            return StackInit[stackTop - n];
    }


template <typename T>
    inline int Stack<T>::stackSize() const
    {
        return size;
    }


template <typename T>
    inline T *Stack<T>::stackLink() const
    {
        return StackInit;
    }


template <typename T>
    inline int Stack<T>::stackGetTop() const
    {
        return stackTop;
    }


int main() {
    int n;
    std::cin >> n;

    Stack<int> stackS(n);

    for (int i = 0, elementStack; i < n; ++i) {
        std::cin >> elementStack;
        stackS.stackPush(elementStack);
    }

    stackS.stackPrint();
    std::cout << std::endl;

    for (int i = stackS.stackGetTop() - 1; i <= 0; i--) {
        for (int j = stackS.stackGetTop() - 1; j <= 0; j--){
            if (stackS.Peek(i) == stackS.Peek(j)) {
                stackS.stackDel();
            }
        }
    }

    std::cout << "Стек после удаления повторяющихся элементов:" << std::endl;
    stackS.stackPrint();
}