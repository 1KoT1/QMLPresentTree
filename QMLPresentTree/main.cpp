#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "model.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Model m;
    QtQuick2ApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("programmModel", &m);
    viewer.setMainQmlFile(QStringLiteral("qml/QMLPresentTree/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
