// -*- C++ -*-
/*!
 * @file  VoiceInterface.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "VoiceInterface.h"

// Module specification
// <rtc-template block="module_spec">
static const char* voiceinterface_spec[] =
  {
    "implementation_id", "VoiceInterface",
    "type_name",         "VoiceInterface",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "Intelligent Systems Lab.",
    "category",          "Voice",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
VoiceInterface::VoiceInterface(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_speech_inIn("speech_in", m_speech_in),
    m_commandOut("command", m_command),
    m_speech_outOut("speech_out", m_speech_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
VoiceInterface::~VoiceInterface()
{
}



RTC::ReturnCode_t VoiceInterface::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("speech_in", m_speech_inIn);
  
  // Set OutPort buffer
  addOutPort("command", m_commandOut);
  addOutPort("speech_out", m_speech_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t VoiceInterface::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VoiceInterface::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VoiceInterface::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

RTC::ReturnCode_t VoiceInterface::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

RTC::ReturnCode_t VoiceInterface::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

RTC::ReturnCode_t VoiceInterface::onExecute(RTC::UniqueId ec_id)
{
    enum { kGoForward = 1, kGoBackward, kTurnRight, kTurnLeft, kStop, kMoveTo, kSaveTarget };

    if(m_speech_inIn.isNew()) {
        m_speech_inIn.read();

        std::string speech_in(m_speech_in.data);

        std::cout<<speech_in<<std::endl;
        
        if(speech_in == "go forward") {
            m_command.data = kGoForward;
            m_commandOut.write();
        } else if(speech_in == "go backward") {
            m_command.data = kGoBackward;
            m_commandOut.write();
        } else if(speech_in == "turn right") {
            m_command.data = kTurnRight;
            m_commandOut.write();
        } else if(speech_in == "turn left") {
            m_command.data = kTurnLeft;
            m_commandOut.write();
        } else if(speech_in == "stop") {
            m_command.data = kStop;
            m_commandOut.write();
        } else if(speech_in == "move to target") {
            m_command.data = kMoveTo;
            m_commandOut.write();
        } else if(speech_in == "save target") {
            m_command.data = kSaveTarget;
            m_commandOut.write();
        }
    }

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t VoiceInterface::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VoiceInterface::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VoiceInterface::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VoiceInterface::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t VoiceInterface::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void VoiceInterfaceInit(RTC::Manager* manager)
  {
    coil::Properties profile(voiceinterface_spec);
    manager->registerFactory(profile,
                             RTC::Create<VoiceInterface>,
                             RTC::Delete<VoiceInterface>);
  }
  
};


