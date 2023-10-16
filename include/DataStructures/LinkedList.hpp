#pragma once

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Node.hpp"

/**
 * @file LinkedList.hpp
 * @brief Class representing a linked list in C++.
 *
 * This class implements a doubly linked list to store data of type DataType.
 * The list can grow dynamically and allows for inserting, removing, accessing,
 * and checking the presence of elements. It keeps track of the size and stores
 * references to the start and end of the list.
 *
 * @tparam DataType The data type of the elements in the list.
 */
template <class DataType>
class LinkedList
{
protected:
    Node<DataType> *_head;
    Node<DataType> *_tail;

    int _size;

    int _lastGetIndex = -1;
    Node<DataType> *_lastGetNode = nullptr;

    /**
     * @brief Gets the element at the specified position in the list using a linear search.
     * The search can start from either the first element or the last, depending on the
     * more efficient path.
     *
     * @param index The position of the desired element in the list.
     * @return The element at the specified position.
     */
    DataType LinearGet(int index)
    {
        Node<DataType> *current;

        if (index <= _size / 2)
        {
            current = _head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
        }
        else
        {
            current = _tail;
            for (int i = _size - 1; i > index; i--)
            {
                current = current->previous;
            }
        }

        _lastGetIndex = index;
        _lastGetNode = current;

        return current->data;
    }

public:
    /**
     * @brief Default constructor for the LinkedList class.
     *
     * Creates a new instance of LinkedList with an empty list.
     */
    LinkedList()
    {
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    };

    /**
     * @brief Destructor for the LinkedList class.
     *
     * Releases the memory allocated for the list's elements and destroys the list instance.
     */
    ~LinkedList()
    {
        auto current = _head;

        for (int i = 0; i < _size; i++)
        {
            auto next = current->next;

            if (current == nullptr)
                break;

            delete current;
            current = next;
        }
    }

    /**
     * @brief Returns the current size of the list.
     *
     * @return The number of elements in the list.
     */
    int Length()
    {
        return _size;
    }

    /**
     * @brief Inserts a new element at the end of the list.
     *
     * @param data The element to be inserted into the list.
     */
    void Insert(DataType data)
    {
        Node<DataType> *newNode = new Node<DataType>();
        newNode->data = data;

        newNode->next = nullptr;
        newNode->previous = _tail;

        if (_size == 0)
        {
            _head = newNode;
            _tail = newNode;
        }
        else
        {
            _tail->next = newNode;
            _tail = newNode;
        }

        _size++;
    }

    /**
     * @brief Removes the first occurrence of an element from the list.
     *
     * @param data The element to be removed from the list, if present.
     */
    void Remove(DataType data)
    {
        auto current = _head;

        while (current != nullptr)
        {
            if (current->data == data)
            {
                if (current->previous == nullptr)
                {
                    _head = current->next;
                }
                else
                {
                    current->previous->next = current->next;

                    if (current->next != nullptr)
                        current->next->previous = current->previous;

                    if (current->next == nullptr)
                        _tail = current->previous;
                }

                delete current;
                _size--;
                return;
            }

            current = current->next;
        }
    }

    /**
     * @brief Gets the element at the specified position in the list. This method internally
     * manages the cache-like information to improve access performance, determining where
     * in the list it's more efficient to start the search and storing information to enable
     * O(1) complexity for iterations.
     *
     * @param index The position of the desired element in the list.
     * @return The element at the specified position.
     * @throw empty_set_exception If the list is empty, or the index is invalid.
     */
    DataType Get(int index)
    {
        if (index < 0 || index >= _size)
            throw empty_set_exception();

        if (_lastGetIndex == -1)
            return LinearGet(index);

        if (_lastGetIndex == index - 1)
        {
            _lastGetIndex = index;
            _lastGetNode = _lastGetNode->next;

            return _lastGetNode->data;
        }

        if (_lastGetIndex == index + 1)
        {
            _lastGetIndex = index;
            _lastGetNode = _lastGetNode->previous;

            return _lastGetNode->data;
        }

        if (_lastGetIndex < index)
        {
            auto current = _lastGetNode;
            for (int i = index; i < index; i++)
            {
                current = current->next;
            }

            _lastGetIndex = index;
            _lastGetNode = current;

            return current->data;
        }

        return LinearGet(index);
    }

    /**
     * @brief Returns the last element of the list.
     *
     * @return The last element in the list.
     * @throw empty_set_exception If the list is empty.
     */
    DataType Last()
    {
        if (Empty())
            throw empty_set_exception();

        return _tail->data;
    }

    /**
     * @brief Checks if the list is empty.
     *
     * @return true if the list is empty, false otherwise.
     */
    bool Empty()
    {
        return _size == 0;
    }

    /**
     * @brief Checks if the list contains a specific element.
     *
     * @param data The element to be searched for in the list.
     * @return true if the element is present in the list, false otherwise.
     */
    bool Contains(DataType data)
    {
        auto current = _head;

        while (current != nullptr)
        {
            if (current->data == data)
                return true;

            current = current->next;
        }

        return false;
    }
};

#endif