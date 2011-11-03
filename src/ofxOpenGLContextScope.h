#pragma once

#include "ofMain.h"

class ofxOpenGLContextScope
{
public:
	
	inline ofxOpenGLContextScope()
	{
		CGLCreateContext(pixStuff, ctx, &newCtx);
		CGLLockContext(newCtx);
		CGLSetCurrentContext(newCtx);
		CGLEnable(newCtx, kCGLCEMPEngine);
	}
	
	inline ~ofxOpenGLContextScope()
	{
		CGLDisable(newCtx, kCGLCEMPEngine);
		CGLUnlockContext(newCtx);
		CGLDestroyContext(newCtx);
	}
	
	static void setup()
	{
		ctx = CGLGetCurrentContext();
		pixStuff = CGLGetPixelFormat(ctx);
	}
	
private:
	
	CGLContextObj newCtx;
	static CGLContextObj ctx;
	static CGLPixelFormatObj pixStuff;
	
	ofxOpenGLContextScope(const ofxOpenGLContextScope&);
	ofxOpenGLContextScope& operator=(const ofxOpenGLContextScope&);
	
};
