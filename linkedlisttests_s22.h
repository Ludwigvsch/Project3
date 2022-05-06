#ifndef PROJECT3_DLLTEST_H
#define PROJECT3_DLLTEST_H

#define MAKE_MEMBERS_PUBLIC

#include<iostream>
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include<iterator>
#include<vector>
#include<string>

#ifdef _MSC_VER // Visual Studio
#define __func__ __FUNCTION__
#endif

#include"debugmem.h"

// Blank out macros if debugmem.h is not included
#ifndef DEBUG_NEW
#define DEBUG_NEW new
#endif
#ifndef RESET()
#define RESET()
#endif
#ifndef GETMEMORYREPORT()
#define GETMEMORYREPORT()
#endif
#ifndef SIZE()
#define SIZE() 0
#endif

#include"dllist.h"

#include<assert.h>
#include<exception>
#include<functional>

int runTest(std::function<int(int)> test, int testNum) {
    int retval = 0;
    try {
        retval = test(testNum);
    }
    catch (const std::runtime_error& re) {
        std::cerr << "Runtime error: " << re.what() << std::endl;
        retval = 1;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
        retval = 1;
    }
    catch (...) {
        std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
        retval = 1;;
    }
    return retval;
}


//Test empty
int test_empty(int testNum) {
    std::cout <<__func__ <<testNum << std::endl;
    std::string name = std::string(__func__);
    switch (testNum) {
    case 0: {
        
        DLList<int> * l = new DLList<int>;

        assert(l->empty() == true);

        break;
    }
    case 1: {
        
        //Make some control nodes
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->empty() == false);
        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;
}


//Test push_front
int test_push_front(int testNum) {
    std::cout << __func__ << testNum << std::endl;
    std::string name = std::string(__func__);

    switch (testNum) {
    case 0: {

        DLList<int> * l = new DLList<int>;

        l->push_front(99);

        assert(l->head != nullptr);
        assert(l->tail != nullptr);

        assert(l->head->prev == nullptr);
        assert(l->head->next == nullptr);
        
        assert(l->head->item == 99);
        assert(l->size == 1);

        break;
    }
    case 1: {
    
        //Make some control nodes
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        //Now with the list given a complete and correct starting state
        //We can test various member functions for correctness.
        //For example we can use this as one test for push_front;
        l->push_front("Zero");

        //Examing the final state of our list after call
        assert(l->size == 4);
        assert(l->head != nullptr);
        assert(l->head->prev == nullptr);
        assert(l->head == first->prev);
        assert(l->head->next == first);
        assert(l->head->item == "Zero");
        assert(l->tail == third);
        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;
}

//Test push_rear
int test_push_rear(int testNum) {
    std::cout << __func__ << testNum << std::endl;
    std::string name = std::string(__func__);
    switch (testNum) {
    case 0: {

        DLList<int> * l = new DLList<int>;

        l->push_rear(99);
        assert(l->head != nullptr);
        assert(l->tail != nullptr);
        assert(l->head->prev == nullptr);
        assert(l->head->next == nullptr);
        assert(l->head->item == 99);
        assert(l->size == 1);
        break;
    }
    case 1: {

             //Make some control nodes
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        //Now with the list given a complete and correct starting state
        //We can test various member functions for correctness.
        //For example we can use this as one test for push_rear;
        l->push_rear("forth");

        //Examing the final state of our list after call
        assert(l->size == 4);
        assert(l->head != nullptr);
        assert(l->tail != nullptr);
        assert(l->head == first);
        assert(l->tail->next == nullptr);
        assert(l->tail->item == "forth");
        assert(l->tail->prev == third);
        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;
}

//Test push_at
int test_push_at(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl;
    switch (testNum) {
    case 0: {
        
        DLList<int> * l = new DLList<int>;

        l->push_at(0, 1);

        assert(l->head != nullptr);
        assert(l->tail != nullptr);

        assert(l->size == 1);
        assert(l->head->item == 1);
        assert(l->head == l->tail);
        
        assert(l->head->next == nullptr);
        assert(l->head->prev == nullptr);
        break;
        
    }
    case 1: {
    
        DLList<int> * l = new DLList<int>;

        l->push_at(-1, 1);

        assert(l->head != nullptr);
        assert(l->tail != nullptr);

        assert(l->size == 1);
        assert(l->head->item == 1);
        assert(l->head == l->tail);
        
        assert(l->head->next == nullptr);
        assert(l->head->prev == nullptr);
        break;
    }
    case 2: {
        DLList<int> * l = new DLList<int>;

        l->push_at(99, 1);

        assert(l->head != nullptr);
        assert(l->tail != nullptr);
        assert(l->head->item == 1);
        assert(l->size == 1);
        assert(l->head == l->tail);
        assert(l->head->next == nullptr);
        assert(l->head->prev == nullptr);
        break;
    }
    case 3: {
        //Make some control nodes
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = second;
        l->size = 2;

        l->push_at(0, "Zero");

        //Examing the final state of our list after call
        assert(l->head != nullptr);
        assert(l->tail != nullptr);
        assert(l->size == 3);
        assert(l->head->prev == nullptr);
        assert(l->head == first->prev);
        assert(l->head->next == first);
        assert(l->head->item == "Zero");
        assert(l->tail == second);

        break;
    }
    case 4: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = second;
        l->size = 2;

        l->push_at(-1, "Zero");

        //Examing the final state of our list after call
        assert(l->head != nullptr);
        assert(l->tail != nullptr);
        assert(l->size == 3);
        assert(l->head->prev == nullptr);
        assert(l->head == first->prev);
        assert(l->head->next == first);
        assert(l->head->item == "Zero");
        assert(l->tail == second);

        break;
    }
    case 5: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = second;
        l->size = 2;

        l->push_at(4, "third");
    
        //Examing the final state of our list after call
        assert(l->head != nullptr);
        assert(l->tail != nullptr);
        assert(l->size == 3);
        assert(l->head == first);
        assert(l->tail->next == nullptr);
        assert(l->tail->item == "third");
        assert(l->tail->prev == second);
        break;
    }
    case 6: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = second;
        l->size = 2;

        l->push_at(1, "half");
    
        //Examing the final state of our list after call
        assert(l->size == 3);
        assert(l->head == first);

        assert(l->head != nullptr);
        assert(l->tail != nullptr);

        assert(l->head->prev == nullptr);
        assert(l->head->next->item == "half");
        assert(l->tail->prev == l->head->next);
        assert(l->tail == second);
        assert(l->tail->next == nullptr);
        assert(l->head->next->next == l->tail);
        assert(l->head == l->tail->prev->prev);
        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;
}

//Test find
int test_find(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl;
    switch (testNum) {
    case 0: {
        DLList<int> * l = new DLList<int>;

        assert(l->find(100)==-1);

        break;
    }
    case 1: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        //Examing the final state of our list after call
        assert(l->find("Zero") == -1);
        assert(l->find("first") == 0);
        assert(l->find("second") == 1);
        assert(l->find("third") == 2);
        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;
        

    }
    return 0;
}

//Test front
int test_front(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl;
    switch (testNum) {
    case 0: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;


        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->front() == "first");
        break;
    }
    case 1: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->front() == "first");
        break;
    }

    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;
    

    }
    return 0;
}


//Test rear
int test_rear(int testNum) {
    std::string name = std::string(__func__);
    
    std::cout << __func__ << testNum << std::endl;
    switch (testNum) {
    case 0: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->rear() == "first");
        break;
    }
    case 1: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->rear() == "third");
        break;
    }

    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;
}
//Test at
int test_at(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl;
    switch (testNum) {
    case 0: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;


        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->at(0) == "first");
        break;
    }
    case 1: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->at(0) == "first");
        assert(l->at(1) == "second");
        assert(l->at(2) == "third");
        break;
    }
    
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;
    }
    return 0;
}

//Test pop_front
int test_pop_front(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl;
    switch (testNum) {
    case 0: {
        DLList<int> * l = new DLList<int>;
        assert(l->pop_front() == false);
        break;
    }
    case 1: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;


        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->pop_front() == true);
        assert(l->size == 0);
        assert(l->head == nullptr);
        assert(l->tail == nullptr);
        break;
    }
    case 2: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->pop_front() == true);
        assert(l->size == 2);
        assert(l->head == second);
        assert(l->tail == third);
        assert(l->head->prev == nullptr);
        break;
    }
    
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;
}
//Test pop_rear
int test_pop_rear(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl;
    switch (testNum) {
    case 0: {
        DLList<int> * l = new DLList<int>;
        assert(l->pop_rear() == false);
        break;

    }
    case 1: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;


        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->pop_rear() == true);
        assert(l->size == 0);
        assert(l->head == nullptr);
        assert(l->tail == nullptr);
        break;
    }
    case 2: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->pop_rear() == true);
        assert(l->size == 2);
        assert(l->head == first);
        assert(l->tail == second);
        assert(l->tail->next == nullptr);
        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;
    }
    return 0;
}


int test_pop_at(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl <<std::flush;
    switch (testNum) {
    case 0: {
        DLList<int> * l = new DLList<int>;
        assert(l->pop_at(-1) == false);
        break;
    }
    case 1: {
        DLList<int> * l = new DLList<int>;
        assert(l->pop_at(9999) == false);
        break;
    }
    case 2: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->pop_at(-1) == false);

        break;
    }
    case 3: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;


        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->pop_at(9999) == false);

        break;
    }
    case 4: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;


        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->pop_at(0) == true);
        assert(l->size == 0);
        assert(l->head == nullptr);
        assert(l->tail == nullptr);
        break;
    }
    case 5: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->pop_at(0) == true);
        assert(l->size == 2);
        assert(l->head == second);
        assert(l->head->prev == nullptr);
        assert(l->tail == third);
        break;

    }
    case 6: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->pop_at(2) == true);
        assert(l->size == 2);
        assert(l->head == first);
        assert(l->tail->next == nullptr);
        assert(l->tail == second);
        break;

    }
    case 7: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->pop_at(1) == true);
        assert(l->size == 2);

        assert(l->head == first);
        assert(l->tail == third);

        assert(l->head->next == third);
        assert(l->tail->prev == first);
        break;


    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;
}

int test_pop_item(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl << std::flush;
    switch (testNum) {
    case 0: {//Test with empty list
        DLList<int> * l = new DLList<int>;
        assert(l->pop_item(1) == -2);
        break;
    }
    case 1: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->pop_item("second") == -1);

        break;
    }

    case 2: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = nullptr;


        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = first;
        l->size = 1;

        assert(l->pop_item("first") == 0);
        assert(l->size == 0);
        assert(l->head == nullptr);
        assert(l->tail == nullptr);
        break;
    }
    case 3: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->pop_item("first") == 0);
        assert(l->size == 2);
        assert(l->head == second);
        assert(l->head != nullptr);
        assert(l->head->prev == nullptr);
        assert(l->tail == third);
        break;

    }
    case 4: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->pop_item("third") == 2);
        assert(l->size == 2);
        assert(l->head == first);
        assert(l->tail != nullptr);
        assert(l->tail->next == nullptr);
        assert(l->tail == second);
        break;

    }
    case 5: {
        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = "first";
        first->prev = nullptr;
        first->next = second;

        second->item = "second";
        second->prev = first;
        second->next = third;

        third->item = "third";
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->pop_item("second") == 1);
        assert(l->size == 2);

        assert(l->head == first);
        assert(l->tail == third);

        assert(l->head != nullptr);
        assert(l->tail != nullptr);
        assert(l->head->next == third);
        assert(l->tail->prev == first);

        break;


    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;
}
int test_print(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl << std::flush;
    switch (testNum) {
    case 0: {

        std::string test_string1("Tom Dick Mary");
        std::stringstream buffer(test_string1);
        std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
        buffer.str("");

        DLList<std::string>::Node* first = new DLList<std::string>::Node;
        DLList<std::string>::Node* second = new DLList<std::string>::Node;
        DLList<std::string>::Node* third = new DLList<std::string>::Node;

        //Link together to make a valid linked list
        first->item = test_vector[0];
        first->prev = nullptr;
        first->next = second;

        second->item = test_vector[1];
        second->prev = first;
        second->next = third;

        third->item = test_vector[2];
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

        l->print();
        std::cout.rdbuf(old);

        std::string text = buffer.str();

        std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
            std::istream_iterator<std::string>() };

        assert(text.length() == test_string1.length());
        assert(text == test_string1);
        for (int i = 0; i < ret.size(); i++) {
            assert(ret[i] == test_vector[i]);
        }



        break;

    }
    case 1: {

        std::string test_string1("");
        std::stringstream buffer(test_string1);
        std::vector<std::string> test_vector{ std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>() };
        buffer.str("");

        //Assume Constructor Correctly Implemented
        DLList<std::string> * l = new DLList<std::string>;

        //hijack cout buffer
        std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());

        l->print();

        //restore cout buffer
        std::cout.rdbuf(old);

        std::string text = buffer.str();
        std::vector<std::string> ret{ std::istream_iterator<std::string>(buffer),
            std::istream_iterator<std::string>() };

        assert(text.length() == test_string1.length() );
        assert(text == test_string1);
        for (int i = 0; i < ret.size(); i++) {
            assert(ret[i] == test_vector[i]);
        }

        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;

}
int test_count(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl << std::flush;
    switch (testNum) {
    case 0: {

        DLList<int>::Node* first = new DLList<int>::Node;
        DLList<int>::Node* second = new DLList<int>::Node;
        DLList<int>::Node* third = new DLList<int>::Node;

        //Link together to make a valid linked list
        first->item = 2;
        first->prev = nullptr;
        first->next = second;

        second->item = 4;
        second->prev = first;
        second->next = third;

        third->item = 76;
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<int> * l = new DLList<int>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        assert(l->count() == 3);

        break;

    }
    case 1: {
        DLList<std::string> * l = new DLList<std::string>;
        assert(l->count() == 0);
        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;

}

int test_copyCtor(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl << std::flush;
    switch (testNum) {
    case 0: {

        DLList<int> * l = new DLList<int>;
        DLList<int> * p = new DLList<int>(*l);

        //Set up the initial state of the list to test
        assert(p->head==nullptr);
        assert(p->tail == nullptr);
        assert(p->size == 0);

        break;

    }

    case 1: {


        DLList<int>::Node* first = new DLList<int>::Node;
        DLList<int>::Node* second = new DLList<int>::Node;
        DLList<int>::Node* third = new DLList<int>::Node;

        //Link together to make a valid linked list
        first->item = 2;
        first->prev = nullptr;
        first->next = second;

        second->item = 4;
        second->prev = first;
        second->next = third;

        third->item = 76;
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<int> * l = new DLList<int>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;
         
        DLList<int> * p = new DLList<int>(*l);

        assert(p->head != nullptr );
        assert(p->tail != nullptr);
        assert(p->size == 3);

        assert(p->head->item == first->item);
        assert(p->head->next->item == second->item);
        assert(p->tail->prev->item == second->item);
        assert(p->tail->item == third->item);

        assert(p->head != first);
        assert(p->tail != third);

        break;


    }
    case 2: {
        DLList<int>::Node* first = new DLList<int>::Node;
        DLList<int>::Node* second = new DLList<int>::Node;
        DLList<int>::Node* third = new DLList<int>::Node;

        //Link together to make a valid linked list
        first->item = 2;
        first->prev = nullptr;
        first->next = second;

        second->item = 4;
        second->prev = first;
        second->next = third;

        third->item = 76;
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<int> * l = new DLList<int>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        DLList<int> * p = new DLList<int>(*l);

        assert(p->head != nullptr);
        assert(p->tail != nullptr);
        assert(p->size == 3);

        assert(p->head->item == first->item);
        assert(p->head->next->item == second->item);
        assert(p->tail->prev->item == second->item);
        assert(p->tail->item == third->item);


        //check aliasing
        assert(p->head != first);
        assert(p->head != second);
        assert(p->head != third);

        assert(p->head->next != first);
        assert(p->head->next != second);
        assert(p->head->next != third);

        assert(p->tail != first);
        assert(p->tail != second);
        assert(p->tail != third);

        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;

}


int test_assgnOper(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl << std::flush;
    switch (testNum) {
    case 0: {

        DLList<int> * l = new DLList<int>;
        DLList<int> * p = new DLList<int>;

        *p = *l;
        //Set up the initial state of the list to test

        assert(p->head == nullptr);
        assert(p->tail == nullptr);
        assert(p->size == 0);

        break;

    }

    case 1: {

        DLList<int>::Node* first = new DLList<int>::Node;
        DLList<int>::Node* second = new DLList<int>::Node;
        DLList<int>::Node* third = new DLList<int>::Node;

        //Link together to make a valid linked list
        first->item = 2;
        first->prev = nullptr;
        first->next = second;

        second->item = 4;
        second->prev = first;
        second->next = third;

        third->item = 76;
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<int> * l = new DLList<int>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        DLList<int> * p = new DLList<int>;

        *p = *l;

        assert(p->head != nullptr);
        assert(p->tail != nullptr);
        assert(p->size == 3);

        assert(p->head->item == first->item);
        assert(p->head->next->item == second->item);
        assert(p->tail->prev->item == second->item);
        assert(p->tail->item == third->item);

        assert(p->head != first);
        assert(p->tail != third);

        break;


    }
    
    case 2: {
        DLList<int>::Node* first = new DLList<int>::Node;
        DLList<int>::Node* second = new DLList<int>::Node;
        DLList<int>::Node* third = new DLList<int>::Node;

        //Link together to make a valid linked list
        first->item = 2;
        first->prev = nullptr;
        first->next = second;

        second->item = 4;
        second->prev = first;
        second->next = third;

        third->item = 76;
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        DLList<int> * l = new DLList<int>;

        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;

        DLList<int> * p = new DLList<int>;

        *p = *l;

        assert(p->head != nullptr);
        assert(p->tail != nullptr);
        assert(p->head->next != nullptr);
        assert(p->tail->prev != nullptr);

        assert(p->size == 3);

        assert(p->head->item == first->item);
        assert(p->head->next->item == second->item);
        assert(p->tail->prev->item == second->item);
        assert(p->tail->item == third->item);


        //check aliasing
        assert(p->head != first);
        assert(p->head != second);
        assert(p->head != third);

        assert(p->head->next != first);
        assert(p->head->next != second);
        assert(p->head->next != third);

        assert(p->tail != first);
        assert(p->tail != second);
        assert(p->tail != third);

        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;

}


int test_mem_destructor(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl << std::flush;
    switch (testNum) {
    case 0: {
        RESET();
        DLList<int>::Node* first = DEBUG_NEW DLList<int>::Node;
        DLList<int>::Node* second = DEBUG_NEW DLList<int>::Node;
        DLList<int>::Node* third = DEBUG_NEW DLList<int>::Node;

        //Link together to make a valid linked list
        first->item = 2;
        first->prev = nullptr;
        first->next = second;

        second->item = 4;
        second->prev = first;
        second->next = third;

        third->item = 76;
        third->prev = second;
        third->next = nullptr;

        //Assume Constructor Correctly Implemented
        {
            DLList<int> * l = new DLList<int>;

            //Set up the initial state of the list to test
            l->head = first;
            l->tail = third;
            l->size = 3;

            //destructor
            delete l;
        }

        //GETMEMORYREPORT();
        if (SIZE() != 0) {
            std::cerr << "Destructor: Memory Leak detected" << std::endl;
        }
        assert(SIZE() == 0);

        break;

    }

    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;

    }
    return 0;
}

int test_mem_assgnOper(int testNum) {
    std::string name = std::string(__func__);
    std::cout << __func__ << testNum << std::endl << std::flush;
    switch (testNum) {
    case 0: {
        //Assume Constructor Correctly Implemented
        DLList<int> * l = new DLList<int>;
        DLList<int> * p = new DLList<int>;

        RESET();

        DLList<int>::Node* first = DEBUG_NEW DLList<int>::Node;
        DLList<int>::Node* second = DEBUG_NEW DLList<int>::Node;
        DLList<int>::Node* third = DEBUG_NEW DLList<int>::Node;

        //Link together to make a valid linked list
        first->item = 2;
        first->prev = nullptr;
        first->next = second;

        second->item = 4;
        second->prev = first;
        second->next = third;

        third->item = 76;
        third->prev = second;
        third->next = nullptr;


        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;
                
        *l = *p;

        //GETMEMORYREPORT();
        if (SIZE() != 0) {
            std::cerr << "Assign Op: Memory Leak detected" << std::endl;
        }
        assert(SIZE() == 0);
        break;
    }
    case 1: {

        //Assume Constructor Correctly Implemented
        DLList<int> * l = new DLList<int>;

        RESET();
        DLList<int>::Node* first = DEBUG_NEW DLList<int>::Node;
        DLList<int>::Node* second = DEBUG_NEW DLList<int>::Node;
        DLList<int>::Node* third = DEBUG_NEW DLList<int>::Node;

        //Link together to make a valid linked list
        first->item = 2;
        first->prev = nullptr;
        first->next = second;

        second->item = 4;
        second->prev = first;
        second->next = third;

        third->item = 76;
        third->prev = second;
        third->next = nullptr;

    
        //Set up the initial state of the list to test
        l->head = first;
        l->tail = third;
        l->size = 3;
        //GETMEMORYREPORT();

        *l = *l;
        if (SIZE() != 3) {
            std::cerr << "Assign Op: Improper assignment" << std::endl;
        }
        assert(SIZE() == 3);
        break;
    }
    default:
        std::cout << __func__ << " No Such Test: " << testNum << std::endl << std::flush;
        return -1;
    }
    return 0;

}


#endif
