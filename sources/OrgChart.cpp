#include "OrgChart.hpp"
using namespace std;
namespace ariel
{
    OrgChart &OrgChart::add_root(string name)
    {
        root.name = name;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string parent, string child)
    {
        if (!add_sub(root, parent, child))
        {
            throw "You need to init the Org ";
        }
        return *this;
    }
    bool OrgChart::add_sub(Node &node, string &parent, string &child)
    {
        return true ; 
    }
    string *OrgChart::begin_level_order()
    {
        begin_iter_level_order.clear();
        begin_iter_level_order.push_back(root.name);
        fill_level_order(root);
        return &begin_iter_level_order[0];
    }
    void OrgChart::fill_level_order(Node &node)
    {
        for (size_t i = 0; i < node.children.size(); i++)
        {
            begin_iter_level_order.push_back(node.children[i].name);
        }
        for (size_t i = 0; i < node.children.size(); i++)
        {
            fill_level_order(node.children[i]);
        }
    }
    string *OrgChart::end_level_order()
    {
        return &begin_iter_level_order[begin_iter_level_order.size()];
    }

    string *OrgChart::begin_reverse_order()
    {
        begin_iter_reverse_order.clear();
        begin_iter_reverse_order.insert(begin_iter_reverse_order.begin(), root.name);
        fill_reverse_order(root);
        return &begin_iter_reverse_order[0];
    }
    void OrgChart::fill_reverse_order(Node &node)
    {
        for (int i = node.children.size() - 1; i >= 0; i--)
        {
            begin_iter_reverse_order.insert(begin_iter_reverse_order.begin(), node.children[(size_t)i].name);
        }
        for (int i = node.children.size() - 1; i >= 0; i--)
        {
            fill_reverse_order(node.children[(size_t)i]);
        }
    }
    string *OrgChart::reverse_order()
    {
        return &begin_iter_reverse_order[begin_iter_reverse_order.size()];
    }

    string *OrgChart::begin_preorder()
    {
        begin_iter_preorder.clear();
        fill_preorder(root);
        return &begin_iter_preorder[0];
    }
    void OrgChart::fill_preorder(Node &node)
    {
        begin_iter_preorder.push_back(node.name);
        for (size_t i = 0; i < node.children.size(); i++)
        {
            fill_preorder(node.children[i]);
        }
    }
    string *OrgChart::end_preorder()
    {
        return &begin_iter_preorder[begin_iter_preorder.size()];
    }
    ostream &operator<<(ostream &os, OrgChart &org)
    {
        for (auto it = org.begin_preorder(); it != org.end_preorder(); ++it)
        {
            os << (*it) << " ";
        }
        return os;
    }
}