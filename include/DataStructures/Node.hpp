#pragma once

#ifndef NODE_HPP
#define NODE_HPP

/**
 * @brief Exception thrown when an operation is performed on an empty list or invalid item access.
 *
 * This class represents a custom exception thrown when an operation is performed on an empty list,
 * where the operation is not valid in such a context.
 */
class empty_set_exception
{
};

/**
 * @brief Structure representing a node in a data structure (shared with lists, queues, and stacks).
 *
 * This structure is used to create nodes in a data structure. Each node contains an element
 * of data of type DataType, a reference to the next node, and a reference to the previous node
 * in the list.
 *
 * @tparam DataType The data type to be stored in a node.
 */
template <class DataType>
struct Node
{
    DataType data;
    Node *next;
    Node *previous;
};

#endif