#pragma once

#include "ofMain.h"
class Penner{
public:
    //This is using Penner elastic equations
    //t == currentIteration
    //b == startValue
    //c == changeInValue
    //d == totalIterations
    static float easeInElastic (float t,float b , float c, float d);
    static float easeOutElastic (float t,float b , float c, float d);
    static float easeInOutElastic (float t,float b , float c, float d);

    static float linear(float t,float b , float c, float d);

    static float easeInSine(float t,float b , float c, float d);
    static float easeOutSine(float t,float b , float c, float d);
    static float easeInOutSine(float t,float b , float c, float d);

    static float easeInCubic(float t,float b , float c, float d);
    static float easeOutCubic(float t,float b , float c, float d);
    static float easeInOutCubic(float t,float b , float c, float d);

    static float easeInQuint(float t,float b , float c, float d);
    static float easeOutQuint(float t,float b , float c, float d);
    static float easeInOutQuint(float t,float b , float c, float d);

    static float easeInCirc(float t,float b , float c, float d);
    static float easeOutCirc(float t,float b , float c, float d);
    static float easeInOutCirc(float t,float b , float c, float d);

    static float easeInBack(float t,float b , float c, float d);
    static float easeOutBack(float t,float b , float c, float d);
    static float easeInOutBack(float t,float b , float c, float d);

    static float easeInQuad(float t,float b , float c, float d);
    static float easeOutQuad(float t,float b , float c, float d);
    static float easeInOutQuad(float t,float b , float c, float d);

    static float easeInQuart(float t,float b , float c, float d);
    static float easeOutQuart(float t,float b , float c, float d);
    static float easeInOutQuart(float t,float b , float c, float d);

    static float easeInExpo(float t,float b , float c, float d);
    static float easeOutExpo(float t,float b , float c, float d);
    static float easeInOutExpo(float t,float b , float c, float d);

    static float easeInBounce(float t,float b , float c, float d);
    static float easeOutBounce(float t,float b , float c, float d);
    static float easeInOutBounce(float t,float b , float c, float d);
};

