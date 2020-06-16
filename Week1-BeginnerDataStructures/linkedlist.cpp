#include <iostream>

class Node
{
private:
    int element;
    Node *nextPtr;

public:
    Node(int e)
    {
        element = e;
        nextPtr = nullptr;
    }

    Node *getNext()
    {
        return nextPtr;
    }

    int getElement()
    {
        return element;
    }

    void setNext(Node *next)
    {
        nextPtr = next;
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
    Node append(int element)
    {
        Node *traverse = HEAD;
        Node *newElement = new Node(element);
        if (traverse == nullptr)
        {
            HEAD = newElement;
            TAIL = newElement;
        }
        else
        {
            TAIL->setNext(newElement);
            TAIL = newElement;
        }
        return *newElement;
    }

    Node prepend(int element)
    {
        Node* newElement = new Node(element);
        newElement->setNext(HEAD);
        HEAD = newElement;
        if(TAIL == nullptr){
            TAIL = newElement;
        }
        return *newElement;
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
            }
            return true;
        }

        while(n->getNext()!= nullptr && n->getNext()->getElement() != value){
            n = n->getNext();
        }
        if(n->getNext() != nullptr){
            if(n->getNext() == TAIL){
                TAIL = n;
                TAIL->setNext(nullptr);
            }else{
                n->setNext(n->getNext()->getNext());
            }
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
    a.printList();
}