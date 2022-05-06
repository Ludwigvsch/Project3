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

*/
template<typename Item>
DLList<Item>::DLList(const DLList<Item>& other) {
    
}
/* Overloaded assignment operator
*/
template<typename Item>
DLList<Item>& DLList<Item>::operator=(const DLList<Item>& other) {

    /*  TODO  */

    return *this;
}

/* DLList destructor
*/
template<typename Item>
DLList<Item>::~DLList() {

    /*  TODO  */

}

/* DLList print
*/
template<typename Item>
void DLList<Item>::print() const {

    /*  TODO  */

}

/* DLList empty
*/
template<typename Item>
bool DLList<Item>::empty() const {

    /*  TODO  */

    bool dummyReturnValue = false;
    return dummyReturnValue;
}


/* DLList push_front
*/
template<typename Item>
void DLList<Item>::push_front(const Item &item) {

    /*  TODO  */

}

/* DLList push_rear
*/
template<typename Item>
void DLList<Item>::push_rear(const Item &item) {

    /*  TODO  */

}

/* DLList push_at
*/
template<typename Item>
void DLList<Item>::push_at(int idx, const Item &item) {

    /*  TODO  */

}

/*  DLList front
*/
template<typename Item>
Item DLList<Item>::front() const {

    // This should never be tripped, this is just here to let
    // you know that you messed up with your usage, this function
    // is never called on an empty list.
    assert(head != nullptr);
    
    
    /*  TODO  */

    Item dummyReturnValue;
    return dummyReturnValue;

}

/* DLList rear
*/
template<typename Item>
Item DLList<Item>::rear() const {

    // This should never be tripped, this is just here to let
    // you know that you messed up with your usage, this function
    // is never called on an empty list.
    assert(tail != nullptr);

    /*  TODO  */

    Item dummyReturnValue;
    return dummyReturnValue;
    
}

/* DLList at
*/
template<typename Item>
Item DLList<Item>::at(int idx) const {

    // Assert that index is correct before getting the Item
    assert(idx >= 0 && idx < size);

    /*  TODO  */

    Item dummyReturnValue;
    return dummyReturnValue;
}

/* DLList count
*/
template<typename Item>
int DLList<Item>::count() const {

    /*  TODO  */

    int dummyReturnValue = 9000;
    return dummyReturnValue;
}

/* DLList find
*/
template<typename Item>
int DLList<Item>::find(const Item &item) const {

    /*  TODO  */

    int dummyReturnValue = 8675309;
    return dummyReturnValue;
}

/* DLList pop_front
*/
template<typename Item>
bool DLList<Item>::pop_front() {

    /*  TODO  */

    bool dummyReturnValue = false;
    return dummyReturnValue;
}
/* DLList pop_rear
*/
template<typename Item>
bool DLList<Item>::pop_rear() {

    /*  TODO  */

    bool dummyReturnValue = false;
    return dummyReturnValue;
}

/* DLList pop_at on index
*/
template<typename Item>
bool DLList<Item>::pop_at(int idx) {

    /*  TODO  */

    bool dummyReturnValue = false;
    return dummyReturnValue;

}

/* DLList pop_item on item
*/
template<typename Item>
int DLList<Item>::pop_item(const Item &item) {

    /*  TODO  */
    int dummyReturnValue = 42;
    return dummyReturnValue;
}

#endif



























































































// _X_XMXXII
