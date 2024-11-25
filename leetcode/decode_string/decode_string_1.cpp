class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string currentStr="";
        int currentNum=0;

        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(isdigit(c)){
                currentNum=currentNum*10+(c-'0');
            }else if(c=='['){
                strStack.push(currentStr);
                numStack.push(currentNum);

                currentStr="";
                currentNum=0;
            }else if(c==']'){
                string previousStr=strStack.top(); strStack.pop();
                int previousNum=numStack.top(); numStack.pop();

                string repeatStr="";
                for(int j=0;j<previousNum;j++){
                    repeatStr+=currentStr;
                }

                currentStr=previousStr+repeatStr;
            }else{
                currentStr+=c;
            }
        }

        return currentStr;
    }
};