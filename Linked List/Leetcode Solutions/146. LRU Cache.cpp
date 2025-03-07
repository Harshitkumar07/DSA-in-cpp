** Leetcode Problem 146 :- **

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input :
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output :
[null, null, null, 1, null, -1, null, -1, 3, 4]
Explanation :
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

** Code :- **

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev,*next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> map;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newnode) {
        Node* temp = head->next;

        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node* delnode) {
        Node* prev = delnode->prev;
        Node* next = delnode->next;
        prev->next = next;
        next->prev = prev;
    }

    int get(int key) {
        if (map.find(key) != map.end()) {
            Node* resNode = map[key];
            int ans = resNode->val;

            map.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            map[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* curr = map[key];
            map.erase(key);
            deleteNode(curr);
        }

        if (map.size() == cap) {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        map[key] = head->next;
    }
};


** Time Complexity :- **

1. get(int key) - Accessing a Value
Lookup in unordered_map: Takes O(1).
Removing and Re-inserting the Node:
Deleting the node: Takes O(1) (adjusting pointers in a doubly linked list).
Adding the node to the front: Takes O(1) (inserting at the head).
Total Complexity: O(1).
2. put(int key, int value) - Inserting a Value
Checking if the key exists (unordered_map lookup): O(1).
Deleting the existing node (if key exists): O(1).
Removing the least recently used node (if capacity is full): O(1).
Adding the new node: O(1).
Updating unordered_map: O(1).
Total Complexity: O(1).
Total Time Complexity for All Operations
Operation	Complexity :
get(key)	O(1)
put(key, value)	O(1)
Since both get and put operate in constant time, the overall time complexity is O(1) per operation.

** Space Complexity :- **
    
1. Storing Key-Value Pairs in unordered_map
The unordered_map stores O(capacity) key-node pairs, leading to O(capacity) space.
2. Storing Nodes in the Doubly Linked List
The doubly linked list stores at most O(capacity) nodes, leading to O(capacity) space.
Total Space Complexity :
O(capacity) + O(capacity) = O(capacity).
