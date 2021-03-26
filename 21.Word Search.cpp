class Solution {
ppublic:
bool exist(vector<vector<char> >& board, string word) {
        for(int i = 0; i < board.size(); i++) {
                for(int j = 0; j < board.at(i).size(); j++)
                        if(search(board, i, j, 0, word) == true)
                                return true;
        }

        return false;
}

bool search(vector<vector<char> > &board, int i, int j, int index, string &word){
        if(index >= word.length()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board.at(i).size()) return false;
        if(board.at(i).at(j) != word.at(index)) return false;
        if(board.at(i).at(j) == '*') return false;


        char val = board.at(i).at(j);
        board.at(i).at(j) = '*';
        // can only go horizontally or vertically
        bool wordExists = search(board, i - 1, j, index + 1, word) ||
                          search(board, i + 1, j, index + 1, word) ||
                          search(board, i, j - 1, index + 1, word) ||
                          search(board, i, j + 1, index + 1, word);

        // backtrack
        board.at(i).at(j) = val;
        return wordExists;
}
};
