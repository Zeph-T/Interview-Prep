struct Node {
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

// Add any helper functions you may need here

Node* reverseList(Node* start,Node* end){
  Node* prev = end;
  Node* curr = start;
  while(curr != end){
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }
  
  return prev;
}



Node* reverse(Node *head) {
  // Write your code here
  Node* dummy = new Node(-1);
  dummy->next = head;
  Node* prev = dummy;
  Node* curr = head;
  
  while(curr){
    Node* start = curr;
    while(curr and curr->data%2 == 0)curr = curr->next;
    if(start != curr){
      prev->next = reverseList(start,curr);
    }
    if(curr == NULL)break;
     prev = curr;
     curr = curr->next;
  }
  return dummy->next;
  
}
