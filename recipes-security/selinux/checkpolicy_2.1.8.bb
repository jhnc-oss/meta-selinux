SUMMARY = "SELinux policy compiler"
DESCRIPTION = "\
This package contains checkpolicy, the SELinux policy compiler. Only \
required for building policies. It uses libsepol to generate the \
binary policy. checkpolicy uses the static libsepol since it deals \
with low level details of the policy that have not been \
encapsulated/abstracted by a proper shared library interface."

SECTION = "base"
PR = "r1"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=393a5ca445f6965873eca0259a17f833"

include selinux_20120216.inc

SRC_URI[md5sum] = "e7b5d62873d4efc8a502b75f042f6735"
SRC_URI[sha256sum] = "8ed586fd2ccf9900f86e38b72af4aa5cc3bade35d0fa19c53ac1a3d59fe0013a"

DEPENDS += "libsepol libselinux flex-native flex"

EXTRA_OEMAKE += "PREFIX=${D}" 
EXTRA_OEMAKE += "LEX='flex'"

BBCLASSEXTEND = "native"

do_install_append() {
	install test/dismod ${D}/${bindir}/sedismod
	install test/dispol ${D}/${bindir}/sedispol
}

