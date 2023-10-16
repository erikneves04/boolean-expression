#pragma once

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Node.hpp"

/**
 * @file Queue.hpp
 * @brief Class representing a queue in C++.
 *
 * This class implements a queue data structure where elements are added to the end of the queue
 * and removed from the front of the queue (FIFO - First-In, First-Out). The queue allows insertion,
 * removal, and checking if it's empty.
 *
 * @tparam DataType The data type of the elements in the queue.
 */
template <class DataType>
class Queue
{
protected:
    Node<DataType> *_first;
    Node<DataType> *_last;

    int _size;

public:
    /**
     * @brief Default constructor for the Queue class.
     *
     * Creates a new instance of an empty queue.
     */
    Queue()
    {
        _first = nullptr;
        _last = nullptr;
        _size = 0;
    };

    /**
     * @brief Destructor for the Queue class.
     *
     * Releases the memory allocated for the elements in the queue and destroys the queue instance.
     */
    ~Queue()
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
     * @brief Inserts a new element at the end of the queue.
     *
     * @param data The element to be inserted into the queue.
     */
    void Insert(DataType data)
    {
        auto newNode = new Node<DataType>;
        newNode->data = data;

        newNode->next = nullptr;
        newNode->previous = _last;

        if (_first == nullptr)
        {
            _first = newNode;
            _last = newNode;
        }
        else
        {
            _last->next = newNode;
            _last = newNode;
        }

        _size++;
    }

    /**
     * @brief Removes and returns the element from the front of the queue.
     *
     * @return The element removed from the front of the queue.
     * @throw empty_set_exception If the queue is empty.
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
     * @brief Checks if the queue is empty.
     *
     * @return true if the queue is empty, false otherwise.
     */
    bool Empty()
    {
        return _size == 0;
    }
};

#endif