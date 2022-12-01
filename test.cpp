// Cpp program to implement linked list data structure as [(1, 10), (2, 20), (3, 30)]
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;

  // Default constructor
  Node() {
    data = 0;
    next = NULL;
  }

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList {
public:
  Node* head;

  // Default constructor
  LinkedList() {
    head = NULL;
  }

  // Insert a node at the index entered
  void insert(int index, int data) {
    Node* newNode = new Node(data);
    if (index == 1) {
      newNode->next = head;
      head = newNode;
      return;
    }
    Node* temp = head;
    for (int i = 1; i < index - 2; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // Delete a node at the index entered
  void deleteNode(int index) {
    Node* temp = head;
    if (index == 0) {
      head = temp->next;
      delete temp;
      return;
    }
    for (int i = 0; i < index - 2; i++) {
      temp = temp->next;
    }
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
  }

  // Print the linked list
  void print() {
    Node* temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  // print the linked list with index as [(1, 10) (2, 20)(3, 30)]
  void printWithIndex() {
    Node* temp = head;
    int index = size();
    cout << "[";
    while (temp != NULL) {
      cout << "(" << index << ", " << temp->data << ")";
      temp = temp->next;
      index--;
    }
    cout << "]" << endl;
  }

  //reverse the linked list with index [(3, 30)(2, 20)(1, 10)]
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


  // Get the size of the linked list
  int size() {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
      count++;
      temp = temp->next;
    }
    return count;
  }


  // Print the linked list in reverse order
  void printReverse(Node* head) {
    if (head == NULL) {
      return;
    }
    printReverse(head->next);
    cout << head->data << " ";
  }

  // sort the linked list
  void sort() {
    Node* temp = head;
    while (temp != NULL) {
      Node* temp1 = temp->next;
      while (temp1 != NULL) {
        if (temp->data > temp1->data) {
          int temp2 = temp->data;
          temp->data = temp1->data;
          temp1->data = temp2;
        }
        temp1 = temp1->next;
      }
      temp = temp->next;
    }
  }

  // isEmpty function to check if the linked list is empty
  bool isEmpty() {
    if (head == NULL) {
      return true;
    }
    return false;
  }
};

int main() {
  LinkedList list;
  // list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);
  list.insert(3, 4);
  list.insert(4, 5);
  cout << "Original List: ";
  list.printWithIndex();

  while(!list.isEmpty()) {
    list.deleteNode(1);
    cout << "List after deleting the first node: ";
    list.printWithIndex();
  }

  list.reverse();
  list.deleteNode(2);
  list.print();
  list.printReverse(list.head);
  cout << endl;
  list.sort();
  list.print();
  return 0;
}