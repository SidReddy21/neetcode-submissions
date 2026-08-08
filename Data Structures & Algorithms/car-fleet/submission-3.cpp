class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,double>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());

        int carFleets = 1;
        double front = (target-cars.back().first)/cars.back().second;
        for(int i = cars.size()-2; i >= 0; i--){
            cout << (target-cars[i].first)/cars[i].second << endl;
            cout << front << endl;
            if((target-cars[i].first)/cars[i].second > front){
                carFleets++;
                front = (target-cars[i].first)/cars[i].second;
            }
        }

        return carFleets;
    }
};
