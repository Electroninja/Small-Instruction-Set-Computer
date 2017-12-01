#pragma once

#include "ofMain.h"
#include <Compiler.h>

class ofApp : public ofBaseApp, public ofThread{
	public:
		void setup();
		void draw();
        void update();
        void keyPressed(int key);

		void threadedFunction();

        Compiler compiler;
        Computer computer;

};
