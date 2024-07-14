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
    bool operator()(Node* first, Node* second) {
        if (first->frq > second->frq) {
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

    //formiraj stablo
    while (pq.size() != 1) {
        Node *left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        int newFrq = left->frq + right->frq; 
        pq.push(new Node('\0', newFrq, left, right)); //ubaci novo podstablo/cvor u red
    }

    Node* root = pq.top();
    return root;
}

void generateCodes(Node* root, const string& str, unordered_map<char, string>& codeMap)
{   
    if (!root) return; //terminalni uslov za rekurziju

    if (!root->left && !root->right) { //karakteri su u listovima stabla
        codeMap[root->c] = str; //updateuj kod za karakter
    }

    generateCodes(root->left, str + "0", codeMap);
    generateCodes(root->right, str + "1", codeMap);
}

string encode(string& message, unordered_map<char, string>& codeMap)
{
    stringstream ss;
    for (char ch : message) {
        ss << codeMap[ch];
    }
    return ss.str();
}

string decode(string& code, Node* root)
{
    stringstream ss;
    Node* curr = root;
    for (char bit : code) {
        if (bit == '0') {
            curr = curr->left;
        }
        else if (bit == '1') {
            curr = curr->right;
        }

        //ako smo naisli na list (karakter) upisemo ga
        if (!curr->left && !curr->right) {
            ss << curr->c;
            curr = root; //vratimo se u koren i trazimo novi karakter
        }
    }
    
    return ss.str();
}
