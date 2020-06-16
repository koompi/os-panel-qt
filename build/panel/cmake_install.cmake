# Install script for directory: /home/vathana/DriveD/vathana/project/koompi-os-panel/panel

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_ar.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_arn.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_ast.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_ca.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_cs.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_cy.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_da.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_de.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_el.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_en_GB.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_eo.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_es.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_es_UY.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_es_VE.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_eu.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_fa.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_fi.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_fr.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_gl.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_he.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_hr.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_hu.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_ia.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_id.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_it.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_ja.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_ko.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_lt.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_nb_NO.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_nl.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_pl.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_pt.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_pt_BR.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_ro_RO.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_ru.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_sk_SK.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_sl.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_sr@latin.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_sr_BA.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_sr_RS.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_sv.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_th_TH.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_tr.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_uk.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_zh_CN.qm;/usr/local/share/lxqt/translations/lxqt-panel/lxqt-panel_zh_TW.qm")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/lxqt/translations/lxqt-panel" TYPE FILE FILES
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_ar.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_arn.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_ast.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_ca.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_cs.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_cy.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_da.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_de.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_el.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_en_GB.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_eo.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_es.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_es_UY.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_es_VE.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_eu.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_fa.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_fi.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_fr.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_gl.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_he.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_hr.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_hu.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_ia.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_id.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_it.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_ja.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_ko.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_lt.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_nb_NO.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_nl.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_pl.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_pt.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_pt_BR.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_ro_RO.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_ru.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_sk_SK.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_sl.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_sr@latin.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_sr_BA.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_sr_RS.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_sv.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_th_TH.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_tr.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_uk.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_zh_CN.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel_zh_TW.qm"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lxqt-panel" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lxqt-panel")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lxqt-panel"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/panel/lxqt-panel")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lxqt-panel" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lxqt-panel")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lxqt-panel"
         OLD_RPATH "/usr/local/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lxqt-panel")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lxqt" TYPE FILE FILES "/home/vathana/DriveD/vathana/project/koompi-os-panel/panel/resources/panel.conf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lxqt" TYPE FILE FILES
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/panel/lxqtpanelglobals.h"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/panel/pluginsettings.h"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/panel/ilxqtpanelplugin.h"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/panel/ilxqtpanel.h"
    )
endif()

