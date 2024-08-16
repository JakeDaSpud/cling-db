#ifndef CLING_H
#define CLING_H

#include "./node_group.h"
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>

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
    std::string _m_user_input = "__START_INPUT__";
    std::vector<std::string> _m_found_node_groups; /// @brief Node Groups that Cling has found from data/
    NodeGroup _m_current_nodegroup = NodeGroup("__NULL_NODEGROUP__"); /// @brief The Current Node Group in use
    Node _m_current_editing_node; /// @brief The Current Node being edited
    bool _m_edit_mode = false; /// @brief If a Node is being edited
    const std::string _DATA_PATH = "data/"; /// @brief Relative path to where User Data is stored

private:
    /// @brief End Cling instance
    void _end();

    /// @brief Takes standard input and capitalises it
    void _get_user_input();

    /// @brief Find Node Group Names from data/ and push to _m_node_groups
    void _import_node_groups();

    /// @brief Create a new Node Group
    /// @param NodeGroup_Name Name of new Node Group, e.g. "Manga Collection"
    void _create_node_group(std::string NodeGroup_Name);

    void _print_main_menu();
    void _print_node_group_menu(); 
    void _print_node_menu();
    void _print_help();

    /// @brief Returns a capitalised Input String
    /// @param string_input
    /// @return Capitalised form of Input String
    std::string _string_to_upper(const std::string &string_input);

    // needs docs
    std::string cling::Cling::_string_to_lower(const std::string &string_input);

    // User's Commands

    /// @brief Prints out all detected Node Groups, or a message if none are found
    void command_view();

    /// @brief Enter / Use the named Node Group
    /// @param NodeGroup_Name Name of the Node Group you want to use
    void command_use(std::string NodeGroup_Name);
};

}

#endif