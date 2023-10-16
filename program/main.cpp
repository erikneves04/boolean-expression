#include <iostream>

#include "Expression.hpp"
#include "SatisfactionEvaluator.hpp"

#define SUCCESS (0)
#define FAILURE (1)

int main(int argc, char const *argv[])
{
    // Check the correct number of command-line arguments.
    if (argc != 4)
    {
        std::cout << "Usage: -function -expression -input" << std::endl;

        // Terminate the program with an error.
        return FAILURE;
    }

    // Extract command-line arguments.
    std::string function(argv[1]);
    std::string expressionBase(argv[2]);
    std::string input(argv[3]);

    try
    {
        // Evaluate the function specified in the command-line arguments.
        if (function == "−a" || function == "-a")
        {
            Expression expression = Expression(expressionBase, input);
            std::cout << expression.Evaluate() << std::endl;
        }
        else if (function == "−s" || function == "-s")
        {
            SatisfactionEvaluator satisfactionEvaluator = SatisfactionEvaluator(expressionBase, input);
            bool hasSolution = satisfactionEvaluator.HasSolution();

            if (hasSolution)
                std::cout << hasSolution << " " << satisfactionEvaluator.GetSolution() << std::endl;
            else
                std::cout << hasSolution << std::endl;
        }
    }
    catch (...)
    {
        // Handle exceptions and print an error message.
        std::cout << "The parameters entered are invalid." << std::endl;
        std::cout << "Function: " << function << std::endl;
        std::cout << "Expression: " << expressionBase << std::endl;
        std::cout << "Input: " << input << std::endl;

        // Terminate the program with an error.
        return FAILURE;
    }

    // Terminate the program with success.
    return SUCCESS;
}