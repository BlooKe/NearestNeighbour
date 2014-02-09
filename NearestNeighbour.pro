TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    include

SOURCES += src/main.c \
    src/fileread.c \
    src/calculations.c
    

HEADERS += \
    include/definitions.h \
    include/fileread.h \
    include/typedefs.h \
    include/calculations.h
    
OTHER_FILES += \
    LICENSE \
    README.md \
    data.txt
