/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Iir_filterAudioProcessorEditor::Iir_filterAudioProcessorEditor (Iir_filterAudioProcessor& p, AudioProcessorValueTreeState& vts)
: AudioProcessorEditor (&p), processor (p), valueStateTree (vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    setVisible(true);
    
    //Cutoff Dial
    filterCutoffDial.setRange(0, 20000);
    filterCutoffDial.setValue(20000);
    filterCutoffDial.setTextValueSuffix(" Hz");
    addAndMakeVisible(filterCutoffDial);
    //filterCutoffDial.addListener(this);
    
    //Resonance Dial
    filterResDial.setRange(1, 5);
    filterResDial.setValue(0.71f);
    filterResDial.setTextValueSuffix(" Hz");
    //filterResDial.addListener(this);
    addAndMakeVisible(filterResDial);
}

Iir_filterAudioProcessorEditor::~Iir_filterAudioProcessorEditor()
{
}

//==============================================================================
void Iir_filterAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("IIR Filter", getLocalBounds(), Justification::centred, 1);
}

void Iir_filterAudioProcessorEditor::resized()
{
    filterCutoffDial.setBounds(getLocalBounds());
    filterResDial.setBounds(getLocalBounds());
}
