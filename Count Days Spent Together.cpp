class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
        auto toDays = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int total = day;
            for (int i = 0; i < month - 1; i++)
                total += days[i];
            return total;
        };
        int start = max(toDays(arriveAlice), toDays(arriveBob));
        int end = min(toDays(leaveAlice), toDays(leaveBob));
        if (start > end) return 0;
        int count = 0;
        for (int day = start; day <= end; day++)
            count++;
        return count;
    }
};
