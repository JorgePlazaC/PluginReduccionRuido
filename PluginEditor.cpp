/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor(NewProjectAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(400, 300);

    cutoffFrequencySlider.setRange(20, 20000, 1);
    cutoffFrequencySlider.setValue(audioProcessor.cutoffFrequency);
    cutoffFrequencySlider.addListener(this);
    addAndMakeVisible(cutoffFrequencySlider);
}



void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &cutoffFrequencySlider)
    {
        audioProcessor.cutoffFrequency = cutoffFrequencySlider.getValue();
    }
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
    cutoffFrequencySlider.removeListener(this);
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    cutoffFrequencySlider.setBounds(10, 10, getWidth() - 20, 20);
}
