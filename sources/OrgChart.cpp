#include "OrgChart.hpp"
using namespace std;
namespace ariel
{
    /*
     * This function is used to add a new root to the OrgChart.
     * @param role - the role of the new root.
     * @return - the OrgChart object.
     */

    OrgChart &OrgChart::add_root(string role)
    {
        Node new_root;
        new_root.role = role;
        new_root.level = 0;
        max_level = 0;
        root = new_root;
        return *this;
    }

    /*
     * This function is used to add a new sub to the OrgChart.
     * @param parent - the parent of the new sub.
     * @param child - the child of the new sub.
     * @return - the OrgChart object.
     */

    bool OrgChart::check_parent(string &parent, string &child, Node &node)
    {
        if (node.role.compare(parent) == 0)
        {
            Node new_sub;
            new_sub.level = node.level + 1;
            if (new_sub.level > max_level)
            {
                max_level = new_sub.level;
            }
            new_sub.role = child;
            node.children.push_back(new_sub);
            return true;
        }
        for (unsigned int i = 0; i < node.children.size(); i++)
        {
            if (check_parent(parent, child, node.children[i]))
            {
                return true;
            }
        }

        return false;
    }

    /*
     * This function is used to get the begin of the level order.
     * @return - the begin of the level order.
     */

    OrgChart &OrgChart::add_sub(string parent, string child)
    {
        if (!check_parent(parent, child, root))
        {
            throw "Parent does not exist";
        }

        return *this;
    }

    /*
     * This function is used to get the begin of the level order.
     * @return - the begin of the level order.
     */

    string *OrgChart::begin_level_order()
    {
        if (iter_vec_level.size() != 0)
        {
            iter_vec_level.clear(); // clear the vector
            iter_vec_height.clear();
        }
        iter_vec_level.push_back(root.role); // push the root to the vector
        iter_vec_height.push_back(0);        // push the height of the root to the vector
        fill_level_order(root);              // fill the vector with the level order

        return &iter_vec_level[0]; // return the first element of the vector
    }

    /*
     * This function is used to get the end of the level order.
     * @return - the end of the level order.
     */

    /*
     * level order is a tree traversal algorithn using breadth first search.
     */

    void OrgChart::fill_level_order(Node &node)
    {
        unsigned int i = 0;
        for (i = 0; i < node.children.size(); i++)
        {
            iter_vec_level.push_back(node.children[i].role);
            iter_vec_height.push_back(node.children[i].level);
        }
        for (i = 0; i < node.children.size(); i++)
        {
            fill_level_order(node.children[i]);
        }
    }

    /*
     * This function is used to get the begin of the reverse order.
     * @return - the begin of the reverse order.
     */

    string *OrgChart::end_level_order() { return &iter_vec_level[iter_vec_level.size()]; }

    /*
     * This function is used to get the begin of the reverse order.
     * @return - the begin of the reverse order.
     */

    string *OrgChart::begin_reverse_order()
    {
        iter_vec_reverse.clear(); // clear the vector

        iter_vec_reverse.insert(iter_vec_reverse.begin(), root.role); // push the root to the vector
        fill_reverse_order(root);
        return &iter_vec_reverse[0]; // return the first element of the vector
    }
    /*
     * This function is used the reverse order.
     * using this https://stackoverflow.com/questions/48251254/how-can-i-insert-element-into-beginning-of-vector
     * @return - the end of the reverse order.
     */

    void OrgChart::fill_reverse_order(Node &node)
    {
        for (unsigned int i = node.children.size() - 1; i >= 0 && i < 4000000000; i--)
        {
            iter_vec_reverse.insert(iter_vec_reverse.begin(), node.children[i].role);
        }
        for (unsigned int i = node.children.size() - 1; i >= 0 && i < 4000000000; i--)
        {
            fill_reverse_order(node.children[i]);
        }
    }

    /*
     * This function is used to get the begin of the preorder.
     * @return - the begin of the preorder.
     */

    string *OrgChart::reverse_order() { return &iter_vec_reverse[iter_vec_reverse.size()]; }

    /*
     * This function is used to get the begin of the preorder.
     * @return - the begin of the preorder.
     */

    string *OrgChart::begin_preorder()
    {

        iter_vec_preorder.clear(); // clear the vector 
        iter_vec_preorder.push_back(root.role); // push the root to the vector
        fill_preorder(root);
        return &iter_vec_preorder[0];
    }

    /*
    * preorder is a tree traversal algorithn using depth first search.
    * @return - the end of the preorder.
    */ 
    void OrgChart::fill_preorder(Node &node)
    {
        for (unsigned int i = 0; i < node.children.size(); i++)
        {
           
            iter_vec_preorder.push_back(node.children[i].role); // push the children to the vector
            if (node.children[i].children.size() != 0)
            {
                fill_preorder(node.children[i]);
            }
        }


    }
    string *OrgChart::end_preorder() { return &iter_vec_preorder[iter_vec_preorder.size()]; }

    /*
     * Os stram operator for printing.
     */
    ostream &operator<<(ostream &COUT, OrgChart &org)
    {
        return COUT;
    }

}