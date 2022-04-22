# quori_base_embedded
Basic code for diff and holo functionality on Quori base using Mbed.

## Instructions to flash code
1)Connect mbed to computer
2) Download the .bin file for this build
3) paste the .bin folder into the mbed device. You may need to update your driver to do this. The device firmware may need to be updated. See "Nucleo ST-LINK/V2 driver installation and firmware upgrade" from https://os.mbed.com/platforms/ST-Nucleo-F303K8/ for more information

## Instructions to export code from online complier
1) Download as a zip folder
2) Delete ".mbed" " GettingStarted.htm", "mbed.bld", and "mbed_config.h"

## ROS Information
The [quori_ros](https://github.com/Quori-ROS/quori_ros) package is designed to control the base. If you do not want to use [quori_ros](https://github.com/Quori-ROS/quori_ros) you may be interested in the information below.
The base expects commands to be sent at 50-100Hz. If commands are not recieved within 10Hz the base will coast as a safety measure.
A diagram of the system will be added soon.
### Topics

#### Base Commands
  - `/quori/base/cmd_holo: Vector3` - Holonomic Control of the top plate of the base as with the Vector3 message X,Y,Z being mapped to X(m/s),Y(m/s),Theta(rads/s) of the base.
  - `/quori/base/cmd_diff: Vector3` - Differential Control of the of the base as with the Vector3 message X,Y,Z being mapped to the Right Motor(m/s),Left Motor(m/s),Top Plate Motor(degrees/s) of the base.
  - `/quori/base/cmd_offset: Float32` - This allows the zero position, and thus the heading of the top plate in holonomic mode, to be set. The offset is global and in units of percent revolution from 0.0 to 1.0
  - `/quori/base/set_M1Gains: Vector3` - PID gains for the right motor. It is not reccomended that you alter this. The value will not be saved when power is disconnedted from the microcontroller.
  - `/quori/base/set_M2Gains: Vector3` - PID gains for the left motor. It is not reccomended that you alter this. The value will not be saved when power is disconnedted from the microcontroller.
  - `/quori/base/set_MTGains: Vector3` - PID gains for the top plate motor. It is not reccomended that you alter this. The value will not be saved when power is disconnedted from the microcontroller.

#### Base State Information
  - `/quori/base/vel_status: Vector3` - Velocity of the right wheel(m/s), left wheel(m/s), and top plate(should be rad/s in holonomic and deg/s in differential mode).
  - `/quori/base/loop_error: Int32` - the ellapsed time for the main loop as measured in microseconds. 
  - `/quori/base/desired_vel_status: Vector3` - Desired Motor velocities as directly recieved (in the differential drive case) or calculated (in the holonomic case)
  - `/quori/base/pos_status: Float32` - Orientation of the top plate measure as percent of a revolution, i.e from 0 to 1

