//Main concept of the problem

//1. First we try to find all unique tables and food items in ascending order.
//which can easily be done by set all the duplicate values will automatically will be removed.

//2.From these two set we can make 2 maps which will give us the index of tableNumber and index of foodItem in sorted set.
// (ie that indexes will match with the index in resulting vector)

//3.Now just traverse through orders and find the index of tableNumber(row for the resulting vector)
// and foodItem(col for the resulting vector) from the above maps.

class Solution {
public:
vector<vector<string> > displayTable(vector<vector<string> >& orders) {

        set<int> tableNums;
        set<string> foodItems;

        //first get all the unique tableNumber and foodItems
        for(int i=0; i<orders.size(); i++)
        {
                tableNums.insert(stoi(orders[i][1]));
                foodItems.insert(orders[i][2]);
        }

        vector<vector<string> > res(tableNums.size()+1,vector<string>(foodItems.size()+1,"0"));

        unordered_map<string,int> fmap;
        unordered_map<int,int> tmap;
        res[0][0]="Table";

        int counter=1;
        for(auto i:foodItems) {
                fmap[i] = counter;
                res[0][counter]=i;
                counter++;
        }
        counter=1;
        for(auto i:tableNums) {
                tmap[i] = counter;
                res[counter][0]=to_string(i);
                counter++;
        }
        int t,f;
        for(int i=0; i<orders.size(); i++)
        {
                t=tmap[stoi(orders[i][1])];
                f=fmap[orders[i][2]];
                res[t][f]=to_string(stoi(res[t][f])+1);
        }
        return res;
}
};
