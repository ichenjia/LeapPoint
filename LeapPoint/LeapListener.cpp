//
//  LeapListener.cpp
//  LeapPoint
//
//  Created by Jia Chen on 1/19/14.
//  Copyright (c) 2014 Jia Chen. All rights reserved.
//

#include "LeapListener.h"
#include <iostream>
#include "Utilities.h"

LEAP_EXPORT  void LeapListener::onInit(const Controller&)
{
    cout<<"listener added"<<endl;
}

LEAP_EXPORT  void LeapListener::onConnect(const Controller& controller)
{
    cout<<"Hooray!! Controller is connected"<<endl;
    controller.setPolicyFlags(Leap::Controller::POLICY_BACKGROUND_FRAMES); // must turn on background frames
    controller.enableGesture(Gesture::TYPE_CIRCLE); // only these two gestures are enabled to improve performance
    controller.enableGesture(Gesture::TYPE_SWIPE);
    Config config=controller.config();
    config.setFloat("Gesture.Swipe.MinLength", 300);
    config.setFloat("Gesture.Circle.MinArc", 2*PI);
    if(config.save())
    {
        cout<<"Gestures are customized."<<endl<<"Swipe must be over 30 cm (towards left-front/right-front) and Circle must be at least 5mm in radius and run a complete circle"<<endl;
    }
    m_bControllerConnected=true;
    m_pController=&controller;
}




LEAP_EXPORT  void LeapListener::onDisconnect(const Controller&)
{
    cout<<"D'oh!!! Controller is disconnected"<<endl;
        m_bControllerConnected=false;
    m_pController=NULL;
}

LEAP_EXPORT  void LeapListener::onExit(const Controller&)
{
    cout<<"T_T leaving.... Think of me....."<<endl;
}


LEAP_EXPORT  void LeapListener::onFrame(const Controller& c)
{
    GestureList g=c.frame().gestures();
    if(g.count()!=1) // it can only process one gesture at one time
    {
        return;
    }
    Gesture gesture=g[0];
    if(gesture.state()==Leap::Gesture::STATE_STOP)
    {
        switch(gesture.type())
        {
            case Leap::Gesture::TYPE_SWIPE:
            {
                SwipeGesture sg=(SwipeGesture) gesture;
                Vector v=sg.direction();
                if(v.roll()>0)
                {
                    //swipe to right-->forwards
                    Utilities::slideMovement(Utilities::forwards);
                }
                else{
                    //swipe to left-->backgwards
                    Utilities::slideMovement(Utilities::backwards);
                }
                break;
            }
            case Leap::Gesture::TYPE_CIRCLE:
            {
                CircleGesture cg=(CircleGesture)gesture;
                if (cg.pointable().direction().angleTo(cg.normal()) <= PI/2) {
                    // clockwise--> go to back
                    Utilities::slideMovement(Utilities::start);
                }
                else
                {
                    //finger goes down-clockwise -->go back to beginning
                    Utilities::slideMovement(Utilities::end);
                }
            }
            default:
                break;
        }
    }
}



