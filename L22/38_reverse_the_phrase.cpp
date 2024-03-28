//given a character array, reverse the order of the words
//solve it in-place , i.e. without allocating extra space
// eg: "the sky is blue" ---> "blue is sky the"

#include <iostream>
using namespace std;

int stringLength(char arr[]){
    int length = 0;
    int i = 0;
    while(arr[i]!='\0'){
        length++;
        i++;
    }
    return length;
}

void reverseWords(char arr[])
{
    int i = 0;
    int j = 0;

    while (true)
    {
        while ( (arr[j] != ' ') && (arr[j] != '\0') )
        {
            j++;
        }

        int start = i;
        int end = j - 1;
        while (start <= end)
        {
            swap(arr[start++], arr[end--]);
        }

        if (arr[j] == '\0')
        {
            break;
        }

        i = j + 1;
        j = j + 1;
    }
}

void reversePhrase(char arr[]){
    int s = 0;
    int e = stringLength(arr)-1;

    while(s<=e){
        swap(arr[s++],arr[e--]);
    }

    reverseWords(arr);
}

int main(){
    char arr[100] = "the sky is blue.";

    reversePhrase(arr);

    cout<<arr<<endl;
}