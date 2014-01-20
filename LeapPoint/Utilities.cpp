//
//  Utilities.cpp
//  LeapPoint
//
//  Created by Jia Chen on 1/19/14.
//  Copyright (c) 2014 Jia Chen. All rights reserved.
//

#include "Utilities.h"



void Utilities::PostKey(CGKeyCode key)
{
    CGEventSourceRef source = CGEventSourceCreate(kCGEventSourceStateCombinedSessionState);
    
    CGEventRef keyDown = CGEventCreateKeyboardEvent(source, key, TRUE);
    CGEventRef keyUp = CGEventCreateKeyboardEvent(source, key, FALSE);
    
    CGEventPost(kCGAnnotatedSessionEventTap, keyDown);
    CGEventPost(kCGAnnotatedSessionEventTap, keyUp);
    
    CFRelease(keyUp);
    CFRelease(keyDown);
    CFRelease(source);
}

void Utilities::slideMovement(Utilities::slideEvents e)
{
    CGKeyCode key;
    switch (e) {
        case Utilities::forwards:
            key=0x7C;
            break;
        case Utilities::backwards:
            key=0x7B;
            break;
        case Utilities::start:
            key=0x73;
            break;
        case Utilities::end:
            key=0x77;
            break;
            
    }
    PostKey(key);
}
