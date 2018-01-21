#include "FunkyTriangle.h"

FunkyTriangle::FunkyTriangle(){

}

void FunkyTriangle::setup(ofxDelaunay _d, int _i){
    // initialize FunkyTriangle's vertices
    int pA = _d.triangleMesh.getIndex(_i*3);
    int pB = _d.triangleMesh.getIndex(_i*3+1);
    int pC = _d.triangleMesh.getIndex(_i*3+2);


    ofPoint pointA = _d.triangleMesh.getVertex(pA);
    ofPoint pointB = _d.triangleMesh.getVertex(pB);
    ofPoint pointC = _d.triangleMesh.getVertex(pC);

    vertices.push_back(pointA);
    vertices.push_back(pointB);
    vertices.push_back(pointC);

    // initialize FunkyTriangle's color
    greyScale = ofRandom(0,256);
    greyStep = 1;
}

void FunkyTriangle::update(){
    // iterate up and down along grayscale color
    
    // linear transition
    //if(greyScale >= 255 || greyScale <= 0){
        //greyStep = -greyStep;
    //}
    //greyScale += greyStep;
    
    // sin transition
    sinScale = ofMap(sin((ofGetElapsedTimef()+greyScale)),-1,1,0,255);
}

void FunkyTriangle::draw(){
    ofPushStyle();
    ofPushMatrix();
    ofSetColor(sinScale,75);
    ofTranslate(ofGetWidth()/2,0);
    ofRotateZ(sinScale*0.25);
    ofTranslate(0,sin(sinScale*0.02),0);
    ofDrawTriangle(vertices[0],vertices[1],vertices[2]);
    if(sinScale > 250){
        ofSetColor(255,150);
    }else{
        ofSetColor(255,50);
    }
    ofDrawCircle(vertices[0][0],vertices[0][1],10);
    ofDrawCircle(vertices[1][0],vertices[1][1],10);
    ofDrawCircle(vertices[2][0],vertices[2][1],10);
    ofPopMatrix();
    ofPopStyle();
}
