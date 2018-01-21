#pragma once

#include "ofMain.h"
#include "ofxDelaunay.h"

class FunkyTriangle{
    public:
        FunkyTriangle();


        // class variables
        vector <ofPoint> vertices;
        int greyScale;
        int greyStep;
        int sinScale;


        // class functions
        void setup(ofxDelaunay _d, int _i);
        void draw();
        void update();
};
