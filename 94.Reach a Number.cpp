class Solution {
public:
int reachNumber(int target) {
        int pos=1,jumps=1,prev_jump=1;
        while(pos<=target)
        {
                if(pos==target)
                        return jumps;
                jumps++;
                prev_jump++;
                pos+=prev_jump;
        }
        int delta=pos-target;
        if(delta%2==0)
                return jumps;

        else{
                if((jumps+1+delta)%2==0)
                        return jumps+1;
                return jumps+2;
        }
}
};
