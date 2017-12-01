#include "ofApp.h"


void ofApp::setup()
{
    compiler.compile("code.txt",computer);
    startThread();
}
//--------------------------------------------------------------
void ofApp::threadedFunction()
{
    computer.start();
    //computer.M.print();
    stopThread();
}
//--------------------------------------------------------------
void ofApp::update()
{

}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(0,0,0);
    ofDrawBitmapString("Timing Register: " + ofToString(computer.TR.read()),20,100);
    ofDrawBitmapString("Instruction Register: " + ofToString(computer.IR.read()),20,110);

    ofDrawBitmapString("MAR: " + ofToString(computer.MAR.read()),20,20);
    ofDrawBitmapString("PC: " + ofToString(computer.PC.read()),20,30);
    ofDrawBitmapString("Return PC: " + ofToString(computer.SubPC.read()),20,40);

    ofDrawBitmapString("Active Control Signal: " + ofToString(computer.controlsignal),20,120);

    ofDrawBitmapString("MBROp: " + ofToString(computer.MBR.readOpCode()),150,20);
    ofDrawBitmapString("MBRAd: " + ofToString(computer.MBR.read()),150,30);

    ofDrawBitmapString("A: " + ofToString(computer.A.read()),300,20);
    ofDrawBitmapString("B: " + ofToString(computer.B.read()),300,30);
    ofDrawBitmapString("TEMP: " + ofToString(computer.Temp.read()),300,40);
    ofDrawBitmapString("X: " + ofToString(computer.X.read()),300,50);
    ofDrawBitmapString("Y: " + ofToString(computer.Y.read()),300,60);
    ofDrawBitmapString("Counter: " + ofToString(computer.C.read()),300,70);

    ofDrawBitmapString("Clock Cycles: " + ofToString(computer.clock),300,100);
    ofDrawBitmapString("Lines Executed: " + ofToString(computer.lines),300,110);

    ofDrawBitmapString("FLAGS: N Z V C",400,20);
    ofDrawBitmapString(ofToString(computer.FLAG.getn()) + " " + ofToString(computer.FLAG.getz()) + " "+ ofToString(computer.FLAG.getv()) + " "+ ofToString(computer.FLAG.getc()) + " ",456,30);

    ///Memory Table
    ofSetColor(128,0,252);
    ofDrawBitmapString("Memory Table",20,150);
    for(int i=0;i<16;i++)
    {
        ofDrawBitmapString(ofToString(16*i),5,160+i*10);
        for(int k=0;k<16;k++)
        {
            ofDrawBitmapString(ofToString(computer.M.read(i*16+k,0)) + ":" + ofToString(computer.M.read(i*16+k,1)),35+k*60,160+i*10);
        }
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == ' ')
    {
        computer.step();
    }
    if (key == 13)
    {
        computer.Istep();
    }
}
