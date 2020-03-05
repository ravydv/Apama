
DESCRIPTION

   Simple application to send and receive email with attachment. This application shows how to use Base64 codec.

   
COPYRIGHT NOTICE

   Copyright (c) 2020 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG 

FILES

   README.txt                            This file
   LoadImage.cpp                         Source to load image
   Makefile                              GNU Make compatible makefile
   make.bat                              Windows build script
   LoadImage{sln,vcxproj}                Microsoft Visual Studio solution/project
   client.yaml                           client YAML file
   server.yaml                           server YAML file
   HTTPServer.properties                 Defines server correlator port
   ReceiveEmail.mon                      An EPL receiver to receive email
   SendEmail.mon                         An EPL sender to send email

BUILDING THE SAMPLES

   It is recommended that you copy this sample folder to an area of your 
   APAMA_WORK directory rather than running it directly from the installation 
   directory. For Windows users with UAC enabled this step is required to 
   avoid access denied errors when writing to the sample directory.

   Note also that on Unix, GNU make (gmake) is required in order to build the 
   samples using the supplied Makefile.

   ** To build the samples on Unix (Linux) **
   
   Source the apama_env file located in the installation bin directory to set 
   the environment variables required for building sample. Run gmake in the 
   current directory:  

    $ gmake

   If the C++ compiler is not in the default location assumed by the Makefile,
   this can be overridden by setting the CXX variable on the gmake command line.
   For example:

    $ gmake CXX=/usr/bin/gcc-4.8.5/g++

   would select a GNU C++ compiler installed under /usr/bin/gcc-4.8.5

   A successful build will produce one output file in the Release subdirectory:

    libLoadIMage.so

   ** To build the samples on Microsoft Windows **
   
   Prepare the Apama environment by selecting "Apama Command Prompt" from the 
   Start Menu, or by running the APAMA_HOME\bin\apama_env.bat script. 
   
   Then ensure that the Visual Studio environment is set correctly for the 
   Apama architecture you are building against; this typically means running:
   
   > "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64
   
   Once the environment is configured, the sample can be built using:
   
   > make.bat release
   
   Alternatively the solution file can be opened in the Visual Studio IDE with:

   > make.bat ide
      
   A successful build will leave one DLL files in the Release subdirectory:

    LoadIMage.dll

   
RUNNING THE APPLICTION

   Running of the application requires access to the Correlator and Apama command 
   line tools.
   
   To ensure that the environment is configured correctly for Apama, all the 
   commands below should be executed from an Apama Command Prompt, or from a 
   shell or command prompt where the bin\apama_env script has been run (or on 
   Unix, sourced). Now run these commands from the application's directory.
   
   1. Start the Apama Server Correlator in the Apama Command Prompt by running:
   
      > correlator --config HTTPServer.properties --config server.yaml

   2. Start the Apama HTTP client Correlator in a new Apama Command Prompt by running:
   
      > correlator --port 15904 --config HTTPServer.properties --config client.yaml

   3. Inject the connectivity plugins support EPL from the monitors/ directory
   of your Apama installation (Skip the inject for the client if you intend to only use curl):

      On Unix:
      > engine_inject "$APAMA_HOME/monitors/ConnectivityPluginsControl.mon" "$APAMA_HOME/monitors/ConnectivityPlugins.mon"
      > engine_inject --port 15904 "$APAMA_HOME/monitors/ConnectivityPluginsControl.mon" "$APAMA_HOME/monitors/ConnectivityPlugins.mon"
      
      On Windows:
      > engine_inject "%APAMA_HOME%\monitors\ConnectivityPluginsControl.mon" "%APAMA_HOME%\monitors\ConnectivityPlugins.mon"
      > engine_inject --port 15904 "%APAMA_HOME%\monitors\ConnectivityPluginsControl.mon" "%APAMA_HOME%\monitors\ConnectivityPlugins.mon"

   4. Inject the ReceiveEmail.mon into the receiver correlator to receive email

      > engine_inject ReceiveEmail.mon

   5. Inject the SendEmail.mon  into the sender correlator to send email

      > engine_inject SendEmail.mon --port 15904
Output
  Check the receiver correlator log for the following
  
  Got Email: Email("a@sag.com","b@sag.com,c@sag.com","d@sag.com,e@sag.com","Fluffy Kitten","Hello from Fluffy Kitten",
  


