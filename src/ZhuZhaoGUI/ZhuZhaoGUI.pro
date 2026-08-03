#添加依赖的QT，主要包含core gui widgets
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#声明C++语言规范版本
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

#添加源文件和头文件
SOURCES += \
    ZZConfigWidget/ZZConfigWidget.cpp \
    ZZConfigWidget/ZZOneParamWidget.cpp \
    ZZConfigWidget/ZZProcessThread.cpp \
    ZZListener.cpp \
    ZZLogWidget/ZZLogMessage.cpp \
    ZZLogWidget/ZZLogWidget.cpp \
    ZZThumWidget/HThumbnailList.cpp \
    ZZThumWidget/LitImgItemWidget.cpp \
    ZZThumWidget/VThumbnailList.cpp \
    ZZViewWidget/CustomGraphicsView.cpp \
    ZZViewWidget/CustomImageItem.cpp \
    ZZViewWidget/CustomImageView.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    ZZConfigWidget/ImageConvert.h \
    ZZConfigWidget/ZZConfigWidget.h \
    ZZConfigWidget/ZZOneParamWidget.h \
    ZZConfigWidget/ZZProcessThread.h \
    ZZListener.h \
    ZZLogWidget/ZZLogMessage.h \
    ZZLogWidget/ZZLogWidget.h \
    ZZThumWidget/HThumbnailList.h \
    ZZThumWidget/LitImgItemWidget.h \
    ZZThumWidget/VThumbnailList.h \
    ZZViewWidget/CustomGraphicsView.h \
    ZZViewWidget/CustomImageItem.h \
    ZZViewWidget/CustomImageView.h

#添加资源文件
RESOURCES += \
    ZhuzhaoGuiRes.qrc

#配置opencv库
INCLUDEPATH += D:/OPENCV/opencv/build/include
Debug: {
LIBS += -lD:/OPENCV/opencv/build/x64/vc15/lib/opencv_world460d
}
Release: {
LIBS += -lD:/OPENCV/opencv/build/x64/vc15/lib/opencv_world460
}

#配置我们自己实现的光度立体算法库
INCLUDEPATH += $$PWD/../PhotometricStereo #include头文件
Debug: {
    LIBS += -l$$PWD/../bin/PhotometricStereoDLL #动态库：lib和dll
}
Release: {
    LIBS += -l$$PWD/../bin/PhotometricStereoDLL
}

#配置生成路径，将我们的结果输出产物输出到bin文件夹内，方便管理
CONFIG(debug, debug|release){
    DESTDIR = $$PWD/../bin
}else{
    DESTDIR = $$PWD/../bin
}

#设置图标
RC_ICONS = zhuzhao_logo.ico

#添加翻译文件
TRANSLATIONS += language_ch.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
