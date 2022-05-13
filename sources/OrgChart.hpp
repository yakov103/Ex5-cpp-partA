#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
namespace ariel
{
    struct Node
    {
        string role;
        vector<Node> children;
    };
    class OrgChart
    {
    private:
        Node root;
        bool add_sub(Node &node, string &parent, string &child);
        vector<string> iter_vec_level;
        vector<string> iter_vec_reverse;
        vector<string> iter_vec_preorder;
        
        void fill_level_order(Node &node);
        void fill_reverse_order(Node &node);
        void fill_preorder(Node &node);


    public:
        // OrgChart();
        OrgChart &add_root(string role);
        OrgChart &add_sub(string parent, string child);

        string *begin_level_order();
        string *end_level_order();

        string *begin_reverse_order();
        string *reverse_order();

        string *begin_preorder();
        string *end_preorder();

        string *begin(){return begin_level_order();}
        string *end(){return end_level_order();}
        // ~OrgChart();
        friend ostream &operator<<(ostream &os, OrgChart &root);
    };
}