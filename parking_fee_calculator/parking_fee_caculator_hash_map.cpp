#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>

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
    
    map<string, int> total_mins;
    unordered_map<string, string> in_times;
    
    for(int i=0;i<parsed_records.size();i++){
        vector<string> parsed_record = parsed_records[i];
        string time=parsed_record[0];
        string number=parsed_record[1];
        string io=parsed_record[2];
        
        if(io=="IN"){
            in_times.insert({number, time});
            continue;
        }
        string time_in = in_times[number];
        in_times.erase(number);
        int used_time=min_diff(time_in,time);
        
        if(total_mins.find(number)==total_mins.end()){
            total_mins[number]=used_time;
        }else{
            total_mins[number]+=used_time;
        }
    }
    
    for(const auto& pair : in_times){
        string number=pair.first;
        string time_in=pair.second;
        int used_time=min_diff(time_in,"23:59");
        
        if(total_mins.find(number)==total_mins.end()){
            total_mins[number]=used_time;
        }else{
            total_mins[number]+=used_time;
        }
    }
    
    vector<int> answer;
    for(const auto& pair : total_mins){
        int total_min=pair.second;
        total_min-=std_min;
        
        if(total_min<0){
            total_min=0;
        }
        
        int cost = ceil((double)total_min/unit_min)*unit_cost + std_cost;
        answer.push_back(cost);
    }
    
    return answer;
    
}