AUTHOR = "Intel® RealSense™"
HOMEPAGE = "https://github.com/IntelRealSense/librealsense"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=a1692f06943fa281fd047a22d7e10800"

inherit cmake pkgconfig

DEPENDS = "\
    libusb1 \
    udev \
"

RRECOMMENDS:${PN} += "kernel-module-uvcvideo"

SRC_URI = "git://github.com/realsenseai/librealsense.git;protocol=https;branch=master;rev=5af97a58423ec11822e8d951d37d9c6945a09a24"

EXTRA_OECMAKE = " \
    -DBUILD_UNIT_TESTS:BOOL=OFF \
    -DBUILD_WITH_OPENMP:BOOL=OFF \
    -DCHECK_FOR_UPDATES:BOOL=OFF \
"

PACKAGECONFIG ??= ""
PACKAGECONFIG[rsusb] = "-DFORCE_RSUSB_BACKEND:BOOL=ON,-DFORCE_RSUSB_BACKEND:BOOL=OFF"

