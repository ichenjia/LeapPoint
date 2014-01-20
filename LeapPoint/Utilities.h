//
//  Utilities.h
//  LeapPoint
//
//  Created by Jia Chen on 1/19/14.
//  Copyright (c) 2014 Jia Chen. All rights reserved.
//

#ifndef __LeapPoint__Utilities__
#define __LeapPoint__Utilities__

#include <iostream>
#include <CoreServices/CoreServices.h>
#include <ApplicationServices/ApplicationServices.h>

class Utilities {
public:
    enum slideEvents
    {
        forwards=0,
        backwards,
        start,
        end
    };
    static void slideMovement(Utilities::slideEvents e);
private:
    static void PostKey(CGKeyCode key);

};
#endif /* defined(__LeapPoint__Utilities__) */
