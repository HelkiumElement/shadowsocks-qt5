#include "mainwindow.h"
#include "profiles.h"
#include "ss_process.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    /*
     * autostart if there is a valid profile activated already.
     * and don't show the mainwindow
     */
     //validate first
     //TODO: more accurate
     if (w.current_profile.local_port.toInt() > 0 &&
            w.current_profile.method != NULL &&
            w.current_profile.password != NULL &&
            w.current_profile.server != NULL &&
            w.current_profile.server_port.toInt() > 0 &&
            w.current_profile.timeout.toInt() > 0) {
        w.ss_local.start(w.current_profile);
     }
     else {//profile is not valid
        w.show();
     }

    return a.exec();
}
