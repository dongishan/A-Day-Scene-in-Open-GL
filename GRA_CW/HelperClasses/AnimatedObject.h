//
//  AnimatedObject.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 28/04/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__AnimatedObject__
#define __GRA_CW__AnimatedObject__

#include <stdio.h>
#include "DisplayableObject.h"

class AnimatedObject : public DisplayableObject {       // inherits DisplayableObject
public:
    virtual void update(float dT) = 0;                  // update function (MUST OVERLOAD)
};

#endif /* defined(__GRA_CW__AnimatedObject__) */
