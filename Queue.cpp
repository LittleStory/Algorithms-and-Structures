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
            head  = 0;
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
    Queue <int> optioQue(n);

    for(int i = 0; i < n; i++){
        int element;
        std::cin >> element;
        standQue.Enqueue(element);
    }

    for (int i = 0; i <= n; i++)
        std::cout << standQue.Dequeue() << " ";

   int j = 0, elS = 0;

   for(int i = 1; i <= n; i++){
       elS = standQue.Dequeue();
       if(elS%2 == 0){
           standQue.Enqueue(elS);
       }
       else{

           optioQue.Enqueue(elS);
           j = j + 1;
       }
   }

   for (int i = ; i <= j; i++)
       standQue.Enqueue(optioQue.Dequeue());

   std::cout << std::endl;

}