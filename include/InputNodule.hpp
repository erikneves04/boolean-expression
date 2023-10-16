#pragma once

#ifndef INPUTNODULE_HPP
#define INPUTNODULE_HPP

#include <string>
#include "Nodule.hpp"

/**
 * @brief Exception thrown when a value is not set correctly.
 *
 * This exception is thrown when an attempt is made to access a value that has not been set.
 */
class value_not_set_exception
{};

/**
 * @brief Class representing a boolean input value.
 *
 * This class represents a boolean input value associated with a key or variable.
 */
class InputValue
{
public:
    std::string key;
    bool value;

    /**
     * @brief Default constructor of the InputValue class.
     *
     * Creates an instance of InputValue with default values (empty key and false value).
     */
    InputValue();

    /**
     * @brief Constructor of the InputValue class.
     *
     * Creates an instance of InputValue associated with a key and a boolean value.
     *
     * @param key The key or variable associated with the value.
     * @param value The boolean value to be associated with the key.
     */
    InputValue(std::string key, bool value);
};

/**
 * @brief Class representing a boolean input nodule.
 *
 * This class is an extension of the Nodule class and represents a boolean input nodule that can
 * hold a current value. It is used to represent boolean variables in the expression.
 */
class InputNodule
    : public Nodule
{
protected:
    bool _currentValue;
    bool _currentValueIsSet = false;

public:
    /**
     * @brief Default constructor of the InputNodule class.
     *
     * Creates an instance of InputNodule without a defined current value.
     */
    InputNodule();

    /**
     * @brief Constructor of the InputNodule class.
     *
     * Creates an instance of InputNodule associated with a key.
     *
     * @param value The key or variable associated with the input nodule.
     */
    InputNodule(std::string value);

    /**
     * @brief Constructor of the InputNodule class.
     *
     * Creates an instance of InputNodule associated with a key and a current value.
     *
     * @param value The key or variable associated with the input nodule.
     * @param currentValue The current value associated with the input nodule.
     */
    InputNodule(std::string value, bool currentValue);

    /**
     * @brief Gets the current value of the input nodule.
     *
     * @return The current value of the input nodule.
     * @throw value_not_set_exception If the current value has not been set.
     */
    bool GetCurrentValue();

    /**
     * @brief Sets a new current value for the input nodule.
     *
     * @param newValue The new current value to be associated with the input nodule.
     */
    void SetCurrentValue(bool newValue);
};

#endif