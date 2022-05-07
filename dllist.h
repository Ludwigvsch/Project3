#ifndef CS20A_DLLIST_H
#define CS20A_DLLIST_H

#include<iostream>
#include<assert.h>
// Linked DLList object that maintains both head and tail pointers
// and the size of the list.  Note that you have to keep the head,
// tail and size consistent with the intended state of the DLList
// otherwise very bad things happen.
template<typename Item>
class DLList {
public:

    DLList();

    DLList(const DLList<Item>& other);

    DLList<Item>& operator=(const DLList<Item>& other);

    ~DLList();

    void    print() const;
    bool    empty() const;

    void    push_front(const Item &item);
    void    push_rear(const Item &item);
    void    push_at(int idx, const Item &item);

    // Note that the user must first ensure the list is not empty
    // prior to calling these functions.
    Item    front() const;
    Item    rear() const;
    Item    at(int idx) const;

    int        count() const;
    int        find(const Item &item) const;

    bool    pop_front();
    bool    pop_rear();
    bool    pop_at(int idx);
    int        pop_item(const Item &item);

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
    // Forward declare the nodes for our DLList.
    // Will be implemented along with list
    // member functions
    struct Node;

    // We'll have both head and tail points for
    // Fast insertion/deletion from both ends.
    Node*    head;
    Node*    tail;

    // Keep track of number of nodes in the list
    int        size;
};


/* DLList Implementation
//
//  Since DLList is a template class (which is not an actual
//  class yet, not until we actually instantiate the list)
//  we need to keep the implementation together with
//  the definition.  There are ways to simulate having
//  separate "implementation/definition" with templates,
//  but they aren't necessary and can be confusing.
*/

/* Node definition
//        Already implemented, nothing to do here but to use it.
*/
template<typename Item>
struct DLList<Item>::Node {
    Node() :next(nullptr), prev(nullptr) {}
    Node(Item it, Node* p, Node* n) : item(it), next(n), prev(p) {}

    Item  item;
    Node* next;
    Node* prev;
};

/* DLList default constructor
//        Set head and tail pointer to point to nothing, size is zero
//        Already implemented, nothing to do.
*/
template<typename Item>
DLList<Item>::DLList() :head(nullptr), tail(nullptr), size(0) {
    /*  DONE  */
}


/* Copy constructor
Copy constructor for the linked list. This should create an entirely new linked list 
with the same number of Nodes and the Items stored these Nodes in the same order as 
seen the other list’s Nodes. This should not result in any memory leaks or aliasing.
*/
template<typename Item>
DLList<Item>::DLList(const DLList<Item>& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node* curr = other.head;
    while (curr != nullptr)
    {
        push_rear(curr->item);
        curr = curr->next;
    }
}


/* Overloaded assignment operator
Overloaded assignment operator for the linked list. Causes the already existing 
linked list to be identical to the other linked list without causing any memory leaks or aliasing.
*/
template<typename Item>
DLList<Item>& DLList<Item>::operator=(const DLList<Item>& other) {
    if (this != &other)
    {
        while (head != nullptr)
        {
            pop_front();
        }
        Node* curr = other.head;
        while (curr != nullptr)
        {
            push_rear(curr->item);
            curr = curr->next;
        }
    }
    return *this;
}
    

/* DLList destructor
The list dynamically allocates nodes, that means when we 
destruct your list we need to ensure we deallocated the nodes appropriately to avoid memory leaks.
*/
template<typename Item>
DLList<Item>::~DLList() {
    while (head != nullptr) {
        pop_front();
    }
}

/* DLList print
Traverses the list and prints the items in the list in a single line with 
spaces in between each item. There are no spaces before the first word and 
after the last word. There is no newline after all items have been printed. 
For example suppose our list contains the strings “Cash”, “Shell”, and “Ruby”, 
print will display in the console:
Cash Shell Ruby
*/
template<typename Item>
void DLList<Item>::print() const {
    if (empty()) return;
    Node * curr = head;
    if (curr->next == nullptr) std::cout << curr->item;
    else {
        while (curr->next != nullptr) 
        {
            std::cout<<curr->item << " ";
            curr = curr->next;
        }
        std::cout << curr->item;
    }
}

/* DLList empty
returns boolean value indicating if the list is empty or not.
*/
template<typename Item>
bool DLList<Item>::empty() const {
    return size == 0;
}



/* DLList push_front
Adds item to a new Node at the Front of the list. Updates head, 
tail, and size accordingly. Must appropriately handle cases in 
which the list is empty and if there are nodes already in the list.
*/
template<typename Item>
void DLList<Item>::push_front(const Item &item) {
   Node* temp = new Node(item, nullptr, nullptr);
    if (head == nullptr) 
    {
        head = temp;
        tail = temp;
    }
    else 
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    size++;
}

    /* DLList push_rear
    Adds item to a new Node at the Rear of the list.
    Updates head, tail, and size accordingly. Must
    appropriately handle cases in which the list is empty and if there are nodes already in the list.
    */
    template <typename Item>
    void DLList<Item>::push_rear(const Item &item)
    {
        Node* temp = new Node(item, nullptr, nullptr);
    if (head == nullptr) 
    {
        head = temp;
        tail = temp;
    }
    else 
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
}

/* DLList push_at
Given an index, this function adds the item to a new Node at the index. 
Updates head, tail, and size accordingly. If the index is less than or 
equal to zero add the item to the front. If the index is greater than or
 equal to the size of the list, then add it to the rear. Otherwise add 
 the item at the index indicated. Indices begin at zero.
*/
template<typename Item>
void DLList<Item>::push_at(int idx, const Item &item) {
    if (idx <= 0)
    {
        push_front(item);
    }
    else if (idx >= size)
    {
        push_rear(item);
    }
    else
    {
        Node* temp = new Node(item, nullptr, nullptr);
        Node* curr = head;
        for (int i = 0; i < idx; i++)
        {
            curr = curr->next;
        }
        temp->next = curr;
        temp->prev = curr->prev;
        curr->prev->next = temp;
        curr->prev = temp;
        size++;
    }
}

/*  DLList front
returns the item in the Node at the front of the list without modifying the list. 
The function cannot be called if the list is empty.
*/
template<typename Item>
Item DLList<Item>::front() const {

    // This should never be tripped, this is just here to let
    // you know that you messed up with your usage, this function
    // is never called on an empty list.
    assert(head != nullptr);
    return head->item;
}

/* DLList rear
returns the item in the Node at the rear of the list without modifying the list. 
The function cannot be called if the list is empty.
*/
template<typename Item>
Item DLList<Item>::rear() const {

    // This should never be tripped, this is just here to let
    // you know that you messed up with your usage, this function
    // is never called on an empty list.
    assert(tail != nullptr);
    return tail->item;  
}

/* DLList at
returns the item in the Node in the index place of the list. Indices begin at zero.
*/
template<typename Item>
Item DLList<Item>::at(int idx) const {

    // Assert that index is correct before getting the Item
    assert(idx >= 0 && idx < size);

    Node* curr = head;
    for (int i = 0; i < idx; i++)
    {
        curr = curr->next;
    }
    return curr->item;
}


/* DLList count
returns the number of nodes currently in the list.
*/
template<typename Item>
int DLList<Item>::count() const {

   return size;
}

/* DLList find
Searches the list to see if the item is currently in the list. 
If it is, the function returns the index of the item, otherwise 
it returns -1. Indices begin at zero.
*/
template<typename Item>
int DLList<Item>::find(const Item &item) const {

    Node* curr = head;
    for (int i = 0; i < size; i++)
    {
        if (curr->item == item)
        {
            return i;
        }
        curr = curr->next;
    }
    return -1;
}


/* DLList pop_front
Removes the first item in the list, returns true if the item was deleted, 
false otherwise. Updates head, tail, and size accordingly. 
Must appropriately manage cases where the list is empty or has one or more items.
*/
template<typename Item>
bool DLList<Item>::pop_front() {

    if (head == nullptr)
    {
        return false;
    }
    else if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return true;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        size--;
        return true;
    }
}


/* DLList pop_rear
Removes the last item in the list, returns true if the item was deleted, 
false otherwise. Updates head, tail, and size accordingly. 
Must appropriately manage cases where the list is empty or has one item, 
or has two or more items.
*/
template<typename Item>
bool DLList<Item>::pop_rear() {

    if (head == nullptr)
    {
        return false;
    }
    else if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return true;
    }
    else
    {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        size--;
        return true;
    }
}

/* DLList pop_at on index
Removes the item at the index of the list, 
returns true if the item was deleted false otherwise. 
Updates head, tail, and size accordingly. If the 
indices are out of bound pop_at does nothing and 
returns false. Indices begin at zero.
*/
template<typename Item>
bool DLList<Item>::pop_at(int idx) {

    if (idx < 0 || idx >= size)
    {
        return false;
    }
    else if (idx == 0)
    {
        return pop_front();
    }
    else if (idx == size - 1)
    {
        return pop_rear();
    }
    else
    {
        Node* curr = head;
        for (int i = 0; i < idx; i++)
        {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
        return true;
    }
}


/* DLList pop_item on item
Removes the first occurrence of the item relative to the front 
of the list, returns the index of the removed item. If the list 
is empty return -2. Return -1 if the item is not found. Indices begin at zero.
*/
template<typename Item>
int DLList<Item>::pop_item(const Item &item) {

    if (head == nullptr)
    {
        return -2;
    }
    else
    {
        Node* curr = head;
        for (int i = 0; i < size; i++)
        {
            if (curr->item == item)
            {
                pop_at(i);
                return i;
            }
            curr = curr->next;
        }
        return -1;
    }
}


#endif


