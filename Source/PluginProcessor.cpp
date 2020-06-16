/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SummativeAssessmentAudioProcessor::SummativeAssessmentAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), tree(*this, nullptr)
#endif
{
   NormalisableRange<float> cutOffRange (20.0f, 20000.0f);
    
    tree.createAndAddParameter("lowCutoff", "Cutoff", "lowCutoff", cutOffRange, lowPassFreq, nullptr, nullptr);
    tree.createAndAddParameter("hiCutoff", "Cutoff", "hiCutoff", cutOffRange, highPassFreq, nullptr, nullptr);
}

SummativeAssessmentAudioProcessor::~SummativeAssessmentAudioProcessor()
{
}

//==============================================================================
const String SummativeAssessmentAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SummativeAssessmentAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SummativeAssessmentAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SummativeAssessmentAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SummativeAssessmentAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SummativeAssessmentAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SummativeAssessmentAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SummativeAssessmentAudioProcessor::setCurrentProgram (int index)
{
}

const String SummativeAssessmentAudioProcessor::getProgramName (int index)
{
    return {};
}

void SummativeAssessmentAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SummativeAssessmentAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    lastSampleRate = sampleRate;
    
    dsp::ProcessSpec spec;
    spec.sampleRate = lastSampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getMainBusNumOutputChannels();

    lowPassFilter.reset();
    hiPassFilter.reset();
    updateFilter();
    lowPassFilter.prepare(spec);
    hiPassFilter.prepare(spec);
}

void SummativeAssessmentAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}


void SummativeAssessmentAudioProcessor::updateFilter()
{
    int lowCutoff = *tree.getRawParameterValue("lowCutoff");
    int hiCutoff = *tree.getRawParameterValue("hiCutoff");
    
    lowPassFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
    hiPassFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::highPass;
    
    lowPassFilter.state->setCutOffFrequency (lastSampleRate, lowCutoff);
    hiPassFilter.state->setCutOffFrequency (lastSampleRate, hiCutoff);
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SummativeAssessmentAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
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

void SummativeAssessmentAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();


    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    
    
    //at the moment the filter happens before the bit crush!! TBC
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* inBuffer = buffer.getReadPointer (channel);
        auto* outBuffer = buffer.getWritePointer (channel);
        
        for (auto sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
           float bitSample =  inBuffer[sample] * (degradeAmount);
            //float bitSampleFine =  bit;
            float roundedValue = roundToInt(bitSample);
            
            //pow()-1
            //perform transformation on result of this line to round.
            //outBuffer[sample] =  ((bitSample * (1 << (8))) / (1 << (8)));
            //outBuffer[sample] = bitSample; (bitSample << 1)
            outBuffer[sample] = roundedValue / (degradeAmount); //How am I going to reduce quality? Round off. for example 63229 rounded to 100s  63200
            // , floor(), ceil()
            
            
            
        }

        // ..do something to the data...
    }
    dsp::AudioBlock<float> block (buffer);
    //lowPassFilter.process(dsp::ProcessContextReplacing<float> (block));
       
    hiPassFilter.process(dsp::ProcessContextReplacing<float> (block));
    updateFilter();
}

//==============================================================================
bool SummativeAssessmentAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SummativeAssessmentAudioProcessor::createEditor()
{
    return new SummativeAssessmentAudioProcessorEditor (*this);
}

//==============================================================================
void SummativeAssessmentAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SummativeAssessmentAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SummativeAssessmentAudioProcessor();
}
