#pragma once

#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <string>

#include "DataStructures/LinkedList.hpp"

#include "Nodule.hpp"
#include "InputNodule.hpp"

/**
 * @brief Exception thrown when the number of provided inputs is different from the number of variables in the expression.
 *
 * This class represents a custom exception thrown when the number of provided inputs
 * is different from the number of variables in the expression, making it impossible to correctly evaluate the result.
 */
class difference_between_inputs_and_variable_count_exception
{ };

/**
 * @file Expression.hpp
 * @brief Class representing a boolean expression in C++.
 *
 * This class allows the creation and evaluation of boolean expressions. It can parse
 * the expression and calculate its value based on provided input values. The class also
 * supports the definition of variables and their associated values.
 */
class Expression
{
private:
    bool _disableValuesMemoryDelete = false;
    bool _valuesWasSet = false;
    int _inputCount = 0;
    int _differentVariablesOnExpression = 0;

    LinkedList<Nodule*>* _expression = nullptr;
    LinkedList<InputValue>* _values = nullptr;
    LinkedList<InputNodule*>* _variableNodules = nullptr;

    bool* _valuesMemory = nullptr;

    /**
     * @brief Reads an input string and converts it into values to be assigned to nodules later.
     */
    void SetupValues(std::string values);

    /**
     * @brief Reads a string with the boolean expression and converts it into nodules to be manipulated by the class.
     */
    void SetupExpression(std::string expression);

    /**
     * @brief Retrieves the value of a nodule based on its key in the input values set.
     */
    bool FindValue(std::string key);

    /**
     * @brief Retrieves the value of a nodule based on its key in the provided values set.
     */
    bool FindValue(std::string key, LinkedList<InputValue>* values);

    /**
     * @brief Updates the input values for the variables in the expression.
     *
     * @param values A list of input values for the variables in the expression.
     */
    void SetMemoryValue(LinkedList<InputValue>* values);

public:
    /**
     * @brief Constructor that accepts an expression and initial values.
     *
     * Creates an instance of the Expression class with a boolean expression and initial values.
     *
     * @param expression The boolean expression to be evaluated.
     * @param values A string representing initial values for the variables in the expression.
     */
    Expression(std::string expression, std::string values);

    /**
     * @brief Constructor that accepts only an expression.
     *
     * Creates an instance of the Expression class with a boolean expression. The values of the variables
     * must be defined later.
     *
     * @param expression The boolean expression to be evaluated.
     */
    Expression(std::string expression);

    /**
     * @brief Destructor of the Expression class.
     *
     * Frees the memory allocated during the execution of the Expression class.
     */
    ~Expression();

    /**
     * @brief Evaluates the expression based on the defined values.
     *
     * @return true if the evaluation is successful, false otherwise.
     */
    bool Evaluate();

    /**
     * @brief Evaluates the expression based on provided values, which can be partial, as long as the SetupMemoryValue
     * method has been used previously to assign values to the remaining inputs.
     *
     * @param values A list of input values for the variables in the expression.
     * @return true if the evaluation is successful, false otherwise.
     */
    bool Evaluate(LinkedList<InputValue>* values);

    /**
     * @brief Sets initial values for the variables in the expression, aiming for quick access; therefore,
     * dynamic arrays are used to store and access this data.
     *
     * @param input A string representing the initial values for the variables in the expression.
     */
    void SetupMemoryValues(std::string input);

    /**
     * @brief Sets the variable nodules in the expression.
     *
     * @param input A string describing the variable nodules in the expression.
     */
    void SetupVariableNodules(std::string input);
};

#endif