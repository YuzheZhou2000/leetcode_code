#include<bits/stdc++.h>
using namespace std;

int fast(vector<int>& vec, int star, int end){
    int flag = vec[star];
    while(star < end){
        while (end> star && vec[end] >= flag){
            end --;
        }
        vec[star] = vec[end];
        while(end > star && vec[star] < flag){
            star++;
        }
        vec[end] = vec[star];

    }
    vec[star] = flag;
    return star;
}

void fastSort(vector<int> & vec, int star, int end){
    if (star > end){
        return;
    }
    int index = fast(vec, star, end);
    fastSort(vec, star, index-1);
    fastSort(vec, index+1, end);
}
int main(){
    vector<int> vec = {7,5,3,8,2,7,22,6,1};
    cout <<"source vec: ";
    for (auto & i : vec){
        cout <<i<<"  ";
    }
    cout << endl;
    fastSort(vec, 0, vec.size()-1);
    cout <<"fast sort vec: ";
    for (auto & i : vec){
        cout <<i <<"  ";
    }

}