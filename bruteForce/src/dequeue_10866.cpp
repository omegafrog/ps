#include <iostream>
using namespace std;

#define CAPACITY 20000

class dequeue
{
private:
    // front is index-1 of first element
    // rear is the index of last element
    int front, rear, size;
    int data[20000];

public:
    dequeue();
    ~dequeue();
    bool empty();
    int getSize();
    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int peekFront();
    int peekBack();
};

dequeue::dequeue()
{
    front = 0;
    rear = 0;
    size = 0;
}

dequeue::~dequeue()
{
}

bool dequeue::empty()
{
    return (front == rear);
}

int dequeue::getSize()
{
    return this->size;
}
void dequeue::push_front(int value)
{
    data[front] = value;
    front = (front-1+CAPACITY)%CAPACITY;
    this->size++;
}
void dequeue::push_back(int value)
{
    rear = (rear+1)%CAPACITY;
    data[rear] = value;
    this->size++;
}
int dequeue::pop_front()
{
    if (this->empty())
    {
        return -1;
    }
    else
    {
        this->size--;
        front = (front+1)%CAPACITY;
        return data[front];
    }
}
int dequeue::pop_back()
{
    if (this->empty())
    {
        return -1;
    }
    else
    {
        this->size--;
        int res = data[rear];
        rear = (rear-1+CAPACITY)%CAPACITY;
        return res;
    }
}
int dequeue::peekFront()
{
    if(empty()){
        return -1;
    }
    return data[(front + 1) % CAPACITY];
}
int dequeue::peekBack()
{
    if(empty()){
        return -1;
    }
    return data[(rear) % CAPACITY];
}

int main(int argc, char const *argv[])
{
    int N;
    string input;
    dequeue q1;
    cin >> N;
    cin.ignore();
    cin.clear();
    for (int i = 0; i < N; ++i)
    {
        getline(cin, input);
        int index = input.find(" ", 0);
        if (index != -1)
        {
            string command = input.substr(0, index);
            int arg = stoi(input.substr(index + 1));
            if (command.compare("push_front") == 0)
            {
                q1.push_front(arg);
            }
            else if (command.compare("push_back") == 0)
            {
                q1.push_back(arg);
            }
        }
        else
        {
            string command = input;
            if (command.compare("empty") == 0)
            {
                cout << q1.empty() << "\n";
            }
            else if (command.compare("size") == 0)
            {
                cout << q1.getSize() << "\n";
            }
            else if (command.compare("pop_front") == 0)
            {
                cout << q1.pop_front() << "\n";
            }
            else if (command.compare("pop_back") == 0)
            {
                cout << q1.pop_back() << "\n";
            }
            else if (command.compare("front") == 0)
            {
                cout << q1.peekFront() << "\n";
            }
            else if (command.compare("back") == 0)
            {
                cout << q1.peekBack() << "\n";
            }
        }
    }
    return 0;
}
