// print all combinations of k elements from n-element array

// Creating all possible k combinations of n items in C++
//   https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c

#include <iostream>
#include <vector>

using namespace std;

vector<int> array;
vector<int> state;

void print_state(){
    for (int i=0; i<state.size(); i++){
        cout << state[i] << ' ';
    }
    cout << endl;
}

void combine(int offset, int k){
    if ( k == 0 ) {
        print_state();
        return ;
    }
    else {
        for (int i=offset; i<=array.size()-k; i++){
            state.push_back(array[i]);
            combine(i+1, k-1);
            state.pop_back();
        }
    }
}

int main(){
    int n = 5, k = 4;
    for (int i=0; i<n; i++){
        array.push_back(i);
    }
    combine(0, k);

    return 0;
}
