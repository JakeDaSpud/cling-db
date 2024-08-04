#ifndef NODE_H
#define NODE_H

// Node Declarations

#include <iostream>
#include <string>

namespace cling {

/// @brief An Entry with a Name Label and Attribute
class Node {
public:
    std::string m_Label; /// @brief This Node's Label
    std::string m_Attribute; /// @brief This Node's Attribute

    /// @brief Edit a Node's Attribute
    /// @param[in] New_Value The value to set the selected Attribute to
    void edit_attribute(std::string New_Value);
};

}

#endif