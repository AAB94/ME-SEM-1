#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int trials = 10000;
    int i, j, k;
    int people = 0;
    int count = 0;
    cout<<"Enter Number of People"<<endl;
    cin>>people;
    srand(time(NULL));
    for(i = 0;i < trials; ++i){
        int *ptr = (int *)calloc(people, sizeof(int));
        bool flag = false;
        for(j = 0;j < people; ++j){
            ptr[j] = rand() % 365 + 1;
        }
        for(j = 0; j < people; ++j){
            for(k = j+1; k < people; ++k){
                if(ptr[j] == ptr[k]){
                    count++;
                    flag = true;
                    break;
                }
            if(flag)
                break;
            }
        }
        free(ptr);
    }
    double ans = count/trials;
    cout<<"Answer is "<<ans;
    return 0;
}