/*
  ==============================================================================

    KnobLookAndFeel.h
    Created: 28 Apr 2025 7:08:41pm
    Author:  Chris Bienvenu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


class KnobLookAndFeel : public juce::LookAndFeel_V4
{
public:
    KnobLookAndFeel();

    
    void drawRotarySlider(juce::Graphics& g,
                          int x, int y, int width, int height,
                          float sliderPos,
                          float rotaryStartAngle, float rotaryEndAngle,
                          juce::Slider& slider) override;

private:
    juce::Array<juce::Image> knobFrames;
};
