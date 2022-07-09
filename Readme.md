This repository reproduces a problem mentioned in [this forum post](https://forum.qt.io/topic/137740/qprocess-docker-problem)


# Initial setup
```
sudo apt-get install qemu binfmt-support qemu-user-static # Install the qemu packages
docker run --rm --privileged multiarch/qemu-user-static --reset -p yes # This step will execute the registering scripts
```
# Building Image
Change directory to repository root folder `cd <REPO_PATH>` and then enter:

```
docker build . -f Dockerfile.ubuntu.armv7 -t arm_test:latest
```

# Runnning and reproducing error
To reproduce error, run these commands:
```
docker run --platform linux/arm/v7 -it --rm -v $(pwd)/src:/problematic_src arm_test:latest /bin/bash
cd /problematic_src
mkdir -p build 
cd build 
cmake ..
make -j$(nproc) && ./qt_process_arm
```
