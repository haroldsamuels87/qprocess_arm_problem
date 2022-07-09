
#include <QDebug>
#include <QProcess>
#include <unistd.h>

int main(int argc, char *argv[])
{
    qInfo("Hi This is qprocess simultation\n");
#if 0
    QProcess::execute("/usr/bin/ls /");
#else 
	
    QProcess ls;
    ls.start("/usr/bin/ls", QStringList() << "/");
    ls.waitForFinished();
    qInfo() << "ls.readAllStandardOutput:"<<ls.readAllStandardOutput() ;
    qInfo() << "ls.readAllStandardError:"<<ls.readAllStandardError();
    
#endif 
    sleep(10);
    
    return 0;
    
}
