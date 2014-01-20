//
//  main.cpp
//  LeapPoint
//
//  Created by Jia Chen on 1/19/14.
//  Copyright (c) 2014 Jia Chen. All rights reserved.
//

#include "LeapListener.h"
using namespace std;
using namespace Leap;



int main(int argc, const char * argv[])
{

    Controller controller;
    LeapListener* listener=new LeapListener();
    controller.addListener(*listener);
    if(!listener->isControllerConnected())
    {
        cout<<"D'oh!!! Controller is not yet connected. Please check....."<<endl;
    }
    cout<<"press ctrl+c to end"<<endl;
    cin.get();
    
    controller.removeListener(*listener);

    
    cout<<"service ended"<<endl;
    delete listener;


    return 0;
}

