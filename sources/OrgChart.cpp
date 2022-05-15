#include "OrgChart.hpp"
using namespace std;
namespace ariel
{
    OrgChart &OrgChart::add_root(string role){
        root.role = role;
        return *this;
    }
  
    bool OrgChart::add_sub(Node &node, string &parent, string &child){
        return true ; 
    }
      OrgChart &OrgChart::add_sub(string parent, string child) {
        return *this;
    }
    string *OrgChart::begin_level_order(){
        if (iter_vec_level.size() != 0){
           iter_vec_level.clear(); // clear the vector
        }
        iter_vec_level.push_back(root.role); // push the root to the vector

        fill_level_order(root); // fill the vector with the level order

        return &iter_vec_level[0]; // return the first element of the vector
    }

    void OrgChart::fill_level_order(Node &node) {
    }
    string *OrgChart::end_level_order(){return &iter_vec_level[iter_vec_level.size()];}

    string *OrgChart::begin_reverse_order()
    {
        if (iter_vec_reverse.size() != 0){
           iter_vec_reverse.clear(); // clear the vector
        }
        iter_vec_level.push_back(root.role);
        fill_level_order(root);
        return &iter_vec_level[0];

    }
    void OrgChart::fill_reverse_order(Node &node)
    {
         for (unsigned int i = 0; i < node.children.size(); i++)
        {
            iter_vec_level.push_back(node.children[i].role);
        }
        for (unsigned int i = 0; i < node.children.size(); i++)
        {
            fill_level_order(node.children[i]);
        }
    }
    string *OrgChart::reverse_order(){return &iter_vec_level[iter_vec_level.size()];}

    string *OrgChart::begin_preorder()
    {
        if (iter_vec_preorder.size() != 0){
           iter_vec_preorder.clear(); // clear the vector
        }
        iter_vec_level.push_back(root.role);
        return &iter_vec_level[0];
    }
    void OrgChart::fill_preorder(Node &node)
    {}
    string *OrgChart::end_preorder(){return &iter_vec_level[iter_vec_level.size()]; }
    
    ostream &operator<<(ostream &COUT, OrgChart &org){
        for (auto it = org.begin_preorder(); it != org.end_preorder(); ++it)
        {
            COUT << (*it); // print the string
            COUT << endl;  // print the endline
        }
        return COUT;
    }
}