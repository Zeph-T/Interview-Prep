class Solution {
public:
    double angleClock(int hour, int minutes) {
        float hourPosition = (hour%12 + (float)(minutes)/60 ) * 30;
        float minutePosition = minutes * 6;
        float angle =  fabs(hourPosition - minutePosition);
        if(angle > 180)return 360 - angle;
        return angle;
    }
};