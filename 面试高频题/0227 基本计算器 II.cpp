class Solution {
public:
    vector<char> op_v = {'+','-','*','/'};

    int helper(string &s, int &i) {
        char op = '+';
        stack<int> stk;
        int num = 0;
        int res = 0;
        int top = 0;
        for (i; i<s.size(); ++i) {
            if (s[i]>='0' && s[i]<='9') { // 计算数字
                num = num * 10 + (s[i]-'0');
            }
            if (s[i]=='(') { // 左括号进入递归，在新的递归中，stk 和 op 都被重置
                num = helper(s, ++i);
                ++i; // 出了右括号，将指针右移一位
            }

            // if (i >= s.size()-1 || ((s[i]<'0' || s[i]>'9') && s[i] != ' ')) {
            if (i>=s.size()-1 || find(op_v.begin(), op_v.end(), s[i]) != op_v.end() || s[i]==')') {
            // 遇到新的运算符、右括号和字符串末尾，则出栈入栈，这一写法无需考虑其他特殊字符（比如空格）
                if (op=='+') {
                    stk.push(num);
                }
                if (op=='-') {
                    stk.push(-num);
                }
                if (op=='*') {
                    top = stk.top();
                    stk.pop();
                    stk.push(top*num);
                }
                if (op=='/') {
                    top = stk.top();
                    stk.pop();
                    stk.push(top/num);
                }
                op = s[i]; // 更新下一次的运算符，注意必须写在处理完运算符的步骤后面
                num = 0;
            }

            if (s[i]==')') { // 右括号跳出循环，执行末尾的清栈步骤，然后回到上一层递归
                break;
            }
        }

        // 计算栈中数字之和
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }

    int calculate(string s) {
        int i = 0;
        return helper(s, i);
    }
};