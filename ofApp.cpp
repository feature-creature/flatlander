#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(125);
    ofSetLineWidth(3);
    ofFill();

    // create Delaunay triangulation object with 15 random points
    for (int i=0; i<35; i++){
        triangulation.addPoint(ofPoint(ofRandomWidth(), ofRandomHeight())); 
    }
    // calculate the object's triangulation
    triangulation.triangulate(); 

    // iterate through the triangulation object's calculated triangles
    for (int g=0; g<triangulation.getNumTriangles(); g++){ // loop over the triangles
        //create FunkyTriangle objects
        FunkyTriangle tri;
        tri.setup(triangulation,g);
        triangles.push_back(tri);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // from delaunay addon - no documentation
    // debugging - draw triangulation object's wireframe mesh
//    ofPushStyle();
//    ofNoFill();
//    ofSetColor(0,50);
//    triangulation.triangleMesh.drawWireframe();
//    ofPopStyle();

    // iterate through the vector of FunkyTriangles
    // update color value and draw
    for (int g=0; g<triangles.size(); g++){
        triangles[g].update();
        triangles[g].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
