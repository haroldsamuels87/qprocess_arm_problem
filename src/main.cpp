
#include <QDebug>
#include <QProcess>
#include <unistd.h>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qInfo("Hi This is qprocess simultation\n");
#if 0
    QProcess::execute("/usr/bin/ls /");
#else 
	
    QProcess ls;
    ls.start("/usr/bin/ls", QStringList() << "/");
    //ls.start("/usr/bin/sh", QStringList() << "-c" << "/usr/bin/ls /");

    QObject::connect(&ls, &QProcess::stateChanged, [=](QProcess::ProcessState state) 
    { 
        qInfo() << "state:" << state << Qt::endl; 
    });
    
    QObject::connect(&ls, &QProcess::errorOccurred, [=](QProcess::ProcessError error) 
    { 
    	qInfo() << "error:" << error << Qt::endl; 
    });

    ls.waitForFinished();
    qInfo() << "ls.readAllStandardOutput:"<<ls.readAllStandardOutput() ;
    qInfo() << "ls.readAllStandardError:"<<ls.readAllStandardError();
    
#endif 
    sleep(10);
    
    return app.exec();
    
}
