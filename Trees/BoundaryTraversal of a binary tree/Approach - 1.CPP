//gfg problem link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab 

class Solution {
public:

void findleafnodes(Node *root, vector<Node*>  &leafnodes){
    if(root==nullptr) return;
    if(root->left==nullptr && root->right==nullptr){
      leafnodes.push_back(root);
      return;
    }
    findleafnodes(root->left,leafnodes);
    findleafnodes(root->right,leafnodes);
}
void findleftboundary(Node *root, vector<Node*> &leftboundary){
    if(!root) return;
    //if a particular node's left child and right child is null 
    //then it is a leaf node so don't add it here, since it's already 
    //in the leafnodes vector
    if(root->left==nullptr && root->right==nullptr){
        return;
    }
    leftboundary.push_back(root);
    findleftboundary(root->left,leftboundary);
}

void findrightboundary(Node *root, vector<Node*>&rightboundary){
    if(!root) return;
    //if a particular node's left child and right child is null 
    //then it is a leaf node so don't add it here, since it's already 
    //in the leafnodes vector
    if(root->left==nullptr && root->right==nullptr){
        return;
    }
    
    //also right boundary elements are to be printed in bottom to top, so we first call and return and then we add the root
    findrightboundary(root->right, rightboundary);
    rightboundary.push_back(root);
}
vector<int> boundary(Node *root)
{
    vector<Node*> leafnodes;
    vector<Node*> leftboundary;
    vector<Node*> rightboundary;

    //leaf nodes:
    findleafnodes(root,leafnodes);
    //left boundary nodes:
    findleftboundary(root,leftboundary);
    //right boundary nodes:
    findrightboundary(root,rightboundary);

    //output order: leftboundary+leafnodes+rightboundary
    
    //also the root element is present in both the boundary vectors right now, and ideally should be removed from one of the nodes
    //rightboundary has root element as the last element of vector so remove it.
    rightboundary.pop_back(); //to remove last element from a vector, not pop but popback is used
    
    vector<int> boundarytraversalorder;
    for(Node* node: leftboundary){
        boundarytraversalorder.push_back(node->data);
    }
    for(Node* node: leafnodes){
        boundarytraversalorder.push_back(node->data);
    }
    for(Node* node: rightboundary){
        boundarytraversalorder.push_back(node->data);
    }
    return boundarytraversalorder;

}
};


//THIS GIVES SEPGEMENTATION FAULT