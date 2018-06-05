#pragma once

#include "ofMain.h"

class Pen {
public:
    Pen();
    glm::vec2 pos;
    ofPolyline history;
    int historyLimit = 300;
    float speed = 0.5;

    void moveTo(float x, float y);
    void drawCircle(float radius);
    void drawLine(glm::vec2 s, glm::vec2 e);
    void drawHistory();
    void addToHistory(glm::vec2 point);
    
};
