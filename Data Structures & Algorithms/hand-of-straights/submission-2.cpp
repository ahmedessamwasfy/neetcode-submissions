class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size()%groupSize!=0)return false;
    sort(hand.begin(),hand.end());
    
    vector<int> groups[hand.size()/groupSize];
    // int groups[hand.size()/groupSize][groupSize] = 0;
    int first = 0;
    int following = 0; 

    for(int x:hand){
      following = first+1;
      if (groups[first].size() == 0)groups[first].push_back(x);
      else if (x == groups[first].back() + 1){
        groups[first].push_back(x);
         if(groups[first].size() == groupSize) first++;
      }
      else if (x > groups[first].back() + 1) return false;
      else if (x == groups[first].back()) {
        while(following < (hand.size()/groupSize)){
          if (groups[following].size() == 0){
            groups[following].push_back(x);
            break;
          }
          else if (x == groups[following].back() + 1){
            groups[following].push_back(x);
            break;
        }
          following++;
        }
      }

      if (following == hand.size()/groupSize && following > first+1) return false;

    }
    return true;
    }
};
