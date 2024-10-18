//COMSC-210 | Midterm 1| Gaby Filipova
// repl URL: https://github.com/gn08/210-midterm1.git

#include <iostream>
using namespace std;

//set the constant minimum and maximum values
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

//doubly linked list class
class DoublyLinkedList {
private:
//node for the list
    struct Node {
        //define data type
        int data;
        //previous node in list
        Node* prev;
        //next node in list
        Node* next;
        //constructor to initialize node
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            //set data to node
            data = val; 
            //set pointer to previous
            prev = p;
            //set pointer to next
            next = n;
        }
    };
//pointer to begining of list
    Node* head;
//pointer to end of list
    Node* tail;

public:
//constructor
//set pointer to head
//set pointer to tail
    DoublyLinkedList() { head = nullptr; tail = nullptr; }
//inserts a new node after a specific position
    void insert_after(int value, int position) {
        //check position
        if (position < 0) {
            //error message if not
            cout << "Position must be >= 0." << endl;
            //leave function
            return;
        }
//new node with specific value
        Node* newNode = new Node(value);
        //if list empty
        if (!head) {
            //set head and tail to new node
            head = tail = newNode;
            //leave function
            return;
        }
//temporary pointer
        Node* temp = head;
        //node at specifc position
        for (int i = 0; i < position && temp; ++i)
        //next node
            temp = temp->next;
//if position is more than size of list
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            //free memory
            delete newNode;
            return;
        }
//new node after position
        newNode->next = temp->next;
        //previous node to the current temp
        newNode->prev = temp;
        //check if node after
        if (temp->next)
        //set to new node
            temp->next->prev = newNode;
        else
        //if no next node set tail to new node
            tail = newNode;
            //set current to next
        temp->next = newNode;
    }
//delete the first of a value
    void delete_val(int value) {
        //if list empty stop
        if (!head) return;
//set temporary
        Node* temp = head;
        //find specific node
        while (temp && temp->data != value)
            temp = temp->next;
//if no value then leave
        if (!temp) return; 
//if node not head
        if (temp->prev)
        //set to the next one
            temp->prev->next = temp->next;
        else
        //if head deleted set new one
            head = temp->next; 
//if tail deleted set new one
        if (temp->next)
            temp->next->prev = temp->prev;
        else
        //clean up memory
            tail = temp->prev; 
//free up memory of deleted node
        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void every_other_element(){
        Node* current = head;
        bool skip = false;
        while (current) {
            if(!skip){
                cout << current -> data << " ";
            }
            skip = !skip;
            current = current -> next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    cout << "Every other: ";
    list.every_other_element();

    return 0;
}
