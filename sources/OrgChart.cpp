#include "OrgChart.hpp"
using namespace std;
namespace ariel
{
    /*
    * This function is used to add a new root to the OrgChart.
    * @param role - the role of the new root.
    * @return - the OrgChart object.
    */

    OrgChart &OrgChart::add_root(string role){return *this;}
  
    /*
    * This function is used to add a new sub to the OrgChart.
    * @param parent - the parent of the new sub.
    * @param child - the child of the new sub.
    * @return - the OrgChart object.
    */

    bool OrgChart::add_sub(Node &node, string &parent, string &child){return true ; }

    /*
    * This function is used to get the begin of the level order.
    * @return - the begin of the level order.
    */

    OrgChart &OrgChart::add_sub(string parent, string child) { return *this;}

    /*
    * This function is used to get the begin of the level order.
    * @return - the begin of the level order.
    */

    string *OrgChart::begin_level_order(){
        if (iter_vec_level.size() != 0){
           iter_vec_level.clear(); // clear the vector
        }
        iter_vec_level.push_back(root.role); // push the root to the vector

        fill_level_order(root); // fill the vector with the level order

        return &iter_vec_level[0]; // return the first element of the vector
    }

    /*
    * This function is used to get the end of the level order.
    * @return - the end of the level order.
    */


    void OrgChart::fill_level_order(Node &node) {
    }

    /*
    * This function is used to get the begin of the reverse order.
    * @return - the begin of the reverse order.
    */

    string *OrgChart::end_level_order(){return &iter_vec_level[iter_vec_level.size()];}

    /*
    * This function is used to get the begin of the reverse order.
    * @return - the begin of the reverse order.
    */

    string *OrgChart::begin_reverse_order(){return &iter_vec_level[0];}

    /*
    * This function is used to get the end of the reverse order.
    * @return - the end of the reverse order.
    */

    void OrgChart::fill_reverse_order(Node &node)
    {

    }

    /*
    * This function is used to get the begin of the preorder.
    * @return - the begin of the preorder.
    */

    string *OrgChart::reverse_order(){return &iter_vec_level[iter_vec_level.size()];}


    /*
    * This function is used to get the begin of the preorder.
    * @return - the begin of the preorder.
    */

    string *OrgChart::begin_preorder(){return &iter_vec_level[0];
    }
    void OrgChart::fill_preorder(Node &node)
    {}
    string *OrgChart::end_preorder(){return &iter_vec_level[iter_vec_level.size()]; }
    

    /*
    * Os stram operator for printing.
    */
    ostream &operator<<(ostream &COUT, OrgChart &org){
        return COUT;
    }


}