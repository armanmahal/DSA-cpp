//implementation of heaps

#include <iostream>
using namespace std;

//implementation class of a max-heap:
class heap {
    public:
    int arr[100];
    //initial size :
    int size = 0;

    //function to print:
    void print(){
        for(int i = 1; i <= size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    //function to insert:
    void insert(int val){
        size = size+1;
        int indexToInsert = size;

        //inserting element to the array:
        arr[indexToInsert] = val;

        //putting the inserted element to its right position , by comparing it to the parent element (if larger than parent element , swap it , in case of  max-heap)
        while(indexToInsert > 1){
            int parentIndex = indexToInsert/2;

            if(arr[parentIndex] < arr[indexToInsert]){
                swap(arr[parentIndex],arr[indexToInsert]);
            }
            else{
                //if element smaller than parent:
                return;
            }
        }
    }

    //function to delete rootNode:
    void deleteFromHeap() {
        if(size== 0){
            cout<<"Empty"<<endl;
            return;
        }

        //swapping root node with last node:
        arr[1] = arr[size];
        //removing the last node i.e. the former root node:
        arr[size] = -1;
        size--;

        //take the current root node to its correct position:
        int i = 1;
        while(i < size){
            int leftChildIndex = 2*i;
            int rightChildIndex = 2*i+1;

            // comparing the root node with its left child:
            if(leftChildIndex < size && arr[i] < arr[leftChildIndex]){
                swap(arr[i], arr[leftChildIndex]);
                i = leftChildIndex;
            }
            // comparing the root node with its right child:
            else if(rightChildIndex<size && arr[i] < arr[rightChildIndex]){
                swap(arr[i], arr[rightChildIndex]);
            }
            // if root node larger than its children:
            else{
                return;
            }
        }

    }
};
 
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();

    h.print();
}