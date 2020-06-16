#include <iostream>

class Node
{
private:
    int element;
    Node *nextPtr;
    Node *prevPtr;

public:
    Node(int e)
    {
        element = e;
        nextPtr = nullptr;
        prevPtr = nullptr;
    }

    Node *getNext()
    {
        return nextPtr;
    }

    Node *getPrev()
    {
        return prevPtr;
    }

    int getElement()
    {
        return element;
    }

    void setNext(Node *next)
    {
        nextPtr = next;
    }

    void setPrev(Node *prev)
    {
        prevPtr = prev;
    }

    void setElement(int element)
    {
        this->element = element;
    }
};

class LinkedList
{
private:
    Node *HEAD = nullptr;
    Node *TAIL = nullptr;

public:
    void append(int element)
    {
        Node *newElement = new Node(element);
        if (HEAD == nullptr)
        {
            HEAD = newElement;
            TAIL = newElement;
        }
        else
        {
            TAIL->setNext(newElement);
            newElement->setPrev(TAIL);
            TAIL = newElement;
        }
    }

    int get(int index)
    {
        Node *n = HEAD;
        for (int i = 0; i < index; i++)
        {
            if (n == nullptr)
                return -1;
            else
            {
                n = n->getNext();
            }
        }
        return n->getElement();
    }

    void prepend(int element)
    {
        Node *newElement = new Node(element);
        newElement->setNext(HEAD);
        HEAD->setPrev(newElement);
        HEAD = newElement;

        if (TAIL == nullptr)
        {
            TAIL = newElement;
        }
    }

    bool contains(int value)
    {
        Node *traverse = HEAD;
        while (traverse != nullptr && traverse->getElement() != value)
        {
            traverse = traverse->getNext();
        }
        if (traverse == nullptr)
        {
            return false;
        }
        return true;
    }

    bool remove(int value)
    {
        if (HEAD == nullptr)
        {
            return false;
        }
        Node *n = HEAD;
        if (n->getElement() == value)
        {
            if (HEAD == TAIL)
            {
                HEAD = nullptr;
                TAIL = nullptr;
            }
            else
            {
                HEAD = HEAD->getNext();
                HEAD->setPrev(nullptr);
            }
            return true;
        }

        while (n != nullptr && n->getElement() != value)
        {
            n = n->getNext();
        }
        if (n == TAIL)
        {
            TAIL = TAIL->getPrev();
            TAIL->setNext(nullptr);
            return true;
        }
        else if (n != nullptr)
        {
            n->getPrev()->setNext(n->getNext());
            n->getNext()->setPrev(n->getPrev());
            return true;
        }

        return false;
    }

    int removeByIndex(int index){
        //TODO: Make this more elegant, change implementation vice versa
        Node *n = HEAD;

        for(int i=0; i<index; i++){
            if(n == nullptr)
                return -1;
            else
            {
                n = n->getNext();
            }
        }

        if (n == HEAD)
        {
            if (HEAD == TAIL)
            {
                HEAD = nullptr;
                TAIL = nullptr;
            }
            else
            {
                HEAD = HEAD->getNext();
                HEAD->setPrev(nullptr);
            }
            return n->getElement();
        }

        if (n == TAIL)
        {
            TAIL = TAIL->getPrev();
            TAIL->setNext(nullptr);
            return n->getElement();
        }
        else
        {
            n->getPrev()->setNext(n->getNext());
            n->getNext()->setPrev(n->getPrev());
            return n->getElement();
        }

        return -1;
    }


    void printList()
    {
        Node *traverse = HEAD;
        while (traverse != nullptr)
        {
            std::cout << traverse->getElement() << "\n";
            traverse = traverse->getNext();
        }
    }
};

class Queue
{
private:
    LinkedList q;

public:
    Queue()
    {
        q = LinkedList();
    }

    int peek()
    {
        return q.get(0);
    }

    int pop()
    {
        //TODO: error handling
        return q.removeByIndex(0);

    }

    void push(int n)
    {
        q.append(n);
    }

    bool contains(int n)
    {

        return q.contains(n);
    }
};

int main(){
    Queue q = Queue();
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << q.pop() << " " << q.pop() << " " << q.pop();

}
