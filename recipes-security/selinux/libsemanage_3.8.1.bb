SUMMARY = "SELinux binary policy manipulation library"
DESCRIPTION = "libsemanage provides an API for the manipulation of SELinux binary policies. \
It is used by checkpolicy (the policy compiler) and similar tools, as well \
as by programs like load_policy that need to perform specific transformations \
on binary policies such as customizing policy boolean settings."
SECTION = "base"
LICENSE = "LGPL-2.1-or-later"
LIC_FILES_CHKSUM = "file://${S}/LICENSE;md5=03068f550c635f6520e0f0252da412fc"

require selinux_common.inc

inherit lib_package python3native

SRC_URI += "file://libsemanage-Fix-execve-segfaults-on-Ubuntu.patch \
            file://libsemanage-allow-to-disable-audit-support.patch \
            file://libsemanage-disable-expand-check-on-policy-load.patch \
           "

DEPENDS = "libsepol libselinux python3 bison-native swig-native"

DEPENDS:append:class-target = " audit"

EXTRA_OEMAKE:class-native = "DISABLE_AUDIT=y"

PACKAGES =+ "${PN}-python"

# For /usr/libexec/selinux/semanage_migrate_store
RDEPENDS:${PN}-python = "python3-core"

FILES:${PN}-python = "${PYTHON_SITEPACKAGES_DIR}/* \
                      ${libexecdir}/selinux/semanage_migrate_store"
FILES:${PN}-dbg += "${PYTHON_SITEPACKAGES_DIR}/.debug/*"
FILES:${PN} += "${libexecdir}"

do_compile:append() {
    oe_runmake pywrap \
        PYLIBVER='python${PYTHON_BASEVERSION}' \
        PYINC='-I${STAGING_INCDIR}/${PYLIBVER}' \
        PYLIBS='-L${STAGING_LIBDIR}/${PYLIBVER} -l${PYLIBVER}'
}

do_install:append() {
    oe_runmake install-pywrap \
        DESTDIR=${D} \
        PYCEXT='.so' \
        PYLIBVER='python${PYTHON_BASEVERSION}' \
        PYTHONLIBDIR='${PYTHON_SITEPACKAGES_DIR}'

    # Update "policy-version" for semanage.conf
    sed -i 's/^#\s*\(policy-version\s*=\).*$/\1 33/' \
        ${D}/etc/selinux/semanage.conf
}

BBCLASSEXTEND = "native"
