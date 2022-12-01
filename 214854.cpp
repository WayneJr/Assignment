// implement a linked list with a dummy node

#include <cstdlib>
#include <iostream>
using namespace std;

class Node {
 public:
  Node(int d = 0, Node *n = NULL) {
    data = d;
    next = n;
  }
  int data;
  Node *next;
};

class List {
 public:
  List();
  ~List();
  void insert(int d);
  void remove(int d);
  void print();

 private:
  Node *head;
};

List::List() {
  head = new Node;
  head->next = NULL;
}

List::~List() {
  Node *p = head;
  while (p != NULL) {
    Node *q = p;
    p = p->next;
    delete q;
  }
}

void List::insert(int d) {
  Node *p = head;
  while (p->next != NULL && p->next->data < d) p = p->next;
  p->next = new Node(d, p->next);
}

void List::remove(int d) {
  Node *p = head;
  while (p->next != NULL && p->next->data < d) p = p->next;
  if (p->next != NULL && p->next->data == d) {
    Node *q = p->next;
    p->next = q->next;
    delete q;
  }
}

void List::print() {
  Node *p = head->next;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int main() {
  List list;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    list.insert(d);
  }
  list.print();
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int d;
    cin >> d;
    list.remove(d);
  }
  list.print();
  return 0;
}

// Path: 214855.cpp
// Delete
// restore
// insert