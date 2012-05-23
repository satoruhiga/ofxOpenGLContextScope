#include "testApp.h"

#include "ofxOpenGLContextScope.h"

class MyThread : public ofThread
{
public:
	
	ofImage image;
	
	void threadedFunction()
	{
		ofxOpenGLContextScope scope; // clash if commented out
		
		image.loadImage("ofw-logo.png");
		
		printf("loaded\n");
	}
	
};

MyThread *t;

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(30);
	
	ofxOpenGLContextScope::setup();

	t = new MyThread();
	t->startThread();
}

//--------------------------------------------------------------
void testApp::update()
{

}

//--------------------------------------------------------------
void testApp::draw()
{
	t->image.draw(0, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}