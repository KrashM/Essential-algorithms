#include<bits/stdc++.h>

#define MAX_SIZE 101

class Queue{

    private:
        int Q[MAX_SIZE];
        int front, rear;

    public:
        Queue(){

            front = -1;
            rear = -1;

        }

        bool IsEmpty(){

            return (front == -1 && rear == -1);

        }

        bool IsFull(){

            return (rear + 1) % MAX_SIZE == front ? true : false;

        }

        void Enqueue(int x){

            if(IsFull()) return;
            if(IsEmpty()) front = rear = 0;
            else rear = (rear + 1) % MAX_SIZE;

            Q[rear] = x;

        }

        void Dequeue(){

            if(IsEmpty()) return;
            else if(front == rear) rear = front = -1;
            else front = (front + 1) % MAX_SIZE;

        }

        int Front(){

            if(front == -1) return -1;
            return Q[front];

        }

        void Print(){

            int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;

            for(int i = 0; i < count; i++){

                int index = (front + i) % MAX_SIZE;
                std :: cout << Q[index] << ' ';

            }

            std :: cout << '\n';

        }


};

int main(){

    Queue qu;

    qu.Enqueue(4);
    qu.Enqueue(6);
    qu.Enqueue(8);
    qu.Enqueue(10);
    qu.Print();
    qu.Dequeue();
    qu.Print();

    std :: cout << '\n';

    qu.Dequeue();
    qu.Dequeue();
    qu.Dequeue();
    std :: cout << qu.Front();
}
