/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <juce_dsp/juce_dsp.h>


//==============================================================================
AirDelayRemakeAudioProcessorEditor::AirDelayRemakeAudioProcessorEditor (AirDelayRemakeAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    setSize(500, 380);

    setupKnobs();
}

AirDelayRemakeAudioProcessorEditor::~AirDelayRemakeAudioProcessorEditor()
{

}

void AirDelayRemakeAudioProcessorEditor::setupKnobs()
{
    
        // Mix Knob
        mixKnob.onValueChange = [this]() {
        audioProcessor.mix = mixKnob.getValue();
        };
    
        // Setup Feedback Knob
        feedbackKnob.setSliderStyle(juce::Slider::Rotary);
        feedbackKnob.setRange(0.0, 1.0, 0.01);
        feedbackKnob.setValue(audioProcessor.delayEffectProcessor.getFeedback()); 
        feedbackKnob.onValueChange = [this]() {
            audioProcessor.delayEffectProcessor.setFeedback(feedbackKnob.getValue());
        };
        addAndMakeVisible(feedbackKnob);

        // Setup Delay Knob
        delayTimeKnob.setSliderStyle(juce::Slider::Rotary);
        delayTimeKnob.setRange(1, 48000, 1); // 1 second delay
        delayTimeKnob.setValue(audioProcessor.delayEffectProcessor.getDelaySamples());
        delayTimeKnob.onValueChange = [this]() {
            audioProcessor.delayEffectProcessor.setDelaySamples(static_cast<int>(delayTimeKnob.getValue()));
        };
        addAndMakeVisible(delayTimeKnob);
    
        // Setup Labels
        feedbackLabel.setText("Feedback", juce::dontSendNotification);
        addAndMakeVisible(feedbackLabel);

        delayTimeLabel.setText("Delay", juce::dontSendNotification);
        addAndMakeVisible(delayTimeLabel);
    
        // Mix Knob
        mixKnob.setSliderStyle(juce::Slider::Rotary);
        mixKnob.setRange(0.0, 1.0, 0.01);
        addAndMakeVisible(mixKnob);
        mixLabel.setText("Mix", juce::dontSendNotification);
        addAndMakeVisible(mixLabel);

        // HPF Knob
        hpfKnob.setSliderStyle (juce::Slider::Rotary);
        hpfKnob.setRange(20.0, 20000.0, 1.0);
        hpfKnob.setValue(audioProcessor.hpfCutoff.getCurrentValue());
        hpfKnob.onValueChange = [this]()
        {
        audioProcessor.hpfCutoff = hpfKnob.getValue();
        audioProcessor.updateFilters();
        };
        addAndMakeVisible (hpfKnob);
        hpfLabel.setText ("HPF", juce::dontSendNotification);
        addAndMakeVisible (hpfLabel);

        // LPF Knob
        lpfKnob.setSliderStyle (juce::Slider::Rotary);
        lpfKnob.setRange(20.0, 20000.0, 1.0);
        lpfKnob.setValue(audioProcessor.lpfCutoff.getCurrentValue());
        lpfKnob.onValueChange = [this]()
        {
        audioProcessor.lpfCutoff = lpfKnob.getValue();
        audioProcessor.updateFilters();
        };
        addAndMakeVisible (lpfKnob);
        lpfLabel.setText ("LPF", juce::dontSendNotification);
        addAndMakeVisible (lpfLabel);
    
        // Randomizer
        randomizeButton.setButtonText("Randomize");
        randomizeButton.onClick = [this]()
        {
        // Randomize all knob values
        feedbackKnob.setValue(juce::Random::getSystemRandom().nextFloat());
        delayTimeKnob.setValue(juce::Random::getSystemRandom().nextInt(48000)); // max samples
        mixKnob.setValue(juce::Random::getSystemRandom().nextFloat());
        hpfKnob.setValue(juce::Random::getSystemRandom().nextFloat() * (20000.0f - 20.0f) + 20.0f);
        lpfKnob.setValue(juce::Random::getSystemRandom().nextFloat() * (20000.0f - 20.0f) + 20.0f);
        };

        // Bypass Button
        bypassButton.setButtonText("Bypass");
        bypassButton.onClick = [this]()
        {
            audioProcessor.bypass = bypassButton.getToggleState();
        };
        // HPF Toggle
        hpfToggle.setButtonText("Enable");
        hpfToggle.setToggleState(audioProcessor.enableHPF, juce::dontSendNotification);
        hpfToggle.onClick = [this]()
        {
            audioProcessor.enableHPF = hpfToggle.getToggleState();
        };

        // LPF Toggle
        lpfToggle.setButtonText("Enable");
        lpfToggle.setToggleState(audioProcessor.enableLPF, juce::dontSendNotification);
        lpfToggle.onClick = [this]()
        {
            audioProcessor.enableLPF = lpfToggle.getToggleState();
        };
    
    addAndMakeVisible(hpfToggle);
    
    addAndMakeVisible(lpfToggle);
    
    addAndMakeVisible(bypassButton);
    
    addAndMakeVisible(randomizeButton);
    

    }
    
    void AirDelayRemakeAudioProcessorEditor::paint(juce::Graphics& g)
    {
        
        // Gradient background
        juce::ColourGradient gradient(
            juce::Colours::darkslategrey,
            0, 0,
            juce::Colours::black,
            0, (float) getHeight(),
            false
        );

        g.setGradientFill(gradient);
        g.fillAll();

        // Draw a soft border
        g.setColour(juce::Colours::grey.withAlpha(0.6f));
        g.drawRoundedRectangle(getLocalBounds().toFloat().reduced(5.0f), 10.0f, 2.0f);

        // Divider line between top and bottom rows
        int dividerY = 150;
        g.setColour(juce::Colours::grey.withAlpha(0.3f));
        g.drawLine(20.0f, (float) dividerY, (float) getWidth() - 20.0f, (float) dividerY, 1.0f);
        
        // Draw AirDelay Logo
            if (airDelayLogo.isValid())
            {
                int logoWidth = 500;
                int logoHeight = 120;
                int logoX = (getWidth() - logoWidth) / 2;
                int logoY = dividerY + 110; // How much gap you want

                g.drawImage(airDelayLogo, logoX, logoY, logoWidth, logoHeight, 0, 0, airDelayLogo.getWidth(), airDelayLogo.getHeight());
            }
    }

    void AirDelayRemakeAudioProcessorEditor::resized()
    {
        const int knobWidth = 130;
        const int knobHeight = 130;
        const int labelHeight = 20;
        const int paddingX = 30;
        const int paddingY = 30;
            
        const int startX = 20;
        const int startY = 20;

        int x = startX;
        int y = startY;

        // Top row: Delay, Feedback, Mix
        delayTimeKnob.setBounds(x, y, knobWidth, knobHeight);
        delayTimeLabel.setBounds(20, -30 + knobHeight, knobWidth, labelHeight);

        x += knobWidth + paddingX;

        feedbackKnob.setBounds(x, y, knobWidth, knobHeight);
        feedbackLabel.setBounds(x, -30 + knobHeight, knobWidth, labelHeight);

        x += knobWidth + paddingX;

        mixKnob.setBounds(x, y, knobWidth, knobHeight);
        mixLabel.setBounds(x, -30 + knobHeight, knobWidth, labelHeight);

        // Bottom row 
        x = startX;
        y += knobHeight + labelHeight + paddingY;

        hpfKnob.setBounds(x, +135, knobWidth, knobHeight);
        hpfLabel.setBounds(x, 90 + knobHeight, knobWidth, labelHeight);

        x += knobWidth + paddingX;

        lpfKnob.setBounds(x, +135, knobWidth, knobHeight);
        lpfLabel.setBounds(x, 90 + knobHeight, knobWidth, labelHeight);

        x += knobWidth + paddingX;
        
        randomizeButton.setBounds(x, +135 + (knobHeight / 2) - 15, 120, 30); // 120px wide, centered vertically
        
        // Bypass
        bypassButton.setBounds(400, 20, 80, 30);
        
        hpfToggle.setBounds(50, 215, 80, 30);  // Adjust?
        lpfToggle.setBounds(210, 215, 80, 30);
        
        //Image
        airDelayLogo = juce::ImageCache::getFromMemory(BinaryData::AirDelayLogo_png, BinaryData::AirDelayLogo_pngSize);
        
        
    }
