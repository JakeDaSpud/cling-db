#ifndef CLING_H
#define CLING_H

#include "./node_group.h"

// Cling Declarations
namespace cling {

/// @brief Cling App Class
class Cling {
public:

    /// @brief Default Constructor
    Cling() {
        std::cout << "Cling App instantiated" << std::endl;
    };

    /// @brief Default Destructor
    ~Cling() {
        std::cout << "Cling App destroyed" << std::endl;
    };

    /// @brief Start Cling instance
    void start();
    
private:
    NodeGroup _m_current_nodegroup; /// @brief The Current Node Group in use
    Node _m_current_editing_node; /// @brief The Current Node being edited
    bool _m_edit_mode = false; /// @brief If a Node is being edited

private:
    /// @brief End Cling instance
    void _end();

    /// @brief Enter / Use the named Node Group
    /// @param NodeGroup_Name Name of the Node Group you want to use
    void _use_node_group(std::string NodeGroup_Name);

    /// @brief Create a new Node Group
    /// @param NodeGroup_Name Name of new Node Group, e.g. "Manga Collection"
    void _create_node_group(std::string NodeGroup_Name);

    /// @brief Print the Node Group Menu
    void _print_node_group_menu(); 

    /// @brief Print the Node Menu 
    void _print_node_menu();
    
    /// @brief Print the help menu
    void _print_help(); 
};

}

#endif