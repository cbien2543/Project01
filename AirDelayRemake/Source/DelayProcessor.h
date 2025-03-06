/*
  ==============================================================================

    DelayProcessor.h
    Created: 6 Mar 2025 12:44:40pm
    Author:  Chris Bienvenu

  ==============================================================================
*/

#pragma once
#include <vector>

class DelayEffectProcessor{
    
    public:
    DelayEffectProcessor(int delaySamples = 48000, float feedback = 0.5f)
        : delaySamples(delaySamples), feedback(feedback)
    {
        buffer.resize(delaySamples, 0.0f);
    }

    void setFeedback(float newFeedback)
    {
        feedback = newFeedback;
    }

    float processSample(float x)
    {
        float delayedSample = buffer[readIndex];
        float output = x + delayedSample * feedback;
        
        buffer[writeIndex] = x + delayedSample * feedback;
        
        readIndex = (readIndex + 1) % delaySamples;
        writeIndex = (writeIndex + 1) % delaySamples;
        
        return output;
    }

private:
    std::vector<float> buffer;
    int delaySamples;
    float feedback;
    int readIndex = 0;
    int writeIndex = 0;
};
