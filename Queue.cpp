#include "iostream"
#include "cmath"

template <typename T>
    class Queue{
        private:
            T *queue;
            int size;
            int tail;
            int head;

        public:
            Queue(int = 5);
            ~Queue();

            inline T Enqueue(const T &);
            inline T Dequeue();
    };

template <typename T>
        Queue<T>::Queue(int sizeOf):
        size(sizeOf)
        {
            queue = new T [size];
            head  = 1;
            tail = size - 1;
        }

template <typename T>
        Queue<T>::~Queue() {
            delete [] queue;
        }

template <typename T>
        inline T Queue<T>::Enqueue(const T &elem) {
            queue[tail] = elem;
            if(tail == size)
                tail = 1;
            else
                tail = tail + 1;
        }

template <typename T>
        inline T Queue<T>::Dequeue() {
            T elem = queue[head];
            if(head == size)
                head = 1;
            else
                head = head + 1;
            return elem;
        }

int main(){
    int n;
    std::cin >> n;

    Queue <int> standQue(n);

    for(int i = 0; i < n; i++){
        int element;
        std::cin >> element;
        standQue.Enqueue(element);
    }

        for (int j = 0; j < n; j++){
            int elm = standQue.Dequeue();
            if(elm%2 == 0)
                std::cout << elm << " ";
        }

        for (int j = 0; j < n; j++){
            int elm = standQue.Dequeue();
            if(elm%2 != 0)
                std::cout << elm << " ";
        }
}