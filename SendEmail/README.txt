
DESCRIPTION

   Simple application to send and receive email with attachment. This application shows how to use Base64 codec.

   
COPYRIGHT NOTICE

   Copyright (c) 2020 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
   Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG 

FILES

   README.txt                            This file
   client.yaml                           client YAML file
   server.yaml                           server YAML file
   HTTPServer.properties                 Defines server correlator port
   ReceiveEmail.mon                      An EPL receiver to receive email
   SendEmail.mon                         An EPL sender to send email

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
  
  Got Email: Email("a@sag.com","b@sag.com,c@sag.com","d@sag.com,e@sag.com","Fluffy Kitten","Hello from Fluffy Kitten")
  


