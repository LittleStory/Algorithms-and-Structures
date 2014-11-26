#include "iostream"
#include "cmath"

template <typename T>
        class Stack{
            private:
                T *stackInit;
                int stackSize;
                int stackTop;

             public:
                Stack(int = 5);
                ~Stack();

                inline bool stackEmpty();
                inline void stackPush(const T &);
                inline T    stackPop();
        };
template <typename T>
Stack<T>::Stack(int sizeOfStack):
        stackSize(sizeOfStack)
        {
            stackInit = new T [stackSize];
            stackTop  = 0;
        }

template <typename T>
Stack<T>::~Stack()
        {
            delete [] stackInit;
        }

template <typename T>
inline bool Stack<T>::stackEmpty()
        {
            if(stackTop == 0)
                return true;
            else
                return false;
        }

template <typename T>
inline void Stack<T>::stackPush(const T &value)
        {
            stackTop = stackTop + 1;
            stackInit[stackTop] = value;
        }

template <typename T>
inline T Stack<T>::stackPop()
        {
            if(!stackEmpty()){
                stackTop = stackTop - 1;
                return  stackInit[stackTop + 1];
            }
        }




int main(){
    int n = 0;
    std::cout << "Введите размер стека:" << " ";
    std::cin >> n;

    Stack <int> stackStand(n);
    Stack <int> stackOpt(n);

    std::cout << std::endl << "n = " << n;
    std::cout << std::endl << "Ввод элментов стека:";
    int elm = 0;
    for (int i = 0; i < n; i++) {
        std::cout << std::endl << "iteration" << " " << i << std::endl;
        std::cin >> elm;
        stackStand.stackPush(elm);
    }

    for(int i = 0; i < n; i++){
        int elemX = stackStand.stackPop();
        while(!stackStand.stackEmpty()) {
            int elOp = stackStand.stackPop();
            if (elemX != elOp)
                stackOpt.stackPush(elOp);
        }

        stackOpt.stackPush(elemX);

        while(!stackOpt.stackEmpty())
            stackStand.stackPush(stackOpt.stackPop());
    }

    while(!stackStand.stackEmpty())
        std::cout << stackStand.stackPop() << " ";
}