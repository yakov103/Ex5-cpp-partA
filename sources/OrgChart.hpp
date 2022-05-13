#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
namespace ariel
{
    struct Node
    {
        string name;
        vector<Node> children;
    };
    class OrgChart
    {
    private:
        Node root;
        bool add_sub(Node &node, string &parent, string &child);
        vector<string> begin_iter_level_order;
        void fill_level_order(Node &node);
        vector<string> begin_iter_reverse_order;
        void fill_reverse_order(Node &node);
        vector<string> begin_iter_preorder;
        void fill_preorder(Node &node);

    public:
        // OrgChart();
        OrgChart &add_root(string name);
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