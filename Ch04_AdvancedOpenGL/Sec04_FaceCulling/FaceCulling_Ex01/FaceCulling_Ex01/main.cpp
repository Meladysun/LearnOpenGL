//
//  main.cpp
//  FaceCulling_Ex01
//
//  Created by shenyuanluo on 2017/9/4.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <iostream>
#include "Window.hpp"


int main(int argc, const char * argv[])
{
    Window window(800, 600, "Face Culling Ex01");
    
    window.setCWD(argv[0]);
    
    window.render();
    
    return 0;
}