#include "../third_party/doctest.h"

#include "Expression.hpp"
#include "SatisfactionEvaluator.hpp"

TEST_CASE("01")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( ( 3 | ( ( ~ 0 & 1 ) & 2 ) ) & 4 )", "aa10a");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("02")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( 4 | ~ ( ( ( 1 | 0 ) & 2 ) & 3 ) )", "1ea1a");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("03")
{
    auto expression = Expression("( 4 & ( 3 | ( ( 1 & ~ 0 ) | 2 ) ) )", "10001");
    bool isTrue = expression.Evaluate();

    CHECK(isTrue == false);
}

TEST_CASE("04")
{
    auto expression = Expression("~ ( ( ~ ( 0 | 1 ) & 2 ) & 3 )", "1000");
    bool isTrue = expression.Evaluate();

    CHECK(isTrue == true);
}

TEST_CASE("05")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( ( ( 3 & ( ( 1 & 0 ) | 2 ) ) | 4 ) & 5 )", "a1ee0a");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("06")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("~ ~ ( 2 & ( ~ 0 | 1 ) )", "e0a");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("07")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( ~ ( 3 | ( ( 1 & 0 ) | 2 ) ) | 4 )", "e0e10");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("08")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("~ ( 4 & ( 3 & ( 2 | ( 0 | 1 ) ) ) )", "e10a1");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("09")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( ~ ( 1 | ~ ( 1 | 0 ) ) & 2 )", "01e");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("10")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( 5 | ( ( 3 & ( ( 0 | 1 ) | 2 ) ) & 4 ) )", "aee001");
    bool hasSolution = satisfactionEvaluator.HasSolution();
    auto solution = satisfactionEvaluator.GetSolution();

    CHECK(hasSolution == true);
    CHECK(solution == "aaa001");
}

TEST_CASE("11")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( 43 & ( 16 | ~ ( 45 & ( ~ ~ ( ( ( ( ( 30 | ( 18 | ( 25 & ( 31 | ( 10 & ( 26 | ( 42 | ~ ( 41 | ~ ( ( 7 | ( ( 39 | ( ~ ( 3 | ( ( ~ ~ ( 37 & ( 29 & ( ( ~ ( 14 & ( ( ( 16 | ( 32 & ( ~ ( ( ( 33 & ( ( 17 | ( ( ( 31 | ( 30 | ~ ( 21 & ( 0 | ( 18 | ~ ~ ( 26 & ( ( ( ( 16 | ~ ( ( ( ( ( ( ( ( 23 & ~ ( 22 | ( 21 & ( 20 | ( ( ( ( 18 & ( ~ ( 16 | ( ( 14 & ( ( ( ( 10 & ( 9 | ( ( ( ( 5 & ( 0 & ( ( ( 2 | ( 1 | 0 ) ) | 3 ) | 4 ) ) ) & 6 ) | 7 ) | 8 ) ) ) | 11 ) | 12 ) & 13 ) ) | 15 ) ) & 17 ) ) | 0 ) | 8 ) | 19 ) ) ) ) ) & 24 ) | 25 ) & 26 ) | 3 ) & 8 ) & 27 ) & 7 ) ) & 28 ) & 29 ) | 14 ) ) ) ) ) ) ) & 14 ) | 32 ) ) & 13 ) ) & 0 ) | 4 ) | 24 ) ) ) & 34 ) | 35 ) ) | 36 ) & 27 ) ) ) | 38 ) | 37 ) ) & 3 ) ) & 37 ) ) | 40 ) ) ) ) ) ) ) ) ) | 36 ) | 8 ) & 26 ) & 43 ) & 44 ) ) ) )", "011100001111110110100101110100a101100100110000");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("12")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( 9 | ~ ( ( 43 & ( ( ( ( ( ( 40 | ( ~ ( ( ~ ( 11 & ( 31 | ( ~ ( ( ( 37 & ~ ~ ( 36 & ( ( ( 34 & ( 28 & ( ( ( ( 19 & ( 12 | ( 31 | ( ( 30 | ~ ~ ( ( ( ( 27 | ( ( 1 | ( 26 | ( ( 24 | ( 12 & ( 21 & ( ~ ~ ( 17 | ~ ~ ( ( ~ ( 22 & ( 16 & ( 21 & ( 20 | ( 19 & ( ( ( 17 & ( ~ ( 1 & ( 16 & ( ( ~ ( ( 14 | ( ( 8 & ( ( ( 12 & ( 9 & ~ ~ ( ( 10 & ( 9 & ( ( ( ( 6 | ~ ( ~ ( 2 & ( 4 | ( 3 | ~ ( 2 | ( 0 | 1 ) ) ) ) ) | 5 ) ) & 7 ) | 2 ) & 8 ) ) ) & 11 ) ) ) & 0 ) | 13 ) ) | 2 ) ) | 4 ) & 3 ) | 15 ) ) ) & 3 ) ) | 18 ) | 13 ) ) ) ) ) ) & 23 ) & 24 ) ) & 25 ) ) ) ) | 21 ) ) ) & 20 ) ) & 24 ) | 28 ) | 29 ) ) | 20 ) ) ) ) | 32 ) & 33 ) | 28 ) ) ) & 7 ) & 35 ) ) ) | 8 ) & 5 ) & 38 ) ) ) | 10 ) & 32 ) & 39 ) ) & 30 ) & 41 ) & 42 ) & 15 ) & 0 ) ) & 44 ) )", "0a111000001111010101e1a1011011111010000011001");
    bool hasSolution = satisfactionEvaluator.HasSolution();
    auto solution = satisfactionEvaluator.GetSolution();

    CHECK(hasSolution == true);
    CHECK(solution == "0a111000001111010101a1a1011011111010000011001");
}

TEST_CASE("13")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( ( 0 & ( 35 | ( ( ( 41 | ( 40 | ( 39 & ( 38 | ~ ( ~ ( ( 13 & ~ ( 10 | ( 37 & ( ( ( 30 & ~ ( ( 33 | ( ~ ( ~ ( ( ( ( 9 | ~ ( 29 | ( ( ( ( ( ( 26 & ( ( 20 & ( ( 22 | ( 11 | ~ ( ( 0 & ~ ~ ( ( 6 | ( ( 4 & ( 9 | ( ( 3 | ~ ( ( ( ( 16 | ~ ( ( 21 & ( 20 & ( 19 | ( 15 & ( 8 | ( 15 | ( ( 18 & ( 13 | ( ( ~ ( 17 & ( 2 | ( 16 & ( ( ~ ~ ( 13 & ( 12 | ( 11 | ( 10 | ( ( ( 8 | ( 7 | ~ ( 6 | ( ( ( 3 | ~ ~ ~ ( 2 & ( 1 & 0 ) ) ) | 4 ) & 5 ) ) ) ) & 0 ) & 9 ) ) ) ) ) | 14 ) | 15 ) ) ) ) & 8 ) | 13 ) ) ) & 8 ) ) ) ) ) ) ) | 6 ) ) & 22 ) & 11 ) & 23 ) ) & 24 ) ) ) | 9 ) ) & 16 ) ) | 13 ) ) ) & 25 ) ) | 7 ) ) | 27 ) & 28 ) | 13 ) | 15 ) & 13 ) ) ) | 30 ) & 3 ) & 8 ) & 31 ) & 32 ) ) | 34 ) ) | 35 ) & 36 ) ) ) ) & 24 ) & 15 ) ) ) ) ) | 42 ) | 43 ) ) ) & 41 )", "0000111011010e101100101000110010100101000a1a");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("14")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( 44 & ( 15 & ( 4 | ( 43 & ( 42 | ( 41 | ( ( ( 1 & ( ( ( ( ~ ~ ( ~ ( 35 | ( ( ( ( ~ ( ~ ~ ~ ( ( 36 | ( 30 & ( 2 | ( 33 & ( ( ( ~ ~ ( ~ ~ ( ( 25 | ( 3 | ( ( ( ( 21 & ( 31 & ( 30 & ( ( 28 & ( ( 27 | ( ( ~ ( 0 | ( ( ( ( 22 | ~ ( 21 & ~ ~ ( 1 & ( 20 & ( 19 | ( ~ ( 0 & ~ ( ( ~ ~ ( 16 | ( 9 | ( ( ( ( 10 | ( ~ ( ( 12 & ( ~ ( ( ( ( ( 7 & ( ( 5 & ( 4 & ( ~ ( ( 1 | 0 ) | 2 ) & 3 ) ) ) | 6 ) ) & 8 ) & 9 ) | 10 ) & 11 ) & 7 ) ) | 10 ) | 13 ) ) | 14 ) & 15 ) & 1 ) ) ) & 17 ) | 18 ) ) | 5 ) ) ) ) ) ) | 23 ) | 24 ) & 25 ) ) | 26 ) & 18 ) ) | 15 ) ) & 29 ) ) ) ) & 28 ) & 32 ) | 33 ) ) ) & 34 ) | 30 ) & 8 ) | 35 ) & 26 ) ) ) ) ) & 37 ) & 24 ) & 38 ) | 29 ) | 9 ) & 39 ) ) & 37 ) | 22 ) | 40 ) & 18 ) | 14 ) ) | 4 ) & 26 ) ) ) ) ) ) )", "000100a10111110110010011010110100a11010100101");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("15")
{
    auto expression = Expression("~ ( 40 & ( ( ( 39 & ( 38 & ( ~ ( 36 & ( 9 & ~ ( 33 | ( 9 | ( 35 | ( ( 5 & ( ( 7 | ~ ( 8 & ( 18 | ( ( ( ~ ( 2 & ~ ( ( ( 5 & ~ ( ( ~ ( ( ( 0 | ( ( 32 & ( ( ( 21 | ( 5 | ( 1 & ( ~ ( 28 & ( 27 | ( 20 & ( ( 23 | ~ ( 17 | ( ( 7 | ( 26 & ~ ~ ( 5 | ~ ( ( ( ( 23 & ( ( 6 | ( 22 & ( 21 & ( 9 | ~ ( ( ( ( 18 | ( 17 & ( ~ ( 15 | ( ( ( 12 & ( ( 10 | ~ ( ( ( ( ( ~ ( ~ ( 5 & ( 0 & ( 4 & ~ ( 3 | ( ~ ( 1 | 0 ) | 2 ) ) ) ) ) | 1 ) | 6 ) & 7 ) & 1 ) | 8 ) | 9 ) ) | 11 ) ) & 13 ) & 14 ) ) & 16 ) ) ) & 19 ) | 20 ) & 4 ) ) ) ) ) | 6 ) ) & 24 ) & 25 ) | 21 ) ) ) ) & 18 ) ) ) | 21 ) ) ) ) | 29 ) ) ) ) | 30 ) & 31 ) ) | 5 ) ) | 10 ) | 28 ) | 9 ) | 31 ) ) | 33 ) & 34 ) ) & 23 ) & 1 ) | 2 ) ) ) ) | 2 ) ) | 0 ) ) ) ) ) ) | 37 ) ) ) | 34 ) & 34 ) )", "11000010000101010010100011011100001010101");
    bool isTrue = expression.Evaluate();

    CHECK(isTrue == false);
}

TEST_CASE("16")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( 46 | ( ( 45 & ( ( ~ ( ~ ( ( 47 | ( 28 & ~ ( ~ ( ( ( ( ( 44 | ( ( 39 | ~ ~ ~ ( 39 | ( ( 1 | ( ( 40 | ( 39 & ( 38 | ~ ( ( 37 & ~ ( 36 & ( ( 34 | ( 33 | ( ( 9 & ( 9 & ( 25 | ( ( 31 & ( ( ~ ( 25 | ( 28 & ( 27 & ( 26 & ( 8 | ( 25 & ( 24 | ( 2 & ( 23 & ( 22 & ( 21 | ( ( 20 | ( ( ( 7 | ( 3 & ( 18 & ( ~ ( 17 | ~ ( 16 & ( 15 | ~ ( 4 & ( 14 | ( ~ ( ( ( ( 12 & ( ~ ( ~ ( ( 10 & ( 9 | ~ ( ( 8 & ( ( ( ( ~ ( 4 | ( 3 | ( 2 & ( 0 & 1 ) ) ) ) | 5 ) | 6 ) & 7 ) | 1 ) ) & 5 ) ) ) | 1 ) & 1 ) & 11 ) ) & 4 ) | 13 ) & 11 ) & 4 ) ) ) ) ) ) | 12 ) ) ) ) & 19 ) | 10 ) ) | 3 ) ) ) ) ) ) ) ) ) ) ) ) & 29 ) | 30 ) ) & 24 ) ) ) ) & 32 ) ) ) | 35 ) ) ) & 31 ) ) ) ) | 41 ) ) | 42 ) ) ) & 43 ) ) | 15 ) | 41 ) & 26 ) & 45 ) & 46 ) ) ) | 17 ) & 48 ) | 16 ) | 49 ) ) & 50 ) )", "1111001010011111a0010e100a0110110010000101000e00001");
    bool hasSolution = satisfactionEvaluator.HasSolution();
    auto solution = satisfactionEvaluator.GetSolution();

    CHECK(hasSolution == true);
    CHECK(solution == "1111001010011111a0010a100a0110110010000101000100001");
}

TEST_CASE("17")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( 37 & ( ( ( 4 & ( ( ( ~ ~ ( ( 15 | ~ ( ( 41 & ( 8 | ( 40 | ~ ( 24 | ~ ( 9 & ~ ( ~ ( 30 | ( ~ ( 38 & ( ( ( 18 & ( 35 | ( ( ( 34 & ( ~ ( 33 & ( ( 31 & ( 14 & ( ( ~ ~ ( 23 & ( 30 & ~ ( ( 14 & ( ( ( 5 | ( 28 & ( 27 | ( 2 | ( ( ( 7 | ( 4 & ( 26 | ( 23 & ( 0 | ( ( 10 | ( ( ( 23 | ( 22 & ( 13 | ( ( ~ ( 19 & ( ( 17 | ~ ( ~ ( ( ( ( ( 7 & ( 12 & ( ( 10 | ( 9 | ( ( ( 3 | ( 6 & ( 1 & ( ( ~ ( ~ ( 2 | ( 1 & ~ 0 ) ) | 3 ) | 4 ) | 5 ) ) ) ) & 7 ) | 8 ) ) ) | 11 ) ) ) | 13 ) & 14 ) & 11 ) | 15 ) & 16 ) ) & 18 ) ) | 20 ) | 21 ) ) ) ) & 24 ) & 25 ) ) | 8 ) ) ) ) ) ) | 12 ) & 17 ) ) ) ) ) & 24 ) & 29 ) ) & 4 ) ) ) & 7 ) | 0 ) ) ) & 32 ) ) | 0 ) ) & 9 ) & 5 ) ) ) & 36 ) & 37 ) ) | 39 ) ) & 36 ) ) ) ) ) ) | 39 ) ) & 18 ) | 8 ) | 42 ) & 0 ) ) & 39 ) | 43 ) )", "1101011000000011010000101111011110000a110101");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("18")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( ( ( 2 | ~ ( ( 2 | ( ( ( 34 | ( ( ( ~ ( 43 | ( ( ~ ( 44 & ( 5 & ( ( 43 & ( 21 | ( ( 2 & ( ( 6 | ( 28 | ( ( 41 | ~ ( ( 40 & ~ ( ( 39 | ~ ( 38 | ( 36 & ~ ( 17 | ( 37 & ( ( 5 | ~ ( ( ( ( ( ( ( ( 27 & ( ( ( 29 & ( ( ~ ( 27 & ( 26 | ~ ( 14 | ( 25 | ( ( 24 & ( 23 & ( ( 22 & ( 19 | ~ ( 7 & ~ ( ( 20 & ~ ( 1 & ( 19 | ( 18 | ( ( 17 | ( ( 15 & ( 14 | ( ( ( ( ~ ~ ( 9 | ( 8 & ( ( ( 6 | ( ( ( ~ ( 2 | ( 0 & 1 ) ) & 3 ) & 4 ) & 5 ) ) | 3 ) | 7 ) ) ) | 10 ) | 11 ) | 12 ) | 13 ) ) ) & 16 ) ) | 13 ) ) ) ) ) & 21 ) ) ) ) | 5 ) ) ) & 13 ) ) ) ) ) & 28 ) & 20 ) ) | 30 ) & 31 ) ) | 14 ) & 32 ) | 5 ) & 33 ) & 34 ) & 35 ) | 8 ) ) | 36 ) ) ) ) ) ) | 17 ) ) | 10 ) ) | 16 ) ) ) & 10 ) ) & 42 ) ) ) & 4 ) ) ) & 45 ) | 1 ) ) & 16 ) | 46 ) | 6 ) ) & 16 ) & 2 ) ) | 27 ) ) | 47 ) | 26 )", "000001011111e10001111010010111000110011101011101");
    bool hasSolution = satisfactionEvaluator.HasSolution();
    auto solution = satisfactionEvaluator.GetSolution();

    CHECK(hasSolution == true);
    CHECK(solution == "000001011111a10001111010010111000110011101011101");
}

TEST_CASE("19")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("~ ( 12 | ( 38 | ~ ~ ( ( ( 43 & ~ ( 42 & ~ ( 34 | ( 26 | ( ( ( 38 & ( ~ ( ( ( ( 1 & ( ( ~ ( ~ ( 15 | ( 29 & ( ( 24 | ( ( 3 & ( 13 | ( ( ( ( 28 | ( 33 | ( 32 & ( ( 21 & ( ( 13 | ( 21 | ( ( 30 | ( ( ( ~ ~ ~ ( 26 & ~ ( ( ~ ( ~ ( ( ( 12 | ( 25 | ~ ~ ~ ( 2 & ~ ( 24 & ( 23 | ( ( 22 & ( 21 & ( ( 19 & ( ( ( ( 7 | ~ ( ( 14 & ( ( 12 & ( ( ( ( ( ~ ( 0 | ~ ( 7 & ( ( 5 & ( 4 & ( 3 | ( 2 | ( 1 | 0 ) ) ) ) ) & 6 ) ) ) & 8 ) | 9 ) | 10 ) & 4 ) & 11 ) ) & 13 ) ) | 15 ) ) & 16 ) | 17 ) & 18 ) ) | 20 ) ) ) & 18 ) ) ) ) ) ) & 23 ) & 26 ) & 19 ) & 17 ) & 27 ) ) & 28 ) | 29 ) | 12 ) ) | 6 ) ) ) & 31 ) ) | 5 ) ) ) ) | 34 ) & 3 ) | 35 ) ) ) & 36 ) ) | 37 ) ) ) | 0 ) & 14 ) | 38 ) ) & 29 ) | 39 ) & 40 ) & 41 ) ) | 32 ) | 14 ) ) ) ) ) | 13 ) | 44 ) ) )", "100110000101111001110110011010011100011010000");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}

TEST_CASE("20")
{
    auto satisfactionEvaluator = SatisfactionEvaluator("( 49 & ( 31 | ( 48 | ( 25 & ( ~ ( 2 | ( 47 & ( 46 | ( 45 | ~ ( 44 & ( ( 43 & ~ ( ~ ( ~ ( 41 | ( ( 39 & ( 38 | ( 37 | ( ~ ~ ( ( 16 & ( 35 | ~ ( ( 26 & ( ( ( 21 | ( ( 8 | ~ ~ ( ( ( 9 | ~ ( 9 & ( 31 | ( 30 | ( 25 & ( ( ~ ( 13 | ( 22 & ( ( ( 26 & ( ( ( 5 | ( ( ( ( 23 & ( 22 & ( ~ ( ( ( ( ( ( 15 & ( ( ~ ( 1 | ( 16 | ~ ~ ( 15 | ( ( 13 | ( ( ( ( 9 & ~ ( ( ~ ( ( ~ ( 6 & ( 5 | ( 4 | ~ ( 3 & ( 2 & ( 1 & 0 ) ) ) ) ) ) & 7 ) | 0 ) & 8 ) & 7 ) ) & 10 ) | 11 ) & 12 ) ) & 14 ) ) ) ) | 14 ) | 17 ) ) | 18 ) & 19 ) & 5 ) | 6 ) & 20 ) & 21 ) ) ) & 2 ) & 24 ) & 19 ) ) & 16 ) & 25 ) ) & 16 ) & 27 ) ) ) & 28 ) | 29 ) ) ) ) ) ) & 2 ) & 32 ) ) | 33 ) ) | 19 ) & 34 ) ) | 29 ) ) ) | 26 ) | 36 ) ) ) ) | 40 ) ) & 42 ) | 35 ) ) | 38 ) ) ) ) ) ) | 30 ) ) ) ) )", "0011011011011010001010010010a1100111101001ea010101");
    bool hasSolution = satisfactionEvaluator.HasSolution();

    CHECK(hasSolution == false);
}
