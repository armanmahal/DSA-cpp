// given a matrix(2D array) whose EACH ROW IS SORTED IN ASCENDING ORDER from left to right, EACH COLUMN IS SORTED IN ASCENDING ORDER from top to bottom and the last element of one row is NOT NECCESSARILY LESS than the first element of next row, do binary search on it.
/* example matrix:
    |1 |3 |5 |7 |11|
    |2 |5 |8 |12|19|
    |3 |6 |9 |16|22|
    |10|13|14|17|24|
    |18|21|23|26|30|

    'or'

    --> {1,3,5,7,11,2,5,8,12,19,3,6,9,16,22,10,13,14,17,24,18,21,23,26,30}

    ~thus conventional binary search is not applicable on this array
*/

#include <iostream>
#include <vector>
using namespace std;

void binarySearch(vector<vector<int>>v, int key){
    //calculating number of rows and columns
    int rows = v.size();
    int columns = v[0].size();

    //initializing the current row and column so as they should point to the index of top right element in the matrix
    int currentRow = 0;
    int currentCol = columns-1;

    bool found = false;

    while(currentRow<rows && currentCol>=0){
        
        //current element :
        int currentElement = v[currentRow][currentCol];

        //if key found:
        if(currentElement == key){
            cout << "element found at " << currentRow << " , " << currentCol << endl;
            found = true;
            break;
        }

        //if key is greater than the current element then we have to increase the current row by one , as we have start searching from top right element that is the largest element in the current row, and if key is to be greater than current element(the last element in row), than it is clear that key is not present in the current row as all the previous elements are already smaller than the current element:
        else if(currentElement < key){
            currentRow++;
        }

        //if key is smaller than the current element then then we can search in the same row by decreasing current column one by one as the previous elements in one array are smaller so there is a chance of finding the key: 
        else{
            currentCol--;
        }
    }

    //if key not found
    if(!found){
        cout<<"Element does not exist"<<endl;
    }

}

int main(){

    vector<vector<int>> v = {{1,3,5,7,11},
                             {2,5,8,12,19},
                             {3,6,9,16,22},
                             {10,13,14,17,24},
                             {18,21,23,26,30}};

    int key = 17;

    binarySearch(v, key);
}