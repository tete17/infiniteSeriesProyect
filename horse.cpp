//
//  horse.cpp
//  chessPieces
//
//  Created by Miguel Sacristán on 13/1/17.
//  
//

#include "horse.h"

using namespace std;

horse::horse(){
    position[0]=0;
    position[1]=0;
}

horse::horse(int x, int y){
    
    if ( x>8 || x<0 || y>8 || y<0 ) {
        cout<<"Values outside the range, initializing to (0,0)"<<endl;
        position[0]=0;
        position[1]=0;
    } else{
        position[0]=x;
        position[1]=y;
    }
}

horse::~horse(){
    
}

void horse::move(int dx, int dy){
    
    if (moveIsLegal(dx, dy)) {
        position[0]+=dx;
        position[1]+=dy;
    } else{
        cout<<"Illegal move!!"<<endl;
    }
    
}

bool horse::moveIsLegal(int dx, int dy){

    return (position[0] + dx < 8 && position[0] + dx > -1) &&
           (position[1]+dy < 8 && position[1]+dy > -1);
    
}

void horse::randomMove(){
    
    int dx=9;
    int dy=9;
    
    while (!moveIsLegal(dx, dy)) {
        
        int firstDirection              = rand() % 4;
        int secondDirection             = rand() % 2;
        
        //Decision on what movement
        //[WIP] to put in another function
        
        if (firstDirection == 0) {
            dx=2;
            if (secondDirection == 0) {
                                            //     |
                dy=1;                       //  ---
                                            //
            } else {
                                            //
                dy=-1;                      //  ---
                                            //     |
            }
        } else if (firstDirection == 1) {
            dy=2;
            if (secondDirection == 0) {
                                            //       --
                dx=1;                       //      |
                                            //      |
            } else {
                                            //    --
                dx=-1;                      //      |
                                            //      |
            }
            
        } else if (firstDirection == 2){
            dx=-2;
            if (secondDirection == 0) {
                                            // |
                dy=1;                       //  ---
                                            //
            } else {
                                            //
                dy=-1;                      //  ---
                                            // |
            }
        } else if (firstDirection == 3){
            dy=-2;
            if (secondDirection == 0) {
                                            //      |
                dx=1;                       //      |
                                            //       --
            } else {
                                            //      |
                dx=-1;                      //      |
                                            //    --
            }
        }
    }
    
        move(dx, dy);
    
}

int horse::getPositionX(){
    return position[0];
}

int horse::getPositionY(){
    return position[1];
}

void horse::printPosition(){
    
    system("clear");
    
    for (int i=7; i>=0; i--) {
        
        for (int j=0; j<8; j++) {
            cout<<" ::::::::::::::";
        }
        cout<<endl;
        for (int n=0; n<6; n++) {
            
            for (int j=0; j<9; j++) {
                if (position[0]==j && position[1]==i) {
                    if (n==0) {
                        cout<<":    |\\.       ";
                    }else if (n==1){
                        cout<<":   /*  '.     ";
                    }else if (n==2){
                        cout<<":  /_.'-  \\    ";
                    }else if (n==3){
                        cout<<":     /   |    ";
                    }else if (n==4){
                        cout<<":    /____|    ";
                    }else if (n==5){
                        cout<<":   `.____.´   ";
                    }
                }else{
                    cout<<":              ";
                }
            }
            cout<<endl;
            
        }
        
    }
    for (int j=0; j<8; j++) {
        cout<<" ::::::::::::::";
    }
    cout<<endl;
    sleep(1);
    
}

int horse::numberOfMovesToComeBack(){
    
    int n=0;
    int x = getPositionX();
    int y = getPositionY();
    
    randomMove();
    n++;
    while ((position[0] != x) || position[1] != y) {
        randomMove();
        n++;
    }
    return n;
}






