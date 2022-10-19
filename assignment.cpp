#include <iostream>
using namespace std;
  
// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
  
// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;
  
public:
    // Default constructor
    Linkedlist() { head = NULL; }
  
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNodeBack(int);
    void push(int);

    void SearchElement(int);
  
    void searchNode(int);

    void reverseList();
    // Function to print the
    // linked list.
    void printList();
  
    // Function to delete the
    // node at given position
    void deleteNode(int);

    ~Linkedlist(){
        cout<<"Destructor"<<endl;
    }
};

// insert at the front of the list

   //Add new element at the start of the list
    void Linkedlist :: push(int newElement) {
      Node* newNode = new Node();
      newNode->data = newElement;
      newNode->next = head; 
      head = newNode;   
    }



// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;
  
    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }
  
    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }
  
    // Check if the position to be
    // deleted is less than the length
    // of the linked list.
    if (ListLen < nodeOffset) {
        cout << "Index out of range"
             << endl;
        return;
    }
  
    // Declare temp1
    temp1 = head;
  
    // Deleting the head.
    if (nodeOffset == 1) {
  
        // Update head
        head = head->next;
        delete temp1;
        return;
    }
  
    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1) {
  
        // Update temp2
        temp2 = temp1;
  
        // Update temp1
        temp1 = temp1->next;
    }
  
    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;
  
    // Delete the node
    delete temp1;
}
  
// Function to insert a new node.
void Linkedlist::insertNodeBack(int data)
{
    // Create the new Node.
    Node* newNode = new Node(data);
  
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;
}
 void Linkedlist::reverseList()
    {
        // Initialize current, previous and next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
  
// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

  //Search an element in the list
    void Linkedlist :: SearchElement(int searchValue) {   
      Node* temp = head;
      int found = 0;
      int i = 0;

      if(temp != NULL) {
        while(temp != NULL) {
          i++;
          if(temp->data == searchValue) {
            found++;
            break;
          }
          temp = temp->next;
        }
        if (found == 1) {
          cout<<searchValue<<" is found at index = "<<--i<<".\n";
        } else {
          cout<<searchValue<<" is not found in the list.\n";
        }
      } else {
        cout<<"The list is empty.\n";
      }
    } 
  
// Driver Code
int main()
{
    Linkedlist list;
  
    Node* head = NULL;
    // Inserting nodes
    list.insertNodeBack(1);
    list.insertNodeBack(2);
    list.insertNodeBack(3);
    list.insertNodeBack(4);
  
    cout << "Elements of the list are: ";
  
    // Print the list
    list.printList();
    cout << endl;
  
    // Delete node at position 2.
    list.deleteNode(2);
  
    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;

    list.push(12);
    list.SearchElement(12);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;

    list.reverseList();
    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    

    return 0;
}
