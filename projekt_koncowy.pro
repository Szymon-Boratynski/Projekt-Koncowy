TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        aplikacja.cpp \
        klient.cpp \
        main.cpp \
        produkt.cpp \
        zamowienie.cpp

HEADERS += \
    aplikacja.h \
    klient.h \
    produkt.h \
    zamowienie.h
