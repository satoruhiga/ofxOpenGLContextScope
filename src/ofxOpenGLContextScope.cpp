#include "ofxOpenGLContextScope.h"

#ifdef TARGET_OSX

#include <OpenGL/OpenGL.h>

struct ofxOpenGLContextScopeImpl
{
	ofxOpenGLContextScopeImpl()
	{
		CGLCreateContext(pixStuff, ctx, &newCtx);
		CGLLockContext(newCtx);
		CGLSetCurrentContext(newCtx);
		CGLEnable(newCtx, kCGLCEMPEngine);
	}
	
	~ofxOpenGLContextScopeImpl()
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

	CGLContextObj newCtx;
	static CGLContextObj ctx;
	static CGLPixelFormatObj pixStuff;
};

CGLContextObj ofxOpenGLContextScopeImpl::ctx = NULL;
CGLPixelFormatObj ofxOpenGLContextScopeImpl::pixStuff = NULL;

#else
#error not implemented
#endif

#pragma mark -

ofxOpenGLContextScope::ofxOpenGLContextScope() : impl(new ofxOpenGLContextScopeImpl) {}

ofxOpenGLContextScope::~ofxOpenGLContextScope()
{
	delete impl;
	impl = NULL;
}

void ofxOpenGLContextScope::setup()
{
	ofxOpenGLContextScopeImpl::setup();
}
