#include<bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char ch , int freq){
        this->ch = ch;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

struct Compare{
    bool operator()(Node *a , Node *b){
        return a->freq > b->freq;
    }
};

void print(Node *root , string str , unordered_map<char , string> *mp){
    if(!root){
        return;
    }
    if(!root -> left && !root -> right){
        (*mp)[root->ch] = str;
        // cout << root->ch <<  " : " << str << endl;
    }
    print(root -> left , str+'0' , mp);
    print(root -> right , str+'1' , mp);
}

int main(){
    vector<pair<char , int>> arr ={
        {'A' , 6},
        {'B' , 7},
        {'C' , 4},
        {'D' , 5}
    };
    priority_queue<Node * , vector<Node *> , Compare> minHeap;
    for(int i=0 ;i < arr.size() ; i++){
        minHeap.push(new Node(arr[i].first , arr[i].second));
    }

    while (minHeap.size() > 1){
        Node *left = minHeap.top();
        minHeap.pop();
        Node * right = minHeap.top();
        minHeap.pop();
        Node *merge = new Node('#' , left->freq+right->freq);
        merge->left = left;
        merge->right = right;
        minHeap.push(merge);
    }
    cout << minHeap.top()->freq << endl;
    unordered_map<char , string> map;
    print(minHeap.top() , "" , &map);
    cout << "Enter the string to encode \n";
    string incode;
    cin >> incode;
    string ans = "";
    for(int i= 0 ; i< incode.length() ; i++){
        ans += map[incode[i]];
    }
    cout << "The encoded string is \n" << ans << endl;
    return 0;
}