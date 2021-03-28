#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {

    stack <char> bracketStack;

    for (int i=0;i<s.length();i++){
        
        //Pushing the starting brackets.
        if (s[i]=='[' || s[i]=='{' || s[i]=='(')
            bracketStack.push(s[i]);

        else if (s[i]==']' && !bracketStack.empty() && bracketStack.top()=='[')
            bracketStack.pop();

        else if (s[i]=='}'  && !bracketStack.empty() && bracketStack.top()=='{')
            bracketStack.pop();

        else if (s[i]==')' && !bracketStack.empty() && bracketStack.top()=='(')
            bracketStack.pop();

        else
            return "NO";
    }

    //If the stack is not empty.
    if (!bracketStack.empty())
        return "NO";
    
    //If all went well.
    return "YES";

}

int main()
{


    string test="[()][{}()][](){}([{}(())([[{}]])][])[]([][])(){}{{}{[](){}}}()[]({})[{}{{}([{}][])}][()][{}[{}[{}]]][]{}[]{}[]{{}({}(){({{}{}[([[]][[]])()]})({}{{}})})}(])[{{{][)[)])(]){(}))[{(})][[{)(}){[(]})[[{}(])}({)(}[[()}{}}]{}{}}()}{({}](]{{[}}(([{]){[]()})}}]{}[}}})}{]{](]](()][{))])(}]}))(}[}{{)}{[[}[]}(]}){";

    string result = isBalanced(test);

    cout<<result<<endl;


    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
