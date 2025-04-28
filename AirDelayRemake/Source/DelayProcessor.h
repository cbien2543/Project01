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

    void prepare(double sampleRate) {
            // Store sample rate for time-based calculations if needed
        currentSampleRate = sampleRate;
            // Reset buffer to avoid artifacts
        std::fill(buffer.begin(), buffer.end(), 0.0f);
        readIndex = 0;
        writeIndex = 0;
        }
    
    void setFeedback(float newFeedback)
    {
        feedback = newFeedback;
    }

    float processSample(float x)
    {
        // Smooth delay time changes
        if (currentDelaySamples != targetDelaySamples) {
            currentDelaySamples = static_cast<int>(currentDelaySamples * smoothingAlpha +
                                                 targetDelaySamples * (1.0f - smoothingAlpha));
            if (abs(currentDelaySamples - targetDelaySamples) < 1) {
                currentDelaySamples = targetDelaySamples;
            }
            readIndex = (writeIndex - currentDelaySamples + buffer.size()) % buffer.size();
        }
        
        float delayedSample = buffer[readIndex];
        float output = x + delayedSample * feedback;
        
        buffer[writeIndex] = x + delayedSample * feedback;
        
        readIndex = (readIndex + 1) % buffer.size();
        writeIndex = (writeIndex + 1) % buffer.size();
        
        return output;
    }

    void setDelaySamples(int newDelaySamples) {
        targetDelaySamples = newDelaySamples;
        // Still resize immediately but we'll smooth the transition
        if (newDelaySamples > buffer.size()) {
            buffer.resize(newDelaySamples, 0.0f);
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
    double currentSampleRate = 44100.0; // Default
};
