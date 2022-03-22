class Solution {
public:
int countCollisions(string directions) {
        int numberOfCollisions=0;
        stack<char> st;
        int numberOfCars=directions.size();

        //never push L on Stack
        for(int i=0; i<numberOfCars; i++) {

                if(directions[i]=='L') {
                        if(!st.empty()&&st.top()=='S') {
                                numberOfCollisions++;
                        }else if(!st.empty()&&st.top()=='R') {
                                st.pop();
                                numberOfCollisions+=2;
                                while(!st.empty()&&st.top()=='R') {
                                        numberOfCollisions++;
                                        st.pop();
                                }
                                st.push('S');
                        }
                }else if(directions[i]=='R') {
                        // no need to check collisons here
                        st.push('R');
                } else {
                        if(!st.empty()&&st.top()=='S')
                                continue;
                        else{
                                while(!st.empty()&&st.top()=='R') {
                                        numberOfCollisions++;
                                        st.pop();
                                }
                                st.push('S');
                        }
                }

        }

        return numberOfCollisions;
}
};
