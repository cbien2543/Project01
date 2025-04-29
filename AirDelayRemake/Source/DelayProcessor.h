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
           // grab the old sample out of the buffer
           float delayedSample = buffer[readIndex];
    
           // write the new composite back into the buffer
           buffer[writeIndex] = x + delayedSample * feedback;
    
           // advance our indices
           readIndex  = (readIndex  + 1) % delaySamples;
           writeIndex = (writeIndex + 1) % delaySamples;
    
           // return **only** the wet part
           return delayedSample * feedback;
       }
    

    void setDelaySamples(int newDelaySamples) {
        if (newDelaySamples != delaySamples)
        {
            // Resize if needed
            if (newDelaySamples > delaySamples)
            {
                // Fill new samples with 0
                buffer.resize(newDelaySamples, 0.0f);
            }
            else
            {
                
                readIndex = readIndex % newDelaySamples;
                writeIndex = writeIndex % newDelaySamples;
                buffer.resize(newDelaySamples);
            }

            delaySamples = newDelaySamples;
        }
    }
        
        
        float getFeedback() const { return feedback; }
        int getDelaySamples() const { return delaySamples; }

private:
    std::vector<float> buffer;
    int delaySamples;
    float feedback;
    int readIndex = 0;
    int writeIndex = 0;
};
