#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
static const int MAX_SPACES = 40;
// -------------------------------
// Data class (NOT a struct)
// -------------------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;
    MonopolySpace() {
        // TODO: define default constructor (recommended)
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }
    MonopolySpace(string propertyName, string propertyColor, int value, int rent) {
        /* TODO: Define overloaded constructor here */
        this -> propertyName = propertyName;
        this -> propertyColor = propertyColor;
        this -> value = value;
        this -> rent = rent;
    }
    bool isEqual(MonopolySpace other) {
        if (this -> propertyName == other.propertyName) {
            return true;
        }
        /* TODO: Define isEqual here (compare by name is fine if you enforce uniqueness) */
        return false;
    }
    void print() {
        cout << propertyName << ", " << propertyColor << ", " << value << ", "<< rent;
        /* TODO: Define print here */
        // Example style:
        // cout << propertyName << " | " << propertyColor << " | $" << value << " |Rent " << rent;
    }
};
// -------------------------------
// Template Node class (NOT a struct)
// -------------------------------
template <typename T> class Node {
public:
    T data;
    Node<T>* nextNode;
    Node(T value) {
    data = value;
    nextNode = nullptr;
    }
};
// -------------------------------
// Template Circular Linked List class
// Spring 2026 version: traversable board
// -------------------------------
template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;
    // player cursor for traversal-based gameplay
    Node<T>* playerNode;
    int nodeCount;
    int passGoCount;
    public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;
        nodeCount = 0;
        passGoCount = 0;
    }
    // -------------------------------
    // Board Construction Policy (Reminder)
    // -------------------------------
    // Spaces are added during board construction BEFORE gameplay.
    // You choose how to construct the board:
    // - hardcode spaces, read from file, or generate programmatically
    // The only non-negotiable requirement:
    // - enforce MAX_SPACES
    // - maintain circular integrity
    // -------------------------------
    // -------------------------------
    // Core A: Add a Space with Capacity Enforcement
    // -------------------------------
    bool addSpace(T value) {
        if (nodeCount == MAX_SPACES) {
            return false;
        }
        Node<T>* newNode = new Node<T>(value);
        if (!headNode) {
            headNode = tailNode = playerNode = newNode;
            newNode->nextNode=headNode;
        }else {
            tailNode->nextNode=newNode;
            tailNode=newNode;
            tailNode->nextNode=headNode;
        }
        nodeCount++;

        // TODO:
        // - If nodeCount == MAX_SPACES return false (do not corrupt list)
        // - Create new node
        // - If empty list: head=tail=player=new, new->next=head
        // - Else: tail->next=new, tail=new, tail->next=head
        // - nodeCount++
        cout << "addSpace written" << endl;
        return true;
    }
    // -------------------------------
    // Core B: Add Multiple Spaces at Once
    // -------------------------------
    int addMany(vector<T> values) {
        int temp = 0;
        if (nodeCount >= MAX_SPACES) {
            return false;
        }
        for (int i = 0; i < values.size(); i++) {
            if (nodeCount >= MAX_SPACES) {
                break;
            }
            Node<T>* newNode = new Node<T>(values[i]);
            if (!headNode) {
                headNode = tailNode = playerNode = newNode;
                newNode->nextNode=headNode;
            } else {
                tailNode->nextNode=newNode;
                tailNode=newNode;
                tailNode->nextNode=headNode;
            }
            nodeCount++;
            temp++;

        }

        // TODO:
        // - Add sequentially until full
        // - Stop exactly when you reach MAX_SPACES
        // - Return number successfully added
        // - Do not corrupt pointers if capacity is exceeded
        cout << "Board Constructed" << endl;
    return temp;
    }
    // -------------------------------
    // Core C: Traversal-Based Player Movement
    // -------------------------------
    void movePlayer(int steps) {
        if (!playerNode) {
            return;
        }
        for (int i = 0; i < steps; i++) {
            playerNode = playerNode->nextNode;
            if (playerNode == headNode) {
                passGoCount++;
            }
        }
        cout << "Player Moved " << steps << " Spaces!" << endl;
        // TODO:
        // - Move playerNode forward 'steps' times, node-by-node
        // - Wrap naturally because list is circular
        // - Detect and track passing GO:
        // increment passGoCount when a move crosses from tail back to head
        // - Must handle empty list safely
    }
    int getPassGoCount() {
        return passGoCount;
    }
    // -------------------------------
    // Core D: Controlled Board Display
    // -------------------------------
    void printFromPlayer(int count) {
        if (!playerNode) {
            return;
        }
        Node<T>* temp = playerNode;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << " ";
            cout << temp->data.propertyName << ", ";
            cout << temp->data.propertyColor << ", ";
            cout << temp->data.value << ", ";
            cout << temp->data.rent << endl;
            temp = temp->nextNode;
        }
        // TODO:
        // - Print exactly 'count' nodes starting from playerNode
        // - Must not infinite loop
        // - Must handle empty list
        // - Output must be deterministic and readable
    }
    // Optional helper: print full board once (one full cycle)
    void printBoardOnce() {
        addMany(MAX_SPACES);
    // TODO:
    // - Traverse exactly one full cycle and print each node.
    cout << "printBoardOnce written" << endl;
    }
    // -------------------------------
    // Advanced Option A (Level 1): removeByName
    // -------------------------------
    bool removeByName(string name) {
        if (headNode == nullptr) {
            return false;
        }
        Node<T>* space = headNode;
        Node<T>* after = headNode->nextNode;
        if (headNode-> data.propertyName == name) {
            Node<T>* temp = headNode;
            if (playerNode == headNode) {
                playerNode = headNode->nextNode;
            }
            headNode = headNode->nextNode;
            tailNode->nextNode = headNode;
            delete temp;
            nodeCount--;
            return true;
        }
        do {
            if (after-> data.propertyName == name) {
                if (playerNode == after) {
                    playerNode = after->nextNode;
                    space->nextNode = after->nextNode;
                    if (after == tailNode) {
                        tailNode = space;
                    }
                    delete after;
                    nodeCount--;
                    return true;
                }
            }
        }
        while (space != headNode);
        do {
            after = space;
            space = space->nextNode;
            if (space->data.propertyName == name) {
                after->nextNode = space->nextNode;
                delete space;
                return true;
            }
        }
        while (space != headNode);

    // TODO:
    // - Delete FIRST matching node
    // - Must handle:
    // - deleting head
    // - deleting tail
    // - deleting the only-node list
    // - Maintain circular link tail->next=head
    // - If playerNode points to deleted node, move playerNode to a safe node
    // - nodeCount--
    cout << "removeByName written" << endl;
    return false;
    }
    // -------------------------------
    // Advanced Option A (Level 1): findByColor
    // -------------------------------
    vector<string> findByColor(string color) {
        vector<string> matches;
        Node<T>* current = headNode;
        do {
            if (current -> data.propertyColor == color) {
                matches.push_back(current->data.propertyName);
            }
            current = current->nextNode;
        } while (current != headNode);
    // TODO:
    // - Traverse ring exactly once
    // - Collect matching names in vector<string>
    // - Return matches

    return matches;
    }
    // -------------------------------
    // Advanced Option B (Level 2): Mirror the Board (Circular Reversal)
    // -------------------------------
    void mirrorBoard() {
        if (!headNode) {
            return;
        }
        if (headNode == tailNode) {
            return;
        }
        Node<T>* next = nullptr;
        Node<T>* before = nullptr;
        Node<T>* current = headNode;
        do {
            next = current->nextNode;
            current->nextNode = before;
            before = current;
            current = next;
        }
        while (current != headNode);
        Node<T>* temp = headNode;
        headNode = tailNode;
        tailNode = temp;

        tailNode->nextNode = headNode;

    // TODO:
    // - Reverse the direction of the circular list by reversing next pointers
    // - Preserve circular structure
    // - Correctly handle empty list and single-node list
    // - Player cursor must remain on the same logical space after reversal
    cout << "mirrorBoard written" << endl;
    }
    // -------------------------------
    // Edge-case helper: countSpaces O(n)
    // -------------------------------
    int countSpaces() {
        int spacecount = 0;
        if (!headNode) {
            return 0;
        }
        Node<T>* temp = headNode;
        do {
            spacecount++;
            temp = temp->nextNode;
        }
        while (temp != headNode);
    // TODO:
    // - Must be O(n), traverse exactly once with correct stop condition
    // - Do NOT rely on nodeCount for this method
    cout << "countSpaces written" << endl;
    return spacecount;
    }
    // -------------------------------
    // Cleanup
    // -------------------------------
    void clear() {
        if (!headNode) {
            return;
        }
        tailNode->nextNode = nullptr;

        Node<T>* current = headNode;

        while (current != nullptr) {
            Node<T>* temp = current->nextNode;
            delete current;
            current = temp;
        }
        nodeCount = 0;
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;
    // TODO:
    // - Safely delete all nodes
    // - Tip: if tailNode exists, break the cycle first: tailNode->nextNode = nullptr
    // - Then delete like a normal singly linked list
    cout << "Cleared Board!" << endl;
    }
};
// -------------------------------
// Main: playable loop demo
// -------------------------------
int rollDice2to12() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    CircularLinkedList<MonopolySpace> board;
    vector<MonopolySpace> spaces = {
        MonopolySpace("GO", "None", 0, 0),
        MonopolySpace("Mediterranean Avenue", "Brown", 0, 0),
        MonopolySpace("Baltic Avenue", "Brown", 0, 0),
        MonopolySpace("Oriental Avenue", "Light Blue", 0, 0),
        MonopolySpace("Vermont Avenue", "Light Blue", 0, 0),
        MonopolySpace("Connecticut Avenue", "Light Blue", 0, 0),
        MonopolySpace("St. Charles Place", "Pink", 0, 0),
        MonopolySpace("States Avenue", "Pink", 0, 0),
        MonopolySpace("Virginia Avenue", "Pink", 0, 0),
        MonopolySpace("St. James Place", "Orange", 0, 0),
        MonopolySpace("Tennessee Avenue", "Orange", 0, 0),
        MonopolySpace("New York Avenue", "Orange", 0, 0),
        MonopolySpace("Kentucky Avenue", "Red", 0, 0),
        MonopolySpace("Indiana Avenue", "Red", 0, 0),
        MonopolySpace("Illinois Avenue", "Red", 0, 0),
        MonopolySpace("Atlantic Avenue", "Yellow", 0, 0),
        MonopolySpace("Ventnor Avenue", "Yellow", 0, 0),
        MonopolySpace("Marvin Gardens", "Yellow", 0, 0),
        MonopolySpace("Pacific Avenue", "Green", 0, 0),
        MonopolySpace("North Carolina Avenue", "Green", 0, 0),
        MonopolySpace("Pennsylvania Avenue", "Green", 0, 0),
        MonopolySpace("Park Place", "Dark Blue", 0, 0),
        MonopolySpace("Boardwalk", "Dark Blue", 0, 0),
        MonopolySpace("Sea World", "Purple", 0, 0),
        MonopolySpace("Belmont Park", "Purple", 0, 0),
        MonopolySpace("SeaPort Village", "Purple", 0, 0),
        MonopolySpace("Balboa Park", "Purple", 0, 0),
        MonopolySpace("San Diego Zoo", "Indigo", 0, 0),
        MonopolySpace("Safari Park", "Indigo", 0, 0),
        MonopolySpace("Santee Lake", "Indigo", 0, 0),
        MonopolySpace("San Diego River", "Black", 0, 0),
        MonopolySpace("Gas Lamp", "Black", 0, 0),
        MonopolySpace("Little Italy", "Black", 0, 0),
        MonopolySpace("Cabrillo National Monument", "White", 0, 0),
        MonopolySpace("Del Mar Fair", "White", 0, 0),
        MonopolySpace("Lego Land", "White", 0, 0),
        MonopolySpace("Petco Park", "Cream", 0, 0),
        MonopolySpace("Coronado Bridge", "Cream", 0, 0),
        MonopolySpace("Hotel Circle", "Cream", 0, 0),
        MonopolySpace("Midway Museum ", "Cream", 0, 0),
        MonopolySpace("Mission Beach", "Cream", 0, 0),
    };
    board.addMany(spaces);
    // -------------------------------
    // Board Construction Phase
    // -------------------------------
    // You decide how to build the board:
    // - hardcode spaces, load from file, or generate spaces programmatically
    // The only requirement: never exceed MAX_SPACES and keep the list circular.
    //
    // Example (hardcoded) usage:
    // vector<MonopolySpace> spaces;
    // spaces.push_back(MonopolySpace("GO","None",0,0));
    // ...
    // board.addMany(spaces);
    //
    // NOTE: This starter calls addSpace once to show the intended API,
    // but your final submission should build a meaningful board.
    // -------------------------------
    // Playable Traversal Loop
    // -------------------------------
    for (int turn = 1; turn <= 10; turn++) {
        int roll = rollDice2to12();
        cout << "\nTurn " << turn << " | Rolled: " << roll << endl;
        board.movePlayer(roll);
        cout << "Board view from player (next 5 spaces):" << endl;
        board.printFromPlayer(5);
        cout << "Times passed GO so far: " << board.getPassGoCount() << endl;
    }
    // -------------------------------
    // Advanced Feature Demos (students choose path)
    // -------------------------------
    // Option A examples:
    // board.removeByName("Baltic Avenue");
    // vector<string> brownProps = board.findByColor("Brown");
    cout << endl;
    board.removeByName("Hotel Circle");
    cout << "Removed property Hotel Circle!" << endl;
    cout << endl;
    vector<string> result = board.findByColor("Cream");
    cout << "Results for properties with Cream color: " << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << i + 1 << " " << result[i] << endl;
    }
    //
    // Option B example:
    // board.mirrorBoard();
    cout << endl;
    board.clear();
return 0;
}
