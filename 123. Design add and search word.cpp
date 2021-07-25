class WordDictionary {
public:
struct Trie {
        char c;
        bool isWord=false;
        struct Trie* children[26];
};
Trie *node;
WordDictionary() {
        node=new Trie();
}

void addWord(string word) {

        int current_word_length=word.length();
        Trie *curr=node;
        for(int i=0; i<current_word_length; i++) {
                if(curr->children[word[i]-'a']== NULL) curr->children[word[i]-'a']= new Trie();
                curr=curr->children[word[i]-'a'];
        }
        curr->isWord=true;
}

bool search(string word,Trie* tempRoot=NULL) {

        Trie * curr;
        if(!tempRoot) curr=node;
        else curr=tempRoot;

        int current_word_length=word.length();
        for(int i=0; i<current_word_length; i++) {

                char c=word[i];
                if(c=='.') {
                        for(int j=0; j<26; j++) {
                                if(curr->children[j]!=NULL&&search(word.substr(i+1, word.size()-i),curr->children[j])) return true;
                        }
                        return false;
                } else{
                        if(curr->children[c-'a']==NULL)
                                return false;
                        curr=curr->children[c-'a'];
                }
        }
        return curr->isWord;
}

};
