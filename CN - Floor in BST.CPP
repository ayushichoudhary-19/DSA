int Floor(BinaryTreeNode<int> *node, int input)
{
	int floor=-1;
	while(node){ 
		if(node->data==input) return node->data;

		else if(node->data>input){
			//means i want something even smaller so i move left
			//but i do not want anything larger than my input as floor so floor not updated rn
			node=node->left;
		}
		else{
			//if we have found something which is smaller than the floor we put it in floor
			floor=node->data;
			node=node->right;
		}
	}
	return floor;
}
