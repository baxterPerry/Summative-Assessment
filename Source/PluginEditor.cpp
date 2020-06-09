/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SummativeAssessmentAudioProcessorEditor::SummativeAssessmentAudioProcessorEditor (SummativeAssessmentAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 300);
}

SummativeAssessmentAudioProcessorEditor::~SummativeAssessmentAudioProcessorEditor()
{
    skin.jpg = ImageCache::getFromMemory(BinaryData::skin.jpg, BinaryData::600,300);
}

//==============================================================================
void SummativeAssessmentAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.drawImageWithin(skin.jpg, 0, 0, getWidth(), getHeight(), RectanglePlacement::fillDestination);
    g.setFont (15.0f);
        
}

void SummativeAssessmentAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
