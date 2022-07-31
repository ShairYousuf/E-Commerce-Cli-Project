
#include<bits/stdc++.h>
using namespace std;


template <typename T1, typename T2, typename T3, typename T4> class Node{
    public: 
    T1 ID;
    T2 Name;
    T3 Email;
    T4 Phone;
    //history array; know name of class. similar to node type

    Node(){

    };

    Node(T1 id, T2 name, T3 email, T4 phone) //add history array
    {
      ID = id;
      Name = name;
      Email = email;
      Phone = phone;
    //add history array

    }
};


template <typename T1, typename T2, typename T3, typename T4> class CustomerHistoryQueue
{
	// Initialize front and rear
	int rear, front;

	// Circular Queue
	int size;
    int currentsize;
	Node <T1, T2, T3, T4> *arr;
public:
	CustomerHistoryQueue(int s)
	{
	front = rear = -1;
	size = s;
    currentsize=0;
	arr = new Node<T1, T2, T3, T4>[s];
	}

    
    
    //Function to add to circular queue
    void enQueue(T1 id, T2 name, T3 email, T4 phone)//add history array
{
    Node <T1, T2, T3, T4>node = Node <T1, T2, T3, T4>(id, name, email, phone);//add history array

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
void deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}


	arr[front] = Node<T1, T2, T3, T4>();
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

void displayQueue()
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

			
			Node <T1, T2, T3, T4>n = arr[i];
            cout<<"ID:"<< n.ID<<", Name: "<<n.Name<<", Email: "<<n.Email<<", Phone: "<<n.Phone<<", "; //add history array
		}
		    
	}
	else
	{
		for (int i = front; i < size; i++){
		Node <T1, T2, T3, T4>n = arr[i];
         cout<<"ID:"<< n.ID<<", Name: "<<n.Name<<", Email: "<<n.Email<<", Phone: "<<n.Phone<<", "; //add history array
		}
		for (int i = 0; i <= rear; i++){
			Node <T1, T2, T3, T4>n = arr[i];
             cout<<"ID:"<< n.ID<<", Name: "<<n.Name<<", Email: "<<n.Email<<", Phone: "<<n.Phone<<", "; //add history array
		}
	}
}



//function to search for specific ID and print info associated with it
void printCustomerInfo(T1 idnumber){
    for (int i=0; i<=currentsize; i++)
    {
        Node <T1, T2, T3, T4>n = arr[i];
        if (n.ID == idnumber)
        {
            cout<<"Here is your customer information: ID: "<< n.ID<<", Name: "<<n.Name<<", Email: "<<n.Email<<", Phone: "<<n.Phone<<", "; //add history array
            return;
        }
    }
    cout<<"The ID was not found in the customer database.";
}





};









/* Driver of the program */
int main()
{
	CustomerHistoryQueue <int, string, string, string> q(5);

	// Inserting elements in Circular Queue
	q.enQueue(1569, "snaazzy", "snzyemail", "709876543");
	q.enQueue(1213, "hello", "hello", "hello");
	q.enQueue(5674, "youdad", "dadsemail", "69696969");
	q.enQueue(9854, "hi", "hi", "hi");

	// Display elements present in Circular Queue
	q.displayQueue();
    q.deQueue();
    q.deQueue();

	q.displayQueue();

//	q.enQueue(9009, "your mom", "yourmom@gmail.com", "70942065");
//	q.enQueue(2056, "krishna", "krishna@mun.ca", "7091234567");
//	q.enQueue(5271, "anna", "asbehm@mun.ca", "7098950536" );

  //  q.printCustomerInfo(5271);
//	q.displayQueue();

//	q.enQueue(2053, "jo", "ma", "ma");
	return 0;
}