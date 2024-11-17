function checkF(begin, word){
    let diff=0;
    for(let i=0;i<begin.length;i++){
        if(begin[i]!=word[i]){
            diff++;
            if(diff>1){
                return false;
            }
        }
    }
    if(diff==1){
        return true;
    }
    return false;
}

function DFS(time, begin, target, words){
    let return_value=-1;
    for(let i=0;i<words.length;i++){
        const word=words[i];
        if(!checkF(begin, word)){
            continue;
        }
        
        if(word==target){
            return time+1;
        }
        
        const next_words = words.slice();
        next_words.splice(i,1);

        const value=DFS(time+1,word,target,next_words);
        
        if(return_value==-1 || value<return_value){
            return_value=value;
        }
    }
    if(return_value==-1){
        return 0;
    }
    return return_value;
}

function solution(begin, target, words) {
    return DFS(0,begin,target,words)
}