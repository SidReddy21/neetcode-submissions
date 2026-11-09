class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,double>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());

        int count = 1;
        double prevTime = (target-cars.back().first)/cars.back().second;
        for(int i = cars.size()-2; i >= 0; i--){
            double currTime = (target-cars[i].first)/cars[i].second;
            if(currTime <= prevTime) continue;
            else prevTime = currTime;
            count++;
        }

        return count++;
    }
};
