#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_map>

using namespace std;

int applyOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b; // 處理加法運算
    case '-':
        return a - b; // 處理減法運算
    case '*':
        return a * b; // 處理乘法運算
    case '/':
        return a / b; // 處理除法運算
    case '%':
        return a % b; // 處理取模運算
    default:
        return 0; // 不應該到達這裡
    }
}

int evaluateExpression(const string &expr)
{
    istringstream iss(expr); // 將表達式轉為字串流
    stack<string> operators; // 儲存運算符的堆疊
    stack<int> operands;     // 儲存操作數的堆疊

    unordered_map<string, int> precedence = {
        {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"%", 2}, {"(", -1}}; // 運算符的優先順序表

    string token;
    while (iss >> token) // 逐字讀取表達式中的每個部分（運算符或操作數）
    {
        if (token == "(")
        {
            operators.push(token); // 左括號直接入運算符堆疊
        }
        else if (token == ")")
        {
            while (operators.top() != "(") // 直到找到對應的左括號
            {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                char op = operators.top()[0];
                operators.pop();
                operands.push(applyOperation(a, b, op)); // 計算括號內的表達式
            }
            operators.pop(); // 移除左括號
        }
        else if (precedence.count(token))
        {
            while (!operators.empty() && precedence[token] <= precedence[operators.top()])
            {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                char op = operators.top()[0];
                operators.pop();
                operands.push(applyOperation(a, b, op)); // 計算優先順序高於或等於當前運算符的操作
            }
            operators.push(token); // 當前運算符入堆疊
        }
        else
        {
            operands.push(stoi(token)); // 將數字轉為整數並入操作數堆疊
        }
    }

    while (!operators.empty())
    {
        int b = operands.top();
        operands.pop();
        int a = operands.top();
        operands.pop();
        char op = operators.top()[0];
        operators.pop();
        operands.push(applyOperation(a, b, op)); // 計算剩餘在堆疊中的運算
    }

    return operands.top(); // 返回最終結果
}

int main()
{
    string input;
    while (getline(cin, input)) // 讀取輸入的算術表達式
    {
        int result = evaluateExpression(input); // 計算表達式的結果
        cout << result << endl;                 // 輸出結果
    }
    return 0;
}
