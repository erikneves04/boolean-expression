#pragma once

#ifndef OPERATIONNODULE_HPP
#define OPERATIONNODULE_HPP

#include <string>

#include "Nodule.hpp"
#include "InputNodule.hpp"

#define OR ("|")
#define AND ("&")
#define NOT ("~")

/**
 * @brief Exception thrown when an operation format is invalid.
 *
 * This exception is thrown when attempting to perform an operation with an invalid format.
 */
class invalid_operation_format_exception
{};

/**
 * @brief Class representing an operation nodule in an expression.
 *
 * This class is an extension of the Nodule class and represents an operation nodule in a boolean expression.
 * It can perform operations with other input nodules or other operation nodules, provided that the operation format is valid.
 */
class OperationNodule
    : public Nodule
{
public:
    /**
     * @brief Constructor of the OperationNodule class.
     *
     * Creates an instance of OperationNodule associated with a value.
     *
     * @param value The value associated with the operation nodule.
     */
    OperationNodule(std::string value);

    /**
     * @brief Performs the operation with two input nodules.
     *
     * @param left The left input nodule.
     * @param right The right input nodule.
     * @return true if the operation is successful, false otherwise.
     * @throw invalid_operation_format_exception If the operation format is invalid.
     */
    bool PerformOperation(InputNodule* left, InputNodule* right);

    /**
     * @brief Performs the operation with a single input nodule.
     *
     * @param value The input nodule for the operation.
     * @return true if the operation is successful, false otherwise.
     * @throw invalid_operation_format_exception If the operation format is invalid.
     */
    bool PerformOperation(InputNodule* value);

    /**
     * @brief Checks if the operation nodule has a higher precedence than another operation nodule.
     *
     * @param other The operation nodule to be compared.
     * @return true if the current operation nodule has higher precedence, false otherwise.
     */
    bool HasAGreaterPrecedenceThan(OperationNodule* other);
};

/**
 * @brief Class representing a parentheses nodule in an expression.
 *
 * This class is an extension of the Nodule class and represents a parentheses nodule (start or end) in a mathematical expression.
 * It is used to delimit groups of operations with priority or to indicate the start and end of nested expressions.
 */
class ParenthesesNodule
    : public Nodule
{
public:
    ParenthesesNodule* _end;

    /**
     * @brief Constructor of the ParenthesesNodule class.
     *
     * Creates an instance of ParenthesesNodule associated with a value and a specific type.
     *
     * @param value The value associated with the parentheses nodule.
     * @param type The type of the parentheses nodule (START_PARENTHESES or END_PARENTHESES).
     */
    ParenthesesNodule(std::string value, NoduleType type);
};

#endif