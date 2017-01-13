//
//  main.cpp
//  Projekt do ZOO ZS2013
//
//  Created by Jakub Kubista on 27/12/13.
//  Copyright (c) 2013 Jakub Kubista. All rights reserved.
//

#include <iostream>
#include "HraciDeska.h"
#include "CivEngine.h"


int main(int argc, const char * argv[])
{
    modelHra::CivEngine* hra;
    hra = new modelHra::CivEngine();
    hra->hrej();

    delete hra;
    return 0;
}
