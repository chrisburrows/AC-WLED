Import('env')
import os
import shutil

# copy WLED00/my_config_sample.h to WLED00/my_config.h
if os.path.isdir("local_customisations"):
    if os.path.isfile("local_customisations/my_config.h"):
        print ("*** use existing local_customisations/my_config.h ***")
    else:
        if os.path.isfile("my_config.h"):
            print("*** moving existing my_config.h to local_customisations/my_config.h")
            shutil.move("my_config.h", "local_customisations/my_config.h")
        else: 
            shutil.copy("wled00/my_config_sample.h", "local_customisations/my_config.h")
else:
    if os.path.isfile("my_config.h"):
        print ("*** use existing my_config.h ***")
    else: 
        shutil.copy("wled00/my_config_sample.h", "my_config.h")
