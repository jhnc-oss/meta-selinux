PV = "2.20240226+git"

SRC_URI = "git://github.com/SELinuxProject/refpolicy.git;protocol=https;branch=main;name=refpolicy;destsuffix=refpolicy"

SRCREV_refpolicy ?= "351a5a7f4dc959769aaa8fe47c6e77f94fe5b657"

UPSTREAM_CHECK_GITTAGREGEX = "RELEASE_(?P<pver>\d+_\d+)"

FILESEXTRAPATHS:prepend := "${THISDIR}/refpolicy:"

include refpolicy_common.inc
