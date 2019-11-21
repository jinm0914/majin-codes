 //
 // This file is part of Easylogging++ samples
 //
 // Very basic sample to configure using global configuration (el::Loggers::configureFromGlobal)
 //
 // Revision 1.1
 // @author mkhan3189
 //

#define MAJIN(LEVEL) LOG(LEVEL)
#include <unistd.h>
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(void) {

	// Load configuration from file
    el::Configurations conf("my.conf");
    // Reconfigure single logger
     el::Loggers::reconfigureLogger("default", conf);
    // Actually reconfigure all loggers instead
    el::Loggers::reconfigureAllLoggers(conf);
    // // Now all the loggers will use configuration from file

	el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);

    el::Loggers::getLogger("MAJIN");

    // MAJIN(GLOBAL) << "Info log before using global configuration";
    int i=0;
    while(1){
        sleep(1);
        MAJIN(TRACE) << "this is TRACE  " << i;
        MAJIN(DEBUG) << "this is DEBUG  " <<i;
        MAJIN(WARNING) << "this is WARNING  " << i;
        MAJIN(INFO) << "this is INFO  " << i;
        // MAJIN(VERBOSE) << "Info log AFTER using global configuration";
        // MAJIN(UNKNOWN) << "Error log AFTER using global configuration";
        // MAJIN(FATAL) << "Info log before using global configuration";
        MAJIN(ERROR) << "this is ERROR  " << i++;
    
    }

    return 0;
}
