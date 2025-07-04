SECTION = "admin"
LICENSE = "GPL-2.0-only"

LIC_FILES_CHKSUM = "file://${S}/COPYING;md5=393a5ca445f6965873eca0259a17f833"

PROVIDES = "virtual/refpolicy"
RPROVIDES:${PN} = "refpolicy"

# Specific config files for Poky
SRC_URI += "file://customizable_types \
            file://setrans-mls.conf \
            file://setrans-mcs.conf \
           "

# Base patches applied to all Yocto-based platforms.  Your own version of
# refpolicy should provide a version of these and place them in your own
# refpolicy-${PV} directory.
SRC_URI += " \
        file://0001-fc-subs-volatile-alias-common-var-volatile-paths.patch \
        file://0002-fc-subs-busybox-set-aliases-for-bin-sbin-and-usr.patch \
        file://0003-fc-hostname-apply-policy-to-common-yocto-hostname-al.patch \
        file://0004-fc-bash-apply-usr-bin-bash-context-to-bin-bash.bash.patch \
        file://0005-fc-resolv.conf-label-resolv.conf-in-var-run-properly.patch \
        file://0006-fc-login-apply-login-context-to-login.shadow.patch \
        file://0007-fc-hwclock-add-hwclock-alternatives.patch \
        file://0008-fc-dmesg-apply-policy-to-dmesg-alternatives.patch \
        file://0009-fc-ssh-apply-policy-to-ssh-alternatives.patch \
        file://0010-fc-sysnetwork-apply-policy-to-network-commands-alter.patch \
        file://0011-fc-rpm-apply-rpm_exec-policy-to-cpio-binaries.patch \
        file://0012-fc-su-apply-policy-to-su-alternatives.patch \
        file://0013-fc-fstools-fix-real-path-for-fstools.patch \
        file://0014-fc-init-fix-update-alternatives-for-sysvinit.patch \
        file://0015-fc-brctl-apply-policy-to-brctl-alternatives.patch \
        file://0016-fc-corecommands-apply-policy-to-nologin-alternatives.patch \
        file://0017-fc-locallogin-apply-policy-to-sulogin-alternatives.patch \
        file://0018-fc-ntp-apply-policy-to-ntpd-alternatives.patch \
        file://0019-fc-kerberos-apply-policy-to-kerberos-alternatives.patch \
        file://0020-fc-ldap-apply-policy-to-ldap-alternatives.patch \
        file://0021-fc-postgresql-apply-policy-to-postgresql-alternative.patch \
        file://0022-fc-screen-apply-policy-to-screen-alternatives.patch \
        file://0023-fc-usermanage-apply-policy-to-usermanage-alternative.patch \
        file://0024-fc-getty-add-file-context-to-start_getty.patch \
        file://0025-fc-vlock-apply-policy-to-vlock-alternatives.patch \
        file://0026-fc-add-fcontext-for-init-scripts-and-systemd-service.patch \
        file://0027-file_contexts.subs_dist-set-aliase-for-root-director.patch \
        file://0028-policy-modules-system-logging-add-rules-for-the-syml.patch \
        file://0029-policy-modules-system-logging-add-rules-for-syslogd-.patch \
        file://0030-policy-modules-kernel-files-add-rules-for-the-symlin.patch \
        file://0031-policy-modules-system-logging-fix-auditd-startup-fai.patch \
        file://0032-policy-modules-kernel-terminal-don-t-audit-tty_devic.patch \
        file://0033-policy-modules-system-systemd-enable-support-for-sys.patch \
        file://0034-policy-modules-system-logging-allow-systemd-tmpfiles.patch \
        file://0035-policy-modules-roles-sysadm-allow-sysadm-to-use-init.patch \
        file://0036-policy-modules-system-systemd-systemd-user-fixes.patch \
        file://0037-policy-modules-system-logging-grant-getpcap-capabili.patch \
        file://0038-policy-modules-system-allow-services-to-read-tmpfs-u.patch \
        file://0039-policy-modules-kernel-domain-allow-all-domains-to-co.patch \
        file://0040-systemd-allow-systemd-logind-to-inherit-fds.patch \
        file://0041-systemd-allow-systemd-tmpfiles-to-read-bin_t-symlink.patch \
        file://0042-policy-modules-system-mount-make-mount_t-domain-MLS-.patch \
        file://0043-policy-modules-roles-sysadm-MLS-sysadm-rw-to-clearan.patch \
        file://0044-policy-modules-services-rpc-make-nfsd_t-domain-MLS-t.patch \
        file://0045-policy-modules-admin-dmesg-make-dmesg_t-MLS-trusted-.patch \
        file://0046-policy-modules-kernel-kernel-make-kernel_t-MLS-trust.patch \
        file://0047-policy-modules-system-init-make-init_t-MLS-trusted-f.patch \
        file://0048-policy-modules-system-systemd-make-systemd-tmpfiles_.patch \
        file://0049-policy-modules-system-systemd-systemd-make-systemd_-.patch \
        file://0050-policy-modules-system-logging-add-the-syslogd_t-to-t.patch \
        file://0051-policy-modules-system-init-make-init_t-MLS-trusted-f.patch \
        file://0052-policy-modules-system-init-all-init_t-to-read-any-le.patch \
        file://0053-policy-modules-system-logging-allow-auditd_t-to-writ.patch \
        file://0054-policy-modules-kernel-kernel-make-kernel_t-MLS-trust.patch \
        file://0055-policy-modules-system-setrans-allow-setrans_t-use-fd.patch \
        file://0056-policy-modules-system-systemd-make-_systemd_t-MLS-tr.patch \
        file://0057-policy-modules-system-logging-make-syslogd_runtime_t.patch \
        "

S = "${UNPACKDIR}/refpolicy"

CONFFILES:${PN} = "${sysconfdir}/selinux/config"
FILES:${PN} += " \
    ${sysconfdir}/selinux/${POLICY_NAME}/ \
    ${datadir}/selinux/${POLICY_NAME}/*.pp \
    ${localstatedir}/lib/selinux/${POLICY_NAME}/ \
    "
FILES:${PN}-dev =+ " \
    ${datadir}/selinux/${POLICY_NAME}/include/ \
    ${sysconfdir}/selinux/sepolgen.conf \
    "

EXTRANATIVEPATH += "bzip2-native"

DEPENDS = "bzip2-replacement-native checkpolicy-native policycoreutils-native semodule-utils-native m4-native"

RDEPENDS:${PN}-dev = " \
    python3-core \
    "

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit python3native

PARALLEL_MAKE = ""

DEFAULT_ENFORCING ??= "enforcing"

POLICY_NAME ?= "${POLICY_TYPE}"
POLICY_DISTRO ?= "debian"
POLICY_UBAC ?= "n"
POLICY_UNK_PERMS ?= "allow"
POLICY_DIRECT_INITRC ?= "y"
POLICY_SYSTEMD ?= "${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'y', 'n', d)}"
POLICY_MONOLITHIC ?= "n"
POLICY_CUSTOM_BUILDOPT ?= ""
POLICY_QUIET ?= "y"
POLICY_MLS_SENS ?= "16"
POLICY_MLS_CATS ?= "1024"
POLICY_MCS_CATS ?= "1024"

EXTRA_OEMAKE = "NAME=${POLICY_NAME} \
    TYPE=${POLICY_TYPE} \
    DISTRO=${POLICY_DISTRO} \
    UBAC=${POLICY_UBAC} \
    UNK_PERMS=${POLICY_UNK_PERMS} \
    DIRECT_INITRC=${POLICY_DIRECT_INITRC} \
    SYSTEMD=${POLICY_SYSTEMD} \
    MONOLITHIC=${POLICY_MONOLITHIC} \
    CUSTOM_BUILDOPT=${POLICY_CUSTOM_BUILDOPT} \
    QUIET=${POLICY_QUIET} \
    MLS_SENS=${POLICY_MLS_SENS} \
    MLS_CATS=${POLICY_MLS_CATS} \
    MCS_CATS=${POLICY_MCS_CATS}"

EXTRA_OEMAKE += "tc_usrbindir=${STAGING_BINDIR_NATIVE}"
EXTRA_OEMAKE += "OUTPUT_POLICY=`${STAGING_BINDIR_NATIVE}/checkpolicy -V | cut -d' ' -f1`"
EXTRA_OEMAKE += "CC='${BUILD_CC}' CFLAGS='${BUILD_CFLAGS}' PYTHON='${PYTHON}'"

python __anonymous() {
    import re

    # Make sure DEFAULT_ENFORCING is something sane
    if not re.match('^(enforcing|permissive|disabled)$',
                    d.getVar('DEFAULT_ENFORCING'),
                    flags=0):
        d.setVar('DEFAULT_ENFORCING', 'permissive')
}

disable_policy_modules() {
    for module in ${PURGE_POLICY_MODULES} ; do
        sed -i "s/^\(\<${module}\>\) *= *.*$/\1 = off/" ${S}/policy/modules.conf
    done
}

do_compile() {
    if [ -f "${WORKDIR}/modules.conf" ] ; then
        cp -f ${WORKDIR}/modules.conf ${S}/policy/modules.conf
    fi
    oe_runmake conf
    disable_policy_modules
    oe_runmake policy
}

prepare_policy_store() {
    oe_runmake 'DESTDIR=${D}' 'prefix=${D}${prefix}' install
    POL_PRIORITY=100
    POL_SRC=${D}${datadir}/selinux/${POLICY_NAME}
    POL_STORE=${D}${localstatedir}/lib/selinux/${POLICY_NAME}
    POL_ACTIVE_MODS=${POL_STORE}/active/modules/${POL_PRIORITY}

    # Prepare to create policy store
    mkdir -p ${POL_STORE}
    mkdir -p ${POL_ACTIVE_MODS}

    # Get hll type from suffix on base policy module
    HLL_TYPE=$(echo ${POL_SRC}/base.* | awk -F . '{if (NF>1) {print $NF}}')
    HLL_BIN=${STAGING_DIR_NATIVE}${prefix}/libexec/selinux/hll/${HLL_TYPE}

    for i in ${POL_SRC}/*.${HLL_TYPE}; do
        MOD_NAME=$(basename $i | sed "s/\.${HLL_TYPE}$//")
        MOD_DIR=${POL_ACTIVE_MODS}/${MOD_NAME}
        mkdir -p ${MOD_DIR}
        echo -n "${HLL_TYPE}" > ${MOD_DIR}/lang_ext
        if ! bzip2 -t $i >/dev/null 2>&1; then
            ${HLL_BIN} $i | bzip2 --stdout > ${MOD_DIR}/cil
            bzip2 -f $i && mv -f $i.bz2 $i
        else
            bunzip2 --stdout $i | \
                ${HLL_BIN} | \
                bzip2 --stdout > ${MOD_DIR}/cil
        fi
        cp $i ${MOD_DIR}/hll
    done
}

rebuild_policy() {
    cat <<-EOF > ${D}${sysconfdir}/selinux/semanage.conf
module-store = direct
[setfiles]
path = ${STAGING_DIR_NATIVE}${base_sbindir_native}/setfiles
args = -q -c \$@ \$<
[end]
[sefcontext_compile]
path = ${STAGING_DIR_NATIVE}${sbindir_native}/sefcontext_compile
args = \$@
[end]

policy-version = 33
EOF

    # Create policy store and build the policy
    semodule -p ${D} -s ${POLICY_NAME} -n -B
    rm -f ${D}${sysconfdir}/selinux/semanage.conf
    # No need to leave final dir created by semanage laying around
    rm -rf ${D}${localstatedir}/lib/selinux/final
}

install_misc_files() {
    cat ${UNPACKDIR}/customizable_types >> \
        ${D}${sysconfdir}/selinux/${POLICY_NAME}/contexts/customizable_types

    # Install setrans.conf for mls/mcs policy
    if [ -f ${UNPACKDIR}/setrans-${POLICY_TYPE}.conf ]; then
        install -m 0644 ${UNPACKDIR}/setrans-${POLICY_TYPE}.conf \
            ${D}${sysconfdir}/selinux/${POLICY_NAME}/setrans.conf
    fi

    # Install policy headers
    oe_runmake 'DESTDIR=${D}' 'prefix=${D}${prefix}' install-headers
}

install_config() {
    echo "\
# This file controls the state of SELinux on the system.
# SELINUX= can take one of these three values:
#     enforcing - SELinux security policy is enforced.
#     permissive - SELinux prints warnings instead of enforcing.
#     disabled - No SELinux policy is loaded.
SELINUX=${DEFAULT_ENFORCING}
# SELINUXTYPE= can take one of these values:
#     minimum - Minimum Security protection.
#     standard - Standard Security protection.
#     mls - Multi Level Security protection.
#     targeted - Targeted processes are protected.
#     mcs - Multi Category Security protection.
SELINUXTYPE=${POLICY_NAME}
" > ${WORKDIR}/config
    install -d ${D}/${sysconfdir}/selinux
    install -m 0644 ${WORKDIR}/config ${D}/${sysconfdir}/selinux/
}

do_install() {
    prepare_policy_store
    rebuild_policy
    install_misc_files
    install_config
}

do_install:append() {
    # While building policies on target, Makefile will be searched from SELINUX_DEVEL_PATH
    echo "SELINUX_DEVEL_PATH=${datadir}/selinux/${POLICY_NAME}/include" > ${D}${sysconfdir}/selinux/sepolgen.conf
}

sysroot_stage_all:append() {
    sysroot_stage_dir ${D}${sysconfdir} ${SYSROOT_DESTDIR}${sysconfdir}
}
