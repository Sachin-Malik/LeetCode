class Solution {
public:
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unordered_map<int,bool> inStack;
        stack<int> st;

        int currentPointer=0;
        for(int i=0; i<popped.size(); i++) {
                if(inStack.find(popped[i])!=inStack.end()) {
                        if(st.size()!=0&&st.top()==popped[i]) {
                                st.pop();
                                inStack[popped[i]]=false;
                        }
                        else
                                return false;
                } else {

                        for(int j=currentPointer; j<pushed.size(); j++) {
                                if(pushed[j]!=popped[i]) {
                                        inStack[pushed[j]]=true;
                                        st.push(pushed[j]);
                                }
                                else {
                                        currentPointer=j+1;
                                        break;
                                }
                        }
                }
        }
        return st.size()==0;
}
};
