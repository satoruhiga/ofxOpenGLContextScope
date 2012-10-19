#pragma once

#include "ofMain.h"

struct ofxOpenGLContextScopeImpl;

class ofxOpenGLContextScope
{
public:

	static void setup();
	
	ofxOpenGLContextScope();
	~ofxOpenGLContextScope();
	
private:
	
	ofxOpenGLContextScopeImpl *impl;
	ofxOpenGLContextScope(const ofxOpenGLContextScope&) {}
	ofxOpenGLContextScope& operator=(const ofxOpenGLContextScope&) {}
	
};
