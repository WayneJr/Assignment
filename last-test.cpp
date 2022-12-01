// Cpp implementation of a LinkedList class with an data, key, and next pointer
// Path: last-test.cpp

// Cpp program to implement linked list data structure as [(1, 10), (2, 20), (3,
// 30)]
#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  int key;
  Node* next;

  // Default constructor
  Node() {
    data = 0;
    next = NULL;
  }

  Node(int key, int data) {
    this->data = data;
    this->key = key;
    this->next = NULL;
  }

  // Destructor
  ~Node() { cout << "Node with key " << key << " is being deleted" << endl; }

  // Print the data of the node
  void printNode() { cout << "(" << key << ", " << data << ")"; }
};

class LinkedList {
 public:
  Node* head;

  // Default constructor
  LinkedList() { head = NULL; }

  // Insert a node at the index entered
  void insert(int index, int data) {
    Node* newNode = new Node(index, data);
    if (index == 1) {
      newNode->next = head;
      head = newNode;
      return;
    }
    Node* temp = head;
    cout << index << endl;
    for (int i = 1; i < index - 2; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // Delete a node at the index entered
  void deleteNode(int index) {
    Node* temp = head;
    if (index == 1) {
      head = temp->next;
      delete temp;
      return;
    }
    for (int i = 1; i < index - 2; i++) {
      temp = temp->next;
    }
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
  }

  void reverse() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
  }

  // Print the data of the linked list
  void printList() {
    Node* temp = head;
    cout << "[";
    while (temp != NULL) {
      temp->printNode();
      temp = temp->next;
    }
    cout << "]" << endl;
  }

  // sort the linked list

  // Destructor
  ~LinkedList() { cout << "List is being deleted" << endl; }
};

int main() {
  LinkedList list;
  list.insert(1, 10);
  list.insert(3, 30);
  list.insert(2, 20);
  // list.insert(4, 40);
  // list.insert(5, 50);
  // list.insert(6, 60);
  cout << "Original List";
  list.printList();

  list.reverse();
  list.printList();
  // list.deleteNode(1);
  // list.printList();
  // list.deleteNode(3);
  // list.printList();
  // list.deleteNode(5);
  // list.printList();
  return 0;
}