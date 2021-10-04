// https://practice.geeksforgeeks.org/viewSol.php?subId=b59164e741e8bed230f4ce32f6419bc5&pid=705885&user=siddharthiiitg
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
        struct MinHeapNode{
            char data;
            int freq;
        
            MinHeapNode *left; 
            MinHeapNode *right;
        
            MinHeapNode(char data, int freq){
                left = right = NULL;
        
                this->data = data;
                this->freq = freq;
            } 
        };
  
        struct compare{
            bool operator()(MinHeapNode *l, MinHeapNode *r){
                return (l->freq > r->freq);
            }
        };
        
        vector <string > vstr;
        void printCodes(struct MinHeapNode* root, string str){
            if(!root){
                return ;
            }
            if(root->data != '$'){ //is leaf node
                // cout << str << " ";
                vstr.push_back(str);
            }
        
            printCodes(root->left, str+"0");
            printCodes(root->right, str+"1");
        }
        
        	vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    struct MinHeapNode *Left, *Right, *Top;

            priority_queue<MinHeapNode*, vector<MinHeapNode *>, compare> MinHeap;
            for(int i = 0; i < N; i++){
                MinHeap.push(new MinHeapNode(S[i], f[i]));
            } 
        
            while (MinHeap.size() != 1)
            {
                Left = MinHeap.top();
                MinHeap.pop();
                Right = MinHeap.top();
                MinHeap.pop();
        
                Top = new MinHeapNode('$', Left->freq+Right->freq);
                Top->left = Left;
                Top->right = Right;
              
              MinHeap.push(Top);
            }
            printCodes(MinHeap.top(), "");
            return vstr;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
       vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
