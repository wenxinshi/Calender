#-------------------------------------------------
#
# Project created by QtCreator 2013-03-31T12:13:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
TEMPLATE = app


SOURCES += main.cpp\
        windowCalendar.cpp \
    cellTag.cpp \
    Calendar/tinyxmlparser.cpp \
    Calendar/tinyxmlerror.cpp \
    Calendar/tinyxml.cpp \
    Calendar/tinystr.cpp


HEADERS  += windowCalendar.h \
    cellTag.h \
    Calendar/XMLWriter.h \
    Calendar/UserDefinedCalParser.h \
    Calendar/tinyxml.h \
    Calendar/tinystr.h \
    Calendar/Time.h \
    Calendar/SortBySubject.h \
    Calendar/SortByStartTime.h \
    Calendar/SortByLocation.h \
    Calendar/SortByEndTime.h \
    Calendar/SortByDescription.h \
    Calendar/Sort.h \
    Calendar/GoogleCalParser.h \
    Calendar/FilterBySubject.h \
    Calendar/FilterByStartTime.h \
    Calendar/FilterByLocation.h \
    Calendar/FilterByEndTime.h \
    Calendar/FilterByDescription.h \
    Calendar/Filter.h \
    Calendar/Event.h \
    Calendar/DukeCalParser.h \
    Calendar/DukeBasketBallCalParser.h \
    Calendar/CalParser.h \
    Calendar/Calendar.h

OTHER_FILES += \
    Calendar/data/output.xml \
    Calendar/data/NFL.xml \
    Calendar/data/googlecal.xml \
    Calendar/data/dukecal.xml \
    Calendar/data/DukeBasketBall.xml \
    Calendar/data/.DS_Store \
    ../../../Desktop/two-palms-and-turquoise-sea-beach-wallpaper.jpg

RESOURCES += \
    resource.qrc





