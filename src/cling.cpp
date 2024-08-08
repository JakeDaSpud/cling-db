
#include "../headers/cling.h"

void cling::Cling::start() {
    // -= Cling App Flow =-

    // Welcome User
    std::cout << "Cling started, [h] or [help] for help.\n";

    // Try Import Node Groups
    _import_node_groups();

    // Main App Print -> Input Loop
    while (_m_user_input != "EXIT" && _m_user_input != "QUIT") {
        
        // Prompt:Select NodeGroup
        // data/ has more than 0 directories: Show Node Group names: Prompt:Select Node Group
        // data/ has 0 directories: "No Node Groups, create a new Node Group?"
        
        if (_m_current_nodegroup.name == "__NULL_NODEGROUP__") {
            _print_main_menu();
            _get_user_input();

            // Check input

            // Help Command
            if (_m_user_input == "H" || _m_user_input == "HELP") {
                _print_help();
            }

            // View Command
            else if (_m_user_input == "VIEW") {
                command_view();
            }

            // Use Command
            else if (_m_user_input.substr(0, 4) == "USE ") {
                for (int i = 0; i < _m_found_node_groups.size(); i++) {
                    std::string node_name_upper = _string_to_upper(_m_found_node_groups[i]);
                    
                    if (_m_user_input.substr(4) == node_name_upper) {
                        _m_current_nodegroup = _m_found_node_groups[i];
                    }
                }

                std::cout << "Error: Didn't find that Node Group\n";
            }

            else {
                std::cout << "Error: Unrecognised command\n";
            }
        }

        // For Selected Node Group:
        // If file not null: populate nodes[] according to how many nodes the top line says it has:
        // Prompt:What do you want to do in the Node Group?:Create Node, view, sort (view), exit, print to {.txt, .csv}
        // On exit, save to file according to node pattern

        // In a Node Group
        else {
            _print_node_group_menu();
            _get_user_input();

            // When User goes out of the Node Group, set _m_current_nodegroup.name to "__NULL_NODEGROUP__"
        }

    }

    _end();
}

void cling::Cling::_get_user_input() {
    // Take User Input
    getline(std::cin, _m_user_input);
    _m_user_input = _string_to_upper(_m_user_input);
}

void cling::Cling::_end() {
    std::cout << std::endl;
    std::cout << "Saving data...\n";

    // Write Node Group Files

    std::cout << "Finished writing files.\n";

    std::cout << "Closing Cling, goodbye!\n";
}

void cling::Cling::_import_node_groups() {
    std::cout << "Trying to Import Node Groups..." << '\n';

    if (std::filesystem::exists(_DATA_PATH) && std::filesystem::is_directory(_DATA_PATH)) {
        std::cout << "Found data/ Path" << '\n';
        
        // Iterate on every directory in the data/ path
        for (const auto& entry : std::filesystem::directory_iterator(_DATA_PATH)) {

            // Check if the entry is a directory, if yes: add directory name to _m_node_groups
            if (entry.is_directory()) {
                std::cout << "Found Node Group: " << entry.path().filename().string() << '\n';
                _m_found_node_groups.push_back(entry.path().filename().string());
            }
        }

        if (_m_found_node_groups.size() == 0) {
            std::cout << "Didn't find any Node Groups in the data/ Path" << '\n';
        }
    }
    
    else {
        std::cout << "Didn't find data/ Path, create a new Node Group to make it" << '\n';
    }
}

void cling::Cling::command_view() {
    // Empty check
    if (_m_found_node_groups.empty()) {
        std::cout << "No Node Groups\n";
        return;
    }

    std::cout << "Node Groups:\n";
    for (int i = 0; i < _m_found_node_groups.size(); i++) {
        std::cout << " - " << _m_found_node_groups[i] << '\n';
    }
}

void cling::Cling::command_use(std::string NodeGroup_Name) {

}

void cling::Cling::_create_node_group(std::string NodeGroup_Name) {

}

void cling::Cling::_print_main_menu() {
    std::cout << std::endl;
    std::cout << "-= Cling: No Node Group in use =-\n"
        << "[view]\n"
        << "[use] Node Group Name\n"
        << "[create] New Node Group Name\n"
        << "[help] [h]\n"
        << "[exit] [quit]\n"
        << "Input: ";
}

void cling::Cling::_print_node_group_menu() {
    std::cout << std::endl;
    std::cout << "-= Node Group: " + _m_current_nodegroup.name + " =-\n";
    
    if (_m_found_node_groups.size() > 0) {
        std::cout << "Choose which Node Group to use, or create a new one\n";

        for (int i = 0; i < _m_found_node_groups.size(); i++) {
            std::cout << "[use] " + _m_found_node_groups.at(i) << "\n";
        }

        std::cout << "[create] New Node Group Name\n";
        std::cout << "Input: ";
    }

    else {
        std::cout << "No Node Groups Found\n";
        std::cout << "[create] New Node Group Name\n";
        std::cout << "Input: ";
    }
}

void cling::Cling::_print_node_menu() {
    std::cout << std::endl;
    std::cout << "_print_node_menu() invoked...\n";
    std::cout << "In Node Group [", _m_current_nodegroup.name, "]\nInput: ";
}

void cling::Cling::_print_help() {
    std::cout << std::endl;
    std::cout   << "-= Cling Commands Help =-\n" 
                    << "[H] [Help]: Show this help menu\n"
                    << "[quit] [exit]: Exit the Cling app\n\n"

                    << "While not in a Node Group:\n"
                        << "\t[create \"NodeGroup_Name\"]: Create a new Node Group by name\n"
                        << "\t[view]: View all Node Groups\n"
                        << "\t[use \"Name_of_NodeGroup\"]: Use a Node Group by name\n\n"

                    << "While in a Node Group:\n"
                        << "\t[add \"Node_Label\"]: Add a new, null Node with a Label\n"
                        << "\t[edit \"Node_Label\"]: Enter edit mode for the Node with this Label\n"
                            << "\t\t[\"Node_Attribute\" \"New_Value\"]: Set this Node's Node_Attribute to New_Value\n"
                            << "\t\t[done]: Exit edit mode\n"
                        << "\t[sort \"Node_Attribute\"]: View all Nodes, sorted by ascending parameter\n"
                        << "\t[view]: View all Nodes, sorted by ascending Label\n\n"

                    << "__MORE COMMANDS FOR EXPORTING A NODE GROUP AS CSV OR TXT__\n\n";
}

std::string cling::Cling::_string_to_upper(const std::string &string_input) {

    std::string upper_string = string_input;

    // Uppercase ALL Letters
    for (int i = 0; i < string_input.length(); i++) {
        upper_string[i] = toupper(string_input[i]);
    }

    return upper_string;
}
