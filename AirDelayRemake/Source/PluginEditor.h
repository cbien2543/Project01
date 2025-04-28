/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================

class AirDelayRemakeAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AirDelayRemakeAudioProcessorEditor (AirDelayRemakeAudioProcessor&);
    ~AirDelayRemakeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AirDelayRemakeAudioProcessor& audioProcessor;
    
    // Knobs
    juce::Slider feedbackKnob;
    juce::Slider delayTimeKnob;
    juce::Slider mixKnob;
    juce::Slider hpfKnob;
    juce::Slider lpfKnob;
    juce::Slider modDepthKnob;
    juce::Slider modRateKnob;
    
    //Buttons
    juce::TextButton randomizeButton;
    
    // Label
    juce::Label feedbackLabel;
    juce::Label delayTimeLabel;
    juce::Label mixLabel;
    juce::Label hpfLabel;
    juce::Label lpfLabel;
    juce::Label modDepthLabel;
    juce::Label modRateLabel;
    
    //Logo
    juce::Image airDelayLogo;
    
    // Link
    void setupKnobs();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AirDelayRemakeAudioProcessorEditor)
};
