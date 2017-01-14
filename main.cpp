//
//  main.cpp
//  chessPieces
//
//  Created by Miguel Sacristán on 13/1/17.
//
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include "horse.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //Set seed for rand and precision output (Not really necesary but nice to have)
    cout<<setprecision(15);
    srand(time(0));
    
    
    //Variables
    int long horses;
    int x;
    int y;
    int long long sum=0;
    
    //Ask the user the parameters
    
    cout<<"---Calculator of Average Number of steps to come back for a horse---"<<endl<<endl;
    cout<<"How many times do you want to run the horse = ";
    cin>>horses;
    cout<<endl;
    
    cout<<"Starting 'x' position (Example A=1 & H=8) = ";
    cin>>x;
    cout<<endl;
    
    cout<<"Starting 'y' position (1-8) = ";
    cin>>y;
    cout<<endl<<endl;
    
    x--;
    y--;
    
    
    //Object (We will reuse it all the time)
    
    horse mylittlepony(x,y);
    
    for (int i=0; i<horses; i++) {
        sum += mylittlepony.numberOfMovesToComeBack();
    }
    
    
    
    //Do the average and extracted
    double average = double(sum)/double(horses);
    
    cout<<"Average Number of moves to come back = "<<average<<endl;
    
    
    return 0;
}
