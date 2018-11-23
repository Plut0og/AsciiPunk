#include <string>
#include <vector>
#include <fstream>
#include <chrono>

#ifndef ANIMATION_H
#define ANIMATION_H

using namespace std;

class Animation{
public:
    Animation(string fileName, double loopTime);
    void start();
    void step();
    void pause();
    void stop();
    string getFrame();

private:
    vector<string> frames;

    chrono::high_resolution_clock::time_point startTime, currentTime;
    unsigned int currentFrame = 0;
	chrono::duration<double> deltaStart;
    int numFrames;
    double deltaFrame, lastFrameTime = 0;
    bool paused;

    vector<string> getFrames(string file);

};

#endif
