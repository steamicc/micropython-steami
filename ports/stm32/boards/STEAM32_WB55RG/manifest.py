include("$(PORT_DIR)/boards/manifest.py")

# Utils
require("time")
require("senml")
require("logging")

# Bluetooth
require("aioble")

# Register external library
add_library("micropython-steami-lib", "$(STEAMI_LIB_DIR)")


require("ssd1327", library="micropython-steami-lib")
require("apds9960", library="micropython-steami-lib")
require("bq27441", library="micropython-steami-lib")
require("hts221", library="micropython-steami-lib")
require("vl53l1x", library="micropython-steami-lib")
