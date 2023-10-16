#pragma once

#ifndef NODULE_HPP
#define NODULE_HPP

#include <string>

/**
 * @brief Enumeration that represents the types of nodules in an expression.
 *
 * This enumeration defines the types of nodules that can occur in a boolean expression.
 * The types include input, operator, start parentheses, and end parentheses.
 */
enum class NoduleType
{
    INPUT,
    OPERATOR,
    START_PARENTHESES,
    END_PARENTHESES
};

/**
 * @brief Class representing a nodule in an expression.
 *
 * This class represents an item in a boolean expression. It can be of various types,
 * including input (variable), operator, start parentheses, and end parentheses. Each nodule
 * has a value and a type associated with it.
 */
class Nodule
{
protected:
    NoduleType _type;
    std::string _value;

public:
    /**
     * @brief Default constructor of the Nodule class.
     *
     * Creates an instance of Nodule without a specified value or type.
     */
    Nodule();

    /**
     * @brief Constructor of the Nodule class.
     *
     * Creates an instance of Nodule associated with a value and a specific type.
     *
     * @param value The value associated with the nodule.
     * @param type The type of the nodule (NoduleType).
     */
    Nodule(std::string value, NoduleType type);

    /**
     * @brief Gets the type of the nodule.
     *
     * @return The type of the nodule (NoduleType).
     */
    NoduleType GetType();

    /**
     * @brief Gets the value of the nodule.
     *
     * @return The value associated with the nodule.
     */
    std::string GetValue();
};

#endif