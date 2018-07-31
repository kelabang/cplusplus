//
//  main.cpp
//  keledai
//
//  Created by Imam Tauhid on 31/07/2018.
//  Copyright © 2018 Imam Tauhid. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define MAX 30

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
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
        ib = (float)total_beban/(float)2;
        
        int a = 0;
        float total_right = 0; // total of the right side
        // total of the right side balance
        do{
            if(total_right < ib) { // check if total right is not yet ideal
                float temp = total_right + (float) data_input[a];
                if(temp > ib){ // check if the next data input cannot satisfy the total as an ideal (more than ideal)
                    a++;
                    continue;
                }
                total_right = temp; // store current total + data input [a]
            }else if(total_right == ib) // check if total already ideal
                break; // stop loop
            a++;
        }
        while(a<=total_input);
        int total_left = total_beban - total_right; // count the left side
        int selisih = total_left - total_right; // count the rest of left - right
        
        if(selisih < 0) selisih = selisih * (-1); // remove negative number
        
        // output data
        i = 0;
        do {
            cout<<data_input[i]<<" ";
            i++;
        }
        while(i<total_input);
        
        cout<<"  h#"<<coba<<": "<<selisih<<endl;
        
    }
    while(true);
    
    

    return 0;
}
