# 🏗️ **Stack Implementation Using Node Pointers in C++**

This repository contains an implementation of a **stack** using linked list nodes in C++. The stack follows the **LIFO (Last In, First Out)** principle, where the last element pushed onto the stack is the first one to be popped off. The implementation uses dynamic memory allocation and provides basic stack operations.

---

## 🌟 **Features**

- **push(t newItem)**: Adds a new item to the top of the stack.
- **pop()**: Removes the top item from the stack.
- **pop(t& stackTop)**: Removes the top item from the stack and returns it in the reference parameter.
- **getTop(t& stackTop)**: Returns the top item without removing it from the stack.
- **isEmpty()**: Checks if the stack is empty.
- **display()**: Displays the elements in the stack from top to bottom.

---

## 🔍 **Code Structure**

### **Stack Class - `stack`**

The class `stack` provides the following methods:
- **`push(t newItem)`**: Adds an item to the top of the stack.
- **`pop()`**: Removes the top item from the stack.
- **`pop(t& stackTop)`**: Removes the top item from the stack and returns it via a reference.
- **`getTop(t& stackTop)`**: Retrieves the top item without removing it from the stack.
- **`isEmpty()`**: Returns `true` if the stack is empty, `false` otherwise.
- **`display()`**: Prints the stack from top to bottom.

---

## 📋 **Example Usage**

```cpp
#include <iostream>
#include <string>
using namespace std;

template<class t>
class stack{
    struct node{
        t item;
        node* next;
    };
    node* top, *cur;
public:
    stack() {
        top = NULL;
    }

    void push(t newItem) {
        node* newItemPtr = new node;
        if (newItemPtr == NULL) {
            cout << "STACK push cannot allocate memory";
        } else {
            newItemPtr->item = newItem;
            newItemPtr->next = top;
            top = newItemPtr;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    void pop() {
        if (isEmpty()) {
            cout << "stack is empty" << "\n";
        } else {
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void pop(t& stackTop) {
        if (isEmpty()) {
            cout << "stack is empty" << "\n";
        } else {
            stackTop = top->item;
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void getTop(t& stackTop) {
        if (isEmpty()) {
            cout << "stack is empty" << "\n";
        } else {
            stackTop = top->item;
        }
    }

    void display() {
        cur = top;
        cout << "[";
        while (cur != NULL) {
            cout << cur->item << "  ";
            cur = cur->next;
        }
        cout << "]\n";
    }
};

int main() {
    stack<string> SP;

    // Push elements onto the stack
    SP.push("Abdallah");
    SP.push("Ali");
    SP.push("Hello");
    SP.push("hero");
    SP.push("hi");

    // Display the stack
    SP.display();  // Output: [hi  hero  Hello  Ali  Abdallah]

    return 0;
}


🧑‍💻 Example Output

[hi  hero  Hello  Ali  Abdallah]
