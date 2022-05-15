#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
namespace ariel
{
    struct Node
    {
        unsigned int level;
        string role;
        vector<Node> children;
    };


    class OrgChart
    {
    private:
        Node root;
        bool check_parent(string &parent, string &child, Node &node);
        unsigned int max_level;
        vector<string> iter_vec_level;
        vector<unsigned int> iter_vec_height; 
        vector<string> iter_vec_reverse;
        vector<string> iter_vec_preorder;
        void fill_level_order(Node &node);
        void fill_reverse_order(Node &node);
        void fill_preorder(Node &node);


    public:
        // OrgChart();
        // ~OrgChart();
        OrgChart &add_root(string role);
        OrgChart &add_sub(string parent, string child);
        string *begin_level_order();
        string *begin_reverse_order();
        string *begin_preorder();
        string *end_level_order();
        string *reverse_order();
        string *end_preorder();
        string *begin(){return begin_level_order();}
        string *end(){return end_level_order();}
        friend ostream &operator<<(ostream &os, OrgChart &root);
    };
}