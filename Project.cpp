#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

struct node { 
  int data; 
  node *next; 
};

class LinkedList
{

    node* head;
    node* tail;

  public:
    // default constructor. Initializing head pointer
    LinkedList()
    {
      head = NULL;
      tail = NULL;
    }
    
	// Time Complexity: O(n)
    LinkedList(int size, LinkedList &li){
    	
    	srand(time(0));
    	
    	for (int i=0; i < size; i++){
    	li.insert_start(rand() % 100);
		}
	}
	
	// Operator overloading
	void operator = (const LinkedList &li){
		this->head = li.head;
		this->tail = tail;
	}
    
	//Time Complexity: O(n)
    ~LinkedList(){
	node *current = new node;
	current = head;
	
	while(current != NULL){
		delete current;
		current = current->next;
	}
};
    
    
    //Inserting at the start //Time Complexity: O(1)
    void insert_start(int val) {
      node* temp = new node();
      temp->data = val;
      temp->next = head;
      head = temp;
    }
    
    //Time Complexity: O(n)
    void insert_end(int value){
    	{
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {
      	node *last = head;
      	while(last->next != NULL){
        last = last->next;
      }
        last->next=temp;
  }
	}
}

    // Boolean search function
    bool search(int val) // Time Complexity: O(n)
    {
    node* current = head; // Initialize current
    while (current->next != NULL) {
        if (current->data == val){
        cout<<"Value " << val << " is indeed available in the list!"<<endl;
        return true;
        cout<<endl;
    	current=current->next;
	}


	return false;
	cout<<"Value "<<val<<" is not available in this list"<<endl;}

}


        void deleteValue(int val) //Time Complexity: O(n)
    {
      if (head->data == val)
      {
        delete head;
        head = head->next;
        return;
      }

      if (head->next == NULL)
      {
        
        if (head->data == val)
        {
          delete head;
          head = NULL;
          return;
        }
       
        cout << "Value not available!" << endl;
        return;
      }

      // Else loop over the list
      node* temp = head;
      while(temp->next!= NULL)
      {
        // When node is found, delete the node and modify the pointers to bridge gap between nodes in list
        if (temp->next->data == val)
        {
          node* temp_ptr = temp->next->next;
          delete temp->next;
          temp->next = temp_ptr;
          return;
        }
        temp = temp->next;
      }

      cout << "Value not available" << endl;
    }
    
    	//Time Complexity: O(n)
        void display()
{
	node* temp = head;

	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse through the list
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout<<endl<<endl;
}

    void reverseList() //Time Complexity: O(n)
    {
        // Initialize current, previous and next pointers
        node* current = head;
        node *prev = NULL, *next = NULL;
 
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
    
    //Removing consecutive duplicates  //Time Complexity: O(n^2)
void removeDuplicate() {  
    //Node current will point to head  
    struct node *current = head, *index = NULL, *temp = NULL;  
      
    if(head == NULL) {  
        return;  
    }  
    else {  
        while(current != NULL){  
            temp = current;  
            index = current->next;  
              
            while(index != NULL) {  
                if(current->data == index->data) {  
                    temp->next = index->next;  
                }  
                else {  
                    temp = index;  
                }  
                index = index->next;  
            }  
            current = current->next;  
        }          
    }  
}

};


int main(){
	LinkedList list;
	int val_size, val_start, val_end, val_search, val_delete;
	
	cout<<"Please enter the size of your initial linked list: ";
	cin>>val_size;
	
	LinkedList(val_size, list);
	cout<<"List: ";
	list.display();
	
	
	cout<<"Let's start our operations now!"<<endl<<endl;
	
	cout<<"Enter any number of your choice to insert at the start of the linked list: ";
	cin>>val_start;
	list.insert_start(val_start);
	cout<<"Linked list after inserting "<<val_start<<" on the beginning!: ";
	list.display();
	
	cout<<"Enter a value to insert at the end of the list: ";
	cin>>val_end;
	list.insert_end(val_end);
	cout<<endl<<"Displaying updated list after insertion at the end: ";
	list.display();
	
	cout<<"Enter a value to check if it is available in our list: ";
	cin>>val_search;
	list.search(val_search);
	list.display();
	
	cout<<"Enter a value you want to remove from the list: ";
	cin>>val_delete;
	list.deleteValue(val_delete);
	list.display();
	
	cout<<"This list is updated to remove consecutive duplicates: ";
	list.removeDuplicate();
	list.display();
	
	cout<<"This is a reversed list: ";
	list.reverseList();
	list.display();
	
	return 0;
}
