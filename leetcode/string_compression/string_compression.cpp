class Solution {
public:
    int compress(vector<char>& chars) {

        vector<char> ans_chars;
        char now=chars[0];
        int length=0;
        for(int i=0;i<chars.size();i++){
            if(chars[i]==now){
                length++;
            }else{
                ans_chars.push_back(now);
                if(length==1){
                    length=1;
                    now=chars[i];
                    continue;
                }
                vector<char> temp;
                while(length/10!=0){
                    int decamical=length%10;
                    temp.push_back(decamical + '0');
                    length=length/10;
                }
                temp.push_back(length + '0');

                for(int j=temp.size()-1;j>=0;j--){
                    ans_chars.push_back(temp[j]);
                }
                length=1;
                now=chars[i];
            }
        }
        ans_chars.push_back(now);
        if(length!=1){
            vector<char> temp;
            while(length/10!=0){
                int decamical=length%10;
                temp.push_back(decamical + '0');
                length=length/10;
            }
            temp.push_back(length + '0');

            for(int j=temp.size()-1;j>=0;j--){
                ans_chars.push_back(temp[j]);
            }
        }
        int ans = ans_chars.size();

        chars=ans_chars;
        
        return ans;
    }
};