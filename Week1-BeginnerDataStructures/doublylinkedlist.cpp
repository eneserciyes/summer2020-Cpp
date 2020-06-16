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
    int get(int index){
        Node* n = HEAD;
        for(int i = 0; i<index;i++){
            if(n == nullptr)
                return -1;
            else
            {
                n = n->getNext();
            }
        }
        return n->getElement();
    }

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

    void prepend(int element)
    {
        Node* newElement = new Node(element);
        newElement->setNext(HEAD);
        HEAD->setPrev(newElement);
        HEAD = newElement;

        if(TAIL == nullptr){
            TAIL = newElement;
        }
    }

    bool contains(int value){
        Node* traverse = HEAD;
        while (traverse != nullptr && traverse->getElement() != value){
            traverse = traverse->getNext();
        }
        if(traverse == nullptr){
            return false;
        }
        return true;
    }

    bool remove(int value){
        if(HEAD == nullptr){
            return false;
        }
        Node* n = HEAD;
        if(n->getElement() == value){
            if(HEAD == TAIL){
                HEAD = nullptr;
                TAIL = nullptr;
            }else{
                HEAD = HEAD->getNext();
                HEAD->setPrev(nullptr);
            }
            return true;
        }

        while(n != nullptr && n->getElement() != value){
            n = n->getNext();
        }
        if(n == TAIL){
            TAIL = TAIL->getPrev();
            TAIL->setNext(nullptr);
            return true;
        }else if(n != nullptr){
            n->getPrev()->setNext(n->getNext());
            n->getNext()->setPrev(n->getPrev());
            return true;
        }

        return false;
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

int main()
{
    LinkedList a = LinkedList();
    a.append(3);
    a.append(4);
    a.append(5);
    a.prepend(2);
    a.prepend(1);

    printf("%s\n", a.contains(5) ? "true":"false");

    a.remove(5);
    a.remove(2);
    a.remove(0);
    a.remove(1);
    a.remove(3);
    a.remove(4);
    a.printList();
}