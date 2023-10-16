#pragma once

#ifndef STACK_HPP
#define STACK_HPP

#include "Node.hpp"

/**
 * @file Stack.hpp
 * @brief Class representing a stack in C++.
 *
 * This class implements a stack data structure where elements are inserted and
 * removed from the top of the stack (LIFO - Last-In, First-Out). The stack allows
 * insertion, removal, access to the element on top, and checking if it's empty.
 *
 * @tparam DataType The data type of the elements in the stack.
 */
template <class DataType>
class Stack
{
protected:
    Node<DataType> *_first;
    Node<DataType> *_last;

    int _size;

public:
    /**
     * @brief Default constructor for the Stack class.
     *
     * Creates a new instance of an empty stack.
     */
    Stack()
    {
        _first = nullptr;
        _last = nullptr;
        _size = 0;
    };

    /**
     * @brief Destructor for the Stack class.
     *
     * Releases the memory allocated for the elements in the stack and destroys the stack instance.
     */
    ~Stack()
    {
        auto current = _first;

        while (current != nullptr)
        {
            auto next = current->next;
            delete current;
            current = next;
        }
    }

    /**
     * @brief Inserts a new element at the top of the stack.
     *
     * @param data The element to be inserted into the stack.
     */
    void Insert(DataType data)
    {
        auto newNode = new Node<DataType>;
        newNode->data = data;

        newNode->next = _first;
        newNode->previous = nullptr;

        if (_first == nullptr)
        {
            _last = newNode;
            _first = newNode;
        }
        else
        {
            _first->previous = newNode;
            _first = newNode;
        }

        _size++;
    }

    /**
     * @brief Removes and returns the element at the top of the stack.
     *
     * @return The element removed from the top of the stack.
     * @throw empty_set_exception If the stack is empty.
     */
    DataType Remove()
    {
        if (_size == 0)
            throw empty_set_exception();

        auto current = _first;
        DataType data = current->data;

        _first = _first->next;
        if (_first != nullptr)
            _first->previous = nullptr;

        delete current;

        _size--;

        return data;
    }

    /**
     * @brief Returns the element at the top of the stack without removing it.
     *
     * @return The element at the top of the stack.
     */
    DataType OnTop()
    {
        return _first->data;
    }

    /**
     * @brief Checks if the stack is empty.
     *
     * @return true if the stack is empty, false otherwise.
     */
    bool Empty()
    {
        return _size == 0;
    }
};

#endif