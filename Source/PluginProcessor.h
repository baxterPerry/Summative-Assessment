/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class SummativeAssessmentAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    SummativeAssessmentAudioProcessor();
    ~SummativeAssessmentAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    float degradeAmount = 8.0;
    int lastSampleRate;
    void updateFilter();
    void updateParameters();
   
   AudioProcessorValueTreeState tree;

private:
    dsp::ProcessorDuplicator< dsp::StateVariableFilter::Filter<float>, dsp::StateVariableFilter::Parameters<float>> lowPassFilter;
    dsp::ProcessorDuplicator< dsp::StateVariableFilter::Filter<float>, dsp::StateVariableFilter::Parameters<float>> hiPassFilter;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SummativeAssessmentAudioProcessor)
};
