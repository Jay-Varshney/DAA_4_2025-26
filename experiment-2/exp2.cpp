#include<bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(int freq , char ch){
        this -> ch = ch;
        this -> freq = freq;
        left = NULL;
        right = NULL;
    }
};

struct Compare{
  bool operator()(Node* a , Node*b){
      return a->freq > b->freq;
  }  
};

void print(Node* top , string ans , unordered_map<char , string>& mp){
    if(top == NULL){
        return;
    }
    if(top -> left == NULL && top -> right == NULL){
        mp[top -> ch] = ans;
        // cout << top->ch << " " << ans << endl;
    }
    print(top -> left , ans+'0' , mp);
    print(top -> right , ans+'1' , mp);
}

void decode(string en, Node* root, string & ans) {
    Node* curr = root;
    for (char bit : en) {
        if (bit == '0'){
            curr= curr->left;
        }
        else{
            curr =curr->right;
        }
        if (curr->left== NULL && curr->right ==NULL) {
            ans += curr->ch;
            curr =root;
        }
    }
}


int main(){
    cout << "Please enter an string to encode in small case\n";
    string s;
    cin >> s;
    int arr[26] ={0};
    for(int i= 0 ; i< s.length() ; i++){
        arr[s[i] - 'a']++;
    }
    vector<pair<char , int>> all;
    for(int i =0 ;i < 26 ; i++){
        if(arr[i] > 0){
            all.push_back({'a'+i , arr[i]});
        }
    }
    priority_queue<Node * , vector<Node *> , Compare> minHeap;
    for(int i= 0 ;i < all.size() ; i++){
        minHeap.push(new Node(all[i].second , all[i].first));
    }
    while (minHeap.size() > 1){
        Node *left = minHeap.top();
        minHeap.pop();
        Node * right = minHeap.top();
        minHeap.pop();
        Node *merge = new Node(left->freq+right->freq , '#');
        merge->left = left;
        merge->right = right;
        minHeap.push(merge);
    }
    cout << minHeap.top()->freq << endl;
    unordered_map<char , string> enco;
    print(minHeap.top() , "" , enco);
    for(auto i: enco){
        cout << i.first << " " << i.second << endl;
    }
    cout << "Your string is\n";
    cout << s << endl;
    string encoded = "";
    cout << "Your encoded string is\n";
    for(int i= 0 ; i< s.length() ; i++){
        encoded += enco[s[i]];
        // cout << enco[s[i]];
    }
    cout << encoded << endl;
    string decoded = "";
    decode(encoded , minHeap.top() , decoded);
    cout << "Your decoded string is\n" << decoded;
    return 0;
}