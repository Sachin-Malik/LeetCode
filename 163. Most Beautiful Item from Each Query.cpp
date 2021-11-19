/*You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an
   item respectively.
   You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the
   maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists,
   then the answer to this query is 0.
   Return an array answer of the same length as queries where answer[j] is the answer to the jth query.
 */
/*
   ANS- Sort the queries too. so we don't need to make loops for every query
 */


class Solution {
public:
vector<int> maximumBeauty(vector<vector<int> >& items, vector<int>& queries) {
        vector<int> ans(queries.size());

        vector<pair<int,int> > queriesPair;
        for (int i = 0; i < queries.size(); i++) {
                queriesPair.push_back({queries[i], i});
        }

        sort(queriesPair.begin(), queriesPair.end());
        sort(items.begin(), items.end());

        int itemIndex = 0, maxBeauty = 0;
        for (int i = 0; i < queriesPair.size(); i++) {
                int maxPriceAllowed = queriesPair[i].first;
                int queryOriginalIndex = queriesPair[i].second;

                // Iterate over items, stop when the price exceeds query price or no item left
                while (itemIndex < items.size() && items[itemIndex][0] <= maxPriceAllowed) {
                        maxBeauty = max(maxBeauty, items[itemIndex][1]);
                        itemIndex++;
                }

                ans[queryOriginalIndex] = maxBeauty;
        }

        return ans;
}
};
