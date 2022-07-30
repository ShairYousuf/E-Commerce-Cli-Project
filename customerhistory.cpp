
#include<bits/stdc++.h>
using namespace std;


class Node{
    public: 
    int ID;
    string Name;
    string Email;
    string Phone;
    //history array; know name of class. similar to node type

    Node(){

    };

    Node(int id, string name, string email, string phone ) //add history array
    {
      ID = id;
      Name = name;
      Email = email;
      Phone = phone;
    //add history array

    }
};


class CustomerHistoryQueue
{
	// Initialize front and rear
	int rear, front;

	// Circular Queue
	int size;
    int currentsize;
	Node *arr;
public:
	CustomerHistoryQueue(int s)
	{
	front = rear = -1;
	size = s;
    currentsize=0;
	arr = new Node[s];
	}

	void enQueue(int id, string name, string email, string phone);//add history array
	void deQueue();
	void displayQueue();
    void printCustomerInfo(int idnumber);
};


//Function to add to circular queue

void CustomerHistoryQueue::enQueue(int id, string name, string email, string phone)//add history array
{
    Node node = Node (id, name, email, phone);//add history array

    //check to see if the queue is full (has 5 items). if so, delete it

    if (currentsize == 5)
	{
		printf("\nQueue is Full, Deleting the Oldest Member and Adding New Customer");
        deQueue();
		
	}

    currentsize +=1;

	if (front == -1) //insert first element
	{
		front = rear = 0;
		arr[rear] = node;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = node;
	}

	else
	{
		rear++;
		arr[rear] = node;
	}
}

// Function to delete element from queue
void CustomerHistoryQueue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}


	arr[front] = Node();
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

    currentsize-=1;
	return;

}

// to display the elements of the queue

void CustomerHistoryQueue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\n Customer Information: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++){

			
			Node n = arr[i];
            cout<<"ID:"<< n.ID<<", Name: "<<n.Name<<", Email: "<<n.Email<<", Phone: "<<n.Phone<<", "; //add history array
		}
		    
	}
	else
	{
		for (int i = front; i < size; i++){
		Node n = arr[i];
         cout<<"ID:"<< n.ID<<", Name: "<<n.Name<<", Email: "<<n.Email<<", Phone: "<<n.Phone<<", "; //add history array
		}
		for (int i = 0; i <= rear; i++){
			Node n = arr[i];
             cout<<"ID:"<< n.ID<<", Name: "<<n.Name<<", Email: "<<n.Email<<", Phone: "<<n.Phone<<", "; //add history array
		}
	}
}



//function to search for specific ID and print info associated with it
void CustomerHistoryQueue::printCustomerInfo(int idnumber){
    for (int i=0; i<=currentsize; i++)
    {
        Node n = arr[i];
        if (n.ID == idnumber)
        {
            cout<<"Here is your customer information: ID: "<< n.ID<<", Name: "<<n.Name<<", Email: "<<n.Email<<", Phone: "<<n.Phone<<", "; //add history array
            return;
        }
    }
    cout<<"The ID was not found in the customer database.";
}





/* Driver of the program */
int main()
{
	CustomerHistoryQueue q(5);

	// Inserting elements in Circular Queue
	q.enQueue(1569, "snaazzy", "snzyemail", "709876543");
	q.enQueue(1213, "hello", "hello", "hello");
	q.enQueue(5674, "youdad", "dadsemail", "69696969");
	q.enQueue(9854, "hi", "hi", "hi");

	// Display elements present in Circular Queue
	q.displayQueue();
   // q.deQueue();
    //q.deQueue();

//	q.displayQueue();

//	q.enQueue(9009, "your mom", "yourmom@gmail.com", "70942065");
//	q.enQueue(2056, "krishna", "krishna@mun.ca", "7091234567");
//	q.enQueue(5271, "anna", "asbehm@mun.ca", "7098950536" );

  //  q.printCustomerInfo(5271);
//	q.displayQueue();

//	q.enQueue(2053, "jo", "ma", "ma");
	return 0;
}