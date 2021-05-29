class RandomizedSet {
public:
unordered_map<int, int> mymap;
vector<int> list;
/** Initialize your data structure here. */
RandomizedSet() {
}

/** Inserts a value to the set. Returns true if the set did not already
 * contain the specified element. */
bool insert(int val) {
        if (mymap.find(val) != mymap.end()) {
                return false;
        }

        list.push_back(val);
        mymap.insert({val, list.size() - 1});
        return true;
}

/** Removes a value from the set. Returns true if the set contained the
 * specified element. */
bool remove(int val) {
        auto it = mymap.find(val);
        if (it == mymap.end()) {
                return false;
        }

        list[it->second] = list.back();
        list.pop_back();
        mymap[list[it->second]] = it->second;
        mymap.erase(val);
        return true;
}

/** Get a random element from the set. */
int getRandom() {
        return list[rand() % list.size()];
}
};
