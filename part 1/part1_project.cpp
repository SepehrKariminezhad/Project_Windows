#include<iostream>
#include"shape.h"
#include <ctime>
#include "vector with 1 ptr.h"
#include "vector with 2 ptr.h"

using namespace std;

int main() {
    //creating a cube and a vector that is written with one pointer
    Cube a ;
    vector<Cube> vec1;
    vec1.push_back(a);
    int onestar_insert;
    int onestar_remove;
    int twostar_insert;
    int twostar_remove;


    // the amount of cubes of reaching about 0.1 MB is about 3125 cubes
    for (int i = 0; i < 3124; i++) {
        vec1.push_back(a);
    }

    vec1.sizeof_();    //this tells us that the size of our cubes is 0.1 MB


    // the for to perform 1000 insert and remove functions and recording the cpu ticks
    
    clock_t s1;
    s1 = clock();
    for (int i = 0; i <= 1000; i++) {
        vec1.insert(i, a);
    }
     onestar_insert = clock() - s1;




    s1 = clock();
    for (int i = 0; i <= 1000; i++) {
        vec1.remove(i);
    }
     onestar_remove = clock() - s1;
        
  


    //creating a vector that is written with 2 pointers and passing 3125 cubes which reaches 0.1 MB according to line 22
    vector_2<Cube> vec2 (3125 , a);




    // the for to perform 1000 insert and remove functions and recording the cpu ticks
    s1 = clock();
    for (int i = 0 ; i < 1001 ; i++)
    {
        vec1.insert(i, a);
    }
    twostar_insert = clock() - s1;


    s1 = clock();
    for (int i = 0 ; i < 1001 ; i++)
    {
        vec1.remove(i);
    }
    twostar_remove = clock() - s1;

    //printing the conclusion
    cout << "one star clock (insert) : " << onestar_insert << endl;
    cout << "one star clock (remove) : " << onestar_remove << endl;
    cout << "two star clock (insert) : " << twostar_insert << endl;
    cout << "two star clock (remove) : " << twostar_remove << endl;

}


