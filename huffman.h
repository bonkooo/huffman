#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include <string>
#include <unordered_map>
using namespace std;

struct Node {
	int frq;
	char c;
	Node* left, *right;

	Node(char c, int frq, Node* left = nullptr, Node* right = nullptr);
};

Node* createTree(const unordered_map<char, int>& frqMap);
void generateCodes(Node* root, string& str, unordered_map<char, string>& codeMap);
string encode(string& message, unordered_map<char, string>& codeMap);
string decode(string& code, Node* root);

#endif // !_HUFFMAN_H

