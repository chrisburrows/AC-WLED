#pragma once

/*
 * Welcome!
 * You can use the file "my_config.h" to make changes to the way WLED is compiled!
 * It is possible to enable and disable certain features as well as set defaults for some runtime changeable settings.
 *
 * How to use:
 * PlatformIO: Just compile the unmodified code once! The file "my_config.h" will be generated automatically and now you can make your changes.
 *
 * ArduinoIDE: Make a copy of this file and name it "my_config.h". Go to wled.h and uncomment "#define WLED_USE_MY_CONFIG" in the top of the file.
 *
 * DO NOT make changes to the "my_config_sample.h" file directly! Your changes will not be applied.
 */

// uncomment to force the compiler to show a warning to confirm that this file is included
// #warning **** my_config.h: Settings from this file are honored ****

// #define WLED_DEBUG

//#define MAX_LEDS 1500       // Maximum total LEDs. More than 1500 might create a low memory situation on ESP8266.
//#define MDNS_NAME "wled"    // mDNS hostname, ie: *.local

// defaults - disable some things we don't use as all
#define WLED_DISABLE_ALEXA
#define WLED_DISABLE_HUESYNC
#define WLED_DISABLE_INFRARED

// #define CLIENT_SSID ""
// #define CLIENT_PASS ""

// instance specific builds


#ifdef KITCHEN_AUDIO_REACTIVE
  // "Kitchen LHS" 
  // LEDs - 85 leds
  // SK6812 RGBW, 
  // pin 16, relay pin 2, 
  // sync wled broadcast 21330 & 65530 receive all, send direct changes, send twice, 
  // mqtt WLED-kitchen-lhs,dev topic wled/kitchen-lhs, group topic wled/kitchen, 
  // audio sync xmit 11988

  #define KITCHEN

  #define USERMOD_AUDIOREACTIVE
  #define SR_DMTYPE 0 // analogue microphone
  #define AUDIOPIN 36 // microphone IO
  #define SR_SQUELCH 100
  #define SR_GAIN 10
#endif

#ifdef KITCHEN_OTHER
  // "Kitchen RHS" 
  // LEDs - 85 leds, 
  // SK6812 RGBW, 
  // pin 16, relay pin 2, 
  // sync wled broadcast 21330 & 65530 receive all, send direct changes, send twice, 
  // mqtt WLED-kitchen-lhs,dev topic wled/kitchen-lhs, group topic wled/kitchen, 
  // audio sync recv 11988

  #define KITCHEN
#endif

#ifdef KITCHEN
  #define LEDPIN 16
  #define RLYPIN 2
  #define RLYMDE 1

  #define USERMOD_MULTI_RELAY
  #define MULTI_RELAY_HA_DISCOVERY true
  #define MULTI_RELAY_MAX_RELAYS 1
  #define MULTI_RELAY_PINS 12
  #define MULTI_RELAY_DELAYS 0
  #define MULTI_RELAY_EXTERNALS true
  #define MULTI_RELAY_INVERTS false
#endif

#ifdef CINEMA_TV
  #define LEDPIN 19
  #define RLYPIN 26
  #define RLYMDE 1
#endif

#ifdef HALL_SHELVES
  // incomplete dig2go
  #define LEDPIN 16
  #define RLYPIN 12
  #define RLYMDE 1
  #define BTNPIN 0
  #define IRPIN 5

  #define USERMOD_AUDIOREACTIVE
  #define SR_DMTYPE 1 // analogue microphone
  #define I2S_SDPIN 19 // microphone IO
  #define I2S_WSPIN 4 // microphone IO
  #define I2S_CKPIN 18 // microphone IO
  #define SR_SQUELCH 100
  #define SR_GAIN 10
#endif