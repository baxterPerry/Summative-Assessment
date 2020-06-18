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
    float degradeAmount = 8.0; // range will be from 1.0 to 100,000.0 we will use an exponential slider to make up for the logarithmic behaviour of the algorithm.
    int lastSampleRate;
    void updateFilter();
    void updateParameters();
    float lowPassFreq = 100.0;//range will be 20k to 20
    float highPassFreq = 20.0; //range will be 20 to 20k
    float mixValue = 1.0f; //range will be 0.0 to 1.0
   
   AudioProcessorValueTreeState tree;

private:
    std::atomic<float>* quantParam = nullptr;
    std::atomic<float>* lowPassParam = nullptr;
   // dsp::ProcessorDuplicator< dsp::StateVariableFilter::Filter<float>, dsp::StateVariableFilter::Parameters<float>> lowPassFilter;
    //dsp::ProcessorDuplicator< dsp::StateVariableFilter::Filter<float>, dsp::StateVariableFilter::Parameters<float>> hiPassFilter;
    dsp::StateVariableFilter::Filter<float>  lowPassFilter;
    dsp::StateVariableFilter::Parameters<float> lowPassParams; //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SummativeAssessmentAudioProcessor)
};
