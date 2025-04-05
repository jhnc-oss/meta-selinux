PV = "2.20250213+git"

SRC_URI = "git://github.com/SELinuxProject/refpolicy.git;protocol=https;branch=main;name=refpolicy;destsuffix=refpolicy"

SRCREV_refpolicy = "353352e31f0d301e6c49db79a753c7d0179b46c2"

UPSTREAM_CHECK_GITTAGREGEX = "RELEASE_(?P<pver>\d+_\d+)"

FILESEXTRAPATHS:prepend := "${THISDIR}/refpolicy:"

include refpolicy_common.inc
