//
//  LeapListener.h
//  LeapPoint
//
//  Created by Jia Chen on 1/19/14.
//  Copyright (c) 2014 Jia Chen. All rights reserved.
//

#ifndef __LeapPoint__LeapListener__
#define __LeapPoint__LeapListener__



#include "leap.h"
using namespace std;
using namespace Leap;

class LeapListener: public Listener
{
public:
    LeapListener()
    {
        m_pController=NULL;
        m_bControllerConnected=false;
    }
    LEAP_EXPORT  void onInit(const Controller&);
    
    LEAP_EXPORT  void onConnect(const Controller&);
    
    
    LEAP_EXPORT  void onDisconnect(const Controller&);
    
    LEAP_EXPORT  void onExit(const Controller&);
    
    LEAP_EXPORT  void onFrame(const Controller&);
    
    bool isControllerConnected(){return m_bControllerConnected;};
private:
    const Controller* m_pController;
    bool m_bControllerConnected;
};

#endif /* defined(__LeapPoint__LeapListener__) */
