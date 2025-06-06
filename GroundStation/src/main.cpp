#include "connectionwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "GroundStation_" + QLocale(locale).name();
        if (translator.load(":/Translations/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w(&translator, &a);
    w.show();
    return a.exec();
}
