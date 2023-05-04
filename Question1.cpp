#include <iostream>
using namespace std;

int strlen(const char ch[]){
    int i = 0;
    while(ch[i] != '\0')
        i++;
    return i; 
}

void zip(int bits[], char zipped[]){
    int i = 0, index = 0, count = 1;
    while(bits[i] == 0 && i < 7) i++;
    zipped[index++] = i + '0';

    for(int j = i; j < 7; j++){
        if(bits[j] == bits[j+1])
            count++;
        else{
            zipped[index++] = count + '0';
            count = 1;
        }
    }
    zipped[index] = '\0';
}

void unzip(char zipped[], int bits[]) { // state means 0 or 1
    int index = 0, state = 1;
    int digit = zipped[0] - '0'; // undo sequence of zeros
    while(digit-- > 0) bits[index++] = 0;
     
    for (int i = 1; i < strlen(zipped); i++) { 
        for(int j = 0; j < zipped[i] - '0'; j++) 
            bits[index++] = state % 2;
        state++; // every new number means the sequence broke
    }
}

int main(){
    int bits[] = {0,1,0,0,1,1,1};
    int bits2[] = {1,1,0,1,1,1,1};
    int partb[7] = {0};
    char zipped[7] = {0};
    zip(bits, zipped);
    cout << zipped << endl;

    unzip(zipped, partb);
    for(int i = 0; i < 7; i++)
        cout << partb[i];

    return 0;
}
