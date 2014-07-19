/*
 * Carla State utils
 * Copyright (C) 2012-2014 Filipe Coelho <falktx@falktx.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * For a full copy of the GNU General Public License see the doc/GPL.txt file.
 */

#ifndef CARLA_STATE_UTILS_HPP_INCLUDED
#define CARLA_STATE_UTILS_HPP_INCLUDED

#include "CarlaBackend.h"
#include "LinkedList.hpp"

namespace juce {
class String;
class XmlElement;
}

CARLA_BACKEND_START_NAMESPACE

// -----------------------------------------------------------------------

struct StateParameter {
    bool        isInput;
    int32_t     index;
    const char* name;
    const char* symbol;
    float       value;
    uint8_t     midiChannel;
    int16_t     midiCC;

    StateParameter() noexcept;
    ~StateParameter() noexcept;

    CARLA_DECLARE_NON_COPY_STRUCT(StateParameter)
};

struct StateCustomData {
    const char* type;
    const char* key;
    const char* value;

    StateCustomData() noexcept;
    ~StateCustomData() noexcept;

    CARLA_DECLARE_NON_COPY_STRUCT(StateCustomData)
};

typedef LinkedList<StateParameter*> StateParameterList;
typedef LinkedList<StateCustomData*> StateCustomDataList;

typedef LinkedList<StateParameter*>::Itenerator StateParameterItenerator;
typedef LinkedList<StateCustomData*>::Itenerator StateCustomDataItenerator;

struct StateSave {
    const char* type;
    const char* name;
    const char* label;
    const char* binary;
    int64_t     uniqueId;

    bool  active;
    float dryWet;
    float volume;
    float balanceLeft;
    float balanceRight;
    float panning;
    int8_t ctrlChannel;
    uint   options;

    int32_t     currentProgramIndex;
    const char* currentProgramName;
    int32_t     currentMidiBank;
    int32_t     currentMidiProgram;
    const char* chunk;

    StateParameterList parameters;
    StateCustomDataList customData;

    StateSave() noexcept;
    ~StateSave() noexcept;
    void clear() noexcept;

    bool fillFromXmlElement(const juce::XmlElement* const xmlElement);
    juce::String toString() const;

    CARLA_DECLARE_NON_COPY_STRUCT(StateSave)
};

// -----------------------------------------------------------------------

CARLA_BACKEND_END_NAMESPACE

#endif // CARLA_STATE_UTILS_HPP_INCLUDED
