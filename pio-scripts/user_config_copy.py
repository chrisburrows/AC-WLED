Import('env')
import os
import shutil

# copy WLED00/my_config_sample.h to WLED00/my_config.h
if os.path.isfile("local_customisations/my_config.h"):
    print ("*** use existing my_config.h ***")
else: 
    shutil.copy("wled00/my_config_sample.h", "local_customisations/my_config.h")
