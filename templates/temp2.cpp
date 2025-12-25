#include <iostream>
using namespace std;

template <typename T, int SIZE>
class Queue {
    T arr[SIZE];
    int head;
    int tail;

public:
    Queue() : head(0), tail(0) {}

    void enqueue(T item) {
        arr[tail] = item;
        tail = (tail + 1) % SIZE;
    }

    T dequeue() {
        T item = arr[head];
        head = (head + 1) % SIZE;
        return item;
    }

    bool isEmpty() const {
        return head == tail;
    }
};

int main() {
    Queue<int, 5> qInt;
    Queue<double, 5> qDouble;
    Queue<char, 5> qChar;

    // Insert elements
    qInt.enqueue(10);
    qInt.enqueue(20);
    qInt.enqueue(30);

    qDouble.enqueue(1.1);
    qDouble.enqueue(2.2);
    qDouble.enqueue(3.3);

    qChar.enqueue('A');
    qChar.enqueue('B');
    qChar.enqueue('C');

    // Remove and display elements
    cout << "Integer queue: ";
    while (!qInt.isEmpty())
        cout << qInt.dequeue() << " ";
    cout << endl;

    cout << "Double queue: ";
    while (!qDouble.isEmpty())
        cout << qDouble.dequeue() << " ";
    cout << endl;

    cout << "Char queue: ";
    while (!qChar.isEmpty())
        cout << qChar.dequeue() << " ";
    cout << endl;

    return 0;
}
