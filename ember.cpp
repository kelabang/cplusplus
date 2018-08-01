#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

#define MAX 30

using namespace std;

int main () {
    int a;
    
    int coba = 0;
    
    do{
        
        // declare
        int total_beban=0;
        int total_input=0;
        int i=0;
        int data_input[MAX];
        float ib = 0;
        
        string my_string;
        cout<<"input beban :"<<endl;
        
        // populate the input
        getline(cin, my_string);
        stringstream ss(my_string);
        int temp;
        
        while (ss >> temp) {
            data_input[i] = (int) temp;
            total_beban = total_beban + data_input[i];
            i++;
        }
        
        total_input = i;
        
        i=0;
        
        // ideal balanced
        ib = (float)total_beban/(float)total_input;
        
        ib = ceil(ib);
        

        // output data
        i = 0;
        do {
            cout<<data_input[i]<<" ";
            i++;
        }
        while(i<total_input);
        coba++;
        cout<<"  h#"<<coba<<": "<<ib<<endl;

    }
    while(true);

    return 0;
}