#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

vector<vector<string>> preprocess_records(vector<string> records){
    string delimiter = " ";
    vector<vector<string>> parsed_records;
    for(int i=0;i<records.size();i++){
        string record = records[i];
        vector<string> parsed_record;
        size_t pos;
        while((pos=record.find(delimiter))!=string::npos){
            parsed_record.push_back(record.substr(0,pos));
            record.erase(0,pos+delimiter.length());
        }
        parsed_record.push_back(record);
        parsed_records.push_back(parsed_record);
    }
    
    return parsed_records;
}

int min_diff(string time_in, string time_out){
    string delimiter=":";
    
    size_t pos_in=time_in.find(":");
    int hour_in = stoi(time_in.substr(0,pos_in));
    int min_in = stoi(time_in.substr(pos_in+delimiter.length()));
    
    size_t pos_out=time_out.find(":");
    int hour_out = stoi(time_out.substr(0,pos_out));
    int min_out = stoi(time_out.substr(pos_out+delimiter.length()));
    
    return ((hour_out-hour_in)*60+(min_out-min_in));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    int std_min=fees[0];
    int std_cost=fees[1];
    int unit_min=fees[2];
    int unit_cost=fees[3];
    
    
    vector<vector<string>> parsed_records=preprocess_records(records);
    
    vector<bool> visited(parsed_records.size(),false);
    map<string, int> total_mins;
    for(int i =0; i<parsed_records.size();i++){
        vector<string> parsed_record_in=parsed_records[i];
        string time_in=parsed_record_in[0];
        string number_in=parsed_record_in[1];
        
        if(visited[i]){
            continue;
        }
        cout<<"number_in: "<<number_in<<endl;
        cout<<"time_in: "<<time_in<<endl;
    
        visited[i]=true;
        bool find=false;
        for(int j=i+1;j<parsed_records.size();j++){
            if(visited[j]){
                continue;
            }
            vector<string> parsed_record_out=parsed_records[j];
            string time_out=parsed_record_out[0];
            string number_out=parsed_record_out[1];
            
            if(number_out!=number_in){
                continue;
            }
            
            int total_min=min_diff(time_in, time_out);
            
            cout<<"time_out: "<<time_out<<"total_min: "<<total_min<<endl;
            
            if(total_mins.find(number_in)==total_mins.end()){
                total_mins[number_in]=total_min;
            }else{
                total_mins[number_in]+=total_min;
            }
            find=true;
            visited[j]=true;
            break;
        }
        if(!find){
            int total_min=min_diff(time_in, "23:59");
            if(total_mins.find(number_in)==total_mins.end()){
                total_mins[number_in]=total_min;
            }else{
                total_mins[number_in]+=total_min;
            }
        }
    }
    vector<int> answer;
    
    for(const auto&total_min : total_mins){
        int total_min_to_paid=total_min.second-std_min;
        cout<<"number: "<<total_min.first<<" total_min_to_paid: "<<total_min_to_paid<<endl;
        if(total_min_to_paid<0){
            total_min_to_paid=0;
        }
        int total_cost=ceil((double)total_min_to_paid/unit_min)*unit_cost+std_cost;
        answer.push_back(total_cost);
    }
    cout<<endl;
    return answer;
}