class Solution {
public:
int max_compat=INT_MIN;
int maxCompatibilitySum(vector<vector<int> >& students, vector<vector<int> >& mentors) {
        backtrack(0,students,mentors);
        return max_compat;
}
void backtrack(int index,vector<vector<int> >&students,vector<vector<int> >&mentors){

        if(index==students.size()) {
                max_compat=max(max_compat,calculate(students,mentors));
        }

        for(int i=index; i<mentors.size(); i++) {
                swap(students[i],students[index]);
                backtrack(index+1,students,mentors);
                swap(students[i],students[index]);
        }
}
int calculate(vector<vector<int> >&students,vector<vector<int> >&mentors){
        int count=0;
        for(int i=0; i<students.size(); i++) {
                for(int j=0; j<students[i].size(); j++) {
                        if(students[i][j]==mentors[i][j])
                                count++;
                }
        }
        return count;
}
};
