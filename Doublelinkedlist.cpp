// doubly linked list
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newNode = new Node();

        // Step 2: Assign value to the data field
        newNode->noMhs = nim;

        // Step 3: Insert at beginning if list is empty or no is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "Duplicate number not allowed" << endl;
                return;
            }

            // Step 4: make newNode->next = START
            newNode->next = START;

            // Step 5: START->prev = newNode (if START exists)
            if (START != NULL)
                START->prev = newNode;

            // Step 6: newNode->prev = NULL
            newNode->prev = NULL;

            // Step 7: START = newNode
            START = newNode;
            return;
        }

        // insert in between nodes
        // Step 8: locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "Duplicate roll numbers not allowed" << endl;
            return;
        }

        // Step 9: insert between current and current->next
        newNode->next = current->next; // Step 3a: newNode->next = current->next
        newNode->prev = current;       // Step 3b: newNode->prev = current

        // insert last node
        if (current->next != NULL)
            current->next->prev = newNode; // Step 3c: current->next->prev = newNode

        current->next = newNode; // Step 3d: current->next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

       Node *current = START;

        // Step 1: Traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // Step 2: If node is at the beginning
        if (current == START)
        {
            START = current->next; // Step 2a: START = START->next

            if (START != NULL)
                START->prev = NULL; // Step 2b: START->prev = NULL
        }
        else
        {
            // Step 3: Link previous node to next of current
            current->prev->next = current->next;

            // Step 4: If current is not last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // Step 5: Delete the node
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: point first node as currentNode
        Node *currentNode = START;

        // Step 2: Repeat until currentNode == NULL
        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << endl;

            // Step 3: Move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revTraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
