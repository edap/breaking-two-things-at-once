#include "Pen.h"

Pen::Pen(){};

void Pen::moveTo(float x, float y){
    pos.x = x;
    pos.y = y;
};

void Pen::drawCircle(float radius){
    ofDrawCircle(pos, radius);
};

void Pen::drawLine(glm::vec2 startPoint, glm::vec2 endPoint){
    ofDrawLine(startPoint.x, endPoint.y, endPoint.x, endPoint.y);
};

void Pen::addToHistory(glm::vec2 point){
    ofPoint p;
    p.x = point.x;
    p.y = point.y;
    history.addVertex(p);

    if(history.size() > historyLimit){
        history.getVertices()
            .erase(
                   history.getVertices().begin()
            );
    }

}

void Pen::drawHistory(){
    history.draw();
};
