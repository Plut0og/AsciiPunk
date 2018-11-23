#include "Animation.h"
Animation::Animation(string file, double loopTime){
    currentFrame = 0;
    frames = getFrames(file);
    numFrames = frames.size();
    deltaFrame = loopTime/numFrames;
}

void Animation::start(){
    startTime = std::chrono::high_resolution_clock::now();
    paused = false;
}

void Animation::step(){
    if (!paused){
        currentTime = chrono::high_resolution_clock::now();
        deltaStart = chrono::duration_cast< std::chrono::duration<double> >(currentTime - startTime);
        if(deltaStart.count() > deltaFrame+lastFrameTime){
            currentFrame = (currentFrame+1)%numFrames;
            lastFrameTime = deltaStart.count();
        }
    }
}

void Animation::pause(){
    paused = true;
}

void Animation::stop(){

}

string Animation::getFrame(){
    return frames.at(currentFrame);
}

vector<string> Animation::getFrames(string file){
    ifstream assetFile;
    assetFile.open(file);

    int frameHeight, frames;
    assetFile >> frameHeight >> frames;

    vector<string> anim;
    string line, frame;
    getline(assetFile, line);
    for (int i = 0; i < frames; i++){
        frame = "";
        for (int j = 0; j < frameHeight; j++){
            getline(assetFile,line);
            frame += line + "\n";
        }
        anim.push_back(frame);
    }
    return anim;
}
