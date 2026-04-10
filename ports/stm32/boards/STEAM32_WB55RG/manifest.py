include("$(PORT_DIR)/boards/manifest.py")

# Utils
require("time")
require("senml")
require("logging")

# Bluetooth
require("aioble")

# Register external library
add_library("micropython-steami-lib", "$(STEAMI_LIB_DIR)")

require("mcp23009e", library="micropython-steami-lib")
require("ssd1327", library="micropython-steami-lib")
require("apds9960", library="micropython-steami-lib")
require("bq27441", library="micropython-steami-lib")
require("hts221", library="micropython-steami-lib")
require("vl53l1x", library="micropython-steami-lib")
require("lis2mdl", library="micropython-steami-lib")
require("wsen-hids", library="micropython-steami-lib")
require("wsen-pads", library="micropython-steami-lib")
require("ism330dl", library="micropython-steami-lib")
require("daplink_bridge", library="micropython-steami-lib")
require("daplink_flash", library="micropython-steami-lib")
require("steami_config", library="micropython-steami-lib")
require("bme280", library="micropython-steami-lib")
