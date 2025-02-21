** Leetcode Problem 138 :- **

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state.
None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

** Code :- **

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        unordered_map<Node*, Node*> map;
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        map[head] = newHead;
        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            map[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            newTemp->random = map[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};

** Time Complexity :- **
    
    
Creating the New List and Mapping Nodes :
The algorithm iterates through the original list once to create a mapping between old nodes and their corresponding new nodes.
Each node is processed once, making this step O(n).
Updating Random Pointers :
A second iteration is performed over the original list to update the random pointers in the new list.
Each node is accessed once again, contributing another O(n).
Total Time Complexity :
Best Case: O(n) → If the linked list has no random pointers or they are NULL, both iterations still take O(n).
Worst Case: O(n) → Every node has a random pointer, but the mapping still allows O(1) lookups.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Extra Hash Map for Node Mapping :
The algorithm uses an unordered_map (map<Node*, Node*>) to store the mapping of original nodes to copied nodes.
In the worst case, the map stores n key-value pairs, where n is the number of nodes in the list.
New List Creation :
A new linked list of size n is created, but this is required for the output and does not count as extra space.
Total Space Complexity :
O(n) → Due to the hash map storing the mapping between original and new nodes.
