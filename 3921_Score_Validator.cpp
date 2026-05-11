class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0;
        int counter=0;
        for(const string& event:events){
            if(counter==10){
                break;
            }
            if(event=="W"){
                counter+=1;
            }
            else if(event=="WD" || event=="NB"){
                score+=1;
            }
            else{
                score+=stoi(event);
            }
        }
        return{score,counter};
        
    }
};