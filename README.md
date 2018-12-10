# rosserial_thruster_controller

# How to make
#### 1. Install [rosserial_mbed](http://wiki.ros.org/rosserial_mbed/Tutorials/rosserial_mbed%20Setup)
#### 2. Make
```bash
$ cd <directory>/motor_driver_left
$ make
$ cd ../motor_driver_right
$ make
```
#### 3. Copy <each motor_driver_{hogehoge}>/LPC1768/motor_driver_{hogehoge}.bin to mbeds.
An LPC 1768 folder is created in each directory.

# branch model

#### /master
branch for competitions (all nodes should be work completely)

#### /devel/feature/(feature_name)
branch for developing each feature

#### /devel/fix/(bug_name)
branch for fixing each bug

/devel/feature/(feature_name) and /devel/fix/(bug_name) feature branch merged to /master branch
