#include "huffman.h"
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

//konstruktor za cvor
Node::Node(char c, int frq, Node* left, Node* right) {
    this->c = c;
    this->frq = frq;
    this->left = left;
    this->right = right;
}

//struktura sa poredbenom funkcijom za prioritetni red
struct cmp {
    bool op(Node* left, Node* right) {
        if (left->frq > right->frq) {
            return true;
        }
        return false;
    }
};

Node* createTree(const unordered_map<char, int>& frqMap)
{
    priority_queue<Node*, vector<Node*>, cmp> pq;

    //incijalizacija prioritetnog reda sa pojedinacnim cvorovima
    for (auto pair : frqMap) {
        pq.push(new Node(pair.first, pair.second));
    }
}

void generateCodes(Node* root, string& str, unordered_map<char, string>& codeMap)
{

}

string encode(string& message, unordered_map<char, string>& codeMap)
{
    return string();
}

string decode(string& code, Node* root)
{
    return string();
}
