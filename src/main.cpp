
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
    QObject::connect(&ls, &QProcess::stateChanged, [=](QProcess::ProcessState state) 
    { 
        qInfo() << "stateChanged:" << state << Qt::endl; 
    });
    
    QObject::connect(&ls, &QProcess::errorOccurred, [=](QProcess::ProcessError error) 
    { 
    	qInfo() << "errorOccurred:" << error << Qt::endl; 
    });

    QObject::connect(&ls, &QProcess::started, [=]() 
    { 
    	qInfo() << "Process started" << Qt::endl; 
    });

    QObject::connect(&ls, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
    [=](int exitCode, QProcess::ExitStatus exitStatus){
    	qInfo() << "Process finished: code: " << exitCode << "status: "<< exitStatus << Qt::endl; 
    });

    QObject::connect(&ls, &QProcess::readyReadStandardError, [&]() 
    { 
    	qInfo() << "stderr:" << ls.readAllStandardError() << Qt::endl; 
    });

    QObject::connect(&ls, &QProcess::readyReadStandardOutput, [&]() 
    { 
    	qInfo() << "stdout:" << ls.readAllStandardOutput() << Qt::endl; 
    });

    // ls.start("/usr/bin/ls", QStringList() << "/");
    // ls.start("/usr/bin/sleep", QStringList() << "10");
    ls.start("/usr/bin/sh", QStringList() << "-c" << "/usr/bin/ls / > /tmp/output 2>&1");

#endif 
    
    return app.exec();
    
}
