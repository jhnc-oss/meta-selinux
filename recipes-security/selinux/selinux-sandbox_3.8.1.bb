SUMMARY = "Run cmd under an SELinux sandbox"
DESCRIPTION = "\
Run application within a tightly confined SELinux domain. The default \
sandbox domain only allows applications the ability to read and write \
stdin, stdout and any other file descriptors handed to it."
SECTION = "base"
LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://${S}/LICENSE;md5=393a5ca445f6965873eca0259a17f833"

require selinux_common.inc

SRC_URI += "file://sandbox-de-bashify.patch \
           "

S = "${UNPACKDIR}/${BP}/sandbox"

DEPENDS = "libselinux libcap-ng gettext-native"

RDEPENDS:${PN} = "\
        python3-core \
        python3-math \
        python3-shell \
        python3-unixadmin \
        libselinux-python \
        selinux-python \
"

FILES:${PN} += "\
        ${datadir}/sandbox/sandboxX.sh \
        ${datadir}/sandbox/start \
"
