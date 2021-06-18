#include <iostream>
#include <string>
using namespace std;

struct Node{
public:
    Node(){
        m_info = 1;
        m_next = nullptr;
    }
    Node(int info){
        m_info = info;
        m_next = nullptr;
    }
    int m_info;
    Node *m_next;
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    void InsertBegin(int value);
    void display();
    void RemoveAt(int);
    void ReverseLL();

private:
    Node* m_head;
    Node* m_tail;
    int m_size;
};

LinkedList::LinkedList(){
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

LinkedList::~LinkedList() {
    cout << "DESTRUCTOR CALLED" << endl;
    Node *curr = m_head;
    while(curr != nullptr){
        m_head = curr;
        curr = curr->m_next;
        delete m_head;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

void LinkedList::ReverseLL(){
    Node* current = m_head;
    Node* prev = NULL, *next = NULL;

    while(current != NULL){
        next = current->m_next;
        current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    m_head = prev;
}

void LinkedList::InsertBegin(int value) {
    Node *temp = new Node();
    temp->m_next = nullptr;
    temp->m_info = value;
    if (m_head == nullptr){
        m_head = temp;
        m_tail = temp;
    }
    else{
        temp->m_next = m_head;
        m_head = temp;
    }
    m_size++;
}

void LinkedList::display() {
    if (m_size == 0){
        cout << "The linked list is empty!" << endl;
        return;
    }
    else{
        Node *temp = m_head;
        while(temp != nullptr){
            cout << temp->m_info << "->";
            temp = temp->m_next;
        }
        cout << "END" << endl;
    }
}

void LinkedList::RemoveAt(int location){
    Node* curr = m_head;
    Node* prev = m_head;
    int counter = 0;
    while(curr != nullptr){
        if (counter == location){
            prev->m_next = curr->m_next;
            delete curr;
            m_size--;
            return;
        }
        prev = curr;
        curr = curr->m_next;
        counter++;
    }
}

int main() {
    LinkedList list1;

    list1.InsertBegin(0);
    list1.InsertBegin(1);
    list1.InsertBegin(2);
    list1.InsertBegin(3);
    list1.InsertBegin(4);
    list1.display();

    list1.ReverseLL();
    list1.display();

    return 0;
}
