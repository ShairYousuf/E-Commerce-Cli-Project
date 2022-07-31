#ifndef SORTING_H
#define SORTING_H

#include <iostream>
using namespace std;
#include <string>
#include<sstream>
#include<cmath>

//variable for data sorting made global as used in two functions 
int hyear;
int hmonth;
int hday;
int year;
int month;
int day;
//Template definition
template <class T,class T2,class T3>
class Sort
{
    public:
    string name;
    T price;
    T2 quantity;
    string expiry;
    T3 priority;
    Sort* next;
    string date;

    //Node for price sorting
    Sort* newNode(string name,T price,T2 quantity,string date)
    {
        Sort* temp = new Sort();
        temp->name = name;
        temp->price=price;
        temp->quantity=quantity;
        temp->priority=price;
        temp->date=date;
        temp->next = NULL;
        return temp;
    }
    // Return the value at head
    int peek(Sort** head) 
    { 
        return (*head)->name; 
    }
    // Removes the element with the
    // highest priority form the list
    void pop(Sort** head)
    {
        Sort* temp = *head;
        (*head) = (*head)->next;
        delete[] temp;

    }
    // Function to push according to priority
    void push(Sort** head, string name,T price,T2 quantity)
    {
        Sort* start = (*head);
        // Create new Sort
        Sort* temp = newNode(name, price,quantity);
        // Special Case: The head of list has
        // lesser priority than new node
        if ((*head)->priority > price) 
        {
        // Insert New Sort before head
            temp->next = *head;
            (*head) = temp;
        }
        else 
        {
        // Traverse the list and find a
        // position to insert new node
            while (start->next != NULL && start->next->priority < price)
            {
                start = start->next;
            }
            // Either at the ends of the list
            // or at required position
            temp->next = start->next;
            start->next = temp;
        }
    }
    //New node for date sorting
    Sort* newNode1(string name,T price,T2 quantity,string date)
    {
        Sort* temp = new Sort();
        temp->name = name;
        temp->price=price;
        temp->quantity=quantity;
        temp->date=date;
        temp->priority=date;
        temp->next = NULL;
        return temp;
    }
     //Function to convert the expiry date of existing head item
    void convertHeadDate(Sort* head_ref)
        {
            
            stringstream ss;
            ss<<(head_ref->priority.at(0)+head_ref->priority.at(1)+head_ref->priority.at(2)+head_ref->priority.at(3));
            ss>>hyear;
            ss<<(head_ref->priority.at(5)+head_ref->priority.at(6));
            ss>>hmonth;
            ss<<(head_ref->priority.at(8)+head_ref->priority.at(8));
            ss>>hday;
        }
        //Function to convert the expiry date of new item being added to queue
    void converttempDate(Sort* temp_ref)
        {
            
            stringstream ss;
            ss<<(temp_ref->priority.at(0)+(temp_ref)->priority.at(1)+(temp_ref)->priority.at(2)+(temp_ref)->priority.at(3));
            ss>>year;
            ss<<(temp_ref->priority.at(5)+(temp_ref)->priority.at(6));
            ss>>month;
            ss<<(temp_ref->priority.at(8)+(temp_ref)->priority.at(8));
            ss>>day;
        }
    void pushDate(Sort** head, string name,T price,T2 quantity,string date)
    {
        
        stringstream ss;
        Sort* start = (*head);
        // Create new Sort
        Sort* temp = newNode1(name, price,quantity,date);
        // Special Case: The head of list has
        // lesser priority than new node
        //converts head
       convertHeadDate(*head);
        converttempDate(temp);
        //converts current temp
        if (hyear>=year &&hmonth>=month &&hday>day ) 
        {
        // Insert New Sort before head
            temp->next = *head;
            (*head) = temp;
        }
        else 
        {
        // Traverse the list and find a
        // position to insert new node
            Sort *current=start->next;
            //coverts current "Head"
            convertHeadDate(current);
            while (start->next != NULL && hyear<=year &&hmonth<=month&&hday<day)
            {
                start = start->next;
            }
            // Either at the ends of the list
            // or at required position
            temp->next = start->next;
            start->next = temp;
        }
    }
    void printQueue(Sort **head,string option)
    {
        int i=1;
        Sort*temp=*head;
        if(option=="price")
        {   cout<<"---------------------"<<endl;
            cout<<"---------------------"<<endl;
            cout<<"Items sorted in Price"<<endl;
            cout<<"---------------------"<<endl;
            cout<<"---------------------"<<endl;
        }
        else
        {
            cout<<"---------------------"<<endl;
            cout<<"---------------------"<<endl;
            cout<<"Items sorted in Date"<<endl;
            cout<<"---------------------"<<endl;
            cout<<"---------------------"<<endl;
        }
        while(temp->next!=NULL)
        {
            cout<<i<<" : "<<temp->name<<" | "<<temp->price<<" | "<<temp->quantity<<" | "<<temp->date<<" | "<<endl;
            temp=temp->next;
            i++;
        }
        
    }
    void ClearQueue(Sort **head)
    {
        while ((*head)->next!=NULL)
        {
            pop(head);
        }
    }
};
#endif