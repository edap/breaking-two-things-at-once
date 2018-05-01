#include "penner.h"

float Penner::easeInElastic (float t,float b , float c, float d) {
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    float postFix =a*pow(2,10*(t-=1));
    return -(postFix * sin((t*d-s)*(2*PI)/p )) + b;
}

float Penner::easeOutElastic(float t,float b , float c, float d) {
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
}

float Penner::easeInOutElastic(float t,float b , float c, float d) {
    if (t==0) return b;  if ((t/=d/2)==2) return b+c;
    float p=d*(.3f*1.5f);
    float a=c;
    float s=p/4;

    if (t < 1) {
        float postFix =a*pow(2,10*(t-=1));
        return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
    }
    float postFix =  a*pow(2,-10*(t-=1));
    return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
}

float Penner::linear(float t,float b , float c, float d){
    return c*t/d + b;
}

float Penner::easeInSine(float t,float b , float c, float d){
    return -c * cos(t/d * (PI/2)) + c + b;
}

float Penner::easeOutSine(float t,float b , float c, float d){
    return c * sin(t/d * (PI/2)) + b;
}

float Penner::easeInOutSine(float t,float b , float c, float d){
    return -c/2 * (cos(PI*t/d) - 1) + b;
}


float Penner::easeInCubic(float t,float b , float c, float d){
    t = t/d;
    return c*(t)*t*t + b;
}

float Penner::easeOutCubic(float t,float b , float c, float d){
    t =t/d-1;
    return c*((t)*t*t + 1) + b;
}

float Penner::easeInOutCubic(float t,float b , float c, float d){
    if ((t/=d/2) < 1) return c/2*t*t*t + b;
    t = t-2;
    return c/2*((t)*t*t + 2) + b;
}

float Penner::easeInQuint(float t,float b , float c, float d){
    t = t/d;
    return c*(t)*t*t*t*t + b;
}
float Penner::easeOutQuint(float t,float b , float c, float d){
    t =t/d-1;
    return c*((t)*t*t*t*t + 1) + b;
}
float Penner::easeInOutQuint(float t,float b , float c, float d){
    if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
    t = t-2;
    return c/2*((t)*t*t*t*t + 2) + b;
}

float Penner::easeInCirc(float t,float b , float c, float d){
    t = t/d;
    return -c * (sqrt(1 - t*t) - 1) + b;
}

float Penner::easeOutCirc(float t,float b , float c, float d){
    t = t/d-1;
    return c * sqrt(1 - t*t) + b;
}

float Penner::easeInOutCirc(float t,float b , float c, float d){
    if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
    t = t-2;
    return c/2 * (sqrt(1 - t*t) + 1) + b;
}

float Penner::easeInBack(float t,float b , float c, float d){
    float s = 1.70158f;
    float postFix = t/=d;
    return c*(postFix)*t*((s+1)*t - s) + b;
}

float Penner::easeOutBack(float t,float b , float c, float d){
    float s = 1.70158f;
    t=t/d-1;
    return c*(t*t*((s+1)*t + s) + 1) + b;
}

float Penner::easeInOutBack(float t,float b , float c, float d){
    float s = 1.70158f;
    t = t/(d/2);
    s = s*1.525f;
    if (t < 1){
        return c/2*(t*t*((s+1)*t - s)) + b;
    }
    float postFix = t-=2;
    return c/2*((postFix)*t*((s+1)*t + s) + 2) + b;
}

float Penner::easeInQuad(float t,float b , float c, float d){
    t = t/d;
    return c*(t)*t + b;
}

float Penner::easeOutQuad(float t,float b , float c, float d){
    t = t/d;
    return -c *(t)*(t-2) + b;
}

float Penner::easeInOutQuad(float t,float b , float c, float d){
    t = t/(d/2);
    if ((t) < 1) return ((c/2)*(t*t)) + b;
    t = t-1;
    return -c/2 * ((t*(t-2)) - 1) + b;
}

float Penner::easeInQuart(float t,float b , float c, float d){
    t = t/=d;
    return c*(t)*t*t*t + b;
}

float Penner::easeOutQuart(float t,float b , float c, float d){
    t = t/d-1;
    return -c * ((t)*t*t*t - 1) + b;
}

float Penner::easeInOutQuart(float t,float b , float c, float d){
    if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
    t = t-2;
    return -c/2 * (t*t*t*t - 2) + b;
}

float Penner::easeInExpo(float t,float b , float c, float d){
    return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}

float Penner::easeOutExpo(float t,float b , float c, float d){
    return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
}

float Penner::easeInOutExpo(float t,float b , float c, float d){
    if (t==0) return b;
    if (t==d) return b+c;
    if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
    return c/2 * (-pow(2, -10 * --t) + 2) + b;
}

float Penner::easeInBounce(float t,float b , float c, float d){
    return c - easeOutBounce (d-t, 0, c, d) + b;
}

float Penner::easeOutBounce(float t,float b , float c, float d){
    if ((t/=d) < (1/2.75f)) {
        return c*(7.5625f*t*t) + b;
    } else if (t < (2/2.75f)) {
        float postFix = t-=(1.5f/2.75f);
        return c*(7.5625f*(postFix)*t + .75f) + b;
    } else if (t < (2.5/2.75)) {
        float postFix = t-=(2.25f/2.75f);
        return c*(7.5625f*(postFix)*t + .9375f) + b;
    } else {
        float postFix = t-=(2.625f/2.75f);
        return c*(7.5625f*(postFix)*t + .984375f) + b;
    }
}

float Penner::easeInOutBounce(float t,float b , float c, float d){
    if (t < d/2) return easeInBounce (t*2, 0, c, d) * .5f + b;
    else return easeOutBounce (t*2-d, 0, c, d) * .5f + c*.5f + b;
}
