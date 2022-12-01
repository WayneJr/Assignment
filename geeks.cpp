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