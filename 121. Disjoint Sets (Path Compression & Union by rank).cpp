#include <bits/stdc++.h>
using namespace std;
int main(){

        struct node {
                int parent;
                int rank;
        };
        vector<node> disjoint_set;

        // Find Operation with Path Compression
        int find_parent(int current_node){
                if(disjoint_set[current_node].parent==-1) {
                        return current_node;
                        return disjoint_set[current_node].parent=find_parent(disjoint_set[current_node].parent);
                }
        }


        //Union Opertation with Rank.
        void union_op(int node1,int node2){

                int node1_parent=find(node1);
                int node2_parent=find(node2);

                if(disjoint_set[node1_parent].rank>disjoint_set[node2_parent].rank) {
                        disjoint_set[node2_parent].parent=node1_parent;
                }
                else if(disjoint_set[node1_parent].rank<disjoint_set[node2_parent].rank) {
                        disjoint_set[node1_parent].parent=node2_parent;
                } else {
                        disjoint_set[node2_parent].parent=node1_parent;
                        disjoint_set[node1_parent].rank++;
                }
        }

}
