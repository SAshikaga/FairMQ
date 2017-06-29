/********************************************************************************
 *    Copyright (C) 2017 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *              GNU Lesser General Public Licence (LGPL) version 3,             *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include <fairmq/PluginServices.h>

using fair::mq::PluginServices;

const std::unordered_map<std::string, PluginServices::DeviceState> PluginServices::fkDeviceStateStrMap = {
    {"OK",                  DeviceState::Ok},
    {"ERROR",               DeviceState::Error},
    {"IDLE",                DeviceState::Idle},
    {"INITIALIZING DEVICE", DeviceState::InitializingDevice},
    {"DEVICE READY",        DeviceState::DeviceReady},
    {"INITIALIZING TASK",   DeviceState::InitializingTask},
    {"READY",               DeviceState::Ready},
    {"RUNNING",             DeviceState::Running},
    {"PAUSED",              DeviceState::Paused},
    {"RESETTING TASK",      DeviceState::ResettingTask},
    {"RESETTING DEVICE",    DeviceState::ResettingDevice},
    {"EXITING",             DeviceState::Exiting}
};
const std::unordered_map<PluginServices::DeviceState, std::string> PluginServices::fkStrDeviceStateMap = {
    {DeviceState::Ok,                 "OK"},
    {DeviceState::Error,              "ERROR"},
    {DeviceState::Idle,               "IDLE"},
    {DeviceState::InitializingDevice, "INITIALIZING DEVICE"},
    {DeviceState::DeviceReady,        "DEVICE READY"},
    {DeviceState::InitializingTask,   "INITIALIZING TASK"},
    {DeviceState::Ready,              "READY"},
    {DeviceState::Running,            "RUNNING"},
    {DeviceState::Paused,             "PAUSED"},
    {DeviceState::ResettingTask,      "RESETTING TASK"},
    {DeviceState::ResettingDevice,    "RESETTING DEVICE"},
    {DeviceState::Exiting,            "EXITING"}
};
const std::unordered_map<std::string, PluginServices::DeviceStateTransition> PluginServices::fkDeviceStateTransitionStrMap = {
    {"INIT DEVICE",  DeviceStateTransition::InitDevice},
    {"INIT TASK",    DeviceStateTransition::InitTask},
    {"RUN",          DeviceStateTransition::Run},
    {"PAUSE",        DeviceStateTransition::Pause},
    {"STOP",         DeviceStateTransition::Stop},
    {"RESET TASK",   DeviceStateTransition::ResetTask},
    {"RESET DEVICE", DeviceStateTransition::ResetDevice},
    {"END",          DeviceStateTransition::End},
    {"ERROR FOUND",  DeviceStateTransition::ErrorFound},
};
const std::unordered_map<PluginServices::DeviceStateTransition, std::string> PluginServices::fkStrDeviceStateTransitionMap = {
    {DeviceStateTransition::InitDevice,  "INIT DEVICE"},
    {DeviceStateTransition::InitTask,    "INIT TASK"},
    {DeviceStateTransition::Run,         "RUN"},
    {DeviceStateTransition::Pause,       "PAUSE"},
    {DeviceStateTransition::Stop,        "STOP"},
    {DeviceStateTransition::ResetTask,   "RESET TASK"},
    {DeviceStateTransition::ResetDevice, "RESET DEVICE"},
    {DeviceStateTransition::End,         "END"},
    {DeviceStateTransition::ErrorFound,  "ERROR FOUND"},
};
const std::unordered_map<FairMQDevice::State, PluginServices::DeviceState> PluginServices::fkDeviceStateMap = {
    {FairMQDevice::OK,                  DeviceState::Ok},
    {FairMQDevice::ERROR,               DeviceState::Error},
    {FairMQDevice::IDLE,                DeviceState::Idle},
    {FairMQDevice::INITIALIZING_DEVICE, DeviceState::InitializingDevice},
    {FairMQDevice::DEVICE_READY,        DeviceState::DeviceReady},
    {FairMQDevice::INITIALIZING_TASK,   DeviceState::InitializingTask},
    {FairMQDevice::READY,               DeviceState::Ready},
    {FairMQDevice::RUNNING,             DeviceState::Running},
    {FairMQDevice::PAUSED,              DeviceState::Paused},
    {FairMQDevice::RESETTING_TASK,      DeviceState::ResettingTask},
    {FairMQDevice::RESETTING_DEVICE,    DeviceState::ResettingDevice},
    {FairMQDevice::EXITING,             DeviceState::Exiting}
};
const std::unordered_map<PluginServices::DeviceStateTransition, FairMQDevice::Event> PluginServices::fkDeviceStateTransitionMap = {
    {DeviceStateTransition::InitDevice,  FairMQDevice::INIT_DEVICE},
    {DeviceStateTransition::InitTask,    FairMQDevice::INIT_TASK},
    {DeviceStateTransition::Run,         FairMQDevice::RUN},
    {DeviceStateTransition::Pause,       FairMQDevice::PAUSE},
    {DeviceStateTransition::Stop,        FairMQDevice::STOP},
    {DeviceStateTransition::ResetTask,   FairMQDevice::RESET_TASK},
    {DeviceStateTransition::ResetDevice, FairMQDevice::RESET_DEVICE},
    {DeviceStateTransition::End,         FairMQDevice::END},
    {DeviceStateTransition::ErrorFound,  FairMQDevice::ERROR_FOUND}
};
