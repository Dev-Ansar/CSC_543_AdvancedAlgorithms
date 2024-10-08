#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// Structure for a Huffman Tree node
struct Node {
    char data; // Character
    int freq;  // Frequency
    Node* left;
    Node* right;

    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue to build the min-heap
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman codes using preorder traversal
void printCodes(Node* root, string str) {
    if (!root) return;

    // If this is a leaf node, print the code
    if (!root->left && !root->right) {
        cout << str <<" ";
        return;
    }

    // Traverse the left and right subtrees
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to print Huffman Explanation
void printExplanation(Node* root, string str) {
    if (!root) return;

    // If this is a leaf node, print the character and its code
    if (!root->left && !root->right) {
        cout << root->data << ": " << str << endl;
        return;
    }

    // Traverse the left and right subtrees
    printExplanation(root->left, str + "0");
    printExplanation(root->right, str + "1");
}


// Function to build the Huffman Tree
Node* buildHuffmanTree(vector<char> data, vector<int> freq) {
    // Create a min-heap of nodes
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (size_t i = 0; i < data.size(); ++i) {
        minHeap.push(new Node(data[i], freq[i]));
    }

    // Iterate while the size of the heap doesn't become one
    while (minHeap.size() != 1) {
        // Extract the two nodes with the minimum frequency
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with these two nodes as children
        Node* internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        // Add the new internal node to the min-heap
        minHeap.push(internalNode);
    }

    // The remaining node is the root of the Huffman Tree
    return minHeap.top();
}

int main() {
    // Input string of characters
    string S;
    cout << "Enter the string of distinct characters: ";
    getline(cin, S);

    // Input frequencies
    vector<int> freq(S.size());
    cout << "Enter the frequencies for each character separated by space: ";
    for (size_t i = 0; i < S.size(); ++i) {
        cin >> freq[i];
    }
    cin.ignore();


    // Build the Huffman Tree
    Node* root = buildHuffmanTree(vector<char>(S.begin(), S.end()), freq);

    // Print the Huffman codes in preorder traversal
    cout << "Huffman Codes:\n";
    printCodes(root, "");
    cout<<"\n\nExplanation:"<<endl;
    printExplanation(root, "");

    return 0;
}
