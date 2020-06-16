# Install script for directory: /home/vathana/DriveD/vathana/project/koompi-os-panel/plugin-mainmenu

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
   "/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_ar.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_arn.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_ast.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_ca.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_cs.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_cy.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_da.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_de.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_el.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_eo.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_es.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_es_UY.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_es_VE.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_eu.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_fi.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_fr.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_gl.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_he.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_hr.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_hu.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_ia.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_id.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_it.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_ja.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_ko.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_lt.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_nb_NO.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_nl.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_pl.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_pt.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_pt_BR.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_ro_RO.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_ru.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_sk_SK.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_sl.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_sr@latin.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_sr_BA.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_sr_RS.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_th_TH.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_tr.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_uk.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_zh_CN.qm;/usr/local/share/lxqt/translations/lxqt-panel/mainmenu/mainmenu_zh_TW.qm")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/lxqt/translations/lxqt-panel/mainmenu" TYPE FILE FILES
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_ar.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_arn.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_ast.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_ca.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_cs.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_cy.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_da.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_de.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_el.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_eo.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_es.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_es_UY.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_es_VE.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_eu.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_fi.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_fr.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_gl.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_he.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_hr.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_hu.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_ia.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_id.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_it.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_ja.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_ko.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_lt.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_nb_NO.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_nl.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_pl.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_pt.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_pt_BR.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_ro_RO.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_ru.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_sk_SK.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_sl.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_sr@latin.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_sr_BA.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_sr_RS.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_th_TH.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_tr.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_uk.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_zh_CN.qm"
    "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu_zh_TW.qm"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/lxqt/lxqt-panel/mainmenu.desktop")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/lxqt/lxqt-panel" TYPE FILE FILES "/home/vathana/DriveD/vathana/project/koompi-os-panel/build/plugin-mainmenu/mainmenu.desktop")
endif()

