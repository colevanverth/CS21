/*
* @author Cole Van Verth
* @pengo cverth
* @email colevanverth@gmail.com
* @file list.h
* @assignment 1: Review; Linked Lists
*/

#include <string>
#include <map> 

/*
 * @brief `List` is a doubly linked list that stores `ListNodes`. Elementary
 * methods are included for removing and adding `ListNodes` at the beginning
 * and end of the `List`. There is a head, tail, and a size that vary as the 
 * container changes. A `ListNode` cannot be instantiated * or modified 
 * outside of a `List` so a method is provided to accsess the data associated
 * with a `ListNode` pointer, in case a derived class of `List` requires that 
 * data. 
*/
class List {
    // Forward declaration 
    struct ListNode; 
public:
    // `List` default constructor
    List();

    // `List` default destructor
    ~List();

    // Creates a new `ListNode` with string input attatched to `List` end
    void insertEnd(std::string input);

    // Creates a new `ListNode` with string input attatched to `List` start
    void insertStart(std::string input);

    // Removes `ListNode` at `List` start
    void removeStart();

    // Removes `ListNode` at `List` end
    void removeEnd();

    // Returns string data associated with a `ListNode`
    std::string getData(ListNode* node);

    // Returns the number of elements in `List`
    size_t getSize();
    
    // Splices the list with another
    void splice(int pos, int len, List* otherList);

    // Reverses a list
    void reverse();

    // Returns a `ListNode` pointer to the `ListNode` at the end of the `List`
    ListNode* getTail();
    ListNode* removeNode(ListNode* Node); // Removes a `ListNode` 
    void removeDuplicates(); 
    ListNode* m_tail = nullptr;
    ListNode* m_head = nullptr;
    size_t m_size = 0;

private:
    /*
    * @brief `ListNode` is modular component that is used to build up a `List`.
    * As a `List` follows a doubly linked convention, each ListNode contains 
    * pointer variables that link the `ListNode` to adjacent `ListNodes`. The 
    * `ListNode` also contains a string that can be stored.     
    * */
    struct ListNode {
        ListNode();
        ListNode* left = nullptr;
        ListNode* right = nullptr;
        std::string data;
    };
};
