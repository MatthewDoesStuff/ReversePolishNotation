#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

class RPN {
public:
    RPN()=default;
    ~RPN()=default;

    double deTing(const std::string& data)
    {
        char c{};
        std::vector<std::string> splitData{split(data, ' ')};
        for(const auto& v : splitData) {
            if(isOperator(v)) {
                c=v[0];
                calculate(c);
            }
            else {
                stack.push(stod(v));
            }
        }
        return stack.top();
    }

private:
    bool isOperator(const std::string& s) {
        return s=="+" or s=="-" or s=="*" or s=="/" or s=="^";
    }

    void calculate(const char c) {
        switch(c)
        {
            case '+':
                sum();
                break;
            case '-':
                subtract();
                break;
            case '*':
                multiply();
                break;
            case '/':
                divide();
                break;
            case '^':
                power();
                break;
            default:
                break;
        }
    }

    void sum() {
        const double x{stack.top()};
        stack.pop();
        const double y{stack.top()};
        stack.pop();
        stack.push(x+y);
    }

    void subtract(){
        const double x{stack.top()};
        stack.pop();
        const double y{stack.top()};
        stack.pop();
        stack.push(x-y);
    }

    void multiply() {
        const double x{stack.top()};
        stack.pop();
        const double y{stack.top()};
        stack.pop();
        stack.push(x*y);
    }

    void divide() {
        const double x{stack.top()};
        stack.pop();
        const double y{stack.top()};
        stack.pop();
        stack.push(y/x);
    }

    void power() {
        const double x{stack.top()};
        stack.pop();
        const double y{stack.top()};
        stack.pop();
        stack.push(pow(y,x));
    }

    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> result;
        std::stringstream ss (s);
        std::string item;

        while (getline (ss, item, delim)) {
            result.push_back (item);
        }

        return result;
    }

    std::stack<double> stack{};
};

int main() {
    RPN rpn;
    std::cout<<rpn.deTing("4 3 1 - 2 3 * ^ /");
    return 0;
}