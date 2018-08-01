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
        int i=0;
        int data_input[MAX];
        
        string my_string;
        cout<<"input  :"<<endl;
        
        // populate the input
        getline(cin, my_string);
        stringstream ss(my_string);

        int temp;
        
        while (ss >> temp) {
            data_input[i] = (int) temp;
            i++;
        }
        
        int hasil_ujian = data_input[0];
        int jumlah_soal = data_input[1];
        int nilai_jawaban_benar = data_input[2];
        int pengurang_jawaban_salah = data_input[3];
        pengurang_jawaban_salah = -data_input[3];
        i=0;

        // total soal 10


        int benar = 0;
        int salah = 0;
        int tidak_dijawab=0;

        string mungkin = "TIDAK";

        // adjust value
        bool seek = true;
        do {
            // loop benar
            int salah = 0;
            if(!seek) 
                break;
            do {
                // loop salah
                int tidak_dijawab=0;
                if(!seek) 
                    break;

                    // formula 
                    int actual_value = (benar*nilai_jawaban_benar)+(salah*pengurang_jawaban_salah);
                    
                    if(hasil_ujian == actual_value){
                        cout<<"SAMA"<<endl;
                        seek = false;
                        break;
                    }

                salah++;
            
            } while(salah <= jumlah_soal);
            
            benar++;
        } while(benar <= jumlah_soal);

        // output data
        i = 0;
        do {
            cout<<data_input[i]<<" ";
            i++;
        }
        while(i<4);
        coba++;
        if(!seek) mungkin = "YA";
        cout<<"  h#"<<coba<<": "<<mungkin<<endl;
        
    }
    while(true);

    return 0;
}