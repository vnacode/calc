#QT_FOR_CONFIG += widgets
#requires(qtConfig(inputdialog))

TEMPLATE = subdirs
SUBDIRS = Calc lib

app.depends = lib

win32-g++ || linux-g++ {
    #https://gcc.gnu.org/onlinedocs/gcc-3.0/gcc_3.html#SEC13
    QMAKE_CXXFLAGS_RELEASE -= -O
    QMAKE_CXXFLAGS_RELEASE -= -O1
    QMAKE_CXXFLAGS_RELEASE -= -O2
    QMAKE_CXXFLAGS_RELEASE -= -O3
    QMAKE_CXXFLAGS_RELEASE *= -Ofast
    QMAKE_CXXFLAGS_RELEASE *= -ffast-math
}

win32-msvc* {
    #https://msdn.microsoft.com/en-us/library/19z1t1wy.aspx
    QMAKE_CXXFLAGS_RELEASE += -Ox
}

QMAKE_CFLAGS_DEBUG = -Zi -MTd

