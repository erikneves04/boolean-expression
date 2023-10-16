#pragma once

#ifndef INPUTEXCHANGER_HPP
#define INPUTEXCHANGER_HPP

#include <string>

#include "InputNodule.hpp"
#include "DataStructures/Queue.hpp"
#include "DataStructures/LinkedList.hpp"

/**
 * @file InputExchanger.hpp
 * @brief Class responsible for generating combinations of values for expression inputs.
 *
 * This class allows generating all possible combinations of values for the variables in an expression
 * based on the specified variable indices. This is useful for evaluating the expression in different input scenarios.
 */
class InputExchanger
{
private:
    std::string _input;
    LinkedList<int>* _variablesIndex;

    /**
     * @brief Checks if there is a corresponding variable for an index.
     *
     * @param index The index to be checked.
     * @return true if there is a corresponding variable for the index, false otherwise.
     */
    bool HasVariableForIndex(int index);

    /**
     * @brief Generates all binary combinations for a specified number of bits.
     *
     * @param bitsCount The number of bits in the combinations.
     * @return A list of strings representing all possible binary combinations.
     */
    LinkedList<std::string> GenerateBinaryCombinations(int bitsCount);

public:
    /**
     * @brief Constructor of the InputExchanger class.
     *
     * Creates an instance of InputExchanger with an input expression and a list of variable indices
     * for which combinations will be generated.
     *
     * @param input The input expression.
     * @param variablesIndex A list of variable indices.
     */
    InputExchanger(std::string input, LinkedList<int>* variablesIndex);

    /**
     * @brief Generates all value combinations for the expression variables.
     *
     * @return A queue containing all value combinations for the variables.
     */
    Queue<LinkedList<InputValue>*>* GetAllInputsCombination();
};

#endif