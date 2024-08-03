# Cling User Flow / Usecases

_Key_\
@: = User input\
C: = Cling is talking

### Usecase: Manga Collection Tracking
_@Jake_\
Jake collects manga and wants to track his collection from his phone, so when he's out he can find the data.\
He does this by uploading his Cling data as a .txt / .csv to a github repository.

```
@:  cling.exe
C:  Cling started, [H] or [Help] for Help
@:  h
C:  Cling Commands:

        [H] [Help]: Show this help menu
        [quit] [exit]: Exit the Cling app

        While not in a NodeGroup:
        [create "NodeGroup_Name"]: Create a new NodeGroup by name 
        [view]: View all NodeGroups
        [go "Name_of_NodeGroup"]: Enter / Use a NodeGroup by name

        While in a NodeGroup:
        [add "Node_Label"]: Add a new, null Node with a Label
        [edit "Node_Label"]: Enter edit mode for the Node with this Label
            ["Node_Attribute" "New_Value"]: Set this Node's Node_Attribute to New_Value
            [done]: Exit edit mode
        [sort "Node_Attribute"]: View all Nodes, sorted by ascending parameter
        [view]: View all Nodes, sorted by ascending Label

        __MORE COMMANDS FOR EXPORTING A NODE GROUP AS CSV OR TXT__
```