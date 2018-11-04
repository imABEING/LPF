/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Iir_filterAudioProcessor::Iir_filterAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       //make Low Pass Filter
                       ), tree(*this, nullptr), lowPassFilter(dsp::IIR::Coefficients <float>::makeLowPass(44100, 20000.0f, 0.1f))
#endif
{
    //Create Slider Ranges
<<<<<<< HEAD
    NormalisableRange<float> cutoffRange (20.0f, 20000.0f);
    NormalisableRange<float> resRange (1.0f, 5.0f);
    
    //Create and return a new parameter objects for features
    tree.createAndAddParameter("cutoff", "Cutoff", String(),
        cutoffRange, 16000.0f, nullptr, nullptr);
    tree.createAndAddParameter("resonance", "Resonance", String(),
        resRange, 1.0f, nullptr, nullptr);
=======
    //NormalisableRange<float> cutoffRange (20.0f, 20000.0f);
    //NormalisableRange<float> resRange (1.0f, 5.0f);
    
    //Create and return a new parameter objects for features
    tree.createAndAddParameter("cutoff", "Cutoff", String(),
        NormalisableRange<float>(20.0f, 20000.0f), 600.0f, nullptr, nullptr);
    tree.createAndAddParameter("resonance", "Resonance", String(),
        NormalisableRange<float>(1.0f, 5.0f), 1.0f, nullptr, nullptr);
>>>>>>> origin/master
    
    //State Identifier
    tree.state = ValueTree(Identifier("FilterState"));
}

Iir_filterAudioProcessor::~Iir_filterAudioProcessor()
{
}

//==============================================================================
const String Iir_filterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Iir_filterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Iir_filterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Iir_filterAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Iir_filterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Iir_filterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Iir_filterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Iir_filterAudioProcessor::setCurrentProgram (int index)
{
}

const String Iir_filterAudioProcessor::getProgramName (int index)
{
    return {};
}

void Iir_filterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Iir_filterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    //Pass in values from dsp module
    lastSampleRate = sampleRate;
    dsp::ProcessSpec spec;
<<<<<<< HEAD
    spec.sampleRate = sampleRate;
=======
    sampleRate = spec.sampleRate;
>>>>>>> origin/master
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();
    
    //reset process spec
    lowPassFilter.prepare(spec);
    
    //lowPassFilter.process(spec);
    
    //reset filter
    lowPassFilter.reset();
}

void Iir_filterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Iir_filterAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void Iir_filterAudioProcessor::updateFilter()
{
    //Access values from value tree to pass into filter state
    const float freq = *tree.getRawParameterValue("cutoff");
    const float res = *tree.getRawParameterValue("resonance");
    
    
<<<<<<< HEAD
    
=======
>>>>>>> origin/master
    
    //Access state attribute to return coefficients
    *lowPassFilter.state = *dsp::IIR::Coefficients <float>::makeLowPass(lastSampleRate, freq, res);
    
    //lowPassFilter.
}

void Iir_filterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    //Data Structure to refer to buffer
    dsp::AudioBlock <float> block (buffer);
    updateFilter();
    lowPassFilter.process(dsp::ProcessContextReplacing<float> (block));
    

/*
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }*/
}

//==============================================================================
bool Iir_filterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Iir_filterAudioProcessor::createEditor()
{
    return new Iir_filterAudioProcessorEditor (*this, tree);
}

//==============================================================================
void Iir_filterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Iir_filterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Iir_filterAudioProcessor();
}
