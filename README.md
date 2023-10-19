<!DOCTYPE html>
<html>
<head>
</head>
<body>
    <h1>Boolean Expression Evaluator</h1>
    <p>
      This is a C++ program that evaluates and checks the satisfiability of Boolean expressions. The program supports both evaluating Boolean expressions and verifying if they can satisfy given constraints.
    </p>
    <h2>Features</h2>
    <ul>
        <li>Evaluate complex Boolean expressions.</li>
        <li>Check if Boolean expressions can satisfy specific constraints.</li>
        <li>A set of test cases is provided to validate the correctness of the program.</li>
    </ul>
    <h2>How to Build</h2>
    <p>To build the program, use the provided Makefile:</p>
    <pre><code>make</code></pre>
    <h2>Usage</h2>
    <p>The program expects the following command line arguments:</p>
    <ul>
        <li><strong>-function</strong>: Specify the function, either <code>-a</code> for expression evaluation or <code>-s</code> for checking if the expression can meet the constraints.</li>
        <li><strong>-expression</strong>: Provide the Boolean expression you want to evaluate or check for satisfiability.</li>
        <li><strong>-input</strong>: The input values for the Boolean expression.</li>
    </ul>
    <h3>Example Usage</h3>
    <p>To evaluate a Boolean expression:</p>
    <pre><code>./expression -a "(3 & (1 | 0))" "11"</code></pre>
    <p>To check if a Boolean expression can satisfy specific constraints:</p>
    <pre><code>./expression -s -expression "(3 & (1 | 0))" "e1"</code></pre>
    <p>In this case, an input element can be either zero or one, or a("for all") or e("exists").</p>
    <h2>License</h2>
    <p>This project is licensed under the MIT License - see the <a href="LICENSE">LICENSE</a> file for details.</p>
</body>
</html>
