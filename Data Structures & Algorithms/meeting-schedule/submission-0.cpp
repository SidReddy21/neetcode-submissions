/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>> times;
        for(Interval poop : intervals){
            times.push_back({poop.start,poop.end});
        }
        sort(times.begin(),times.end());
        int end = -1;
        for(vector<int> interval : times){
            if(end > interval[0]) return false;
            else end = interval[1];
        }
        return true;
    }
};
