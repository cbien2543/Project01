/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <juce_dsp/juce_dsp.h>

//==============================================================================
AirDelayRemakeAudioProcessor::AirDelayRemakeAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )

#endif
{
}

AirDelayRemakeAudioProcessor::~AirDelayRemakeAudioProcessor()
{
}

//==============================================================================
const juce::String AirDelayRemakeAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AirDelayRemakeAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AirDelayRemakeAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AirDelayRemakeAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AirDelayRemakeAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AirDelayRemakeAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AirDelayRemakeAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AirDelayRemakeAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String AirDelayRemakeAudioProcessor::getProgramName (int index)
{
    return {};
}

void AirDelayRemakeAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void AirDelayRemakeAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumInputChannels();
        
    hpf.prepare(spec);
    lpf.prepare(spec);
    
    mix.reset(sampleRate);
    hpfCutoff.reset(sampleRate, 0.02);
    lpfCutoff.reset(sampleRate, 0.02);
    
//    updateFilters();
    
}

void AirDelayRemakeAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AirDelayRemakeAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AirDelayRemakeAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    if (bypass)
        return; // Skip processing entirely

    juce::dsp::AudioBlock<float> block(buffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    
    // Update filter cutoffs
    updateFilters();


    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float dry = channelData[sample];

            if (enableHPF)
                dry = hpf.processSample(dry);

            if (enableLPF)
                dry = lpf.processSample(dry);

            float wet = delayEffectProcessor.processSample(dry);

            float mixValue = mix.getNextValue(); 
            float outputSample = (1.0f - mixValue) * dry + mixValue * wet;

            // Kill denormals
            if (std::abs(outputSample) < 1.0e-15f)
                outputSample = 0.0f;

            channelData[sample] = outputSample;
        }
    }
}


//==============================================================================
bool AirDelayRemakeAudioProcessor::hasEditor() const
{
    return true; 
}

juce::AudioProcessorEditor* AirDelayRemakeAudioProcessor::createEditor()
{
    return new AirDelayRemakeAudioProcessorEditor (*this);
}

//==============================================================================
void AirDelayRemakeAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AirDelayRemakeAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void AirDelayRemakeAudioProcessor::updateFilters()
{
    *hpf.coefficients = *juce::dsp::IIR::Coefficients<float>::makeHighPass(getSampleRate(), hpfCutoff.getNextValue());
    *lpf.coefficients = *juce::dsp::IIR::Coefficients<float>::makeLowPass(getSampleRate(), lpfCutoff.getNextValue());
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AirDelayRemakeAudioProcessor();
}
