# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = EmployeGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += EmployeCommisInterface.cpp EmployeHoraireInterface.cpp EmployeInterface.cpp EmployePatronInterface.cpp main.cpp
HEADERS += EmployeCommisInterface.h EmployeHoraireInterface.h EmployeInterface.h EmployePatronInterface.h
FORMS += EmployeCommisInterface.ui EmployeHoraireInterface.ui EmployeInterface.ui EmployePatronInterface.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++-10
DEFINES += 
INCLUDEPATH += ../Source 
LIBS += ../Source/dist/Debug/GNU-Linux/libsource.a  
