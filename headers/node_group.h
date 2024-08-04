#ifndef NODE_GROUP_H
#define NODE_GROUP_H

#include "./node.h"

// Node Group Declarations

namespace cling {

/// @brief A grouping of Nodes
class NodeGroup {
public:
    /// @brief Add a new Node to this Node Group
    /// @param[in] Node_Label The Label of the new Node
    void add_node(std::string Node_Label);

    /// @brief View all Nodes sorted by Node's Label
    /// @return Nodes_Out is a string that has every Node's information on a new line, returns "Node Group has no Nodes" if there's no Nodes, lines are broken by \\n
    std::string get_view_nodes();

    /// @brief View all Nodes sorted by ascending Node_Attribute
    /// @param Node_Attribute Attribute to sort viewing order by
    /// @return Nodes_Out a string that has every Node's information on a new line, returns "Node Group has no Nodes" if there's no Nodes, lines are broken by \\n
    std::string get_view_nodes_sorted(std::string Node_Attribute);

private:
    int _m_Node_Count; /// @brief Node Group's amount of held Nodes
    cling::Node _m_Nodes[8]; /// @brief Node Group's held Nodes, starts with capacity of 8
};

}

#endif