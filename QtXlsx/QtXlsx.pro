#-------------------------------------------------
# QtXlsx static library project
#  see version.txt 
#-------------------------------------------------
# .Xlsx file wirter for Qt5
# original source code from Debao Zhang
# Copyright (C) 2013-2014 Debao Zhang <hello@debao.me>
# http://qtxlsx.debao.me/
# MIT LIcense
#-------------------------------------------------
# 
# QMAKE_TARGET_COMPANY = "Debao Zhang"
# QMAKE_TARGET_COPYRIGHT = "Copyright (C) 2013-2014 Debao Zhang <hello@debao.me>"
# QMAKE_TARGET_DESCRIPTION = ".Xlsx file wirter for Qt5"

TARGET = QtXlsx
TEMPLATE = lib
CONFIG += staticlib

QT += core gui gui-private
!build_xlsx_lib:DEFINES += XLSX_NO_LIB

CONFIG += build_xlsx_lib

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    ./xlsxdocpropscore_p.h \
    ./xlsxdocpropsapp_p.h \
    ./xlsxrelationships_p.h \
    ./xlsxutility_p.h \
    ./xlsxsharedstrings_p.h \
    ./xlsxcontenttypes_p.h \
    ./xlsxtheme_p.h \
    ./xlsxformat.h \
    ./xlsxworkbook.h \
    ./xlsxstyles_p.h \
    ./xlsxworksheet.h \
    ./xlsxzipwriter_p.h \
    ./xlsxworkbook_p.h \
    ./xlsxworksheet_p.h \
    ./xlsxformat_p.h \
    ./xlsxglobal.h \
    ./xlsxdrawing_p.h \
    ./xlsxzipreader_p.h \
    ./xlsxdocument.h \
    ./xlsxdocument_p.h \
    ./xlsxcell.h \
    ./xlsxcell_p.h \
    ./xlsxdatavalidation.h \
    ./xlsxdatavalidation_p.h \
    ./xlsxcellrange.h \
    ./xlsxrichstring_p.h \
    ./xlsxrichstring.h \
    ./xlsxconditionalformatting.h \
    ./xlsxconditionalformatting_p.h \
    ./xlsxcolor_p.h \
    ./xlsxnumformatparser_p.h

SOURCES += \
    ./xlsxdocpropscore.cpp \
    ./xlsxdocpropsapp.cpp \
    ./xlsxrelationships.cpp \
    ./xlsxutility.cpp \
    ./xlsxsharedstrings.cpp \
    ./xlsxcontenttypes.cpp \
    ./xlsxtheme.cpp \
    ./xlsxformat.cpp \
    ./xlsxstyles.cpp \
    ./xlsxworkbook.cpp \
    ./xlsxworksheet.cpp \
    ./xlsxzipwriter.cpp \
    ./xlsxdrawing.cpp \
    ./xlsxzipreader.cpp \
    ./xlsxdocument.cpp \
    ./xlsxcell.cpp \
    ./xlsxdatavalidation.cpp \
    ./xlsxcellrange.cpp \
    ./xlsxrichstring.cpp \
    ./xlsxconditionalformatting.cpp \
    ./xlsxcolor.cpp \
    ./xlsxnumformatparser.cpp

OTHER_FILES += \
    ./version.txt


