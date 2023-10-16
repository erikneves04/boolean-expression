#pragma once

#ifndef SATISFACTIONEVALUATOR_HPP
#define SATISFACTIONEVALUATOR_HPP

#include <string>

#include "InputNodule.hpp"
#include "Expression.hpp"
#include "DataStructures/LinkedList.hpp"

#define EXISTS ("e")
#define FOR_ALL ("a")

#define SOLUTION_IRRELEVANT_OUTPUT ('a')

/**
 * @file SatisfactionEvaluator.hpp
 * @brief Class for evaluating the satisfaction of a variable-input expression.
 *
 * This class is used to evaluate if a logical expression is satisfied for different combinations of input values.
 * It allows determining whether there are solutions or failures in satisfying the expression and also provides methods to retrieve the found solutions.
 */
class SatisfactionEvaluator
{
private:
    std::string _expression;
    std::string _input;

    LinkedList<int>* _variablesIndex;
    LinkedList<LinkedList<InputValue>*> _allInputsCombination;

    LinkedList<LinkedList<InputValue>*>* _trueCombinations;
    LinkedList<LinkedList<InputValue>*>* _falseCombinations;

    LinkedList<std::string>* _solutions;
    LinkedList<std::string>* _fails;

    /**
     * @brief Checks if a "FOR ALL" constraint is valid.
     *
     * @param index The index of the variable to be checked.
     * @return true if the condition is satisfied, false otherwise.
     */
    bool ForAllAssert(int index);

    /**
     * @brief Checks if an "EXISTS" constraint is valid.
     *
     * @param index The index of the variable to be checked.
     * @return true if the condition is satisfied, false otherwise.
     */
    bool ExistsAssert(int index);

    /**
     * @brief Sets up the list of variable indices in the expression.
     */
    void SetupVariablesIndex();

    /**
     * @brief Checks if there is a corresponding variable for an index.
     *
     * @param index The index to be checked.
     * @return true if there is a corresponding variable for the index, false otherwise.
     */
    bool HasVariableForIndex(int index);

    /**
     * @brief Checks if a variable is irrelevant to the expression's result.
     *
     * @param result The expression result.
     * @param index The index of the variable to be checked.
     * @return true if the variable is irrelevant, false otherwise.
     */
    bool IsVariableIrreleant(std::string& result, int index);

    /**
     * @brief Checks if the 'exists' operator is irrelevant to the expression's result.
     *
     * @param result The expression result.
     * @param index The index of the 'exists' operator to be checked.
     * @return true if the 'exists' operator is irrelevant, false otherwise.
     */
    bool IsExistsIrrelevant(std::string& result, int index);

    /**
     * @brief Checks if the 'forall' operator is irrelevant to the expression's result.
     *
     * @param result The expression result.
     * @param index The index of the 'forall' operator to be checked.
     * @return true if the 'forall' operator is irrelevant, false otherwise.
     */
    bool IsForAllIrrelevant(std::string& result, int index);

    /**
     * @brief Executes all possible input value combinations.
     */
    void ExecuteAllInputsCombination();

    /**
     * @brief Executes an input value combination.
     *
     * @param expression The expression to be evaluated.
     * @param values The list of input values.
     */
    void ExecuteInputCombination(Expression* expression, LinkedList<InputValue>* inputList);

    /**
     * @brief Converts a list of input values into a single string.
     *
     * @param values The list of input values.
     * @return A string representing the input values.
     */
    std::string ConvertValueListIntoString(LinkedList<InputValue>* values);

    /**
     * @brief Converts a list of lists of input values into a list of strings.
     *
     * @param values The list of lists of input values.
     * @return A list of strings representing the input value combinations.
     */
    LinkedList<std::string>* ConvertValueListIntoStringList(LinkedList<LinkedList<InputValue>*>* values);

public:
    /**
     * @brief Constructor of the SatisfactionEvaluator class.
     *
     * Creates an instance of SatisfactionEvaluator with a logical expression and a representation of fixed and variable inputs.
     *
     * @param expression The logical expression to be evaluated.
     * @param input The representation of fixed and variable inputs.
     */
    SatisfactionEvaluator(std::string expression, std::string input);

    /**
     * @brief Destructor of the SatisfactionEvaluator class.
     *
     * Frees the memory allocated during the execution of the SatisfactionEvaluator class.
     */
    ~SatisfactionEvaluator();

    /**
     * @brief Checks if the expression has any solution.
     *
     * @return true if there is at least one solution, false otherwise.
     */
    bool HasSolution();

    /**
     * @brief Gets the found solution, marking irrelevant variables as 'a'.
     *
     * @return The string representing the solution that satisfies the constraints of the expression.
     */
    std::string GetSolution();
};

#endif