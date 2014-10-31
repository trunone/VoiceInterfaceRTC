VoiceInterfaceRTC
=================

Layout
----

![VoiceInterfaceRTC](https://farm4.staticflickr.com/3939/15044463303_96a8b2dea7_o.png)

Features
----
  * Receive the string that recognized from voice
  * Output the command to control the state machine

Requirements
----
  * OS
   * Linux Distributions
   * Windows
  * Softwares
   * OpenRTM-aist C++ 1.1 or later
   * CMake 2.8

Port
----

| Name     | Type          | Data Type   | Purpose |
| -------- | ------------- | ----------- | ------- |
| speech_in   | In       | RTC::TimedString | The recognized text |
| speech_out  | Out      | RTC::TimedString  | The text to speak out |
| command     | Out      | RTC::TimedState   | Command state        |

Usage
----

| Speech Command     | Command State | Purpose |
| -------- | ------------- | ------------|
| Go Forward   | 1       |
| Go Backward  | 2      |
| Turn Right     | 3      |
| Turn Left     | 4      |
| Stop     | 5      |
| Move To     | 6      | Move to the saved position |
| Save Target     | 7      | Save the current position |

License
----

Licensed under the [Apache License, Version 2.0][Apache]  
Distributed under the [MIT License][mit].  
Dual licensed under the [MIT license][MIT] and [Apache License, Version 2.0][Apache].  
 
[Apache]: http://www.apache.org/licenses/LICENSE-2.0
[MIT]: http://www.opensource.org/licenses/mit-license.php
