class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = 1;
        hour = hour%12;
        angle = 6*minutes;
        angle = angle - ((30*hour)+(0.5*minutes));
        angle = abs(angle);
        return min(angle, 360-angle);
    }
};