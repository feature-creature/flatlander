#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(125);
    ofSetLineWidth(3);

    // create Delaunay triangulation object with 15 random points
    for (int i=0; i<15; i++){
        triangulation.addPoint(ofPoint(ofRandomWidth(), ofRandomHeight())); 
    }
    // calculate the object's triangulation
    triangulation.triangulate(); 
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetColor(0);
    // from delaunay addon - no documentation
    // debugging - draw triangulation object's wireframe mesh
    triangulation.triangleMesh.drawWireframe(); 

    ofFill();

    // create a custom FunkyTriangle class.
    // You should use the data of the points to create a FunkyTriangle object
    //
    // Create a setup() function in the class to pass it the initial parameters. 
    // You'll also need a draw() and an update().
    // Start by making 1 FunkyTriangle Object that has some behavior
    // (it goes from black to white and then back to white.)
    // Then create a vector of FunkyTriangles.
    // 
    // For the more daring, create a FunkyTriangleSystem so that you hide the vector and loops
    // See the code provided in class.
    // It's very similar to that, only you don't draw balls, you draw triangles.


    // iterate through the triangulation object's calculated triangles
    for (int g=0; g<triangulation.getNumTriangles(); g++){ // loop over the triangles
        // locally store this triangle's 3 vertices as a vector of points
        vector <ofPoint> pts = getTriangle(triangulation, g);             
        // set fill to random color
        ofSetColor(ofColor::fromHsb(ofRandom(255),255,150));
        // draw the triangle
        ofDrawTriangle(pts[0], pts[1], pts[2]);             
    }
}

//--------------------------------------------------------------
// custom function that takes an index value and returns a vector of points for current triangle's coordinates
// perhaps don't hardcode triangulation into the function.
// make more abstract
vector <ofPoint> ofApp::getTriangle(delaunay d, int i){
    int pA = d.triangleMesh.getIndex(i*3);
    int pB = d.triangleMesh.getIndex(i*3+1);
    int pC = d.triangleMesh.getIndex(i*3+2);

    ofPoint pointA = d.triangleMesh.getVertex(pA);
    ofPoint pointB = d.triangleMesh.getVertex(pB);
    ofPoint pointC = d.triangleMesh.getVertex(pC);

    vector <ofPoint> points;
    points.push_back(pointA);
    points.push_back(pointB);
    points.push_back(pointC);
    return points;
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
