
#include "../headers/cling.h"

void cling::Cling::start() {
    std::cout << "Cling start()" << std::endl;

    // -= Cling App Flow =-

    // Welcome User

    // Prompt:Select NodeGroup
    // data/ has more than 0 directories: Show Node Group names: Prompt:Select Node Group
    // data/ has 0 directories: "No Node Groups, create a new Node Group?"

    // For Selected Node Group:
    // If file not null: populate nodes[] according to how many nodes the top line says it has: 
    // Prompt:What do you want to do in the Node Group?:Create Node, view, sort (view), exit, print to {.txt, .csv}
    // On exit, save to file according to node pattern 

}
