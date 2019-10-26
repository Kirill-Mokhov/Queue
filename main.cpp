#include <iostream>
#include <exception>

using namespace std;

class Queue {
    int Head, Tail;
    int *value;
    int maxElem;
public:
    Queue(unsigned int max) {
        maxElem = max;
        value = new int[max + 1];
        value[max] = *new char;
        value[max] = '*';
        Head = Tail = 0;
    }

    Queue(const Queue &copy) {
        maxElem = copy.maxElem;
        Head = copy.Head;
        Tail = copy.Tail;
        value = new int[maxElem];
        for (size_t i = Head; i < Tail; i++)
            value[i] = copy.value[i];
    }

    int Push(int elem) {
        if (Tail == 0 && Head == 0) {
            value[Tail] = elem;
            Tail++;
            return 0;
        }
        if (value[Tail] == '*') {

//            string error;
            cout << "You are trying to add an item to the full queue!" << endl;
            return 0;
//            throw invalid_argument(error);
        }
        int num = 0;
        while ((elem < value[num]) && (num < Tail)) {
            num++;
        }
        for (int i = Tail; i >= num; i--) {
            value[i] = value[i - 1];
        }
        value[num] = elem;
        Tail++;
    }

    int Pop() {
        if (Head == Tail) {
            cout << "You are trying to remove an item from an empty queue!" << endl;
            return 0;
//            string error;
//            error += "You are trying to remove an item from an empty queue!";
//            throw invalid_argument(error);
        }
        int elemPop = 0;
        elemPop = value[Head];
        for (int i = Head; i <= Tail; i++) {
            value[i] = value[i + 1];
        }
        Tail--;
        return elemPop;
    }

    int Length(){
        return Tail - Head;
    }

    void Print() {
        for (int i = Head; i < Tail; i++) {
            cout << value[i] << " ";
        }
        cout << endl;
    }

    Queue &operator = (const Queue &right) {
        if (this == &right) {
            return *this;
        }
        Head = 0;
        int i = 0, j = right.Head;
        if ((Tail - Head) < (right.Tail - right.Head)) {
            for (i; (i < maxElem) && (i < right.Tail); i++) {
                value[i] = right.value[j];
                j++;
            }
            Tail = i;
            return *this;
        }
        for (i; i <= right.Tail; i++) {
            value[i] = right.value[i];
        }
        Tail = i - 1;
        return *this;
    }

    ~Queue() {
        delete[] value;
    }

};

int main() {
    Queue q1(10);
    Queue q2(10);
    for(size_t i = 0; i < 13; i++){
//        int x = rand() % 100 + 2;        cout << x << endl ;
        q1.Push(5-i%5);
    }

    cout << "q1 " << endl;
    q1.Print();
    cout  << "q1 Length: " << q1.Length() << endl << endl;

    Queue q3(7);

    for (size_t i = 0; i < 5 ; i++){
        q3.Push(q1.Pop());
    }

    cout << "q3" << endl;
    q3.Print();
    cout << "q3 Length: " << q3.Length() << endl;
    cout << "q1 " << endl;
    q1.Print();
    cout  << "q1 Length: " << q1.Length() << endl << endl;

    //q3=q1;
    cout << "q3" << endl;
    q3.Print();
    cout << "q3 Length: " << q3.Length() << endl;
    cout << "q1 " << endl;
    q1.Print();
    cout  << "q1 Length: " << q1.Length() << endl << endl;

    return 0;
}