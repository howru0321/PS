class Solution {
public:
    string decodeString(string s) {
        int idx=0;
        return decode(s,idx);
    }
private:
    string decode(string & str, int & idx){
        string result="";

        int curr_num=0;
        while(idx<str.size()){
            char c = str[idx];

            if(c>='0'&&c<='9'){
                curr_num=curr_num*10+(c-'0');
            }else if(c=='['){
                idx++;
                string inner=decode(str, idx);

                for(int i=0;i<curr_num;i++){
                    result+=inner;
                }
                curr_num=0;
            }else if(c==']'){
                return result;
            }else{
                result+=c;
            }
            idx++;
        }
        return result;
    }
};