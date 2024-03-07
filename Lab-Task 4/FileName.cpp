#include <iostream>
#include <list>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


void customSort(list<int>& lst) {
    lst.sort();
}


list<int> mergeLists(const list<int>& lst1, const list<int>& lst2) {
    list<int> mergedList = lst1;
    return mergedList;
}

int main() {
    cout << "\n\t\t\t*Welcome to OOP-Lab*\n";

    LinkedList myList;
    myList.append(4);
    myList.append(9);
    myList.append(3);

    cout << "\n\tOriginal list: ";
    myList.printList();

    int key;
    cout << "\tEnter a number to search in the list: ";
    cin >> key;
    if (myList.search(key)) {
        cout << endl;
        cout << "\t" << key << " Is Available in the list." << endl;
    }
    else {
        cout << endl;
        cout << "\t" << key << " Is Not Available in the list." << endl;
    }

    cout << "\tReversed list: ";
    myList.reverse();
    myList.printList();


    list<int> myCustomList = { 8, 6, 1 };
    cout << "\n\tBefore sorting: ";
    for (int n : myCustomList) cout << n << " ";
    cout << endl;
    customSort(myCustomList);
    cout << "\tAfter sorting: ";
    for (int n : myCustomList) cout << n << " ";
    cout << endl;

    list<int> list1 = { 9, 0, 3 };
    list<int> list2 = { 2, 4, 6 };
    list<int> merged = mergeLists(list1, list2);
    cout << "\tMerged list: ";
    for (int n : merged) cout << n << " ";
    cout << endl;

    return 0;
}