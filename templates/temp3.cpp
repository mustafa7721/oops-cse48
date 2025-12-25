#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, int SIZE>
class Queue {
    T arr[SIZE];
    int head;
    int tail;
    int count;

public:
    Queue() : head(0), tail(0), count(0) {}

    void enqueue(T item) {
        if (count >= SIZE)
            throw overflow_error("Queue overflow: cannot insert, queue is full.");
        arr[tail] = item;
        tail = (tail + 1) % SIZE;
        count++;
    }

    T dequeue() {
        if (count <= 0)
            throw underflow_error("Queue underflow: cannot remove, queue is empty.");
        T item = arr[head];
        head = (head + 1) % SIZE;
        count--;
        return item;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == SIZE;
    }

    int size() const {
        return count;
    }
};

int main() {
    Queue<int, 5> q;
    int choice, value;

    cout << "Interactive Queue Program\n";

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display size\n4. Exit\nChoice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    q.enqueue(value);
                    cout << value << " added to queue.\n";
                    break;
                case 2:
                    value = q.dequeue();
                    cout << value << " removed from queue.\n";
                    break;
                case 3:
                    cout << "Queue size: " << q.size() << endl;
                    break;
                case 4:
                    return 0;
                default:
                    cout << "Invalid choice.\n";
            }
        }
        catch (overflow_error &e) {
            cout << "Exception: " << e.what() << endl;
        }
        catch (underflow_error &e) {
            cout << "Exception: " << e.what() << endl;
        }
    }

    return 0;
}
