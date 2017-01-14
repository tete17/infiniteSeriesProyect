//
//  horse.h
//  chessPieces
//
//  Created by Miguel Sacristán on 13/1/17.
//  
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


using namespace std;

#ifndef HORSE_H
#define HORSE_H

class horse {

public:
    
    //Default Constructor
    horse();
    
    //Overload Constructor
    horse(int, int);
    
    //Destructor
    ~horse();
    
    //Get Functions
    int getPositionX();
    int getPositionY();
    
    //Movement
    void move(int, int);
    
    //Random Movement
    void randomMove();
    
    //Number of moves until come-back
    int numberOfMovesToComeBack();
    
    //Print position
    void printPosition();
    
    
    
private:
    
    //Member Variables
    int position[2];
    
    //Check if movement is legal
    bool moveIsLegal(int, int);
    
    
};


#endif /* horse_h */


