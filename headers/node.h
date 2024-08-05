#ifndef NODE_H
#define NODE_H

// Node Declarations

#include <iostream>
#include <string>

namespace cling {

/// @brief An Entry with a Name Label and Attribute
class Node {
public:

    /// @brief This Node's extra Attribute(s) besides its Label
    struct node_attribute {

        /// @brief Decides the type of this Attribute
        enum class AttributeType {
            INT,
            FLOAT,
            BOOL,
            STRING
        };

        std::string name;
        AttributeType type;
    };

    std::string m_Label; /// @brief This Node's Label
    node_attribute m_Attributes[8]; /// @brief This Node's Attribute(s)

    /// @brief Edit a Node's Attribute
    /// @param[in] New_Value The value to set the selected Attribute to
    void edit_attribute(std::string New_Value);
};

}

#endif