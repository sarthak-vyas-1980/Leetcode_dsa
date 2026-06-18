class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hourAngle = (hour % 12) * 30;
        hourAngle += (minutes * 1.0 / 60.0) * 30;

        double minuteAngle = (minutes % 60) * 6;
        double ans = abs(hourAngle - minuteAngle);
        return ans <= 180 ? ans : 360-ans;
    }
};