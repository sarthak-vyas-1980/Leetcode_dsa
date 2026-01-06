class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcount = 0;
        int rcount = 0;
        int blank = 0;
        for(int i=0; i<moves.length(); i++){
            if(moves[i]=='R') rcount++;
            else if(moves[i]=='L') lcount++;
            else blank++;
        }
        // if(lcount < rcount) return (blank + rcount - lcount);
        // else if(lcount > rcount) return (blank + lcount - rcount);
        // else return blank;
        return blank + abs(rcount - lcount);
    }
};