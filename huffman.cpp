#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Node{
public:
    char ch;
    int freq;
    Node *left;
    Node *right;
    
    Node(){
        ch = '\0';
        freq = 0;
        left = right = NULL;
    }
    
    Node(char ch, int freq){
        this->ch = ch;
        this->freq = freq;
        left = right = NULL;
    }
};

class Compare{
public:
    bool operator()(Node *a, Node *b){
        return a->freq > b->freq;
    }
};

priority_queue <Node*, vector<Node*>, Compare> calFrequency(string &word){
    unordered_map<char, int> freq;
    for (char ch : word) freq[ch]++;
    
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for (auto it : freq) minHeap.push(new Node(it.first, it.second));
        
    return minHeap;
}

Node* buildHuffmanTree(priority_queue <Node*, vector<Node*>, Compare> &minHeap){
    while (minHeap.size() > 1){
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();
        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left;  
        merged->right = right;
        minHeap.push(merged);
    }
    return minHeap.top();
}

void generateCode(Node *root, unordered_map <char,string> &codes, string code){
    if (!root) return;
    if (root->ch != '\0') codes[root->ch] = code;
    
    generateCode(root->left, codes, code+"0");
    generateCode(root->right, codes, code+"1");
}

unordered_map<char,string> huffmanEncoding(string &word){
    priority_queue <Node*, vector<Node*>, Compare> minHeap = calFrequency(word);
    Node *root = buildHuffmanTree(minHeap);
    unordered_map <char,string> codes;
    generateCode(root,codes,"");
    return codes;
}

int main() {
    string word = "abbbaaccvvddaaggdddbbb";
    unordered_map <char,string> codes = huffmanEncoding(word);
    for (auto it: codes){
        cout << it.first << "-" << it.second << endl;
    }
    return 0;
}