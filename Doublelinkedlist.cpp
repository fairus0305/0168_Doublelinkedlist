#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
    node *prev;
};

class Doublelinkedlist
{
private:
    node *START;

public:
    Doublelinkedlist()
    {
        START = NULL;
    }

    void addnode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        node *newnode = new node();

        // Step 2: Assign value to the data fields
        newnode->info = nim;

        // Step 3: Forward at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->info)
        {
            if (START != NULL && nim == START->info)
            {
                cout << "\nDuplicate roll numbers not allowed" << endl;
                return;
            }

         
        }
    }
}