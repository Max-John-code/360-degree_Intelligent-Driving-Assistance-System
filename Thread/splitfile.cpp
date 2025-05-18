#include "splitfile.h"

SplitFile*SplitFile::splitTh = nullptr;

SplitFile *SplitFile::getInstance()
{
    if(SplitFile::splitTh == nullptr)
    {
        SplitFile::splitTh = new SplitFile;
    }
    return splitTh;
}

SplitFile::SplitFile()
{
    this->socketfd = SocketConnect::getInstance();
    this->wth = WriteThread::getInstance();
    this->rth = ReadThread::getInstance();
    connect(this->rth, SIGNAL(packLoss(FILE_LOSS)), this, SLOT(emitLossFile(FILE_LOSS)));
}

void SplitFile::setUserid(const string &value)
{
    userid = value;
}

QString SplitFile::getFilename() const
{
    return filename;
}

void SplitFile::setFilename(const QString &value)
{
    filename = value;
}

void SplitFile::appendQueue(string file)
{
    this->fileQueue.enqueue(file);
}

int SplitFile::QueueSize()
{
    return this->fileQueue.size();
}

vector<string> SplitFile::split(string str)
{
    int start=0, end=0, size=str.size();
    vector<string> result;
    for (end=0; end<size; ++end) {
        if (str[end]==',') {
            if (end>start) { // Avoid the multi-' ' situation
                string newStr=str.substr(start,end-start);
                result.push_back(newStr);
            }
            start=end+1;
        }
    }
    if (end>start) {
        string newStr=str.substr(start,end-start);
        result.push_back(newStr);
    }
    return result;
}

void SplitFile::fileMerge(QString path)
{
    list<string> fileList;
    struct dirent* mydir;
    int res = 0;
    QString readDir = path + "/packets";
    QString writefile = path + "/" + "transmit.jpg";
    DIR * Rdir = opendir(readDir.toStdString().c_str());
    while ((mydir = readdir(Rdir))!= NULL)
    {
        if(mydir->d_type == DT_DIR)
            continue;
        else if(mydir->d_type == DT_REG)
        {
            qDebug() << "mydir->d_name" << mydir->d_name;
            fileList.push_back((readDir).toStdString() + "/" + mydir->d_name);
            qDebug() << readDir + "/" + mydir->d_name;
        }
    }
    closedir(Rdir);
    //开始排序
    fileList.sort([](const string& a, const string& b)
    {
        size_t posA = a.find('.', 16);
        size_t posB = b.find('.', 16);
        return atoi(a.substr(16, posA - 16).c_str()) < atoi(b.substr(16, posB - 16).c_str());
    });
    //打开准备写入的文件
    this->wfd = open(writefile.toStdString().c_str(), O_WRONLY | O_CREAT, 0777);
    qDebug() << "sort------------------------";
    for (list<string>::iterator i = fileList.begin();i!=fileList.end();i++)
    {
        qDebug() << QString::fromStdString(*i);
        this->rfd = open((*i).c_str(), O_RDONLY);
        while ((res = read(this->rfd, this->buf, sizeof (this->buf)))!=0)
        {
            write(this->wfd, this->buf, res);
            bzero(this->buf, sizeof (this->buf));
        }
    }
    close(this->wfd);
    close(this->rfd);
}

void SplitFile::run()
{
    while (true)
    {
        if(this->fileQueue.size()>0)
        {

            //丢包没有处理完，flag 等于 0
            this->lossFlag = 0;
            string filename = this->fileQueue.dequeue();
            cout << "Queue filename = " << filename ;
            strcpy(this->fileinfo.filename, filename.c_str());

            int res = 0;
            int index = 0;
            string readfile = "./Photo/" +filename;
            qDebug() << "readfile = " << QString::fromStdString(readfile);
            this->rfd = open(readfile.c_str(), O_RDONLY);
            //先计算文件碎片总数
            std::ifstream file(readfile.c_str(), std::ios::binary | std::ios::ate);
            std::streampos size = file.tellg();
            qDebug () << "size = " << size ;
            file.close();
            strcpy(this->fileinfo.account, userid.c_str());
            qDebug() << "fileinfo.account = " << fileinfo.account;
            this->fileinfo.fileNum = (static_cast<int>(size) / 1000) + (static_cast<int>(size)%1000==0?0:1);
            this->fileinfo.fileLegth = static_cast<int>(size);
            qDebug() << "this->fileinfo.fileNum = " << this->fileinfo.fileNum;

            strcpy(this->fileinfo.filename, (filename.c_str()));
            strcpy(this->fileinfo.filepath, "./Photo");
//            //发送第15个协议
//            strcpy(photo.photoPath, readfile.c_str());
//            strcpy(photo.photoName, filename.c_str());
//            photo.allBytes = static_cast<int>(size);
//            filename.erase(filename.find("."), 4);
//            strcpy(photo.traitPhotoTime, filename.c_str());
//            qDebug() << "traitPhotoTime = " << photo.traitPhotoTime;
//            strcpy(photo.user_account, username.c_str());

//            head.businessType = 15;
//            head.businessLength = sizeof(PHOTO);
//            char bodyBuf[2000] = {0};
//            memcpy(bodyBuf, &photo, sizeof (PHOTO));
//            this->wth->setData(head, bodyBuf);

            while((res = read(rfd, this->buf, sizeof(this->buf)))!= 0)
            {
                //测试时本地的文件
        //        QString writefile = path+"/packets/" + QString::number(index++) + ".temp";
        //        this->wfd = open(writefile.toStdString().c_str(), O_WRONLY | O_CREAT, 0777);
        //        write(this->wfd, this->buf, res);
                //传输给服务器
                qDebug() << "this->filename = " << this->fileinfo.filename;
                qDebug() << "this->filepath = " << this->fileinfo.filepath;
                this->fileinfo.length = res;
                memcpy(this->fileinfo.context, this->buf, this->fileinfo.length);

                this->fileinfo.fileindex = index++;
                //存入链表
                this->fileList.push_back(this->fileinfo);
                this->fileMap.insert(make_pair(this->fileinfo.fileindex, this->fileinfo));
                //进行下一次要清空
                bzero(this->buf, sizeof(this->buf));
                //发送文件
                SendTask *sendTask = new SendTask(this->fileinfo, this->socketfd->getSocketfd());
                QThreadPool::globalInstance()->setMaxThreadCount(2);
                QThreadPool::globalInstance()->start(sendTask);
                msleep(500);
            }
            close(this->rfd);
            close(this->wfd);
            //图片发完告诉服务器开始拼
            strcpy(this->finish.account, userid.c_str());
            strcpy(this->finish.filename, filename.c_str());
            head.businessType = 13;
            head.businessLength = sizeof(FILE_FINISH);
            char bodyBuf[2000] = {0};
            memcpy(bodyBuf, &(this->fileinfo), sizeof (FILE_FINISH));
            this->wth->setData(head, bodyBuf);
            //等待丢包处理
            while(!(this->lossFlag))
            {

            }

            //确认这个文件发送完成后，这个文件的碎片链表清空
            this->fileList.clear();
            this->fileMap.clear();
            msleep(500);
            qDebug() << "发送完成一次图片" ;
        }

    }

}

void SplitFile::emitLossFile(FILE_LOSS fileLoss)
{
    //没有丢包
    if(fileLoss.fileCount==0)
    {
        this->lossFlag = 1;
    }
    //有丢包
    else
    {
         vector<string> strarr = split(fileLoss.buf);
         vector<string>::iterator i;
         map<int,FILEINFO>::iterator iter;
         for (i = strarr.begin(); i!=strarr.end();i++)
         {
             iter = this->fileMap.find(stoi(*i));
             //发送文件
             SendTask *sendTask = new SendTask(iter->second, this->socketfd->getSocketfd());
             QThreadPool::globalInstance()->setMaxThreadCount(2);
             QThreadPool::globalInstance()->start(sendTask);
             msleep(500);
         }
    }
}



