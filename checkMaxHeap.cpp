#include<iostream>
#include<vector>

bool checkheap(int heap[],int parent,int size){
    //check if current is greater than parent
    if(parent>size){return true;}
    int leftchild=2*parent+1;
    int rightchild=2*parent+2;
    if(leftchild<size && heap[leftchild]>heap[parent]){
        return false;
    }
    else if(rightchild<size && heap[rightchild]>heap[parent]){
        return false;
    }

        if(!checkheap(heap,leftchild,size) || !checkheap(heap,rightchild,size)){return false;}
  

    return true;

}
int main(){
    int heap[]= {80,13,12,5,11,1};
    int root=0;
    int size=6;
    if(checkheap(heap,root,size)){
        std::cout<<"yes";
    }
    else{
        std::cout<<"no";
    }
    return 0;
}
